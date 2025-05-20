#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  FILE* file = fopen("words.txt", "r");
  char buffer[1024];
  int word_count = 0;
  fscanf(file, "%[^\n]%*c", buffer);
  char* word = strtok(buffer, " ");
  while (word) {
    word_count++;
    word = strtok(NULL, " ");
  }
  printf("Word count: %d\n", word_count);
  fclose(file);
  return 0;
}
