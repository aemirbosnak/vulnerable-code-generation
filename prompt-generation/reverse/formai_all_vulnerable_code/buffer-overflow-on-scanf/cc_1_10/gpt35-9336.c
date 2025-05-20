//FormAI DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 20
#define MAX_USERS 10

struct user {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
};

struct user users[MAX_USERS];
int num_users = 0;

int is_username_valid(char* username) {
  int i;
  if (strlen(username) > MAX_USERNAME_LENGTH) return 0;
  for (i = 0; username[i]; i++)
    if (!isalnum(username[i])) return 0;
  return 1;
}

int is_password_valid(char* password) {
  int i;
  int has_upper = 0, has_digit = 0;
  if (strlen(password) > MAX_PASSWORD_LENGTH) return 0;
  for (i = 0; password[i]; i++) {
    if (password[i] == ' ' || !isgraph(password[i])) return 0;
    if (isdigit(password[i])) has_digit = 1;
    if (isupper(password[i])) has_upper = 1;
  }
  if (!has_digit || !has_upper) return 0;
  return 1;
}

int find_user(char* username) {
  int i;
  for (i = 0; i < num_users; i++)
    if (strcmp(users[i].username, username) == 0)
      return i;
  return -1;
}

void add_user() {
  struct user user;
  char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
  int i;
  printf("Enter username: ");
  scanf("%s", username);
  if (!is_username_valid(username)) {
    printf("[ERROR] Invalid username.\n");
    return;
  }
  i = find_user(username);
  if (i >= 0) {
    printf("[ERROR] User already exists.\n");
    return;
  }
  printf("Enter password: ");
  scanf("%s", password);
  if (!is_password_valid(password)) {
    printf("[ERROR] Invalid password.\n");
    return;
  }
  strcpy(user.username, username);
  strcpy(user.password, password);
  if (num_users >= MAX_USERS) {
    printf("[ERROR] Maximum number of users reached.\n");
    return;
  }
  users[num_users++] = user;
  printf("[SUCCESS] User added.\n");
}

void delete_user() {
  char username[MAX_USERNAME_LENGTH];
  int i, j;
  printf("Enter username: ");
  scanf("%s", username);
  i = find_user(username);
  if (i < 0) {
    printf("[ERROR] User not found.\n");
    return;
  }
  for (j = i + 1; j < num_users; j++)
    users[j - 1] = users[j];
  num_users--;
  printf("[SUCCESS] User deleted.\n");
}

void change_password() {
  char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
  int i;
  printf("Enter username: ");
  scanf("%s", username);
  i = find_user(username);
  if (i < 0) {
    printf("[ERROR] User not found.\n");
    return;
  }
  printf("Enter new password: ");
  scanf("%s", password);
  if (!is_password_valid(password)) {
    printf("[ERROR] Invalid password.\n");
    return;
  }
  strcpy(users[i].password, password);
  printf("[SUCCESS] Password changed.\n");
}

void list_users() {
  int i;
  if (num_users == 0) {
    printf("No users found.\n");
    return;
  }
  printf("Username\n");
  printf("--------\n");
  for (i = 0; i < num_users; i++)
    printf("%s\n", users[i].username);
}

int authenticate(char* username, char* password) {
  int i = find_user(username);
  if (i < 0) return 0;
  if (strcmp(users[i].password, password) == 0)
    return 1;
  return 0;
}

void login() {
  char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
  printf("Enter username: ");
  scanf("%s", username);
  printf("Enter password: ");
  scanf("%s", password);
  if (authenticate(username, password)) {
    printf("[SUCCESS] Login successful.\n");
  }
  else {
    printf("[ERROR] Invalid username/password.\n");
  }
}

int menu() {
  int choice;
  printf("\nMenu\n");
  printf("----\n");
  printf("1. Add user\n");
  printf("2. Delete user\n");
  printf("3. Change password\n");
  printf("4. List users\n");
  printf("5. Login\n");
  printf("6. Exit\n");
  printf("Enter choice: ");
  scanf("%d", &choice);
  return choice;
}

int main() {
  int choice;
  while (1) {
    choice = menu();
    switch (choice) {
      case 1: add_user(); break;
      case 2: delete_user(); break;
      case 3: change_password(); break;
      case 4: list_users(); break;
      case 5: login(); break;
      case 6: exit(0);
      default: printf("[ERROR] Invalid choice.\n"); break;
    }
  }
  return 0;
}