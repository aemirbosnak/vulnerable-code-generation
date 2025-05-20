#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **buffer = NULL;
  int size = 0;
  int i = 0;

  // Allocate memory for the buffer
  buffer = malloc(10 * sizeof(char *));

  // Create a loop to read messages
  while (1) {
    char message[100];

    // Read the message
    printf("Enter a message: ");
    scanf("%s", message);

    // Check if the message is too long
    if (strlen(message) > 100) {
      printf("Error: message too long.\n");
      continue;
    }

    // Allocate memory for the message
    buffer[i] = malloc(strlen(message) * sizeof(char));

    // Copy the message into the buffer
    strcpy(buffer[i], message);

    // Increment the index
    i++;

    // Check if the buffer is full
    if (i == size) {
      // Reallocate the buffer
      buffer = realloc(buffer, (size + 1) * 10 * sizeof(char *));
      size++;
    }
  }

  return 0;
}
