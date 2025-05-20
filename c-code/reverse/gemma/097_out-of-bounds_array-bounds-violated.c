#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filename[256];
  printf("Enter file name: ");
  scanf("%s", filename);

  FILE* file = fopen(filename, "r");
  if (!file) {
    return 1;
  }

  int word_count = 0;
  char word[256];
  while (fscanf(file, "%s", word) != EOF) {
    word_count++;
  }

  fclose(file);

  int word_frequency[word_count];
  memset(word_frequency, 0, word_count * sizeof(int));

  file = fopen(filename, "r");
  if (!file) {
    return 1;
  }

  while (fscanf(file, "%s", word) != EOF) {
    word_frequency[strcmp(word, "")]++;
  }

  fclose(file);

  printf("Word frequencies:\n");
  for (int i = 0; i < word_count; i++) {
    if (word_frequency[i] > 0) {
      printf("%s: %d\n", word_frequency[i], word_frequency[i]);
    }
  }

  return 0;
}
