#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 12);
const int BUTTON = 2;
const int LED    = 13;
const int BUZZER = 8;
const int DOT   = 100;
const int DASH  = 300;
const int G_SIG = 100;
const int G_LET = 300;
const int G_SOS = 700;

void beep(int dur) {
  digitalWrite(LED, HIGH);
  tone(BUZZER, 1000);
  delay(dur);
  digitalWrite(LED, LOW);
  noTone(BUZZER);
  delay(G_SIG);
}

void sendS() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sending S...");
  lcd.setCursor(0, 1);
  lcd.print("   . . .   ");
  Serial.println("S: . . .");
  beep(DOT);
  beep(DOT);
  beep(DOT);
  delay(G_LET);
}

void sendO() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sending O...");
  lcd.setCursor(0, 1);
  lcd.print(" --- --- --- ");
  Serial.println("O: --- --- ---");
  beep(DASH);
  beep(DASH);
  beep(DASH);
  delay(G_LET);
}

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED,    OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("  SOS SYSTEM  ");
  lcd.setCursor(0, 1);
  lcd.print(" Press Button!");
}

void loop() {
  if (digitalRead(BUTTON) == LOW)
   {
    Serial.println("=== SOS START ===");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SOS SENDING...  ");
    delay(500);
    sendS();  
    sendO();  
    sendS();  
    //digitalWrite(LED, HIGH);
    //tone(BUZZER);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SOS COMPLETE!   ");
    lcd.setCursor(0, 1);
    lcd.print(". . . --- . . .");
    Serial.println("=== SOS DONE ===");
    delay(G_SOS);
  } else {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
    lcd.setCursor(0, 0);
    lcd.print("  SOS SYSTEM  ");
    lcd.setCursor(0, 1);
    lcd.print(" Press Button!");
  }
}
