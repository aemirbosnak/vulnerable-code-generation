//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
// Cat Translator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate a string from English to Cat Language
char *translate(char *str) {
  // Create a new string to store the translated text
  char *translated = malloc(strlen(str) + 1);

  // Loop through each character in the string
  int i = 0;
  while (str[i] != '\0') {
    // Translate the character to Cat Language
    switch (str[i]) {
      case 'a':
        translated[i] = 'm';
        break;
      case 'e':
        translated[i] = 'o';
        break;
      case 'i':
        translated[i] = 'a';
        break;
      case 'o':
        translated[i] = 'e';
        break;
      case 'u':
        translated[i] = 'i';
        break;
      default:
        translated[i] = str[i];
    }

    // Increment the index
    i++;
  }

  // Add the null-terminator to the translated string
  translated[i] = '\0';

  // Return the translated string
  return translated;
}

// Function to print a message in Cat Language
void meow(char *str) {
  // Translate the string to Cat Language
  char *translated = translate(str);

  // Print the translated string
  printf("%s", translated);

  // Free the memory allocated for the translated string
  free(translated);
}

// Main function
int main() {
  // Get the message from the user
  char str[100];
  printf("Enter a message to translate to Cat Language: ");
  gets(str);

  // Translate the message to Cat Language
  meow(str);

  // Return 0 to indicate successful execution
  return 0;
}