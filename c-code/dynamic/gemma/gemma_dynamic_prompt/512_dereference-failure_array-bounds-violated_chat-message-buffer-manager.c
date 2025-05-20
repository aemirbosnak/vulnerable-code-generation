#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char **buffer = NULL;
  int size = 0;

  // Allocate memory for the buffer
  buffer = malloc(10 * sizeof(char *));

  // Create an array bounds violation
  buffer[size] = 'A';

  // Free the memory
  free(buffer);

  return 0;
}
