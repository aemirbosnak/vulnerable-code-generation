#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = malloc(10);
  char *ptr = buffer;

  // Write beyond the bounds of the allocated memory
  ptr[-1] = 'A';

  free(buffer);

  return 0;
}
