//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to translate a character from Alien Language to English
char translateChar(char c) {
  // Check if the character is a lowercase letter
  if (islower(c)) {
    // Convert the character to uppercase
    c = toupper(c);
  }

  // Check if the character is an uppercase letter
  if (isupper(c)) {
    // Convert the character to lowercase
    c = tolower(c);
  }

  // Return the translated character
  return c;
}

// Function to translate a string from Alien Language to English
char *translateString(char *s) {
  // Allocate memory for the translated string
  char *translatedString = malloc(strlen(s) + 1);

  // Translate each character in the string
  for (int i = 0; i < strlen(s); i++) {
    translatedString[i] = translateChar(s[i]);
  }

  // Add the null terminator to the end of the translated string
  translatedString[strlen(s)] = '\0';

  // Return the translated string
  return translatedString;
}

// Function to get a string from the user
char *getInputString() {
  // Allocate memory for the input string
  char *inputString = malloc(100);

  // Get the input string from the user
  printf("Enter a string in Alien Language: ");
  gets(inputString);

  // Return the input string
  return inputString;
}

// Main function
int main() {
  // Get a string from the user
  char *inputString = getInputString();

  // Translate the string from Alien Language to English
  char *translatedString = translateString(inputString);

  // Print the translated string
  printf("The translated string in English is: %s\n", translatedString);

  // Free the memory allocated for the input and translated strings
  free(inputString);
  free(translatedString);

  return 0;
}