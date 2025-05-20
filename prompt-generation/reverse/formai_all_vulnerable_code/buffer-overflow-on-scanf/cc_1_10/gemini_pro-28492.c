//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 100

typedef struct {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
} subscriber;

typedef struct {
  subscriber subscribers[MAX_LIST_SIZE];
  int size;
} mailing_list;

void add_subscriber(mailing_list *list, subscriber *new_subscriber) {
  if (list->size == MAX_LIST_SIZE) {
    printf("Error: Mailing list is full.\n");
    return;
  }

  list->subscribers[list->size] = *new_subscriber;
  list->size++;
}

void remove_subscriber(mailing_list *list, char *name) {
  int i;

  for (i = 0; i < list->size; i++) {
    if (strcmp(list->subscribers[i].name, name) == 0) {
      break;
    }
  }

  if (i == list->size) {
    printf("Error: Subscriber not found.\n");
    return;
  }

  for (; i < list->size - 1; i++) {
    list->subscribers[i] = list->subscribers[i + 1];
  }

  list->size--;
}

void send_email(mailing_list *list, char *subject, char *body) {
  int i;

  for (i = 0; i < list->size; i++) {
    printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
    printf("\n");
  }
}

int main() {
  mailing_list list;
  subscriber new_subscriber;
  char command[100];
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  char subject[100];
  char body[1000];

  list.size = 0;

  while (1) {
    printf("> ");
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
      printf("Name: ");
      scanf("%s", name);
      printf("Email: ");
      scanf("%s", email);

      strcpy(new_subscriber.name, name);
      strcpy(new_subscriber.email, email);

      add_subscriber(&list, &new_subscriber);
    } else if (strcmp(command, "remove") == 0) {
      printf("Name: ");
      scanf("%s", name);

      remove_subscriber(&list, name);
    } else if (strcmp(command, "send") == 0) {
      printf("Subject: ");
      scanf("%s", subject);
      printf("Body: ");
      scanf("%s", body);

      send_email(&list, subject, body);
    } else if (strcmp(command, "quit") == 0) {
      break;
    } else {
      printf("Error: Unknown command.\n");
    }
  }

  return 0;
}