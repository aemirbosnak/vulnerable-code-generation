#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  FILE* file = fopen("words.txt", "r");
  char word[1024];
  fscanf(file, "%s", word);
  printf("%s", word);
  fclose(file);
  return 0;
}
