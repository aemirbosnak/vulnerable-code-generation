#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = NULL;
  size_t size = 0;

  // Allocate memory for the buffer
  buffer = malloc(size);

  // Write out of bounds
  buffer[size] = 'a';

  // Free the memory
  free(buffer);

  return 0;
}
