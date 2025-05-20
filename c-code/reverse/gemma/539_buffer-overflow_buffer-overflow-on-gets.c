#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1024];
  printf("Enter a sentence: ");
  fgets(sentence, 1024, stdin);

  char *word = strtok(sentence, " ");
  int word_count = 0;
  while (word) {
    word_count++;
    word = strtok(NULL, " ");
  }

  printf("Number of words in the sentence: %d\n", word_count);

  return 0;
}
