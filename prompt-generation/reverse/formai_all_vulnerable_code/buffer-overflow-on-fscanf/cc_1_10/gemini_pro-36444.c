//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in the dictionary.
#define MAX_WORDS 10000

// Define the maximum length of a word in the dictionary.
#define MAX_WORD_LENGTH 32

// Declare the dictionary of words.
char* dictionary[MAX_WORDS];

// Declare the number of words in the dictionary.
int num_words = 0;

// Initialize the dictionary.
void init_dictionary(void) {
  // Read the dictionary from the file.
  FILE* fp = fopen("dictionary.txt", "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  // Read each word from the file.
  char word[MAX_WORD_LENGTH];
  while (fscanf(fp, "%s", word) != EOF) {
    // Add the word to the dictionary.
    dictionary[num_words++] = strdup(word);
  }

  // Close the file.
  fclose(fp);
}

// Check if a word is in the dictionary.
bool is_word(const char* word) {
  // Loop through the words in the dictionary.
  for (int i = 0; i < num_words; i++) {
    // Compare the word to the dictionary word.
    if (strcmp(word, dictionary[i]) == 0) {
      // The word is in the dictionary.
      return true;
    }
  }

  // The word is not in the dictionary.
  return false;
}

// Check the spelling of a word.
void check_spelling(const char* word) {
  // Check if the word is in the dictionary.
  if (is_word(word)) {
    // The word is spelled correctly.
    printf("%s is spelled correctly.\n", word);
  } else {
    // The word is spelled incorrectly.
    printf("%s is spelled incorrectly.\n", word);
  }
}

// Main function.
int main(void) {
  // Initialize the dictionary.
  init_dictionary();

  // Check the spelling of a word.
  check_spelling("hello");
  check_spelling("world");
  check_spelling("misspell");

  return EXIT_SUCCESS;
}