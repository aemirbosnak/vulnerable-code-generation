//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the functions
void print_greeting();
void translate_alien_word(char *word);

// Define the main function
int main() {
  // Print the greeting
  print_greeting();

  // Get the alien word from the user
  char word[100];
  printf("Enter the alien word: ");
  scanf("%s", word);

  // Translate the alien word
  translate_alien_word(word);

  return 0;
}

// Define the print_greeting function
void print_greeting() {
  printf("Welcome to the Alien Language Translator!\n");
  printf("This translator can help you translate any alien word into English.\n");
}

// Define the translate_alien_word function
void translate_alien_word(char *word) {
  // Declare the variables
  int i;
  int length = strlen(word);
  char translated_word[100];

  // Translate the word
  for (i = 0; i < length; i++) {
    switch (word[i]) {
      case 'a':
        translated_word[i] = 'e';
        break;
      case 'b':
        translated_word[i] = 'i';
        break;
      case 'c':
        translated_word[i] = 'o';
        break;
      case 'd':
        translated_word[i] = 'u';
        break;
      case 'e':
        translated_word[i] = 'a';
        break;
      case 'f':
        translated_word[i] = 's';
        break;
      case 'g':
        translated_word[i] = 'd';
        break;
      case 'h':
        translated_word[i] = 'f';
        break;
      case 'i':
        translated_word[i] = 'g';
        break;
      case 'j':
        translated_word[i] = 'h';
        break;
      case 'k':
        translated_word[i] = 'j';
        break;
      case 'l':
        translated_word[i] = 'k';
        break;
      case 'm':
        translated_word[i] = 'l';
        break;
      case 'n':
        translated_word[i] = 'z';
        break;
      case 'o':
        translated_word[i] = 'x';
        break;
      case 'p':
        translated_word[i] = 'c';
        break;
      case 'q':
        translated_word[i] = 'v';
        break;
      case 'r':
        translated_word[i] = 'b';
        break;
      case 's':
        translated_word[i] = 'n';
        break;
      case 't':
        translated_word[i] = 'm';
        break;
      case 'u':
        translated_word[i] = ',';
        break;
      case 'v':
        translated_word[i] = '.';
        break;
      case 'w':
        translated_word[i] = '!';
        break;
      case 'x':
        translated_word[i] = '?';
        break;
      case 'y':
        translated_word[i] = ':';
        break;
      case 'z':
        translated_word[i] = ';';
        break;
      default:
        translated_word[i] = word[i];
        break;
    }
  }

  // Print the translated word
  printf("The translated word is: %s\n", translated_word);
}