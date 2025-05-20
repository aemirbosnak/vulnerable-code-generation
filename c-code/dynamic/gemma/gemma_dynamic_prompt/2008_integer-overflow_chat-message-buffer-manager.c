#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int buffer_size = 10;
  int message_size = 0;
  int message_length = 0;
  char *message_buffer = NULL;

  // Allocate memory for the message buffer
  message_buffer = malloc(buffer_size);

  // Loop until the user enters a message or exits
  while (1) {
    // Get the user's message
    char message[256];
    printf("Enter your message: ");
    scanf("%s", message);

    // Calculate the message length
    message_length = strlen(message);

    // Check if the message length exceeds the buffer size
    if (message_length > buffer_size - message_size) {
      // Integer overflow!
      message_size = buffer_size - 1;
      printf("Error: Message too long. Please try again.\n");
    } else {
      // Add the message to the buffer
      memcpy(message_buffer + message_size, message, message_length);
      message_size += message_length;

      // Display the message
      printf("Your message has been sent.\n");
    }

    // Check if the user wants to exit
    char exit_message[256];
    printf("Enter 'exit' to exit: ");
    scanf("%s", exit_message);

    if (strcmp(exit_message, "exit") == 0) {
      break;
    }
  }

  // Free the memory allocated for the message buffer
  free(message_buffer);

  return 0;
}
