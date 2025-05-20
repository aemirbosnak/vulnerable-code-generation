//FormAI DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char username[20], password[20], confirm[20];
    int choice;

    printf("Welcome to the System Administration Program!\n");

    do {
        printf("\nPlease choose an option (1-3):\n");
        printf("1. Create a new user\n");
        printf("2. Delete an existing user\n");
        printf("3. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nCreating a new user...");

                printf("\nEnter a username: ");
                scanf("%s", username);

                printf("Enter a password: ");
                scanf("%s", password);

                printf("Confirm password: ");
                scanf("%s", confirm);

                if(strcmp(password, confirm) != 0) {
                    printf("\nError: Passwords do not match. Please try again.\n");
                    break;
                }

                printf("\nNew user created successfully!\n");
                break;

            case 2:
                printf("\nDeleting an existing user...");

                printf("\nEnter the username of the user to delete: ");
                scanf("%s", username);

                printf("\nUser deleted successfully!\n");
                break;

            case 3:
                printf("\nExiting program...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}