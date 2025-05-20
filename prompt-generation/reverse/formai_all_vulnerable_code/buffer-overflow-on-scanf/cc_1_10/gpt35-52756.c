//FormAI DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Welcome message
    printf("Welcome to the C System Administration Example Program.\n");

    // Ask user for name and print greeting
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);

    // Ask user for password and check if correct
    char password[20];
    printf("Please enter the admin password: ");
    scanf("%s", password);
    if (strcmp(password, "admin123") != 0) {
        printf("Incorrect password. Program terminating.\n");
        return 0;
    }

    // Give user list of administration actions to choose from
    int choice;
    do {
        printf("\nPlease select an action:\n");
        printf("1. Add new user\n");
        printf("2. Delete user\n");
        printf("3. View user list\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        // Perform selected action based on user's choice
        switch(choice) {
            case 1:
                printf("\nAdding new user...\n");
                // (code to add new user)
                break;
            case 2:
                printf("\nDeleting user...\n");
                // (code to delete user)
                break;
            case 3:
                printf("\nViewing user list...\n");
                // (code to view user list)
                break;
            case 4:
                printf("\nProgram terminating. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}