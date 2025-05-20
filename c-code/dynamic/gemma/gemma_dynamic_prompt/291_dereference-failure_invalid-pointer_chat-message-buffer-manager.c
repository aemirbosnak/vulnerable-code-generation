#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char **message_buffer = NULL;
int message_size = 0;

void add_message(char *message) {
  message_size++;
  message_buffer = realloc(message_buffer, message_size * sizeof(char *));
  message_buffer[message_size - 1] = message;
}

int main() {
  char *message = "This is a message";
  add_message(message);

  // This line will cause a dereference failure
  char **invalid_pointer = message_buffer[message_size];

  return 0;
}
