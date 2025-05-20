#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = malloc(1024);
  int length = 0;

  // Read the entire request body into the buffer
  printf("Enter the request body: ");
  fgets(buffer, 1024, stdin);

  // Calculate the length of the request body
  length = strlen(buffer) + 1;

  // Print the request body
  printf("Request body: %s", buffer);

  // Free the memory allocated for the buffer
  free(buffer);

  return 0;
}
