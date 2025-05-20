//FormAI DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the System Administration Program!\n\n");

  while(1) {
    printf("Please choose an option:\n");
    printf("1. Add a User\n");
    printf("2. Remove a User\n");
    printf("3. List Users\n");
    printf("4. Modify User\n");
    printf("5. Exit Program\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
      case 1: {
        printf("Please enter the username: ");
        char username[20];
        scanf("%s", username);

        printf("Please enter the password: ");
        char password[20];
        scanf("%s", password);

        char command[50];
        sprintf(command, "sudo useradd %s -p %s", username, password);
        system(command);

        printf("User %s added successfully!\n\n", username);
        break;
      }
      case 2: {
        printf("Please enter the username: ");
        char username[20];
        scanf("%s", username);

        char command[30];
        sprintf(command, "sudo userdel -r %s", username);
        system(command);

        printf("User %s removed successfully!\n\n", username);
        break;
      }
      case 3: {
        char command[20] = "cut -d: -f1 /etc/passwd";
        system(command);
        printf("\n");
        break;
      }
      case 4: {
        printf("Please enter the username: ");
        char username[20];
        scanf("%s", username);

        printf("Please choose a modification option:\n");
        printf("1. Modify password\n");
        printf("2. Modify username\n");

        int modificationChoice;
        scanf("%d", &modificationChoice);

        switch(modificationChoice) {
          case 1: {
            printf("Please enter the new password: ");
            char newPassword[20];
            scanf("%s", newPassword);

            char command[50];
            sprintf(command, "sudo passwd %s %s", username, newPassword);
            system(command);

            printf("Password for user %s modified successfully!\n\n", username);
            break;
          }
          case 2: {
            printf("Please enter the new username: ");
            char newUsername[20];
            scanf("%s", newUsername);

            char command[50];
            sprintf(command, "sudo usermod -l %s %s", newUsername, username);
            system(command);

            printf("Username for user %s modified successfully!\n\n", username);
            break;
          }
          default: {
            printf("Invalid choice! Please try again.\n\n");
            break;
          }
        }

        break;
      }
      case 5: {
        printf("Goodbye!\n");
        exit(0);
      }
      default: {
        printf("Invalid choice! Please try again.\n\n");
        break;
      }
    }
  }

  return 0;
}