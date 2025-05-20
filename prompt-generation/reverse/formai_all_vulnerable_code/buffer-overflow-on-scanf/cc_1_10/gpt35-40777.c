//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <errno.h>

// struct to store username and password
typedef struct {
  char username[50];
  char password[50];
} Account;

// function to generate a random password
void generatePassword(char* password) {
  const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  const int len = sizeof(charset) / sizeof(char) - 1;
  for (int i = 0; i < 12; i++) {
    password[i] = charset[rand() % len];
  }
  password[12] = '\0';
}

// function to create a new account
void createAccount() {
  Account newAccount;
  printf("Enter a username: ");
  scanf("%s", newAccount.username);
  char newPassword[13];
  generatePassword(newPassword);
  printf("Your new password is: %s\n", newPassword);
  strncpy(newAccount.password, newPassword, sizeof(newAccount.password) - 1);
  FILE *file;
  file = fopen("accounts.txt", "a");
  fprintf(file, "%s %s\n", newAccount.username, newAccount.password);
  printf("Account created successfully.\n");
  fclose(file);
}

// function to check if a username exists
bool userExists(char* username) {
  char currentUsername[50];
  char currentPassword[50];
  FILE *file;
  file = fopen("accounts.txt", "r");
  if (file) {
    while (fscanf(file, "%s %s", currentUsername, currentPassword) == 2) {
      if (strcmp(currentUsername, username) == 0) {
        fclose(file);
        return true;
      }
    }
  }
  fclose(file);
  return false;
}

// function to update a password
void updatePassword() {
  char username[50];
  printf("Enter your username: ");
  scanf("%s", username);
  if (!userExists(username)) {
    printf("Username not found.\n");
    return;
  }
  char newPassword[13];
  generatePassword(newPassword);
  bool done = false;
  while (!done) {
    char response[10];
    printf("Are you sure you want to change your password? (y/n) ");
    scanf("%s", response);
    if (tolower(response[0]) == 'y') {
      done = true;
      FILE *file;
      file = fopen("accounts.txt", "r");
      if (file) {
        int i = 0;
        int usernameIndex = -1;
        int passwordIndex = -1;
        char currentUsername[50];
        char currentPassword[50];
        char content[500];
        while (fscanf(file, "%s %s", currentUsername, currentPassword) == 2) {
          if (strcmp(currentUsername, username) == 0) {
            usernameIndex = i;
            passwordIndex = i + strlen(currentUsername) + 1;
          }
          int len = strlen(currentUsername) + strlen(currentPassword) + 1;
          for (int j = 0; j < len; j++) {
            content[i++] = fgetc(file);
          }
        }
        fclose(file);
        content[passwordIndex++] = ' ';
        for (int i = 0; i < strlen(newPassword); i++) {
          content[passwordIndex++] = newPassword[i];
        }
        content[passwordIndex++] = '\n';
        content[i] = '\0';
        file = fopen("accounts.txt", "w");
        fputs(content, file);
        fclose(file);
        printf("Password updated successfully.\n");
      }
    } else if (tolower(response[0]) == 'n') {
      done = true;
    }
  }
}

// function to prompt the user to create a new account or update their password
void promptUser() {
  char action[10];
  bool done = false;
  while (!done) {
    printf("Do you want to create a new account or update your password? (create/update) ");
    scanf("%s", action);
    if (strcmp(action, "create") == 0) {
      done = true;
      createAccount();
    } else if (strcmp(action, "update") == 0) {
      done = true;
      updatePassword();
    }
  }
}

int main(int argc, char** argv) {
  srand(time(NULL));
  promptUser();
  return 0;
}