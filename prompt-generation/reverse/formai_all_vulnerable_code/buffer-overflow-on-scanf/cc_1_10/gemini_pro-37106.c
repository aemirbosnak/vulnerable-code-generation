//GEMINI-pro DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
  char username[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
  if (num_passwords == MAX_PASSWORDS) {
    printf("Error: Password database full.\n");
    return;
  }

  strcpy(passwords[num_passwords].username, username);
  strcpy(passwords[num_passwords].password, password);
  num_passwords++;
}

int find_password(char *username) {
  for (int i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].username, username) == 0) {
      return i;
    }
  }

  return -1;
}

int main() {
  char username[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
  int choice;

  printf("Welcome to the Password Manager!\n");

  while (1) {
    printf("\n1. Add a password\n2. Find a password\n3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);
        add_password(username, password);
        break;
      case 2:
        printf("Enter username: ");
        scanf("%s", username);
        int index = find_password(username);
        if (index == -1) {
          printf("Password not found.\n");
        } else {
          printf("Password: %s\n", passwords[index].password);
        }
        break;
      case 3:
        exit(0);
        break;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}