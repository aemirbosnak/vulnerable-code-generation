#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *log_message = "This is a log message";
  int log_message_length = strlen(log_message) + 1;
  char *buffer = malloc(log_message_length);
  memcpy(buffer, log_message, log_message_length);

  // Out-of-bounds read
  buffer[log_message_length] = 'A';

  printf("%s", buffer);
  free(buffer);

  return 0;
}
