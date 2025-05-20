#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *buffer = NULL;
  int size = 0;

  // Allocate memory for the buffer
  buffer = malloc(size);

  // Read data from the stream
  FILE *fp = fopen("stream.dat", "r");
  fread(buffer, size, 1, fp);

  // Out of bounds read
  buffer[-1] = 0xdeadbeef;

  // Free the memory
  free(buffer);

  return 0;
}
