#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  FILE* log_file = fopen("log.txt", "r");
  char word[100];
  int word_count = 0;

  while (fscanf(log_file, "%s", word) != EOF) {
    word_count++;
  }

  printf("Word count: %d\n", word_count);

  return 0;
}
