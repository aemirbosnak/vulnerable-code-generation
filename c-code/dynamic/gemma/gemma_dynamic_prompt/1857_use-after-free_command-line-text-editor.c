#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  size_t size = 0;
  char key;

  // Allocate memory for the buffer
  buffer = malloc(size);

  // Read the first character
  key = getchar();

  // Loop until the user enters a newline or Ctrl-D
  while (key != '\n' && key != '\x1D') {
    // Expand the buffer if necessary
    if (size == 0) {
      size = 10;
      buffer = realloc(buffer, size);
    }

    // Add the character to the buffer
    buffer = realloc(buffer, size);
    buffer[size - 1] = key;
    size++;

    // Read the next character
    key = getchar();
  }

  // Print the buffer
  printf("%s", buffer);

  // Free the memory
  free(buffer);

  return 0;
}
