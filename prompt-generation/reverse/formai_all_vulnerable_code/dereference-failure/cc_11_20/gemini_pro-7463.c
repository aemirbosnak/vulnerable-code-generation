//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *englishToMorse(char *string) {
  int length = strlen(string);
  char *morseCode = malloc(length * 5);

  for (int i = 0; i < length; i++) {
    switch (string[i]) {
      case 'A':
        strcat(morseCode, ".-");
        break;
      case 'B':
        strcat(morseCode, "-...");
        break;
      case 'C':
        strcat(morseCode, "-.-.");
        break;
      case 'D':
        strcat(morseCode, "-..");
        break;
      case 'E':
        strcat(morseCode, ".");
        break;
      case 'F':
        strcat(morseCode, "..-.");
        break;
      case 'G':
        strcat(morseCode, "--.");
        break;
      case 'H':
        strcat(morseCode, "....");
        break;
      case 'I':
        strcat(morseCode, "..");
        break;
      case 'J':
        strcat(morseCode, ".---");
        break;
      case 'K':
        strcat(morseCode, "-.-");
        break;
      case 'L':
        strcat(morseCode, ".-..");
        break;
      case 'M':
        strcat(morseCode, "--");
        break;
      case 'N':
        strcat(morseCode, "-.");
        break;
      case 'O':
        strcat(morseCode, "---");
        break;
      case 'P':
        strcat(morseCode, ".--.");
        break;
      case 'Q':
        strcat(morseCode, "--.-");
        break;
      case 'R':
        strcat(morseCode, ".-.");
        break;
      case 'S':
        strcat(morseCode, "...");
        break;
      case 'T':
        strcat(morseCode, "-");
        break;
      case 'U':
        strcat(morseCode, "..-");
        break;
      case 'V':
        strcat(morseCode, "...-");
        break;
      case 'W':
        strcat(morseCode, ".--");
        break;
      case 'X':
        strcat(morseCode, "-..-");
        break;
      case 'Y':
        strcat(morseCode, "-.--");
        break;
      case 'Z':
        strcat(morseCode, "--..");
        break;
      case '1':
        strcat(morseCode, ".----");
        break;
      case '2':
        strcat(morseCode, "..---");
        break;
      case '3':
        strcat(morseCode, "...--");
        break;
      case '4':
        strcat(morseCode, "....-");
        break;
      case '5':
        strcat(morseCode, ".....");
        break;
      case '6':
        strcat(morseCode, "-....");
        break;
      case '7':
        strcat(morseCode, "--...");
        break;
      case '8':
        strcat(morseCode, "---..");
        break;
      case '9':
        strcat(morseCode, "----.");
        break;
      case '0':
        strcat(morseCode, "-----");
        break;
      case ' ':
        strcat(morseCode, " ");
        break;
      default:
        strcat(morseCode, "");
        break;
    }
  }

  return morseCode;
}

int main() {
  char *englishText = "SAMPLE TEXT";
  char *morseCode = englishToMorse(englishText);

  printf("English Text: %s\n", englishText);
  printf("Morse Code: %s\n", morseCode);

  free(morseCode);
  return 0;
}