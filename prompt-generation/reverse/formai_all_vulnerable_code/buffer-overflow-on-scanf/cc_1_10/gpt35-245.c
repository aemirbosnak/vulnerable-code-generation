//FormAI DATASET v1.0 Category: Password management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_ACCOUNTS 100

struct Account {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
} accounts[MAX_ACCOUNTS];

int numAccounts = 0;

void createAccount() {
  if (numAccounts >= MAX_ACCOUNTS) {
    printf("Error: Maximum number of accounts reached.\n");
    return;
  }

  struct Account newAccount;
  printf("Enter a username (max %d characters): ", MAX_USERNAME_LENGTH);
  scanf("%s", newAccount.username);

  for (int i = 0; i < numAccounts; i++) {
    if (strcmp(accounts[i].username, newAccount.username) == 0) {
      printf("Error: Username already exists.\n");
      return;
    }
  }

  printf("Enter a password (max %d characters): ", MAX_PASSWORD_LENGTH);
  scanf("%s", newAccount.password);

  accounts[numAccounts++] = newAccount;
  printf("Account created successfully.\n");
}

int findAccount(char* username) {
  for (int i = 0; i < numAccounts; i++) {
    if (strcmp(accounts[i].username, username) == 0) {
      return i;
    }
  }

  return -1;
}

void changePassword(char* username) {
  int accountIndex = findAccount(username);

  if (accountIndex < 0) {
    printf("Error: Username not found.\n");
    return;
  }

  char currentPassword[MAX_PASSWORD_LENGTH];
  char newPassword[MAX_PASSWORD_LENGTH];

  printf("Enter your current password: ");
  scanf("%s", currentPassword);

  if (strcmp(accounts[accountIndex].password, currentPassword) != 0) {
    printf("Error: Incorrect password.\n");
    return;
  }

  printf("Enter your new password (max %d characters): ", MAX_PASSWORD_LENGTH);
  scanf("%s", newPassword);

  strncpy(accounts[accountIndex].password, newPassword, MAX_PASSWORD_LENGTH);
  printf("Password changed successfully.\n");
}

int main() {
  int choice;
  char username[MAX_USERNAME_LENGTH];

  while (1) {
    printf("\n");
    printf("1. Create account\n");
    printf("2. Change password\n");
    printf("3. Exit\n");
    printf("Choice: ");

    scanf("%d", &choice);

    if (choice == 1) {
      createAccount();
    } else if (choice == 2) {
      printf("Enter your username: ");
      scanf("%s", username);
      changePassword(username);
    } else if (choice == 3) {
      printf("Goodbye!\n");
      exit(0);
    } else {
      printf("Error: Invalid choice.\n");
    }
  }

  return 0;
}