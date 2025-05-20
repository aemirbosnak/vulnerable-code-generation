#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10];
  int index = 0;

  // Overflow the buffer by writing beyond the allocated size
  buffer[index++] = 'a';
  buffer[index++] = 'b';
  buffer[index++] = 'c';
  buffer[index++] = 'd';
  buffer[index++] = 'e';

  // Attempt to read from the overflowing buffer
  printf("%c", buffer[index]);

  return 0;
}
