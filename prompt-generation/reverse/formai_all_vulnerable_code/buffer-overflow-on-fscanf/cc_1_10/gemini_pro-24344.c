//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: standalone
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 100

typedef struct {
  char word[MAX_LENGTH];
  int count;
} Word;

int compare(const void *a, const void *b) {
  Word *word1 = (Word *)a;
  Word *word2 = (Word *)b;
  return strcmp(word1->word, word2->word);
}

int main() {
  Word words[MAX_WORDS];
  int word_count = 0;

  FILE *file = fopen("input.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  char buffer[MAX_LENGTH];
  while (fscanf(file, "%s", buffer) != EOF) {
    for (int i = 0; i < strlen(buffer); i++) {
      buffer[i] = tolower(buffer[i]);
    }
    int found = 0;
    for (int i = 0; i < word_count; i++) {
      if (strcmp(words[i].word, buffer) == 0) {
        words[i].count++;
        found = 1;
        break;
      }
    }
    if (!found) {
      strcpy(words[word_count].word, buffer);
      words[word_count].count = 1;
      word_count++;
    }
  }

  fclose(file);

  qsort(words, word_count, sizeof(Word), compare);

  for (int i = 0; i < word_count; i++) {
    printf("%s: %d\n", words[i].word, words[i].count);
  }

  return EXIT_SUCCESS;
}