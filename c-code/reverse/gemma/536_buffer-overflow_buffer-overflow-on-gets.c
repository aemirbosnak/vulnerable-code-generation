#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1024];
  gets(sentence);

  char *word = strtok(sentence, " ");
  int word_count = 0;
  int word_frequency[1024] = {0};

  while (word) {
    word_frequency[word_count++] = word_count;
    word = strtok(NULL, " ");
  }

  printf("Word frequency:\n");
  for (int i = 0; i < word_count; i++) {
    printf("%s: %d\n", word, word_frequency[i]);
  }

  return 0;
}
