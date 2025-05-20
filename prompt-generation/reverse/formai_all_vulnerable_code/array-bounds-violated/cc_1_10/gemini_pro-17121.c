//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct {
  char word[MAX_WORD_LEN];
  int count;
} Word;

int compare_words(const void *a, const void *b) {
  return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <dictionary file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *dict = fopen(argv[1], "r");
  if (dict == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  Word words[MAX_WORDS];
  int num_words = 0;

  char line[MAX_WORD_LEN];
  while (fgets(line, MAX_WORD_LEN, dict)) {
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }

    if (num_words < MAX_WORDS) {
      strcpy(words[num_words].word, line);
      words[num_words].count = 0;
      num_words++;
    }
  }

  fclose(dict);

  qsort(words, num_words, sizeof(Word), compare_words);

  char input[MAX_WORD_LEN];
  while (scanf("%s", input) != EOF) {
    int found = 0;

    for (int i = 0; i < num_words; i++) {
      if (strcmp(input, words[i].word) == 0) {
        found = 1;
        words[i].count++;
        break;
      }
    }

    if (!found) {
      printf("%s: not found\n", input);
    }
  }

  for (int i = 0; i < num_words; i++) {
    if (words[i].count > 0) {
      printf("%s: %d\n", words[i].word, words[i].count);
    }
  }

  return EXIT_SUCCESS;
}