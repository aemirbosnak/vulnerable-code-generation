//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word.
#define MAX_WORD_LENGTH 20

// Declare the global variables.
char *dictionary[10000];
int dictionary_size = 0;

// Load the dictionary from a file.
void load_dictionary(char *filename) {
  // Open the file.
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  // Read each line from the file.
  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
    // Remove the newline character from the end of the line.
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary.
    dictionary[dictionary_size++] = strdup(line);
  }

  // Close the file.
  fclose(file);
}

// Check if a word is in the dictionary.
int is_in_dictionary(char *word) {
  // Convert the word to lowercase.
  for (int i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  // Search for the word in the dictionary.
  for (int i = 0; i < dictionary_size; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  // The word is not in the dictionary.
  return 0;
}

// Check the spelling of a word.
int check_spelling(char *word) {
  // If the word is in the dictionary, return 1.
  if (is_in_dictionary(word)) {
    return 1;
  }

  // If the word is not in the dictionary, return 0.
  return 0;
}

// Print the spelling errors in a sentence.
void print_spelling_errors(char *sentence) {
  // Tokenize the sentence into words.
  char *words[100];
  int word_count = 0;
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    words[word_count++] = token;
    token = strtok(NULL, " ");
  }

  // Check the spelling of each word.
  for (int i = 0; i < word_count; i++) {
    if (!check_spelling(words[i])) {
      printf("The word \"%s\" is misspelled.\n", words[i]);
    }
  }
}

// Main function.
int main(int argc, char **argv) {
  // Load the dictionary.
  load_dictionary("dictionary.txt");

  // Check the spelling of a sentence.
  print_spelling_errors("Hello world!");

  return 0;
}