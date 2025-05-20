#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  gets(buffer);

  // Overflow the buffer
  buffer[1024 - 1] = 'A';

  printf("You have entered: %s", buffer);

  return 0;
}
