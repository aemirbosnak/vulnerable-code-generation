#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *buffer = NULL;
  buffer = (int *)malloc(10 * sizeof(int));
  if (buffer == NULL) {
    return 1;
  }

  // This line contains a dereference failure vulnerability
  int value = buffer[10];

  free(buffer);
  return 0;
}
