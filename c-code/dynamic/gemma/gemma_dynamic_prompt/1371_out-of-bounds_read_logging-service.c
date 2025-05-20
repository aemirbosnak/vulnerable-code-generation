#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  int index = 0;

  // Read data from the buffer
  printf("Enter data: ");
  fgets(buffer, 10, stdin);

  // Out-of-bounds read
  index = 10;
  printf("Content of the buffer at index %d: %c", index, buffer[index]);

  return 0;
}
