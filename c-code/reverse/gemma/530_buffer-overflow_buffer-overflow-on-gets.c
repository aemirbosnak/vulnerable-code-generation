#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[255];
  gets(sentence);

  int words = 0;
  char *word = strtok(sentence, " ");

  while (word) {
    words++;
    word = strtok(NULL, " ");
  }

  printf("Number of words in the sentence: %d\n", words);

  return 0;
}
