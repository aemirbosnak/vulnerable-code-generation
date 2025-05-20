//Code Llama-13B DATASET v1.0 Category: Password management ; Style: peaceful
// A simple password management program in peaceful style

#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20

// Structure to store user information
typedef struct {
  char username[MAX_USERS][MAX_PASSWORD_LENGTH];
  char password[MAX_USERS][MAX_PASSWORD_LENGTH];
} User;

// Function to prompt user for input
void prompt(char *str) {
  printf("%s", str);
  fflush(stdout);
}

// Function to validate user input
int validate(char *str) {
  if (strlen(str) > MAX_PASSWORD_LENGTH) {
    printf("Password is too long.\n");
    return 0;
  }
  return 1;
}

// Function to create a new user
void create_user(User *user) {
  // Prompt user for username and password
  prompt("Enter a username: ");
  scanf("%s", user->username);
  prompt("Enter a password: ");
  scanf("%s", user->password);

  // Validate user input
  if (!validate(user->username) || !validate(user->password)) {
    printf("Invalid input.\n");
    return;
  }

  // Print success message
  printf("User created successfully.\n");
}

// Function to login as a user
void login(User *user) {
  // Prompt user for username and password
  prompt("Enter your username: ");
  scanf("%s", user->username);
  prompt("Enter your password: ");
  scanf("%s", user->password);

  // Validate user input
  if (!validate(user->username) || !validate(user->password)) {
    printf("Invalid input.\n");
    return;
  }

  // Check if user exists
  int i;
  for (i = 0; i < MAX_USERS; i++) {
    if (strcmp(user->username, user->username[i]) == 0) {
      break;
    }
  }
  if (i == MAX_USERS) {
    printf("User does not exist.\n");
    return;
  }

  // Check if password is correct
  if (strcmp(user->password, user->password[i]) != 0) {
    printf("Incorrect password.\n");
    return;
  }

  // Print success message
  printf("Login successful.\n");
}

// Function to change password
void change_password(User *user) {
  // Prompt user for old and new password
  prompt("Enter your old password: ");
  scanf("%s", user->password);
  prompt("Enter your new password: ");
  scanf("%s", user->password);

  // Validate user input
  if (!validate(user->password)) {
    printf("Invalid input.\n");
    return;
  }

  // Check if old password is correct
  int i;
  for (i = 0; i < MAX_USERS; i++) {
    if (strcmp(user->password, user->password[i]) == 0) {
      break;
    }
  }
  if (i == MAX_USERS) {
    printf("Incorrect password.\n");
    return;
  }

  // Update password
  strcpy(user->password[i], user->password);

  // Print success message
  printf("Password changed successfully.\n");
}

// Function to delete user
void delete_user(User *user) {
  // Prompt user for username
  prompt("Enter the username of the user you want to delete: ");
  scanf("%s", user->username);

  // Validate user input
  if (!validate(user->username)) {
    printf("Invalid input.\n");
    return;
  }

  // Check if user exists
  int i;
  for (i = 0; i < MAX_USERS; i++) {
    if (strcmp(user->username, user->username[i]) == 0) {
      break;
    }
  }
  if (i == MAX_USERS) {
    printf("User does not exist.\n");
    return;
  }

  // Delete user
  strcpy(user->username[i], "");
  strcpy(user->password[i], "");

  // Print success message
  printf("User deleted successfully.\n");
}

int main() {
  User user;

  // Create a new user
  create_user(&user);

  // Login as a user
  login(&user);

  // Change password
  change_password(&user);

  // Delete user
  delete_user(&user);

  return 0;
}