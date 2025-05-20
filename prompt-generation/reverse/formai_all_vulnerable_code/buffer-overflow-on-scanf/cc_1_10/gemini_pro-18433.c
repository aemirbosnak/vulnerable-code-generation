//GEMINI-pro DATASET v1.0 Category: Password management ; Style: standalone
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
      passwords[i] = passwords[numPasswords - 1];
      numPasswords--;
      return;
    }
  }

  printf("Error: Password not found.\n");
}

void printPasswords() {
  int i;

  for (i = 0; i < numPasswords; i++) {
    printf("%s: %s\n", passwords[i].username, passwords[i].password);
  }
}

int main() {
  int choice;
  char username[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];

  while (1) {
    printf("1. Add password\n");
    printf("2. Delete password\n");
    printf("3. Print passwords\n");
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
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}