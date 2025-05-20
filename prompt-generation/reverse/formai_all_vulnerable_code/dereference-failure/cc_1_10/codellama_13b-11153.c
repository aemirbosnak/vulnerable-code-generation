//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
#include <stdio.h>
  #include <string.h>

  #define MORSE_DOT "."
  #define MORSE_DASH "-"
  #define MORSE_SPACE " "
  #define MORSE_UNKNOWN "*"

  char* morse_code[] = {
    "A", MORSE_DOT,
    "B", MORSE_DASH, MORSE_DOT, MORSE_DOT, MORSE_DOT,
    "C", MORSE_DASH, MORSE_DOT, MORSE_DASH, MORSE_DOT,
    "D", MORSE_DASH, MORSE_DOT, MORSE_DOT,
    "E", MORSE_DOT,
    "F", MORSE_DOT, MORSE_DOT, MORSE_DASH, MORSE_DOT,
    "G", MORSE_DASH, MORSE_DASH, MORSE_DOT,
    "H", MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_DOT,
    "I", MORSE_DOT, MORSE_DOT,
    "J", MORSE_DOT, MORSE_DASH, MORSE_DASH, MORSE_DASH,
    "K", MORSE_DASH, MORSE_DOT, MORSE_DASH,
    "L", MORSE_DOT, MORSE_DASH, MORSE_DOT, MORSE_DOT,
    "M", MORSE_DASH, MORSE_DASH,
    "N", MORSE_DASH, MORSE_DOT,
    "O", MORSE_DASH, MORSE_DASH, MORSE_DASH,
    "P", MORSE_DOT, MORSE_DASH, MORSE_DASH, MORSE_DOT,
    "Q", MORSE_DASH, MORSE_DASH, MORSE_DASH, MORSE_DASH,
    "R", MORSE_DOT, MORSE_DASH, MORSE_DOT,
    "S", MORSE_DOT, MORSE_DOT, MORSE_DOT,
    "T", MORSE_DASH,
    "U", MORSE_DOT, MORSE_DOT, MORSE_DASH,
    "V", MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_DASH,
    "W", MORSE_DOT, MORSE_DASH, MORSE_DASH,
    "X", MORSE_DASH, MORSE_DOT, MORSE_DOT, MORSE_DASH,
    "Y", MORSE_DASH, MORSE_DOT, MORSE_DASH, MORSE_DASH,
    "Z", MORSE_DASH, MORSE_DASH, MORSE_DOT, MORSE_DOT,
    "0", MORSE_DASH, MORSE_DASH, MORSE_DASH, MORSE_DASH, MORSE_DASH,
    "1", MORSE_DOT, MORSE_DASH, MORSE_DASH, MORSE_DASH, MORSE_DASH,
    "2", MORSE_DOT, MORSE_DOT, MORSE_DASH, MORSE_DASH, MORSE_DASH,
    "3", MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_DASH, MORSE_DASH,
    "4", MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_DASH,
    "5", MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_DOT,
    "6", MORSE_DASH, MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_DOT,
    "7", MORSE_DASH, MORSE_DASH, MORSE_DOT, MORSE_DOT, MORSE_DOT,
    "8", MORSE_DASH, MORSE_DASH, MORSE_DASH, MORSE_DOT, MORSE_DOT,
    "9", MORSE_DASH, MORSE_DASH, MORSE_DASH, MORSE_DASH, MORSE_DOT,
    " ", MORSE_SPACE
  };

  char* morse_encode(char* text) {
    char* result = malloc(strlen(text) * 5 + 1);
    char* p = result;
    for (int i = 0; i < strlen(text); i++) {
      char* code = morse_code[text[i]];
      if (code == NULL) {
        *p++ = MORSE_UNKNOWN;
      } else {
        strcpy(p, code);
        p += strlen(code);
      }
      *p++ = MORSE_SPACE;
    }
    *p = '\0';
    return result;
  }

  int main() {
    char* text = "Hello World!";
    char* result = morse_encode(text);
    printf("%s\n", result);
    free(result);
    return 0;
  }