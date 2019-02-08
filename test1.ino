#include <Servo.h>

//電池はVmotに＋、ボードの-に-


int AIN1 =12;//正方向
int AIN2 =13;//逆方向
int PWMA =11;//速さ変更
//
int echoPin=9;//echopinは入力
int trigPin=8; //trigpinは出力
double Duration=0;
double distance=0;


Servo myservo;
int val;

void setup(){
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  myservo.attach(8);//8番ピンでサーボを制御
}

void loop(){
  //モータの制御
  int i=0;
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,LOW);
  val = 0;
  myservo.write(val);
  
 delay(1500);
 val = 120;
 myservo.write(val);
 delay(1500);
 val = -120;
 myservo.write(val);
delay(1500);
 val = 150;
 myservo.write(val);
 delay(1500);
 val = -150;
 myservo.write(val);
  

 digitalWrite(AIN1,HIGH);
 digitalWrite(AIN2,LOW);
 for(i=0;i<256;i++){
  analogWrite(PWMA,i);//こいつで速さを変える
  delay(500);
 
// for(i=255;i>=0;i--){
//  analogWrite(PWMA,i);
//  delay(500);
// }
//モータの制御終了

//センサー
   Serial.begin(9600);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);  //8回パルス波
  Duration = pulseIn(echoPin ,HIGH);  //HIGHになってからLOWになるまでの時間を計測
  if(Duration>0){
    Duration = Duration/2 ;
    distance = Duration*340*100/1000000;
    Serial.print("Distance");
    Serial.print(distance);
    Serial.println("cm");
  }

  if(distance<10){
    break;
  }
 }
  }
  
 
