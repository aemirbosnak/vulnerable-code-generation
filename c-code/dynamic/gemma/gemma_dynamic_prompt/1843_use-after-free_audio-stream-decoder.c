#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  // Allocate memory for the buffer
  buffer = malloc(1024);

  // Use the buffer after free
  free(buffer);
  buffer[0] = 'H';

  // Print the content of the buffer
  printf("%c", buffer[0]);

  return 0;
}
