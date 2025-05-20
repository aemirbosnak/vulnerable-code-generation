//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Declare the dictionary
char *dictionary[MAX_WORDS];
int dictionary_size = 0;

// Load the dictionary from a file
int load_dictionary(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
    // Remove the newline character
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary
    dictionary[dictionary_size++] = strdup(line);
  }

  fclose(fp);

  return 0;
}

// Check if a word is in the dictionary
int is_word_in_dictionary(char *word) {
  for (int i = 0; i < dictionary_size; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Print the misspelled words
void print_misspelled_words(char **words, int num_words) {
  for (int i = 0; i < num_words; i++) {
    if (!is_word_in_dictionary(words[i])) {
      printf("%s\n", words[i]);
    }
  }
}

// Free the memory allocated for the dictionary
void free_dictionary() {
  for (int i = 0; i < dictionary_size; i++) {
    free(dictionary[i]);
  }
}

int main(int argc, char **argv) {
  // Load the dictionary
  if (load_dictionary("dictionary.txt") != 0) {
    fprintf(stderr, "Error loading dictionary\n");
    return 1;
  }

  // Check the spelling of the words
  print_misspelled_words(argv + 1, argc - 1);

  // Free the memory allocated for the dictionary
  free_dictionary();

  return 0;
}