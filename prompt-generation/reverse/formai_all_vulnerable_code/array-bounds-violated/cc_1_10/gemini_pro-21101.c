//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

char *dictionary[MAX_WORDS];
int dictionarySize = 0;

void loadDictionary(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening dictionary file: %s\n", filename);
    exit(1);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
    line[strlen(line) - 1] = '\0'; // Remove newline character
    dictionary[dictionarySize++] = strdup(line);
  }

  fclose(fp);
}

int isWordInDictionary(char *word) {
  for (int i = 0; i < dictionarySize; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

void checkSpelling(char *text) {
  char *token = strtok(text, " ");
  while (token != NULL) {
    if (!isWordInDictionary(token)) {
      printf("Misspelled word: %s\n", token);
    }
    token = strtok(NULL, " ");
  }
}

int main() {
  loadDictionary("dictionary.txt");

  char text[] = "The quick brown fox jumped over the lazy dog.";
  checkSpelling(text);

  return 0;
}