//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the Alien language symbols and their English equivalents.
const char *alienSymbols[] = {"⚼", "⚽", "⚾", "⚿", "⛀", "⛁", "⛂", "⛃", "⛄", "⛅",
                              "⛆", "⛇", "⛈", "⛉", "⛊", "⛋", "⛌", "⛍", "⛎", "⛏"};
const char *englishEquivalents[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                                   "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};

// Declare the function to translate Alien language to English.
char *alienToEnglish(char *alienText) {
  // Allocate memory for the translated text.
  char *englishText = malloc(strlen(alienText) + 1);

  // Iterate over each character in the Alien language text.
  for (int i = 0; i < strlen(alienText); i++) {
    // Find the index of the Alien language character in the symbol array.
    int symbolIndex = -1;
    for (int j = 0; j < sizeof(alienSymbols) / sizeof(char *); j++) {
      if (strcmp(alienSymbols[j], alienText[i]) == 0) {
        symbolIndex = j;
        break;
      }
    }

    // If the character is not found in the symbol array, it is an invalid character.
    if (symbolIndex == -1) {
      printf("Error: Invalid Alien language character '%c'.\n", alienText[i]);
      free(englishText);
      return NULL;
    }

    // Append the English equivalent of the Alien language character to the translated text.
    englishText[i] = englishEquivalents[symbolIndex];
  }

  // Null-terminate the translated text.
  englishText[strlen(alienText)] = '\0';

  // Return the translated text.
  return englishText;
}

// Declare the function to translate English to Alien language.
char *englishToAlien(char *englishText) {
  // Allocate memory for the translated text.
  char *alienText = malloc(strlen(englishText) + 1);

  // Iterate over each character in the English text.
  for (int i = 0; i < strlen(englishText); i++) {
    // Find the index of the English character in the equivalent array.
    int equivalentIndex = -1;
    for (int j = 0; j < sizeof(englishEquivalents) / sizeof(char *); j++) {
      if (strcmp(englishEquivalents[j], englishText[i]) == 0) {
        equivalentIndex = j;
        break;
      }
    }

    // If the character is not found in the equivalent array, it is an invalid character.
    if (equivalentIndex == -1) {
      printf("Error: Invalid English character '%c'.\n", englishText[i]);
      free(alienText);
      return NULL;
    }

    // Append the Alien language equivalent of the English character to the translated text.
    alienText[i] = alienSymbols[equivalentIndex];
  }

  // Null-terminate the translated text.
  alienText[strlen(englishText)] = '\0';

  // Return the translated text.
  return alienText;
}

// Declare the main function.
int main() {
  // Prompt the user to enter the Alien language text to translate.
  printf("Enter the Alien language text to translate: ");
  char *alienText = malloc(100);
  scanf("%s", alienText);

  // Translate the Alien language text to English.
  char *englishText = alienToEnglish(alienText);

  // Print the translated English text.
  printf("English translation: %s\n", englishText);

  // Free the allocated memory.
  free(alienText);
  free(englishText);

  return 0;
}