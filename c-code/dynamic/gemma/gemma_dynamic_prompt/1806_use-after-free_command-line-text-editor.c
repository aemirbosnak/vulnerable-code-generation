#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = NULL;
  size_t size = 0;

  // Allocate memory for the buffer
  buffer = malloc(size);

  // Prompt the user to enter text
  printf("Enter text: ");
  getline(buffer, &size, stdin);

  // Free the memory allocated for the buffer
  free(buffer);

  // Use the freed memory, causing a use after free vulnerability
  printf("Your text: %s", buffer);

  return 0;
}
