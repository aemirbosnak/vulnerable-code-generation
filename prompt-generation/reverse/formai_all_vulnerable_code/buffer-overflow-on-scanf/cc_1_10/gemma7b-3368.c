//Gemma-7B DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

typedef struct Message {
  char sender[255];
  char recipient[255];
  char subject[255];
  char message[MAX_MSG_SIZE];
} Message;

Message messages[100];

void print_menu() {
  printf("\nWelcome to the Matrix, my dear user. Please select an option:\n");
  printf("1. New Message\n");
  printf("2. Read Messages\n");
  printf("3. Search Messages\n");
  printf("4. Exit\n");
}

void handle_new_message() {
  Message new_message;

  printf("Enter the sender's name: ");
  scanf("%s", new_message.sender);

  printf("Enter the recipient's name: ");
  scanf("%s", new_message.recipient);

  printf("Enter the subject: ");
  scanf("%s", new_message.subject);

  printf("Enter the message: ");
  scanf("%s", new_message.message);

  messages[0] = new_message;
}

void handle_read_messages() {
  int i = 0;

  for (i = 0; messages[i].sender[0] != '\0'; i++) {
    printf("From: %s\n", messages[i].sender);
    printf("To: %s\n", messages[i].recipient);
    printf("Subject: %s\n", messages[i].subject);
    printf("Message: %s\n", messages[i].message);

    printf("\n");
  }
}

void handle_search_messages() {
  char search_term[255];

  printf("Enter the search term: ");
  scanf("%s", search_term);

  int i = 0;

  for (i = 0; messages[i].sender[0] != '\0'; i++) {
    if (strstr(messages[i].sender, search_term) ||
        strstr(messages[i].recipient, search_term) ||
        strstr(messages[i].subject, search_term) ||
        strstr(messages[i].message, search_term)) {
      printf("From: %s\n", messages[i].sender);
      printf("To: %s\n", messages[i].recipient);
      printf("Subject: %s\n", messages[i].subject);
      printf("Message: %s\n", messages[i].message);

      printf("\n");
    }
  }
}

int main() {
  int choice;

  print_menu();
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      handle_new_message();
      break;
    case 2:
      handle_read_messages();
      break;
    case 3:
      handle_search_messages();
      break;
    case 4:
      exit(0);
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}