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

  // Read the input from the user
  printf("Enter text: ");
  getline(buffer, size, stdin);

  // Print the text back to the user
  printf("Your text: %s", buffer);

  // Free the memory allocated for the buffer
  free(buffer);

  return 0;
}
