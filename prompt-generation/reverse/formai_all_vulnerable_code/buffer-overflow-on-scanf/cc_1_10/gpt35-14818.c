//FormAI DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to the Happy Admin Program!\n");
  printf("This program will help you manage your system with a smile on your face.\n");

  int choice;
  while (1) {
    printf("\nWhat would you like to do?\n");
    printf("1. View System Info\n");
    printf("2. Add User\n");
    printf("3. Change Password\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nSystem Info:\n");
        system("uname -a");
        system("lsb_release -a");
        break;
      case 2:
        printf("\nAdding a user...\n");
        printf("Please enter the user's name: ");
        char username[30];
        scanf("%s", username);
        char command[100];
        sprintf(command, "sudo adduser %s", username);
        system(command);
        printf("%s has been added successfully!\n", username);
        break;
      case 3:
        printf("\nChanging password...\n");
        printf("Please enter the username: ");
        char user[30];
        scanf("%s", user);
        char cmd[100];
        sprintf(cmd, "sudo passwd %s", user);
        system(cmd);
        printf("Password for %s has been changed successfully!\n", user);
        break;
      case 4:
        printf("Thank you for using the Happy Admin Program!");
        return 0;
      default:
        printf("Invalid choice, please try again.\n");
        break;
    }
  }
}