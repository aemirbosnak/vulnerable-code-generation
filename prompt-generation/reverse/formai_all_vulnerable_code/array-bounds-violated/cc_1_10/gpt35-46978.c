//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: systematic
#include<stdio.h>
#include<string.h>

void convertToMorse(char* morseStr, char* textStr);

int main() {
  char textStr[100];
  char morseStr[100];
  
  printf("Please enter the text you want to convert to Morse code: ");
  fgets(textStr, 100, stdin);
  
  convertToMorse(morseStr,textStr);
  
  printf("Morse code: %s", morseStr);
  
  return 0;
}

void convertToMorse(char* morseStr, char* textStr) {
  
  //Array to hold the Morse code for each letter and number
  char* morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   //A-I
                       ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", //J-R
                       "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", //S-Z,0-9
                       ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

  int textStrLen = strlen(textStr);
  int currIndex = 0;
  
  for (int i = 0; i < textStrLen; i++) {
    char currChar = textStr[i];
    
    //Convert uppercase letters to lowercase
    if (currChar >= 'A' && currChar <= 'Z') {
      currChar += 32;
    }
    
    //Check if current character is a space
    if (currChar == ' ') {
      //Add 3 spaces for word separation
      morseStr[currIndex++] = ' ';
      morseStr[currIndex++] = ' ';
      morseStr[currIndex++] = ' ';
    }
    else {
      //Get Morse code for current character
      int morseIndex = currChar - 'a';
      char* morseChar = morseCode[morseIndex];
      
      //Add Morse code to morse string
      for (int j = 0; j < strlen(morseChar); j++) {
        morseStr[currIndex++] = morseChar[j];
      }
      //Add space for character separation
      morseStr[currIndex++] = ' ';
    }
  }
  //End the Morse string with a null character
  morseStr[currIndex] = '\0';
}