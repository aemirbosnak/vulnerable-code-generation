#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
  char *word;
  int frequency;
} Word;

int compareWords(Word *a, Word *b) {
  return b->frequency - a->frequency;
}

int main() {
  FILE *fp;
  char text[10000];
  Word words[MAX_WORDS];
  int i = 0;
  int wordCount = 0;

  fp = fopen("text.txt", "r");
  if (fp == NULL) {
    return 1;
  }

  fscanf(fp, "%[^\n]", text);
  fclose(fp);

  char *word = strtok(text, " ");
  while (word) {
    int found = 0;
    for (int j = 0; j < wordCount; j++) {
      if (strcmp(word, words[j].word) == 0) {
        words[j].frequency++;
        found = 1;
      }
    }

    if (!found) {
      words[wordCount].word = strdup(word);
      words[wordCount].frequency = 1;
      wordCount++;
    }

    word = strtok(NULL, " ");
  }

  qsort(words, wordCount, sizeof(Word), compareWords);

  printf("Word frequencies:\n");
  for (int j = 0; j < wordCount; j++) {
    printf("%s: %d\n", words[j].word, words[j].frequency);
  }

  return 0;
}
