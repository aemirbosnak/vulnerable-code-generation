#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];

  printf("Enter HTTP request: ");
  scanf("%s", buffer);

  // Overflow the buffer
  buffer[1024 - 1] = 'A';
  buffer[1024 - 2] = 'A';
  buffer[1024 - 3] = 'A';

  printf("Parsed request: %s", buffer);

  return 0;
}
