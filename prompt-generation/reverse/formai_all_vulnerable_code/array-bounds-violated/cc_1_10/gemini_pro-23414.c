//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_SIZE 1000

// Define the dictionary
char* dictionary[MAX_DICTIONARY_SIZE];

// Define the number of words in the dictionary
int dictionary_size = 0;

// Load the dictionary from a file
void load_dictionary(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error: could not open file %s\n", filename);
    exit(1);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
    // Remove the newline character from the end of the word
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary
    dictionary[dictionary_size++] = strdup(line);
  }

  fclose(file);
}

// Check if a word is in the dictionary
bool is_word_in_dictionary(char* word) {
  for (int i = 0; i < dictionary_size; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return true;
    }
  }

  return false;
}

// Check if a word is spelled correctly
bool is_word_spelled_correctly(char* word) {
  // Convert the word to lowercase
  for (int i = 0; word[i] != '\0'; i++) {
    word[i] = tolower(word[i]);
  }

  // Check if the word is in the dictionary
  return is_word_in_dictionary(word);
}

// Spell check a file
void spell_check_file(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error: could not open file %s\n", filename);
    exit(1);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
    // Remove the newline character from the end of the line
    line[strlen(line) - 1] = '\0';

    // Tokenize the line into words
    char* words[MAX_WORD_LENGTH];
    int num_words = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
      words[num_words++] = token;
      token = strtok(NULL, " ");
    }

    // Spell check each word
    for (int i = 0; i < num_words; i++) {
      if (!is_word_spelled_correctly(words[i])) {
        fprintf(stderr, "Error: the word %s is not spelled correctly\n", words[i]);
      }
    }
  }

  fclose(file);
}

int main(int argc, char** argv) {
  // Load the dictionary
  load_dictionary("dictionary.txt");

  // Spell check the file
  if (argc == 2) {
    spell_check_file(argv[1]);
  } else {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(1);
  }

  return 0;
}