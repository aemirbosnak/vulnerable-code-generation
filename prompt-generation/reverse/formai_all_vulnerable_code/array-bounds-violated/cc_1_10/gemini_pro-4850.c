//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Declare the dictionary
char *dictionary[MAX_WORDS];
int num_words = 0;

// Load the dictionary from a file
void load_dictionary(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening dictionary file\n");
    exit(1);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
    // Remove the newline character from the line
    line[strlen(line) - 1] = '\0';

    // Add the word to the dictionary
    dictionary[num_words++] = strdup(line);
  }

  fclose(fp);
}

// Check if a word is in the dictionary
int is_in_dictionary(char *word) {
  for (int i = 0; i < num_words; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Spell check a text file
void spell_check(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening text file\n");
    exit(1);
  }

  char line[1000];
  while (fgets(line, 1000, fp) != NULL) {
    // Tokenize the line into words
    char *words[100];
    int num_words = 0;
    char *word = strtok(line, " ");
    while (word != NULL) {
      words[num_words++] = word;
      word = strtok(NULL, " ");
    }

    // Check each word for spelling errors
    for (int i = 0; i < num_words; i++) {
      if (!is_in_dictionary(words[i])) {
        printf("Spelling error: %s\n", words[i]);
      }
    }
  }

  fclose(fp);
}

int main() {
  // Load the dictionary
  load_dictionary("dictionary.txt");

  // Spell check a text file
  spell_check("text.txt");

  return 0;
}