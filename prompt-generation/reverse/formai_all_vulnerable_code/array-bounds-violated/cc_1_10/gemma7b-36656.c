//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_Morse_CODE_LENGTH 20

typedef struct MorseCodeEntry {
  char character;
  char morse_code[MAX_Morse_CODE_LENGTH];
} MorseCodeEntry;

MorseCodeEntry morse_code_table[] = {
  {'a', "-.-"},
  {'b', "-.."},
  {'c', "..-"},
  {'d', "..."},
  {'e', "."},
  {'f', ".."},
  {'g', "--"},
  {'h', "...."},
  {'i', ".."},
  {'j', ".---"},
  {'k', "-.."},
  {'l', ".-.."},
  {'m', "--"},
  {'n', "-."},
  {'o', "---"},
  {'p', ".--"},
  {'q', "--.."},
  {'r', ".-"},
  {'s', "..."},
  {'t', "-"},
  {'u', "..-"},
  {'v', "...-"},
  {'w', ".--"},
  {'x', "-..-"},
  {'y', "-.--"},
  {'z', "--.."},
  {'1', ".----"},
  {'2', "..---"},
  {'3', "...--"},
  {'4', "....-"},
  {'5', "....."},
  {'6', "-...."},
  {'7', "--..-"},
  {'8', "---.."},
  {'9', "----."},
  {'0', "-----"}
};

int main() {
  char text[] = "Hello, world!";

  for (int i = 0; text[i] != '\0'; i++) {
    MorseCodeEntry entry = morse_code_table[text[i] - 'a'];
    printf("%s ", entry.morse_code);
  }

  printf("\n");

  return 0;
}