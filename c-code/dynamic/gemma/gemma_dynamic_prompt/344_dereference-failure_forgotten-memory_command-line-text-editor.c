#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buf = NULL;
  int size = 0;

  // Allocate memory for the buffer
  buf = malloc(size);

  // Attempt to dereference a null pointer
  *buf = 'a';

  // Free the memory
  free(buf);

  return 0;
}
