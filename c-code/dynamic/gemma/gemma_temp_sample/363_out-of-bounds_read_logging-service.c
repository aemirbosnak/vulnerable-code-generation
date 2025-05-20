#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = malloc(10);
  strcpy(buffer, "Hello, world!");

  // Out-of-bounds read
  int offset = 100;
  char *read_data = buffer + offset;

  // Print the vulnerable data
  printf("%s\n", read_data);

  free(buffer);
  return 0;
}
