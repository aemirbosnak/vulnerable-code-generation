//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>

int main() {
  printf("Welcome to the System Administration program!\n");
  printf("Please enter your username and password.\n");
  
  char username[20];
  char password[20];
  scanf("%s", username);
  scanf("%s", password);
  
  if(strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
    printf("Access granted! Welcome, %s.\n", username);
    printf("What would you like to do?\n");
    printf("1. View system information\n");
    printf("2. Manage users\n");
    printf("3. Restart system\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        printf("System information:\n");
        system("uname -a");
        break;
      case 2:
        printf("Manage users:\n");
        printf("1. Add a user\n");
        printf("2. Delete a user\n");
        printf("3. Change a user's password\n");
        
        int userChoice;
        scanf("%d", &userChoice);
        
        switch(userChoice) {
          case 1:
            printf("Enter username to add: ");
            char userToAdd[20];
            scanf("%s", userToAdd);
            char command[100];
            sprintf(command, "adduser %s", userToAdd);
            system(command);
            printf("%s was added successfully.\n", userToAdd);
            break;
          case 2:
            printf("Enter username to delete: ");
            char userToDelete[20];
            scanf("%s", userToDelete);
            char command2[100];
            sprintf(command2, "deluser %s", userToDelete);
            system(command2);
            printf("%s was deleted successfully.\n", userToDelete);
            break;
          case 3:
            printf("Enter username to change password: ");
            char userToChange[20];
            scanf("%s", userToChange);
            char command3[100];
            sprintf(command3, "passwd %s", userToChange);
            system(command3);
            printf("Password for %s was changed successfully.\n", userToChange);
            break;
          default:
            printf("Invalid choice.\n");
            break;
        }
        break;
      case 3:
        printf("Are you sure you want to restart the system? y/n. ");
        char restartChoice;
        scanf(" %c", &restartChoice);
        if(restartChoice == 'y') {
          printf("Restarting system...\n");
          system("shutdown -r now");
        } else {
          printf("System restart cancelled.\n");
        }
        break;
      default:
        printf("Invalid choice.\n");
        break;
        
    }
  } else {
    printf("Access denied. Incorrect username or password.\n");
  }
  
  return 0;
}