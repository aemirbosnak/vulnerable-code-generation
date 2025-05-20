#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[16];
  gets(buffer);

  // Overflow the buffer and write arbitrary data
  buffer[15] = 'A';
  buffer[16] = 'B';
  buffer[17] = 'C';

  printf("The modified buffer is: %s\n", buffer);

  return 0;
}
