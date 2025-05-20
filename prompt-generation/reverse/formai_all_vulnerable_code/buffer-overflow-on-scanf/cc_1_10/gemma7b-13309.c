//Gemma-7B DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_MESSAGES 10

typedef struct Message {
  char sender[50];
  char recipient[50];
  char subject[50];
  char message[1000];
} Message;

Message messages[MAX_MESSAGES];

void display_messages() {
  for (int i = 0; i < MAX_MESSAGES; i++) {
    if (messages[i].sender[0] != '\0') {
      printf("From: %s\n", messages[i].sender);
      printf("To: %s\n", messages[i].recipient);
      printf("Subject: %s\n", messages[i].subject);
      printf("Message: %s\n", messages[i].message);
      printf("\n");
    }
  }
}

void add_message() {
  Message new_message;
  printf("Enter your name: ");
  scanf("%s", new_message.sender);

  printf("Enter the recipient's name: ");
  scanf("%s", new_message.recipient);

  printf("Enter the subject: ");
  scanf("%s", new_message.subject);

  printf("Enter your message: ");
  scanf("%s", new_message.message);

  messages[0] = new_message;
  display_messages();
}

int main() {
  int choice;

  display_messages();

  printf("Enter 1 to add a new message, 2 to exit: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      add_message();
      break;
    case 2:
      exit(0);
  }

  return 0;
}