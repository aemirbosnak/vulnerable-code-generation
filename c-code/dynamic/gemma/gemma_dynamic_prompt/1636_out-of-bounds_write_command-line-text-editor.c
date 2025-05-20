#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  // Allocate memory for the buffer
  buffer = malloc(size);

  // Read data from the user
  printf("Enter text: ");
  getline(buffer, size, stdin);

  // Out-of-bounds write
  buffer[size] = '\0';

  // Print the edited text
  printf("Edited text: %s", buffer);

  // Free the memory
  free(buffer);

  return 0;
}
