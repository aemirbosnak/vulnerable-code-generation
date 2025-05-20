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
  buffer = malloc(size);

  // Get the user input
  printf("Enter text: ");
  gets(buffer);

  // Overflow the buffer
  buffer[size - 1] = '\0';

  // Print the user input
  printf("Your text: %s", buffer);

  // Free the memory
  free(buffer);

  return 0;
}
