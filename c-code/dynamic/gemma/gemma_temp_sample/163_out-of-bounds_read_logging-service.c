#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *buffer = NULL;
  int index = 0;

  // Allocate memory for the buffer
  buffer = malloc(10);

  // Read data from the buffer, out of bounds
  buffer[index] = 'A';

  // Free the memory
  free(buffer);

  return 0;
}
