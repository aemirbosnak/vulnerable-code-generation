#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

typedef struct Message {
  char *message;
  struct Message *next;
} Message;

Message *message_manager(char *message) {
  Message *new_message = malloc(sizeof(Message));
  new_message->message = malloc(strlen(message) + 1);
  strcpy(new_message->message, message);
  new_message->next = NULL;

  return new_message;
}

void free_message(Message *message) {
  free(message->message);
  free(message);
}

int main() {
  Message *head = message_manager("Hello, world!");
  free_message(head);
  free_message(head); // Use after free vulnerability

  return 0;
}
