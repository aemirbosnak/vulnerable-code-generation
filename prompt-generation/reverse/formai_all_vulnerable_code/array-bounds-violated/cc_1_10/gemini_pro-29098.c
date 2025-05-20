//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Create a hash table to store the dictionary
char *dictionary[10000];
int dictionary_size = 0;

// Load the dictionary from a file
void load_dictionary(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening dictionary file\n");
    exit(1);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
    // Remove the newline character from the line
    line[strlen(line) - 1] = '\0';

    // Convert the line to lowercase
    for (int i = 0; i < strlen(line); i++) {
      line[i] = tolower(line[i]);
    }

    // Add the line to the dictionary
    dictionary[dictionary_size] = strdup(line);
    dictionary_size++;
  }

  fclose(file);
}

// Check if a word is in the dictionary
int check_spelling(char *word) {
  // Convert the word to lowercase
  for (int i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  // Search for the word in the dictionary
  for (int i = 0; i < dictionary_size; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Get a word from the user
char *get_word() {
  char *word = malloc(MAX_WORD_LENGTH);
  if (word == NULL) {
    fprintf(stderr, "Error allocating memory for word\n");
    exit(1);
  }

  printf("Enter a word: ");
  scanf("%s", word);

  return word;
}

// Print a message indicating whether the word is spelled correctly
void print_result(char *word, int is_correct) {
  if (is_correct) {
    printf("%s is spelled correctly\n", word);
  } else {
    printf("%s is spelled incorrectly\n", word);
  }
}

// Main function
int main() {
  // Load the dictionary
  load_dictionary("dictionary.txt");

  // Get a word from the user
  char *word = get_word();

  // Check the spelling of the word
  int is_correct = check_spelling(word);

  // Print the result
  print_result(word, is_correct);

  // Free the memory allocated for the word
  free(word);

  return 0;
}