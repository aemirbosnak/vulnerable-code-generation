//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_Morse_CODE_LENGTH 20

typedef struct MorseCodeEntry {
  char character;
  char morse_code[MAX_Morse_CODE_LENGTH];
} MorseCodeEntry;

MorseCodeEntry morse_code_table[] = {
  {'a', "-.-"},
  {'b', "-.."},
  {'c', ".."},
  {'d', "."},
  {'e', ""},
  {'f', "..-."},
  {'g', "--"},
  {'h', "...."},
  {'i', ".."},
  {'j', ".---"},
  {'k', "-.."},
  {'l', ".-"},
  {'m', "--."},
  {'n', "-"},
  {'o', "---"},
  {'p', ".--"},
  {'q', "--.-"},
  {'r', ".-."},
  {'s', "..."},
  {'t', "-"},
  {'u', "..-"},
  {'v', "...-"},
  {'w', ".--"},
  {'x', "-..-"},
  {'y', "--.."},
  {'z', "----"}
};

int main() {
  char character;

  printf("Enter a character: ");
  scanf("%c", &character);

  for (int i = 0; i < sizeof(morse_code_table) / sizeof(MorseCodeEntry); i++) {
    if (morse_code_table[i].character == character) {
      printf("Morse code: %s\n", morse_code_table[i].morse_code);
    }
  }

  return 0;
}