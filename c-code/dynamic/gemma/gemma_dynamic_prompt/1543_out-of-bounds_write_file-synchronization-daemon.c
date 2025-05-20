#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buf = malloc(10);
  buf[0] = 'a';
  buf[1] = 'b';
  buf[2] = 'c';
  buf[3] = 'd';
  buf[4] = 'e';
  buf[5] = 'f';
  buf[6] = 'g';
  buf[7] = 'h';
  buf[8] = 'i';
  buf[9] = 'j';

  buf[10] = 'x'; // Out of bounds write

  free(buf);
  return 0;
}
