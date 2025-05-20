//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is an alien character
int isAlienChar(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ' || c == ',' || c == '.' || c == '!' || c == '?' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '<' || c == '>' || c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

// Function to translate an alien word into English
char* translateWord(char* word) {
  int len = strlen(word);
  char* translation = malloc(len + 1);
  int i, j;
  for (i = 0, j = 0; i < len; i++) {
    if (isAlienChar(word[i])) {
      translation[j++] = word[i];
    }
  }
  translation[j] = '\0';
  return translation;
}

// Function to translate an alien sentence into English
char* translateSentence(char* sentence) {
  int len = strlen(sentence);
  char* translation = malloc(len + 1);
  int i, j;
  for (i = 0, j = 0; i < len; i++) {
    if (sentence[i] == ' ') {
      translation[j++] = ' ';
    } else {
      char* word = malloc(len + 1);
      int k;
      for (k = i; k < len && sentence[k] != ' '; k++) {
        word[k - i] = sentence[k];
      }
      word[k - i] = '\0';
      char* translatedWord = translateWord(word);
      strcat(translation, translatedWord);
      j += strlen(translatedWord);
      i = k;
    }
  }
  translation[j] = '\0';
  return translation;
}

int main() {
  // Get the alien sentence from the user
  char* sentence;
  printf("Enter an alien sentence: ");
  scanf("%s", sentence);

  // Translate the alien sentence into English
  char* translation = translateSentence(sentence);

  // Print the English translation
  printf("English translation: %s\n", translation);

  // Free the allocated memory
  free(translation);

  return 0;
}