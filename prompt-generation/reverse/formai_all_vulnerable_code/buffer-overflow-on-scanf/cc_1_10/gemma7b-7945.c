//Gemma-7B DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *password;
  struct Password *next;
} Password;

void insertPassword(Password **head) {
  Password *newPass = malloc(sizeof(Password));
  newPass->name = malloc(20);
  newPass->password = malloc(20);
  newPass->next = NULL;

  printf("Enter name: ");
  scanf("%s", newPass->name);

  printf("Enter password: ");
  scanf("%s", newPass->password);

  if (*head == NULL) {
    *head = newPass;
  } else {
    (*head)->next = newPass;
  }
}

void listPasswords(Password *head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Password: %s\n", head->password);
    printf("\n");
    head = head->next;
  }
}

int main() {
  Password *passwords = NULL;

  printf("Welcome to the Password Management System!\n");

  while (1) {
    printf("Enter 'add' to add a new password, 'list' to list all passwords, or 'exit' to exit: ");
    char input[20];
    scanf("%s", input);

    if (strcmp(input, "add") == 0) {
      insertPassword(&passwords);
    } else if (strcmp(input, "list") == 0) {
      listPasswords(passwords);
    } else if (strcmp(input, "exit") == 0) {
      exit(0);
    } else {
      printf("Invalid input.\n");
    }
  }

  return 0;
}