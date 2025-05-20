#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  FILE* file = fopen("words.txt", "r");
  char buffer[10];
  int word_count = 0;

  while (fscanf(file, "%s", buffer) != EOF) {
    word_count++;
  }

  printf("Word count: %d", word_count);

  fclose(file);

  return 0;
}
