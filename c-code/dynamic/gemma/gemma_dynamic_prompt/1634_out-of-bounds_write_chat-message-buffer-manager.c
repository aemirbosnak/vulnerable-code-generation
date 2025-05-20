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
  buffer = malloc(1024);

  // Get the message from the user
  char message[1024];
  printf("Enter your message: ");
  fgets(message, 1024, stdin);

  // Write the message to the buffer
  int len = strlen(message) + 1;
  if (len > size) {
    size = len;
  }
  memcpy(buffer, message, len);

  // Print the message
  printf("Your message: %s\n", buffer);

  // Free the memory
  free(buffer);

  return 0;
}
