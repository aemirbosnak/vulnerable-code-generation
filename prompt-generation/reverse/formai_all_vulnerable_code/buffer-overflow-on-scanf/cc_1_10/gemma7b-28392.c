//Gemma-7B DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

struct password_node {
  char *password;
  struct password_node *next;
};

void add_password(struct password_node **head) {
  struct password_node *new_node = malloc(sizeof(struct password_node));
  new_node->password = malloc(MAX_PASSWORDS);
  printf("Enter your password: ");
  scanf("%s", new_node->password);
  new_node->next = NULL;
  if (*head == NULL) {
    *head = new_node;
  } else {
    (*head)->next = new_node;
  }
}

void list_passwords(struct password_node *head) {
  while (head) {
    printf("%s\n", head->password);
    head = head->next;
  }
}

int main() {
  struct password_node *passwords = NULL;
  int option;

  while (1) {
    printf("Options:\n");
    printf("1. Add password\n");
    printf("2. List passwords\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        add_password(&passwords);
        break;
      case 2:
        list_passwords(passwords);
        break;
      default:
        printf("Invalid option\n");
    }
  }

  return 0;
}