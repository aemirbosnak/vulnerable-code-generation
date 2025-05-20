//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: automated
// C Spell Checking Example Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 1000

typedef struct {
  char word[MAX_WORD_LEN];
  int count;
} Word;

void print_usage(char *prog_name) {
  printf("Usage: %s [filename]\n", prog_name);
}

int load_words(char *filename, Word words[MAX_WORDS]) {
  FILE *fp;
  char line[MAX_WORD_LEN];
  int i, count = 0;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: Could not open file %s\n", filename);
    return -1;
  }

  while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
    if (count >= MAX_WORDS) {
      printf("Error: Too many words in file %s\n", filename);
      fclose(fp);
      return -1;
    }

    for (i = 0; i < MAX_WORD_LEN; i++) {
      if (line[i] == '\0' || line[i] == '\n') {
        break;
      }
      words[count].word[i] = tolower(line[i]);
    }

    words[count].count = 1;
    count++;
  }

  fclose(fp);
  return count;
}

int compare_words(const void *a, const void *b) {
  Word *w1 = (Word *)a;
  Word *w2 = (Word *)b;
  return strcmp(w1->word, w2->word);
}

void print_words(Word words[MAX_WORDS], int count) {
  int i;
  for (i = 0; i < count; i++) {
    printf("%s\n", words[i].word);
  }
}

int main(int argc, char *argv[]) {
  char filename[MAX_WORD_LEN];
  Word words[MAX_WORDS];
  int count;

  if (argc != 2) {
    print_usage(argv[0]);
    return 1;
  }

  strcpy(filename, argv[1]);
  count = load_words(filename, words);
  if (count < 0) {
    return 1;
  }

  qsort(words, count, sizeof(Word), compare_words);
  print_words(words, count);

  return 0;
}