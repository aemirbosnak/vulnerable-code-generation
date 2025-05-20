//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_Morse_CODE_LENGTH 20

typedef struct MorseCodeEntry
{
  char letter;
  char morseCode[MAX_Morse_CODE_LENGTH];
} MorseCodeEntry;

MorseCodeEntry morseCodeTable[] =
{
  {'a', "-.-"},
  {'b', "-.."},
  {'c', "--."},
  {'d', ".."},
  {'e', "."},
  {'f', "..-."},
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
  {'q', "--.-"},
  {'r', ".-"},
  {'s', "..."},
  {'t', "-"},
  {'u', "..-"},
  {'v', "...-"},
  {'w', ".--"},
  {'x', "-..-"},
  {'y', "--.."},
  {'z', "-----"}
};

int main()
{
  char message[] = "Hello, world!";
  int i = 0;

  printf("Original message: %s\n", message);

  for (i = 0; message[i] != '\0'; i++)
  {
    MorseCodeEntry entry = morseCodeTable[message[i] - 'a'];
    printf("%c is translated to: %s\n", message[i], entry.morseCode);
  }

  return 0;
}