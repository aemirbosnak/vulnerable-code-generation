//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype of translation function
char* translate(char* alienLanguageStr);

int main() {
  // Sample alien language string
  char alienLanguageStr[] = "Dhr zhov zgh glgh";  // Hello in alien language

  // Translate the alien language string
  char* translatedText = translate(alienLanguageStr);

  // Print the translated text
  printf("Translated text: %s\n", translatedText);
  
  // Free the memory allocated to the translated text
  free(translatedText);

  return 0;
}

// Function to translate the alien language string
char* translate(char* alienLanguageStr) {
  // Create a buffer to store the translated text
  char* translatedText = (char*)malloc(strlen(alienLanguageStr) * 2 + 1);

  // Iterate through each character in the alien language string
  int i = 0;
  while (alienLanguageStr[i] != '\0') {
    // Get the current character and convert it to lowercase
    char c = alienLanguageStr[i];
    c = tolower(c);
    
    // Translate the character based on the alien language rules
    char translatedChar;
    switch (c) {
      case 'a':
        translatedChar = 'e';
        break;
      case 'b':
        translatedChar = 'i';
        break;
      case 'c':
        translatedChar = 'o';
        break;
      case 'd':
        translatedChar = 'u';
        break;
      case 'e':
        translatedChar = 'a';
        break;
      case 'f':
        translatedChar = 'y';
        break;
      case 'g':
        translatedChar = 'h';
        break;
      case 'h':
        translatedChar = 'j';
        break;
      case 'i':
        translatedChar = 'b';
        break;
      case 'j':
        translatedChar = 'g';
        break;
      case 'k':
        translatedChar = 'l';
        break;
      case 'l':
        translatedChar = 'k';
        break;
      case 'm':
        translatedChar = 'n';
        break;
      case 'n':
        translatedChar = 'm';
        break;
      case 'o':
        translatedChar = 'c';
        break;
      case 'p':
        translatedChar = 'r';
        break;
      case 'q':
        translatedChar = 's';
        break;
      case 'r':
        translatedChar = 'p';
        break;
      case 's':
        translatedChar = 'q';
        break;
      case 't':
        translatedChar = 'v';
        break;
      case 'u':
        translatedChar = 'd';
        break;
      case 'v':
        translatedChar = 't';
        break;
      case 'w':
        translatedChar = 'x';
        break;
      case 'x':
        translatedChar = 'w';
        break;
      case 'y':
        translatedChar = 'f';
        break;
      case 'z':
        translatedChar = 'z';
        break;
      default:
        translatedChar = c;
        break;
    }
    
    // Append the translated character to the translated text
    translatedText[i] = translatedChar;
    
    // Increment the index
    i++;
  }
  
  // Add the null terminator to the translated text
  translatedText[i] = '\0';
  
  // Return the translated text
  return translatedText;
}