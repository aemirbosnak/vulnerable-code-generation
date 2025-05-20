//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_WORDS 10000

// Define the maximum length of a line in the input text
#define MAX_LINE_LENGTH 1000

// Define the maximum number of lines in the input text
#define MAX_LINES 1000

// Define the dictionary of words
char *dictionary[MAX_DICTIONARY_WORDS];

// Define the number of words in the dictionary
int num_words = 0;

// Define the input text
char *text[MAX_LINES];

// Define the number of lines in the input text
int num_lines = 0;

// Load the dictionary from a file
void load_dictionary(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
    // Remove the newline character from the end of the line
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary
    dictionary[num_words++] = strdup(line);
  }

  fclose(fp);
}

// Load the input text from a file
void load_text(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening input text file");
    exit(EXIT_FAILURE);
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    // Remove the newline character from the end of the line
    line[strlen(line) - 1] = '\0';

    // Add the line to the input text
    text[num_lines++] = strdup(line);
  }

  fclose(fp);
}

// Check the spelling of the words in the input text
void check_spelling() {
  for (int i = 0; i < num_lines; i++) {
    // Get the next line of input text
    char *line = text[i];

    // Tokenize the line into words
    char *word = strtok(line, " ");
    while (word != NULL) {
      // Convert the word to lowercase
      char *lowercase_word = strdup(word);
      for (int j = 0; j < strlen(lowercase_word); j++) {
        lowercase_word[j] = tolower(lowercase_word[j]);
      }

      // Check if the word is in the dictionary
      int found = 0;
      for (int k = 0; k < num_words; k++) {
        if (strcmp(lowercase_word, dictionary[k]) == 0) {
          found = 1;
          break;
        }
      }

      // If the word is not in the dictionary, print an error message
      if (!found) {
        printf("Error: The word '%s' is not in the dictionary.\n", word);
      }

      // Free the memory allocated for the lowercase word
      free(lowercase_word);

      // Get the next word
      word = strtok(NULL, " ");
    }
  }
}

// Free the memory allocated for the dictionary and the input text
void cleanup() {
  for (int i = 0; i < num_words; i++) {
    free(dictionary[i]);
  }

  for (int i = 0; i < num_lines; i++) {
    free(text[i]);
  }
}

// Main function
int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s dictionary_file input_text_file\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Load the dictionary
  load_dictionary(argv[1]);

  // Load the input text
  load_text(argv[2]);

  // Check the spelling of the words in the input text
  check_spelling();

  // Free the memory allocated for the dictionary and the input text
  cleanup();

  return 0;
}