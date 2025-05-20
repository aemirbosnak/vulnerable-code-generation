//GEMINI-pro DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct password {
  char username[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
};

struct password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *username, char *password) {
  if (numPasswords >= MAX_PASSWORDS) {
    printf("Error: Password limit reached.\n");
    return;
  }

  strcpy(passwords[numPasswords].username, username);
  strcpy(passwords[numPasswords].password, password);
  numPasswords++;
}

void deletePassword(char *username) {
  int i;
  for (i = 0; i < numPasswords; i++) {
    if (strcmp(passwords[i].username, username) == 0) {
      break;
    }
  }

  if (i == numPasswords) {
    printf("Error: Password not found.\n");
    return;
  }

  for (; i < numPasswords - 1; i++) {
    strcpy(passwords[i].username, passwords[i + 1].username);
    strcpy(passwords[i].password, passwords[i + 1].password);
  }

  numPasswords--;
}

void printPasswords() {
  int i;
  for (i = 0; i < numPasswords; i++) {
    printf("%s:%s\n", passwords[i].username, passwords[i].password);
  }
}

int main() {
  int choice;
  char username[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];

  do {
    printf("1. Add Password\n");
    printf("2. Delete Password\n");
    printf("3. Print Passwords\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);
        addPassword(username, password);
        break;
      case 2:
        printf("Enter username: ");
        scanf("%s", username);
        deletePassword(username);
        break;
      case 3:
        printPasswords();
        break;
      case 4:
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 4);

  return 0;
}