//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
char alien_dict[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char english_dict[] = "bcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZa";

// Function to translate an Alien word to English
char *alien_to_english(char *alien_word) {
  char *english_word = malloc(strlen(alien_word) + 1);
  int i;
  for (i = 0; i < strlen(alien_word); i++) {
    char alien_char = alien_word[i];
    int index = strchr(alien_dict, alien_char) - alien_dict;
    english_word[i] = english_dict[index];
  }
  english_word[i] = '\0';
  return english_word;
}

// Function to translate an English word to Alien
char *english_to_alien(char *english_word) {
  char *alien_word = malloc(strlen(english_word) + 1);
  int i;
  for (i = 0; i < strlen(english_word); i++) {
    char english_char = english_word[i];
    int index = strchr(english_dict, english_char) - english_dict;
    alien_word[i] = alien_dict[index];
  }
  alien_word[i] = '\0';
  return alien_word;
}

// Main function
int main() {
  // Get the Alien word from the user
  char alien_word[100];
  printf("Enter the Alien word: ");
  scanf("%s", alien_word);

  // Translate the Alien word to English
  char *english_word = alien_to_english(alien_word);

  // Print the English translation
  printf("The English translation is: %s\n", english_word);

  // Free the memory allocated for the English word
  free(english_word);

  // Get the English word from the user
  char english_word2[100];
  printf("Enter the English word: ");
  scanf("%s", english_word2);

  // Translate the English word to Alien
  char *alien_word2 = english_to_alien(english_word2);

  // Print the Alien translation
  printf("The Alien translation is: %s\n", alien_word2);

  // Free the memory allocated for the Alien word
  free(alien_word2);

  return 0;
}