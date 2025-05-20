#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int* buffer = NULL;
  int size = 1024;
  buffer = (int*) malloc(size);

  // Accessing a null pointer
  int value = buffer[0];

  free(buffer);
  return 0;
}
