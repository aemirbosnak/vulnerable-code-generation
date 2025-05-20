//FormAI DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERS 10

// Structs
typedef struct User {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
} User;

// Function prototypes
void createUser(User *users[], int *numUsers);
void deleteUser(User *users[], int *numUsers);
void changePassword(User *users[], int numUsers);
void printUsers(User *users[], int numUsers);

// Main function
int main() {
  int numUsers = 0;
  User *users[MAX_USERS];

  // Main program loop
  while (1) {
    // Display menu
    printf("\n");
    printf("1. Create user\n");
    printf("2. Delete user\n");
    printf("3. Change password\n");
    printf("4. Print users\n");
    printf("5. Quit\n");
    printf("> ");

    // Get user input
    int choice;
    scanf("%d", &choice);

    // Process user's choice
    switch (choice) {
      case 1:
        createUser(users, &numUsers);
        break;
      case 2:
        deleteUser(users, &numUsers);
        break;
      case 3:
        changePassword(users, numUsers);
        break;
      case 4:
        printUsers(users, numUsers);
        break;
      case 5:
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}

// Creates a new user and adds them to the user list
void createUser(User *users[], int *numUsers) {
  // Make sure there's room for another user
  if (*numUsers >= MAX_USERS) {
    printf("Maximum number of users reached.\n");
    return;
  }

  // Allocate memory for the new user
  User *user = (User *) malloc(sizeof(User));

  // Read in the new user's details from the user
  printf("Enter username: ");
  scanf("%s", user->username);
  printf("Enter password: ");
  scanf("%s", user->password);

  // Add the new user to the user list
  users[*numUsers] = user;
  *numUsers += 1;
}

// Deletes a user
void deleteUser(User *users[], int *numUsers) {
  // Make sure there are users to delete
  if (*numUsers == 0) {
    printf("No users to delete.\n");
    return;
  }

  // Read in the username of the user to delete
  char username[MAX_USERNAME_LENGTH];
  printf("Enter username to delete: ");
  scanf("%s", username);

  // Find the user in the user list
  int i;
  for (i = 0; i < *numUsers; i++) {
    if (strcmp(users[i]->username, username) == 0) {
      break;
    }
  }

  // If the user wasn't found, print an error message and return
  if (i == *numUsers) {
    printf("User not found.\n");
    return;
  }

  // Free the memory associated with the user and shift the
  // remaining users down in the array
  free(users[i]);
  for (; i < *numUsers - 1; i++) {
    users[i] = users[i+1];
  }

  // Update the number of users
  *numUsers -= 1;
}

// Changes the password for a user
void changePassword(User *users[], int numUsers) {
  // Make sure there are users to change the password for
  if (numUsers == 0) {
    printf("No users to change password for.\n");
    return;
  }

  // Read in the username and new password
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
  printf("Enter username: ");
  scanf("%s", username);
  printf("Enter new password: ");
  scanf("%s", password);

  // Find the user in the user list
  int i;
  for (i = 0; i < numUsers; i++) {
    if (strcmp(users[i]->username, username) == 0) {
      break;
    }
  }

  // If the user wasn't found, print an error message and return
  if (i == numUsers) {
    printf("User not found.\n");
    return;
  }

  // Change the user's password
  strcpy(users[i]->password, password);
}

// Prints out the list of users
void printUsers(User *users[], int numUsers) {
  printf("Users:\n");
  for (int i = 0; i < numUsers; i++) {
    printf("%s\n", users[i]->username);
  }
}