#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  buffer[0] = 'a';
  buffer[1] = 'b';
  buffer[2] = 'c';
  buffer[3] = 'd';
  buffer[4] = 'e';
  buffer[5] = 'f';
  buffer[6] = 'g';
  buffer[7] = 'h';
  buffer[8] = 'i';
  buffer[9] = 'j';
  buffer[10] = '\0';

  printf("%s\n", buffer);

  return 0;
}
