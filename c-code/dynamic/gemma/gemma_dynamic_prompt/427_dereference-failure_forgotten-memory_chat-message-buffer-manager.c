#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char **message_buffer = NULL;
int message_count = 0;

void add_message(char *message) {
  message_buffer = realloc(message_buffer, (message_count + 1) * sizeof(char *));
  message_buffer[message_count] = strdup(message);
  message_count++;
}

int main() {
  add_message("Hello, world!");
  add_message("This is a message");
  add_message("The buffer is full!");

  // This will crash
  add_message("This message will cause a dereference failure");

  return 0;
}
