#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *buffer = NULL;
  int size = 0;

  // Allocate memory dynamically
  buffer = (char *)malloc(size);

  // Get a large string to overflow the buffer
  char *string = "This is a very long string that will overflow the buffer";

  // Overflow the buffer
  gets(string);

  // Free the memory
  free(buffer);

  return 0;
}
