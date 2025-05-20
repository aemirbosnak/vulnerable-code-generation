//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
  char *word;
  int count;
} word_t;

int compare_words(const void *a, const void *b) {
  return strcmp(((word_t *)a)->word, ((word_t *)b)->word);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char word[MAX_WORD_LEN];
  word_t words[MAX_WORDS];
  int num_words = 0;

  while (fscanf(fp, "%s", word) != EOF) {
    if (strlen(word) > MAX_WORD_LEN) {
      continue;
    }

    int found = 0;
    for (int i = 0; i < num_words; i++) {
      if (strcmp(word, words[i].word) == 0) {
        words[i].count++;
        found = 1;
        break;
      }
    }

    if (!found) {
      words[num_words].word = strdup(word);
      words[num_words].count = 1;
      num_words++;
    }
  }

  fclose(fp);

  qsort(words, num_words, sizeof(word_t), compare_words);

  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i].word, words[i].count);
  }

  return EXIT_SUCCESS;
}