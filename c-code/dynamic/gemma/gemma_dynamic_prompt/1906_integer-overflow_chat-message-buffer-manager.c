#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int buffer_size = 10;
  int message_length = 0;
  char* buffer = malloc(buffer_size);

  // Overflow the buffer by allocating more memory than the buffer size
  message_length = buffer_size * 2;
  buffer = realloc(buffer, message_length);

  // Use the overflowed buffer
  buffer[message_length - 1] = 'A';

  free(buffer);
  return 0;
}
