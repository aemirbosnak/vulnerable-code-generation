//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: standalone
// Alien Language Translator
// by [your name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien alphabet
char alien_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
char human_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Define the translation table
char translation_table[26][26];

// Initialize the translation table
void init_translation_table() {
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      translation_table[i][j] = human_alphabet[(i + j) % 26];
    }
  }
}

// Translate an alien word to a human word
char *translate_word(char *alien_word) {
  char *human_word = malloc(strlen(alien_word) + 1);
  for (int i = 0; i < strlen(alien_word); i++) {
    char alien_char = alien_word[i];
    int alien_char_index = strchr(alien_alphabet, alien_char) - alien_alphabet;
    human_word[i] = translation_table[alien_char_index][0];
  }
  human_word[strlen(alien_word)] = '\0';
  return human_word;
}

// Main function
int main() {
  // Initialize the translation table
  init_translation_table();

  // Get the alien word from the user
  char alien_word[100];
  printf("Enter the alien word: ");
  scanf("%s", alien_word);

  // Translate the alien word to a human word
  char *human_word = translate_word(alien_word);

  // Print the human word
  printf("The human word is: %s\n", human_word);

  // Free the memory allocated for the human word
  free(human_word);

  return 0;
}