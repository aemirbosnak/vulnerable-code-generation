#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  int index = 0;

  printf("Enter a command: ");
  scanf("%s", buffer);

  // Out-of-bounds read vulnerability
  index = atoi(buffer) + 10;
  if (index < 0) {
    index = 0;
  }
  buffer[index] = 'H';

  printf("Updated command: %s\n", buffer);

  return 0;
}
