   // Robot suiveur de ligne noir avec 2 tcrt5000 module et arduino uno et module l293d .
String command;    
//int right_motor = 4;  // in1 on L293D
//int left_motor = 3; // in3 on L293D
int infra1 =A1;  // pin out tcrt5000 droite
int infra2 =A2;  // pin out tcrt5000 gauche
int valorinfra1 =0;   // variable pour l'etat de la valeur capteur droite
int valorinfra2 =0;    // variable pour l'etat de la valeur capteur gauche

int EN1 = 9;
int IN1 = 8;
int EN2 = 3;
int IN3 = 5;

void setup() {
pinMode(EN1,OUTPUT);
pinMode(EN2,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN3,OUTPUT);
  pinMode(infra1,INPUT);
  pinMode(infra2,INPUT);
  Serial.begin(9600);
  delay(2000);
}
  
void loop(){
valorinfra1 = digitalRead(infra1 );
valorinfra2 = digitalRead(infra2 );
(Serial.available());{
command = Serial.readStringUntil('\n');
command.trim();

if (command == "Turn right ahead"){
   digitalWrite(IN1,HIGH);
   digitalWrite(IN3,LOW);
   delay(3000);
   Serial.print("Command: ");
   Serial.println(command);}

   else if (command == "Turn left ahead"){
   digitalWrite(IN1,LOW);
   digitalWrite(IN3,HIGH);
   delay(3000);
   Serial.print("Command: ");
   Serial.println(command);}

   else if (command == "Stop"){
   digitalWrite(IN1,LOW);
   digitalWrite(IN3,LOW);
   delay(2000);
   Serial.print("Command: ");
   Serial.println(command);}
   
   else {
   digitalWrite(IN1,HIGH);
   digitalWrite(IN3,HIGH);
   Serial.print("Command: ");
   Serial.println(command);}
}
if (digitalRead(infra1) == LOW){    
  digitalWrite(IN1, HIGH );
  analogWrite(EN1,180);
  
  }
  else {   
  digitalWrite(IN1,LOW);
  }
  
if (digitalRead(infra2) == LOW){
  digitalWrite(IN3, HIGH );
  analogWrite(EN2,180);
  }
  else {    
  digitalWrite(IN3,LOW);
  }
 }
