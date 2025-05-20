#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1024];
  gets(sentence);

  int word_count = 0;
  char *word = strtok(sentence, " ");

  while (word) {
    word_count++;
    word = strtok(NULL, " ");
  }

  printf("Word frequency: %d\n", word_count);

  return 0;
}
