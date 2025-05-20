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
  buffer = malloc(1024);

  // Get the message from the user
  char message[1024];
  printf("Enter a message: ");
  gets(message);

  // Overflow the buffer
  if (strlen(message) > size) {
    printf("Error: Buffer overflow!\n");
  } else {
    // Store the message in the buffer
    strcpy(buffer, message);

    // Print the message
    printf("Your message: %s\n", buffer);
  }

  // Free the memory
  free(buffer);

  return 0;
}
