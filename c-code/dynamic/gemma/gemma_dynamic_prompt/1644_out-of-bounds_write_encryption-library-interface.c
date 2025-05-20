#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char *buffer = NULL;
  size_t size = 0;

  // Allocate memory for the buffer
  buffer = malloc(size);

  // Out-of-bounds write
  buffer[size] = 'A';

  // Free the memory
  free(buffer);

  return 0;
}
