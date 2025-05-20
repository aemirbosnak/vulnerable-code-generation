#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int message_length = 0;
  int buffer_size = 10;
  char *message_buffer = malloc(buffer_size);

  printf("Enter message length: ");
  scanf("%d", &message_length);

  if (message_length > buffer_size) {
    printf("Error: message length exceeds buffer size.\n");
  } else {
    message_length = message_length * 2; // Exploit overflow
    message_buffer = realloc(message_buffer, message_length);

    printf("Enter your message: ");
    scanf("%s", message_buffer);

    printf("Your message: %s\n", message_buffer);
  }

  free(message_buffer);
  return 0;
}
