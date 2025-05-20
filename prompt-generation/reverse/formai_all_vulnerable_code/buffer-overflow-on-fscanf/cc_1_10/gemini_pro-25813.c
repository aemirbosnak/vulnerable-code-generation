//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Declare the dictionary
char *dictionary[MAX_WORDS];

// Initialize the dictionary
void init_dictionary() {
  // Open the dictionary file
  FILE *dict_file = fopen("dictionary.txt", "r");
  if (dict_file == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  // Read the words from the file
  char word[MAX_WORD_LENGTH];
  int i = 0;
  while (fscanf(dict_file, "%s", word) != EOF) {
    // Convert the word to lowercase
    for (int j = 0; j < strlen(word); j++) {
      word[j] = tolower(word[j]);
    }

    // Add the word to the dictionary
    dictionary[i++] = strdup(word);
  }

  // Close the dictionary file
  fclose(dict_file);
}

// Check if a word is in the dictionary
int is_in_dictionary(char *word) {
  // Convert the word to lowercase
  for (int i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  // Search for the word in the dictionary
  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Spell check a word
void spell_check(char *word) {
  // Check if the word is in the dictionary
  if (is_in_dictionary(word)) {
    printf("%s is spelled correctly.\n", word);
  } else {
    printf("%s is misspelled.\n", word);
  }
}

// Get a word from the user
char *get_word() {
  // Allocate memory for the word
  char *word = malloc(MAX_WORD_LENGTH);
  if (word == NULL) {
    perror("Error allocating memory for word");
    exit(EXIT_FAILURE);
  }

  // Get the word from the user
  printf("Enter a word: ");
  scanf("%s", word);

  // Return the word
  return word;
}

// Main function
int main() {
  // Initialize the dictionary
  init_dictionary();

  // Get a word from the user
  char *word = get_word();

  // Spell check the word
  spell_check(word);

  // Free the memory allocated for the word
  free(word);

  return 0;
}