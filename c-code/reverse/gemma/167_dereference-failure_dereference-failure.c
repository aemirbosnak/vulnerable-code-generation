#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

int main() {
  FILE *fp;
  char **words = NULL;
  int word_count = 0;
  int word_length = 0;
  char word[MAX_WORD_LENGTH];

  fp = fopen("text.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  words = malloc(MAX_WORDS * sizeof(char *));
  if (words == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return 1;
  }

  while (fscanf(fp, "%s", word) != EOF) {
    word_length = strlen(word);
    if (word_length > MAX_WORD_LENGTH) {
      word_length = MAX_WORD_LENGTH;
    }
    words[word_count] = malloc(word_length + 1);
    strcpy(words[word_count], word);
    word_count++;
  }

  fclose(fp);

  // Analyze word frequency
  // ...

  free(words);
  return 0;
}
