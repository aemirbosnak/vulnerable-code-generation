//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 256

typedef struct {
  char letter;
  char* morse;
} MORSE_CODE;

MORSE_CODE morse_codes[] = {
  {'A', ".-"},
  {'B', "-..."},
  {'C', "-.-."},
  {'D', "-.."},
  {'E', "."},
  {'F', "..-."},
  {'G', "--."},
  {'H', "...."},
  {'I', ".."},
  {'J', ".---"},
  {'K', "-.-"},
  {'L', ".-.."},
  {'M', "--"},
  {'N', "-."},
  {'O', "---"},
  {'P', ".--."},
  {'Q', "--.-"},
  {'R', ".-."},
  {'S', "..."},
  {'T', "-"},
  {'U', "..-"},
  {'V', "...-"},
  {'W', ".--"},
  {'X', "-..-"},
  {'Y', "-.--"},
  {'Z', "--.."},
  {'0', "-----"},
  {'1', ".----"},
  {'2', "..---"},
  {'3', "...--"},
  {'4', "....-"},
  {'5', "....."},
  {'6', "-...."},
  {'7', "--..."},
  {'8', "---.."},
  {'9', "----."},
  {'\0', NULL}
};

char* lookup_morse(char letter) {
  for (int i = 0; morse_codes[i].letter; i++) {
    if (morse_codes[i].letter == letter) {
      return morse_codes[i].morse;
    }
  }
  return NULL;
}

int main() {
  char input[LEN];
  char output[LEN];
  
  printf("Enter a text: ");
  scanf("%s", input);
  
  int len = strlen(input);
  int output_len = 0;
  for (int i = 0; i < len; i++) {
    char* morse = lookup_morse(input[i]);
    if (morse) {
      strcat(output, morse);
      output_len += strlen(morse);
    }
  }
  
  printf("Morse code: %s\n", output);
  
  return 0;
}