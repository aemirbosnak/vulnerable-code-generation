//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Declare the dictionary
char *dictionary[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

// Get the next word from the input
char *get_next_word(FILE *fp) {
  char *word = malloc(MAX_WORD_LENGTH);
  fscanf(fp, "%s", word);
  return word;
}

// Check if a word is in the dictionary
int is_in_dictionary(char *word) {
  for (int i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// Print the misspelled words
void print_misspelled_words(FILE *fp) {
  char *word;
  while ((word = get_next_word(fp)) != NULL) {
    if (!is_in_dictionary(word)) {
      printf("%s\n", word);
    }
    free(word);
  }
}

// Main function
int main(int argc, char **argv) {
  // Check if the user provided a filename
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Open the file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Print the misspelled words
  print_misspelled_words(fp);

  // Close the file
  fclose(fp);

  return 0;
}