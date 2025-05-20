//Gemma-7B DATASET v1.0 Category: Email Client ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG_SIZE 1024

typedef struct Message {
  char *subject;
  char *from;
  char *to;
  char *body;
  struct Message *next;
} Message;

void sendMessage(Message *message) {
  // Send message to server
  printf("Sending message: Subject: %s, From: %s, To: %s, Body: %s\n", message->subject, message->from, message->to, message->body);
}

void addMessage(Message **messages) {
  // Allocate memory for new message
  Message *newMessage = malloc(sizeof(Message));

  // Get message details from user
  printf("Enter subject: ");
  newMessage->subject = malloc(MAX_MSG_SIZE);
  scanf("%s", newMessage->subject);

  printf("Enter from: ");
  newMessage->from = malloc(MAX_MSG_SIZE);
  scanf("%s", newMessage->from);

  printf("Enter to: ");
  newMessage->to = malloc(MAX_MSG_SIZE);
  scanf("%s", newMessage->to);

  printf("Enter body: ");
  newMessage->body = malloc(MAX_MSG_SIZE);
  scanf("%s", newMessage->body);

  // Add new message to the list
  newMessage->next = *messages;
  *messages = newMessage;
}

int main() {
  // Create a list of messages
  Message *messages = NULL;

  // Add some messages
  addMessage(&messages);
  addMessage(&messages);

  // Send messages
  sendMessage(messages);

  return 0;
}