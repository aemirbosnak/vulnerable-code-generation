#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  FILE *file = fopen("test.txt", "r");
  fscanf(file, "%s", buffer);
  fclose(file);

  // Overflow the buffer
  buffer[1024 - 1] = 'a';

  file = fopen("test.txt", "w");
  fprintf(file, "%s", buffer);
  fclose(file);

  return 0;
}
