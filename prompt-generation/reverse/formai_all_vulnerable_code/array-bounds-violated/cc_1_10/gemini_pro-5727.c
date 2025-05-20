//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Array of valid words
char* valid_words[MAX_WORDS];
int num_valid_words;

// Load the valid words from a file
void load_valid_words(char* filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
    // Remove the newline character from the end of the word
    line[strlen(line) - 1] = '\0';

    // Add the word to the array of valid words
    valid_words[num_valid_words++] = strdup(line);
  }

  fclose(fp);
}

// Check if a word is valid
int is_valid_word(char* word) {
  for (int i = 0; i < num_valid_words; i++) {
    if (strcmp(word, valid_words[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Spell check a document
void spell_check(char* filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
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

    // Check if the word is valid
    if (!is_valid_word(word)) {
      printf("%s is not a valid word.\n", word);
    }
  }

  fclose(fp);
}

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Usage: %s <dictionary> <document>\n", argv[0]);
    return 1;
  }

  // Load the valid words from the dictionary
  load_valid_words(argv[1]);

  // Spell check the document
  spell_check(argv[2]);

  return 0;
}