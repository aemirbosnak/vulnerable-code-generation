//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Romeo and Juliet style Alien Language Translator

//Function to translate a word from English to Alien
char *englishToAlien(char *word) {
  //Allocate memory for the translated word
  char *translatedWord = malloc(strlen(word) + 1);

  //Translate the word
  for (int i = 0; i < strlen(word); i++) {
    switch (word[i]) {
      case 'a':
        translatedWord[i] = 'j';
        break;
      case 'b':
        translatedWord[i] = 'q';
        break;
      case 'c':
        translatedWord[i] = 'z';
        break;
      case 'd':
        translatedWord[i] = 'x';
        break;
      case 'e':
        translatedWord[i] = 'v';
        break;
      case 'f':
        translatedWord[i] = 't';
        break;
      case 'g':
        translatedWord[i] = 's';
        break;
      case 'h':
        translatedWord[i] = 'r';
        break;
      case 'i':
        translatedWord[i] = 'n';
        break;
      case 'j':
        translatedWord[i] = 'b';
        break;
      case 'k':
        translatedWord[i] = 'm';
        break;
      case 'l':
        translatedWord[i] = 'f';
        break;
      case 'm':
        translatedWord[i] = 'h';
        break;
      case 'n':
        translatedWord[i] = 'g';
        break;
      case 'o':
        translatedWord[i] = 'd';
        break;
      case 'p':
        translatedWord[i] = 'c';
        break;
      case 'q':
        translatedWord[i] = 'a';
        break;
      case 'r':
        translatedWord[i] = 'e';
        break;
      case 's':
        translatedWord[i] = 'w';
        break;
      case 't':
        translatedWord[i] = 'y';
        break;
      case 'u':
        translatedWord[i] = 'p';
        break;
      case 'v':
        translatedWord[i] = 'i';
        break;
      case 'w':
        translatedWord[i] = 'o';
        break;
      case 'x':
        translatedWord[i] = 'u';
        break;
      case 'y':
        translatedWord[i] = 'k';
        break;
      case 'z':
        translatedWord[i] = 'l';
        break;
      default:
        translatedWord[i] = word[i];
    }
  }

  //Return the translated word
  return translatedWord;
}

//Function to translate a word from Alien to English
char *alienToEnglish(char *word) {
  //Allocate memory for the translated word
  char *translatedWord = malloc(strlen(word) + 1);

  //Translate the word
  for (int i = 0; i < strlen(word); i++) {
    switch (word[i]) {
      case 'j':
        translatedWord[i] = 'a';
        break;
      case 'q':
        translatedWord[i] = 'b';
        break;
      case 'z':
        translatedWord[i] = 'c';
        break;
      case 'x':
        translatedWord[i] = 'd';
        break;
      case 'v':
        translatedWord[i] = 'e';
        break;
      case 't':
        translatedWord[i] = 'f';
        break;
      case 's':
        translatedWord[i] = 'g';
        break;
      case 'r':
        translatedWord[i] = 'h';
        break;
      case 'n':
        translatedWord[i] = 'i';
        break;
      case 'b':
        translatedWord[i] = 'j';
        break;
      case 'm':
        translatedWord[i] = 'k';
        break;
      case 'f':
        translatedWord[i] = 'l';
        break;
      case 'h':
        translatedWord[i] = 'm';
        break;
      case 'g':
        translatedWord[i] = 'n';
        break;
      case 'd':
        translatedWord[i] = 'o';
        break;
      case 'c':
        translatedWord[i] = 'p';
        break;
      case 'a':
        translatedWord[i] = 'q';
        break;
      case 'e':
        translatedWord[i] = 'r';
        break;
      case 'w':
        translatedWord[i] = 's';
        break;
      case 'y':
        translatedWord[i] = 't';
        break;
      case 'p':
        translatedWord[i] = 'u';
        break;
      case 'i':
        translatedWord[i] = 'v';
        break;
      case 'o':
        translatedWord[i] = 'w';
        break;
      case 'u':
        translatedWord[i] = 'x';
        break;
      case 'k':
        translatedWord[i] = 'y';
        break;
      case 'l':
        translatedWord[i] = 'z';
        break;
      default:
        translatedWord[i] = word[i];
    }
  }

  //Return the translated word
  return translatedWord;
}

//Main function
int main() {
  //Get the input text
  char *inputText = malloc(1024);
  printf("Enter the text to be translated: ");
  gets(inputText);

  //Translate the text from English to Alien
  char *translatedText = englishToAlien(inputText);

  //Print the translated text
  printf("Translated text: %s\n", translatedText);

  //Translate the text from Alien to English
  char *retranslatedText = alienToEnglish(translatedText);

  //Print the retranslated text
  printf("Retranslated text: %s\n", retranslatedText);

  //Free the allocated memory
  free(inputText);
  free(translatedText);
  free(retranslatedText);

  return 0;
}