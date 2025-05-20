//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Declare the dictionary.
char *dictionary[MAX_WORDS];

// Read the dictionary from a file.
void read_dictionary(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  char line[MAX_WORD_LENGTH];
  int i = 0;
  while (fgets(line, MAX_WORD_LENGTH, file)) {
    // Remove the newline character from the line.
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary.
    dictionary[i] = strdup(line);
    i++;
  }

  fclose(file);
}

// Check if a word is in the dictionary.
bool is_word_in_dictionary(char *word) {
  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return true;
    }
  }

  return false;
}

// Print the possible corrections for a misspelled word.
void print_corrections(char *word) {
  // Check if the word is in the dictionary.
  if (is_word_in_dictionary(word)) {
    printf("The word '%s' is spelled correctly.\n", word);
    return;
  }

  // Generate a list of possible corrections.
  char corrections[MAX_WORDS][MAX_WORD_LENGTH];
  int num_corrections = 0;

  // Check for one-letter errors.
  for (int i = 0; i < strlen(word); i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      if (c != word[i]) {
        char new_word[MAX_WORD_LENGTH];
        strcpy(new_word, word);
        new_word[i] = c;
        if (is_word_in_dictionary(new_word)) {
          strcpy(corrections[num_corrections], new_word);
          num_corrections++;
        }
      }
    }
  }

  // Check for two-letter errors.
  for (int i = 0; i < strlen(word) - 1; i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      for (char d = 'a'; d <= 'z'; d++) {
        if (c != word[i] && d != word[i+1]) {
          char new_word[MAX_WORD_LENGTH];
          strcpy(new_word, word);
          new_word[i] = c;
          new_word[i+1] = d;
          if (is_word_in_dictionary(new_word)) {
            strcpy(corrections[num_corrections], new_word);
            num_corrections++;
          }
        }
      }
    }
  }

  // Check for three-letter errors.
  for (int i = 0; i < strlen(word) - 2; i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      for (char d = 'a'; d <= 'z'; d++) {
        for (char e = 'a'; e <= 'z'; e++) {
          if (c != word[i] && d != word[i+1] && e != word[i+2]) {
            char new_word[MAX_WORD_LENGTH];
            strcpy(new_word, word);
            new_word[i] = c;
            new_word[i+1] = d;
            new_word[i+2] = e;
            if (is_word_in_dictionary(new_word)) {
              strcpy(corrections[num_corrections], new_word);
              num_corrections++;
            }
          }
        }
      }
    }
  }

  // Print the possible corrections.
  if (num_corrections == 0) {
    printf("No corrections found for the word '%s'.\n", word);
  } else {
    printf("Possible corrections for the word '%s':\n", word);
    for (int i = 0; i < num_corrections; i++) {
      printf("  %s\n", corrections[i]);
    }
  }
}

// Get a word from the user.
char *get_word() {
  char *word = malloc(MAX_WORD_LENGTH);
  printf("Enter a word: ");
  scanf("%s", word);
  return word;
}

// Main function.
int main() {
  // Read the dictionary from a file.
  read_dictionary("dictionary.txt");

  // Get a word from the user.
  char *word = get_word();

  // Check if the word is spelled correctly.
  if (is_word_in_dictionary(word)) {
    printf("The word '%s' is spelled correctly.\n", word);
  } else {
    // Print the possible corrections for the misspelled word.
    print_corrections(word);
  }

  // Free the memory allocated for the word.
  free(word);

  return 0;
}