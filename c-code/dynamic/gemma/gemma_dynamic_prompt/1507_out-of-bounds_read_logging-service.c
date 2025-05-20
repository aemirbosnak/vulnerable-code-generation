#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = malloc(10);
  FILE *file = fopen("log.txt", "w");

  // Out-of-bounds read vulnerability
  buffer[10] = 'A';

  fprintf(file, "%s", buffer);
  fclose(file);
  free(buffer);

  return 0;
}
