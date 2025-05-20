#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  // Allocate memory for the buffer
  buffer = malloc(size);

  // Read the input from the user
  char input[1024];
  printf("Enter text: ");
  fgets(input, 1024, stdin);

  // Write the input to the buffer
  int len = strlen(input) + 1;
  buffer = realloc(buffer, len);
  memcpy(buffer, input, len);

  // Out-of-bounds write
  buffer[len - 1] = 'A';

  // Print the edited text
  printf("Edited text: %s\n", buffer);

  // Free the memory
  free(buffer);

  return 0;
}
