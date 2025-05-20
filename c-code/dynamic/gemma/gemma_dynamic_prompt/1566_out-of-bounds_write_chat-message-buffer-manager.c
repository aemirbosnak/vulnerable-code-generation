#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *buffer = (int *)malloc(10 * sizeof(int));
  buffer[0] = 10;
  buffer[1] = 20;
  buffer[2] = 30;
  buffer[3] = 40;
  buffer[4] = 50;

  // Out of bounds write
  buffer[-1] = 60;

  free(buffer);
  return 0;
}
