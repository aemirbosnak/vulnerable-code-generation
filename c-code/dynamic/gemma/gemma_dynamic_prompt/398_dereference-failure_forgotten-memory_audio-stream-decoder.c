#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  char* buffer = NULL;
  int size = 0;
  buffer = (char*)malloc(size);

  // Accessing memory beyond the allocated size
  buffer[size] = 0x5A;

  free(buffer);
  return 0;
}
