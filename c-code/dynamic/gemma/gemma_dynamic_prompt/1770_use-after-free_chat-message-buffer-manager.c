#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int main() {
  char **buffer = NULL;
  int size = 0;

  // Allocate memory for the buffer
  buffer = malloc(10 * sizeof(char *));
  if (buffer == NULL) {
    return 1;
  }

  // Increase the size of the buffer
  size = 10;
  buffer = realloc(buffer, size * sizeof(char *));
  if (buffer == NULL) {
    return 1;
  }

  // Free the memory for the buffer
  free(buffer);

  // Use the freed memory
  buffer[0] = 'H';

  return 0;
}
