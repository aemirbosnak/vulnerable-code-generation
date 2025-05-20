#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  // Allocate memory for the buffer
  buffer = malloc(size);

  // Get the data from the user, overflowing the buffer
  gets(buffer);

  // Free the memory allocated for the buffer
  free(buffer);

  return 0;
}
