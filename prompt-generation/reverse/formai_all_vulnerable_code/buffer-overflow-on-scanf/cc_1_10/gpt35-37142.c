//FormAI DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int input;

    printf("Welcome to the System Administration Example Program.\n");
    printf("Please choose an option from the menu below:\n");
    printf("1. Add a new user\n2. Delete an existing user\n3. Change password for a user\n4. List all existing users\n5. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch(input) {
            case 1:
                printf("Please enter the username of the new user: ");
                char new_username[20];
                scanf("%s", new_username);
                printf("User %s has been added to the system.\n", new_username);
                break;

            case 2:
                printf("Please enter the username of the user that you want to delete: ");
                char del_username[20];
                scanf("%s", del_username);
                printf("User %s has been deleted from the system.\n", del_username);
                break;

            case 3:
                printf("Please enter the username of the user that you want to change the password for: ");
                char pw_username[20];
                scanf("%s", pw_username);
                printf("Please enter the new password for the user %s: ", pw_username);
                char new_password[20];
                scanf("%s", new_password);
                printf("The password for user %s has been changed to %s.\n", pw_username, new_password);
                break;

            case 4:
                printf("The following users exist in the system:\n");
                printf("JohnDoe\nJaneDoe\nBobSmith\n");
                break;

            case 5:
                printf("Thank you for using the System Administration Example Program!\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(input != 5);

    return 0;
}