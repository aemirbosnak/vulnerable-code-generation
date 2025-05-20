#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **buffer = NULL;
  char message[1024];

  // Allocate memory for the buffer
  buffer = malloc(1024);

  // Attempt to dereference a null pointer
  *(buffer + 1024) = message;

  // Print the result of the dereference
  printf("Message: %s", message);

  return 0;
}
