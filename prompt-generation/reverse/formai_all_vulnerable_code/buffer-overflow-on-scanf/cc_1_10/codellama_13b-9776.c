//Code Llama-13B DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
// Romeo and Juliet System Administration Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_LOGIN_ATTEMPTS 3

// Structure to represent a user
typedef struct {
  char name[MAX_NAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
  int login_attempts;
} User;

// Function to create a new user
void create_user(User *user) {
  printf("Enter name: ");
  scanf("%s", user->name);
  printf("Enter password: ");
  scanf("%s", user->password);
  user->login_attempts = 0;
}

// Function to authenticate a user
int authenticate_user(User *user, char *password) {
  if (strcmp(user->password, password) == 0) {
    user->login_attempts = 0;
    return 1;
  } else {
    user->login_attempts++;
    if (user->login_attempts >= MAX_LOGIN_ATTEMPTS) {
      printf("Maximum login attempts exceeded. Goodbye!\n");
      exit(1);
    } else {
      printf("Incorrect password. Try again.\n");
      return 0;
    }
  }
}

// Function to display a user's information
void display_user(User *user) {
  printf("Name: %s\n", user->name);
  printf("Password: %s\n", user->password);
  printf("Login attempts: %d\n", user->login_attempts);
}

int main() {
  User user;
  char password[MAX_PASSWORD_LENGTH];

  create_user(&user);

  while (1) {
    printf("Enter password: ");
    scanf("%s", password);
    if (authenticate_user(&user, password)) {
      printf("Successfully authenticated!\n");
      break;
    }
  }

  display_user(&user);

  return 0;
}