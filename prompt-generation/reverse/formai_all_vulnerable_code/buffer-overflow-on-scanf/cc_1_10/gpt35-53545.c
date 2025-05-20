//FormAI DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LOGIN_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_ATTEMPTS 3

typedef struct {
  char login[MAX_LOGIN_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
} User;

User users[10]; // Maximum 10 users implemented
int numUsers = 0;

void addUser(char *login, char *password) {
  if (numUsers == 10) {
    printf("Cannot add more users. Maximum capacity reached.\n");
    return;
  }
  strcpy(users[numUsers].login, login); // Add new user to users list
  strcpy(users[numUsers].password, password); // Add new user to users list
  numUsers++;
  printf("User successfully added.\n");
}

bool authenticate(char *login, char *password) {
  for (int i = 0; i < numUsers; i++) {
    if (strcmp(users[i].login, login) == 0 && strcmp(users[i].password, password) == 0) {
      printf("Authentication successful. Welcome %s!\n", login);
      return true;
    }
  }
  printf("Invalid credentials. Please try again.\n");
  return false;
}

void changePassword(char *login, char *oldPassword, char *newPassword) {
  for (int i = 0; i < numUsers; i++) {
    if (strcmp(users[i].login, login) == 0 && strcmp(users[i].password, oldPassword) == 0) {
      strcpy(users[i].password, newPassword);
      printf("Password changed successfully.\n");
      return;
    }
  }
  printf("Invalid credentials. Password change failed.\n");
}

int main() {
  addUser("user1", "password1");
  addUser("user2", "password2");
  addUser("user3", "password3");

  int attempts = 0;
  bool authenticated = false;
  char login[MAX_LOGIN_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
  char newPassword[MAX_PASSWORD_LENGTH];

  do {
    printf("Enter login: ");
    scanf("%s", login);
    printf("Enter password: ");
    scanf("%s", password);
    authenticated = authenticate(login, password);
    attempts++;
  } while (!authenticated && attempts < MAX_ATTEMPTS);

  if (!authenticated) {
    printf("Maximum number of attempts reached. Access denied.\n");
    return 0;
  }

  printf("Enter new password: ");
  scanf("%s", newPassword);
  changePassword(login, password, newPassword);

  return 0;
}