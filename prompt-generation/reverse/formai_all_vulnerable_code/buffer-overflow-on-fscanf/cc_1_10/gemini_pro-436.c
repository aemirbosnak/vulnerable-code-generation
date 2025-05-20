//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// Define the dictionary
char *dictionary[MAX_WORDS];
int dictionary_size = 0;

// Load the dictionary from a file
void load_dictionary(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  char word[MAX_WORD_LENGTH];
  while (fscanf(fp, "%s", word) != EOF) {
    // Add the word to the dictionary
    dictionary[dictionary_size++] = strdup(word);
  }

  fclose(fp);
}

// Check if a word is in the dictionary
int is_in_dictionary(char *word) {
  for (int i = 0; i < dictionary_size; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Spell check a document
void spell_check(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening document file");
    exit(EXIT_FAILURE);
  }

  char word[MAX_WORD_LENGTH];
  while (fscanf(fp, "%s", word) != EOF) {
    // Remove punctuation from the word
    for (int i = 0; i < strlen(word); i++) {
      if (!isalpha(word[i])) {
        word[i] = '\0';
        break;
      }
    }

    // Check if the word is in the dictionary
    if (!is_in_dictionary(word)) {
      printf("%s is not in the dictionary\n", word);
    }
  }

  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <dictionary file> <document file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Load the dictionary
  load_dictionary(argv[1]);

  // Spell check the document
  spell_check(argv[2]);

  return 0;
}