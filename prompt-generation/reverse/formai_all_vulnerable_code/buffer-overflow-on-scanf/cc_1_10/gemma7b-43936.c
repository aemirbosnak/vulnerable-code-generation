//Gemma-7B DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

struct Password {
  char *name;
  char *password;
  struct Password *next;
};

void add_password(struct Password **head) {
  struct Password *new_password = malloc(sizeof(struct Password));
  new_password->name = malloc(PASSWORD_LENGTH);
  new_password->password = malloc(PASSWORD_LENGTH);
  new_password->next = NULL;

  printf("Enter a name for the password: ");
  scanf("%s", new_password->name);

  printf("Enter a password: ");
  scanf("%s", new_password->password);

  if (*head == NULL) {
    *head = new_password;
  } else {
    (*head)->next = new_password;
  }
}

void list_passwords(struct Password *head) {
  while (head) {
    printf("Name: %s, Password: %s\n", head->name, head->password);
    head = head->next;
  }
}

int main() {
  struct Password *passwords = NULL;

  while (1) {
    printf("Enter 'add', 'list', or 'exit': ");
    char command[20];
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
      add_password(&passwords);
    } else if (strcmp(command, "list") == 0) {
      list_passwords(passwords);
    } else if (strcmp(command, "exit") == 0) {
      exit(0);
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}