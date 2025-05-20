#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* buffer = malloc(10);
  char* data = "This is a test string";

  // Out-of-bounds read
  buffer[10] = data[0];

  // Print the contents of the buffer
  printf("%s", buffer);

  free(buffer);
  return 0;
}
