//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100000

struct word_freq {
  char word[MAX_WORD_LENGTH];
  int freq;
};

int compare_word_freq(const void *a, const void *b) {
  const struct word_freq *w1 = a;
  const struct word_freq *w2 = b;

  return w2->freq - w1->freq;
}

void print_word_freq(struct word_freq *wf, int num_words) {
  printf("Word Frequency:\n");
  for (int i = 0; i < num_words; i++) {
    printf("%s\t%d\n", wf[i].word, wf[i].freq);
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: word_freq <filename>\n");
    exit(1);
  }

  char *filename = argv[1];

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file: %s\n", filename);
    exit(1);
  }

  char word[MAX_WORD_LENGTH];
  int num_words = 0;
  struct word_freq word_freqs[MAX_WORDS];

  while (fscanf(fp, "%s", word) != EOF) {
    if (strlen(word) > MAX_WORD_LENGTH) {
      printf("Error: word too long\n");
      continue;
    }

    for (int i = 0; i < strlen(word); i++) {
      word[i] = tolower(word[i]);
    }

    int found = 0;
    for (int i = 0; i < num_words; i++) {
      if (strcmp(word, word_freqs[i].word) == 0) {
        word_freqs[i].freq++;
        found = 1;
        break;
      }
    }

    if (!found) {
      if (num_words == MAX_WORDS) {
        printf("Error: too many words\n");
        break;
      }

      strcpy(word_freqs[num_words].word, word);
      word_freqs[num_words].freq = 1;
      num_words++;
    }
  }

  fclose(fp);

  qsort(word_freqs, num_words, sizeof(struct word_freq), compare_word_freq);

  print_word_freq(word_freqs, num_words);

  return 0;
}