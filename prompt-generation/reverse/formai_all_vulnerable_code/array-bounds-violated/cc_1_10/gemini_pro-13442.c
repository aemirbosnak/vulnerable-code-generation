//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language alphabet
char alien_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Define the Earth language alphabet
char earth_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

// Define the translation table
int translation_table[26][26];

// Initialize the translation table
void init_translation_table() {
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      translation_table[i][j] = -1;
    }
  }

  // Add the Earth to Alien translations
  for (int i = 0; i < 26; i++) {
    translation_table[i][i] = i;
  }

  // Add the Alien to Earth translations
  for (int i = 0; i < 26; i++) {
    translation_table[i + 26][i] = i;
  }
}

// Translate an Alien word to an Earth word
char *translate_alien_to_earth(char *alien_word) {
  int len = strlen(alien_word);
  char *earth_word = malloc(len + 1);

  for (int i = 0; i < len; i++) {
    int alien_char = alien_word[i];
    int earth_char = translation_table[alien_char][0];
    earth_word[i] = earth_char;
  }

  earth_word[len] = '\0';
  return earth_word;
}

// Translate an Earth word to an Alien word
char *translate_earth_to_alien(char *earth_word) {
  int len = strlen(earth_word);
  char *alien_word = malloc(len + 1);

  for (int i = 0; i < len; i++) {
    int earth_char = earth_word[i];
    int alien_char = translation_table[0][earth_char];
    alien_word[i] = alien_char;
  }

  alien_word[len] = '\0';
  return alien_word;
}

int main() {
  // Initialize the translation table
  init_translation_table();

  // Get the Alien word from the user
  char alien_word[100];
  printf("Enter an Alien word: ");
  scanf("%s", alien_word);

  // Translate the Alien word to an Earth word
  char *earth_word = translate_alien_to_earth(alien_word);

  // Print the Earth word to the user
  printf("The Earth word is: %s\n", earth_word);

  // Free the memory allocated for the Earth word
  free(earth_word);

  // Get the Earth word from the user
  char earth_word2[100];
  printf("Enter an Earth word: ");
  scanf("%s", earth_word2);

  // Translate the Earth word to an Alien word
  char *alien_word2 = translate_earth_to_alien(earth_word2);

  // Print the Alien word to the user
  printf("The Alien word is: %s\n", alien_word2);

  // Free the memory allocated for the Alien word
  free(alien_word2);

  return 0;
}