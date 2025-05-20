//Gemma-7B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

struct Password {
  char *name;
  char *password;
  struct Password *next;
};

void addPassword(struct Password **head) {
  struct Password *newPass = malloc(sizeof(struct Password));
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

void displayPasswords(struct Password *head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Password: %s\n", head->password);
    printf("\n");
    head = head->next;
  }
}

int main() {
  struct Password *passwords = NULL;

  while (1) {
    char choice;

    printf("Enter 'a' to add a password, 'd' to display passwords, or 'q' to quit: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'a':
        addPassword(&passwords);
        break;
      case 'd':
        displayPasswords(passwords);
        break;
      case 'q':
        exit(0);
    }
  }

  return 0;
}