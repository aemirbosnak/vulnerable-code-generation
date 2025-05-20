//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 1000

typedef struct {
  char word[MAX_WORD_LENGTH];
  int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
  WordFrequency *wordA = (WordFrequency *) a;
  WordFrequency *wordB = (WordFrequency *) b;

  return strcmp(wordA->word, wordB->word);
}

int main() {
  FILE *file;
  char word[MAX_WORD_LENGTH];
  WordFrequency words[MAX_WORDS];
  int numWords = 0;
  int i;

  file = fopen("input.txt", "r");
  if (file == NULL) {
    printf("Error: could not open input file.\n");
    return 1;
  }

  while (fscanf(file, "%s", word)!= EOF) {
    for (i = 0; i < numWords; i++) {
      if (strcmp(words[i].word, word) == 0) {
        words[i].frequency++;
        break;
      }
    }

    if (i == numWords) {
      if (numWords >= MAX_WORDS) {
        printf("Error: too many unique words.\n");
        fclose(file);
        return 1;
      }

      strcpy(words[numWords].word, word);
      words[numWords].frequency = 1;
      numWords++;
    }
  }

  fclose(file);

  qsort(words, numWords, sizeof(WordFrequency), compareWords);

  printf("Word\tFrequency\n");
  for (i = 0; i < numWords; i++) {
    printf("%s\t%d\n", words[i].word, words[i].frequency);
  }

  return 0;
}