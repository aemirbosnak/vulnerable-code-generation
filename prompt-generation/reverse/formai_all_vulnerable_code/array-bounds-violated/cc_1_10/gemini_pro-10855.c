//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Create a dictionary of words
char* dictionary[MAX_WORDS];
int dictionary_size = 0;

// Load the dictionary from a file
void load_dictionary(char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
    // Remove the newline character from the word
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary
    dictionary[dictionary_size++] = strdup(line);
  }

  fclose(fp);
}

// Check if a word is in the dictionary
int is_word_in_dictionary(char* word) {
  for (int i = 0; i < dictionary_size; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Check the spelling of a word
int check_spelling(char* word) {
  // Convert the word to lowercase
  for (int i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  // Check if the word is in the dictionary
  if (is_word_in_dictionary(word)) {
    return 1;
  } else {
    return 0;
  }
}

// Get a word from the user
char* get_word() {
  char* word = malloc(MAX_WORD_LENGTH);
  if (word == NULL) {
    perror("Error allocating memory for word");
    exit(EXIT_FAILURE);
  }

  printf("Enter a word: ");
  scanf("%s", word);

  return word;
}

// Print the results of the spell check
void print_results(char* word, int is_correct) {
  if (is_correct) {
    printf("The word '%s' is spelled correctly.\n", word);
  } else {
    printf("The word '%s' is spelled incorrectly.\n", word);
  }
}

int main() {
  // Load the dictionary
  load_dictionary("dictionary.txt");

  // Get a word from the user
  char* word = get_word();

  // Check the spelling of the word
  int is_correct = check_spelling(word);

  // Print the results of the spell check
  print_results(word, is_correct);

  // Free the memory allocated for the word
  free(word);

  return 0;
}