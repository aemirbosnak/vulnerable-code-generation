//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
  char word[MAX_WORD_LEN];
  int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

int load_dictionary(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  while (fscanf(fp, "%s", dictionary[num_words].word) != EOF) {
    dictionary[num_words].count = 0;
    num_words++;
  }

  fclose(fp);

  return 0;
}

int check_spelling(const char *word) {
  int i;

  for (i = 0; i < num_words; i++) {
    if (strcmp(word, dictionary[i].word) == 0) {
      return 1;
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  int i;
  char line[1000];

  if (argc != 2) {
    printf("Usage: %s <dictionary file>\n", argv[0]);
    return 1;
  }

  if (load_dictionary(argv[1]) != 0) {
    printf("Error: Could not load dictionary.\n");
    return 1;
  }

  printf("Enter some text to check for spelling errors:\n");

  while (fgets(line, 1000, stdin) != NULL) {
    char *word;

    word = strtok(line, " ");
    while (word != NULL) {
      if (!check_spelling(word)) {
        printf("%s is not spelled correctly.\n", word);
      }
      word = strtok(NULL, " ");
    }
  }

  return 0;
}