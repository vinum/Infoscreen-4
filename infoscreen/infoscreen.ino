

#include <Time.h>

int relaypin = 7;
int ledpin = 13; 

int PIR_1 = 2;
int PIR_2 = 3;



unsigned long lastmovemnt = 0;
unsigned int offtime = 3600; //Seconds

unsigned long temp = 0;

void setup() {
//Serial.begin(9600);
pinMode(relaypin, OUTPUT); 
pinMode(ledpin, OUTPUT); 
digitalWrite(relaypin, LOW);
digitalWrite(ledpin, LOW);

pinMode(PIR_1, INPUT); 
//digitalWrite(PIR_1, LOW);
//attachInterrupt(0, movement, RISING);
//pinMode(PIR_2, INPUT); 
//attachInterrupt(1, movement, RISING);

}

void loop() {
/*  if(temp != now()){
Serial.print("lastmovement: ");
Serial.println(lastmovemnt);

Serial.print("now: ");
Serial.println(now());

Serial.print("PIR value: ");
Serial.println(PIR_1);
temp = now();
  }*/
if (digitalRead(PIR_1) == HIGH){
  lastmovemnt = now();
  }

if(now()- lastmovemnt < offtime){
  //Serial.println("IF");
  digitalWrite(relaypin, HIGH);
  digitalWrite(ledpin, HIGH);
}
else if(now()- lastmovemnt > offtime){
  //Serial.println("ELSE");
  digitalWrite(relaypin, LOW);
  digitalWrite(ledpin, LOW);
  }

delay(500); 
}


/*void movement(){
 detachInterrupt(0);
 //detachInterrupt(1);
 Serial.println("INTERRUPT");
 lastmovemnt = now();

 attachInterrupt(0, movement, RISING);
 //attachInterrupt(1, movement, RISING);
}*/
