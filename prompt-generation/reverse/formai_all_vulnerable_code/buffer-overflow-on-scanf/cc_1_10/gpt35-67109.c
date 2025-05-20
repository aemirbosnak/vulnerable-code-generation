//FormAI DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* Initialize variables */
int numUsers = 0;
int loggedIn = 0;
char username[20];
char password[20];

/* Function to print the menu options */
void printMenu() {
  printf("Choose an option:\n");
  printf("1. Create new user\n");
  printf("2. Login\n");
  printf("3. Logout\n");
  printf("4. Shutdown server\n");
}

/* Function to create a new user */
void createNewUser() {
  printf("Enter a username: ");
  scanf("%s", username);
  printf("Enter a password: ");
  scanf("%s", password);
  printf("User %s created successfully!\n", username);
  numUsers++;
}

/* Function to login */
void login() {
  printf("Enter your username: ");
  scanf("%s", username);
  printf("Enter your password: ");
  scanf("%s", password);
  if(strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
    printf("Logged in as admin!\n");
    loggedIn = 1;
  } else {
    printf("Invalid username or password, please try again.\n");
  }
}

/* Function to logout */
void logout() {
  printf("Logged out.\n");
  loggedIn = 0;
}

/* Function to shutdown the server */
void shutdownServer() {
  printf("Shutting down server...\n");
  sleep(5); /* Let's pretend it takes 5 seconds to shut down the server */
  printf("Server has been shut down.\n");
  exit(0);
}

int main() {
  int choice;

  /* Print welcome message */
  printf("Welcome to the server administration tool!\n");

  /* Loop until user chooses to shut down the server */
  while(1) {
    printMenu();
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        createNewUser();
        break;
      case 2:
        login();
        break;
      case 3:
        logout();
        break;
      case 4:
        if(loggedIn == 1) {
          shutdownServer();
        } else {
          printf("You must be logged in as admin to shut down the server.\n");
        }
        break;
      default:
        printf("Invalid choice, please try again.\n");
    }
  }

  return 0;
}