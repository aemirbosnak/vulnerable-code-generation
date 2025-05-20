//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000

typedef struct {
  char *word;
  int count;
} WordEntry;

WordEntry dictionary[MAX_WORDS];
int num_words = 0;

void init_dictionary() {
  FILE *fp = fopen("dictionary.txt", "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  char line[100];
  while (fgets(line, sizeof(line), fp)) {
    // Remove newline character
    line[strlen(line) - 1] = '\0';

    // Allocate memory for the word
    char *word = malloc(strlen(line) + 1);
    if (word == NULL) {
      perror("Error allocating memory for word");
      exit(EXIT_FAILURE);
    }

    // Copy the word into the dictionary
    strcpy(word, line);

    // Add the word to the dictionary
    dictionary[num_words].word = word;
    dictionary[num_words].count = 0;
    num_words++;
  }

  fclose(fp);
}

int compare_words(const void *a, const void *b) {
  WordEntry *wa = (WordEntry *)a;
  WordEntry *wb = (WordEntry *)b;
  return strcmp(wa->word, wb->word);
}

void spellcheck(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  char word[100];
  while (fscanf(fp, "%s", word) != EOF) {
    // Convert the word to lowercase
    for (int i = 0; word[i] != '\0'; i++) {
      word[i] = tolower(word[i]);
    }

    // Search for the word in the dictionary
    WordEntry *result = bsearch(word, dictionary, num_words, sizeof(WordEntry), compare_words);

    // If the word is not found in the dictionary, print it
    if (result == NULL) {
      printf("%s\n", word);
    }
  }

  fclose(fp);
}

int main() {
  init_dictionary();
  spellcheck("input.txt");
  return 0;
}