#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **messages = NULL;
  int size = 0;

  // Allocate memory for the message buffer
  messages = malloc(10 * sizeof(char *));

  // Insert a message into the buffer
  messages[size++] = "Hello, world!";

  // Dereference the pointer to the message
  printf("%s", messages[size - 1]);

  // Free the memory allocated for the message buffer
  free(messages);

  return 0;
}
