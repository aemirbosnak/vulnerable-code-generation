//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
/* Ada Lovelace Spell Checker */

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

/* Types */
typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

/* Global Variables */
Word dictionary[MAX_WORDS];
int num_words;

/* Functions */
void load_dictionary(const char *filename);
int check_spelling(const char *word);
void print_misspellings(const char *filename);

/* Main Function */
int main(int argc, char **argv) {
  // Load the dictionary
  if (argc < 2) {
    fprintf(stderr, "Usage: %s dictionary.txt\n", argv[0]);
    return EXIT_FAILURE;
  }
  load_dictionary(argv[1]);

  // Check the spelling of words in the input file
  if (argc < 3) {
    fprintf(stderr, "Usage: %s dictionary.txt input.txt\n", argv[0]);
    return EXIT_FAILURE;
  }
  print_misspellings(argv[2]);

  return EXIT_SUCCESS;
}

/* Load the dictionary into memory */
void load_dictionary(const char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  // Read the words from the file
  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
    // Remove the newline character
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary
    strcpy(dictionary[num_words].word, line);
    dictionary[num_words].count = 0;
    num_words++;
  }

  // Close the file
  fclose(fp);
}

/* Check the spelling of a word */
int check_spelling(const char *word) {
  // Convert the word to lowercase
  char lower_word[MAX_WORD_LENGTH];
  strcpy(lower_word, word);
  for (int i = 0; i < strlen(lower_word); i++) {
    lower_word[i] = tolower(lower_word[i]);
  }

  // Search for the word in the dictionary
  for (int i = 0; i < num_words; i++) {
    if (strcmp(lower_word, dictionary[i].word) == 0) {
      return 1;  // Word found in the dictionary
    }
  }

  return 0;  // Word not found in the dictionary
}

/* Print the misspellings in the input file */
void print_misspellings(const char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  // Read the words from the file
  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
    // Remove the newline character
    line[strlen(line) - 1] = '\0';

    // Check the spelling of the word
    if (!check_spelling(line)) {
      fprintf(stdout, "%s\n", line);
    }
  }

  // Close the file
  fclose(fp);
}