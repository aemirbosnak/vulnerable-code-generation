//FormAI DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char users[3][20] = {"user1", "user2", "user3"};
  char passwords[3][20] = {"pass1", "pass2", "pass3"};
  char username[20];
  char password[20];

  int i, flag = 0;

  printf("Welcome to the login portal.\n");

  for(i=0;i<3;i++) {
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if(strcmp(username, users[i]) == 0 && strcmp(password, passwords[i]) == 0) {
      flag = 1;
      break;
    }
  }

  if(flag == 1) {
    printf("Login successful.\n");
    printf("What would you like to do?\n");
    printf("1. Check system status\n");
    printf("2. Create new user\n");
    printf("3. Delete user\n");
    printf("4. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("System status: OK\n");
        break;
      case 2:
        printf("Enter new username: ");
        char new_user[20];
        scanf("%s", new_user);
        printf("Enter new password: ");
        char new_pass[20];
        scanf("%s", new_pass);
        printf("New user %s created successfully.\n", new_user);
        break;
      case 3:
        printf("Enter username to delete: ");
        char del_user[20];
        scanf("%s", del_user);
        printf("%s deleted successfully.\n", del_user);
        break;
      case 4:
        printf("Exiting program...\n");
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }
  else {
    printf("Invalid username or password.\n");
  }

  return 0;
}