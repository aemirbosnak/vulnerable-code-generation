#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *message_buffer = malloc(1024);
  message_buffer[1023] = 'A';
  printf("%s", message_buffer);
  free(message_buffer);
  return 0;
}
