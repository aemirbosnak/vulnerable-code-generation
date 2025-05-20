#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  FILE* file = fopen("log.txt", "r");
  char buffer[10];
  int word_count = 0;

  fscanf(file, "%s", buffer);
  char* word = strtok(buffer, " ");

  while (word) {
    word_count++;
    word = strtok(NULL, " ");
  }

  fclose(file);

  printf("Word count: %d", word_count);

  return 0;
}
