#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 255

int main() {
  FILE* file = fopen("text.txt", "r");
  char word[MAX_WORD_LENGTH];
  int word_length = 0;
  int word_frequency[MAX_WORD_LENGTH] = {0};

  fscanf(file, "%s", word);
  while (!feof(file)) {
    word_length = strlen(word);
    if (word_length > MAX_WORD_LENGTH) {
      word_length = MAX_WORD_LENGTH;
    }
    word_frequency[word_length]++;
    fscanf(file, "%s", word);
  }

  fclose(file);

  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    if (word_frequency[i] > 0) {
      printf("%d: %d\n", i, word_frequency[i]);
    }
  }

  return 0;
}
