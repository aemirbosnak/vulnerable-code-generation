#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr = NULL;
  int index = 0;

  ptr = malloc(10);
  if (ptr == NULL) {
    return 1;
  }

  // Out-of-bounds read vulnerability
  ptr[index] = 'A';

  free(ptr);

  return 0;
}
