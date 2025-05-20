//FormAI DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <string.h>

struct User {
  char username[50];
  char password[50];
};

int main() {
  int i, j, choice, userCount=0, loginAttempts=3;
  struct User users[10];
  
  // Welcome screen
  printf("Welcome to the Password Management System!\n");
  
  while (1) {
    // Menu
    printf("\nWhat would you like to do?\n");
    printf("1. Add new user\n");
    printf("2. View all users\n");
    printf("3. Delete user\n");
    printf("4. Login\n");
    printf("5. Exit\n");
    
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        printf("Enter username: ");
        scanf("%s", users[userCount].username);
        printf("Enter password: ");
        scanf("%s", users[userCount].password);
        userCount++;
        printf("User added successfully!\n");
        break;
      case 2:
        printf("\nList of all users:\n");
        for (i=0; i<userCount; i++) {
          printf("%s\n", users[i].username);
        }
        break;
      case 3:
        printf("Enter username of user to delete: ");
        char usernameToDelete[50];
        scanf("%s", usernameToDelete);
        for (i=0; i<userCount; i++) {
          if (strcmp(usernameToDelete, users[i].username) == 0) {
            for (j=i; j<userCount-1; j++) {
              strcpy(users[j].username, users[j+1].username);
              strcpy(users[j].password, users[j+1].password);
            }
            userCount--;
            printf("User deleted successfully!\n");
            break;
          }
        }
        break;
      case 4:
        printf("Enter username: ");
        char usernameToLogin[50];
        scanf("%s", usernameToLogin);
        printf("Enter password: ");
        char passwordToLogin[50];
        scanf("%s", passwordToLogin);
        for (i=0; i<userCount; i++) {
          if (strcmp(usernameToLogin, users[i].username) == 0 && strcmp(passwordToLogin, users[i].password) == 0) {
            printf("Login successful!\n");
            loginAttempts = 3;
            break;
          }
        }
        if (i == userCount) {
          loginAttempts--;
          if (loginAttempts == 0) {
            printf("Login attempts exceeded. Exiting program.\n");
            return 0;
          } else {
            printf("Incorrect username or password. You have %d attempts left.\n", loginAttempts);
          }
        }
        break;
      case 5:
        printf("Exiting program...\n");
        return 0;
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }
  
  return 0;
}