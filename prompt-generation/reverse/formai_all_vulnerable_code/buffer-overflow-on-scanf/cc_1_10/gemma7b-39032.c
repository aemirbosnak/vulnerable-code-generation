//Gemma-7B DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *password;
  int used;
} Password;

Password passwords[MAX_PASSWORDS];

void generate_password(Password *p) {
  p->name = malloc(20);
  p->password = malloc(20);
  p->used = 0;

  printf("Enter a name for the password: ");
  scanf("%s", p->name);

  printf("Enter a password: ");
  scanf("%s", p->password);

  p->used = 1;
}

void list_passwords() {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (passwords[i].used) {
      printf("Name: %s\n", passwords[i].name);
      printf("Password: %s\n", passwords[i].password);
      printf("\n");
    }
  }
}

int main() {
  int choice;

  printf("Welcome to the password manager!\n");
  printf("Please select an option:\n");
  printf("1. Generate a new password\n");
  printf("2. List all passwords\n");
  printf("Enter your choice: ");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      generate_password(&passwords[0]);
      break;
    case 2:
      list_passwords();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}