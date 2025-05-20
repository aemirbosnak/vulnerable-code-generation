#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  int buffer_size = 10;
  char *buffer = (char *)malloc(buffer_size);

  int message_length = 0;
  char message[1024] = "";

  printf("Enter your message: ");
  fgets(message, 1024, stdin);

  // Overflow the buffer size
  message_length = strlen(message) + 1;
  if (message_length > buffer_size) {
    message_length = buffer_size;
  }

  // Copy the message into the buffer
  memcpy(buffer, message, message_length);

  // Print the message
  printf("Your message: %s\n", buffer);

  free(buffer);
  return 0;
}
