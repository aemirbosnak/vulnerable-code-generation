#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  int message_size = 1000000; // Large number to demonstrate overflow
  char *message_buffer = (char *)malloc(message_size);

  // Fill the buffer with data
  memset(message_buffer, 'a', message_size);

  // Overflow the buffer by adding one more character
  message_buffer[message_size - 1] = 'b';

  // Print the buffer content
  printf("%s", message_buffer);

  free(message_buffer);
  return 0;
}
