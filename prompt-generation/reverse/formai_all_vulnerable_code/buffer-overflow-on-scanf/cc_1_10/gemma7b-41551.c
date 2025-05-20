//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct Mail {
  char name[MAX];
  char email[MAX];
  char subject[MAX];
  char message[MAX];
  struct Mail* next;
} Mail;

void insert(Mail** head) {
  Mail* newNode = malloc(sizeof(Mail));
  printf("Enter name: ");
  scanf("%s", newNode->name);
  printf("Enter email: ");
  scanf("%s", newNode->email);
  printf("Enter subject: ");
  scanf("%s", newNode->subject);
  printf("Enter message: ");
  scanf("%s", newNode->message);

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
  newNode->next = NULL;
}

void search(Mail* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      printf("Name: %s\n", head->name);
      printf("Email: %s\n", head->email);
      printf("Subject: %s\n", head->subject);
      printf("Message: %s\n", head->message);
      return;
    }
    head = head->next;
  }
  printf("No mail found.\n");
}

int main() {
  Mail* head = NULL;
  char name[MAX];

  printf("Welcome to the future of mail management!\n");
  printf("Enter 'insert' to insert a new mail, 'search' to search for a mail, or 'quit' to quit: ");
  scanf("%s", name);

  if (strcmp(name, "insert") == 0) {
    insert(&head);
  } else if (strcmp(name, "search") == 0) {
    printf("Enter name: ");
    scanf("%s", name);
    search(head, name);
  } else if (strcmp(name, "quit") == 0) {
    exit(0);
  } else {
    printf("Invalid command.\n");
  }

  return 0;
}