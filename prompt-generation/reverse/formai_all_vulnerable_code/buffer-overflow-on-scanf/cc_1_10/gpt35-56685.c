//FormAI DATASET v1.0 Category: System administration ; Style: lively
#include <stdio.h>
#include <stdlib.h>

/* Let's create a program to automate the management of user accounts on a Unix-based system.
   Users can create accounts, delete existing accounts, view all accounts on the system and even edit the details of existing accounts. */

int main() {

    int choice;
    int num_of_users = 0;
    char user_name[30];
    char user_email[50];
    char user_password[20];
    char user_role[10];

    /* We start by presenting the user with the options to manage the system */
    printf("\nWelcome to the User Account Management System\n\n");
    while(1) {
        printf("Please select what you would like to do:\n");
        printf("1. Create a new user account\n");
        printf("2. Delete an existing user account\n");
        printf("3. View all user accounts\n");
        printf("4. Edit an existing user account\n");
        printf("5. Exit the program\n");
        printf("\nOption: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:

                printf("\nCreating a new user account...\n\n");
                printf("Enter user name: ");
                scanf("%s", user_name);
                printf("Enter email address: ");
                scanf("%s", user_email);
                printf("Enter password: ");
                scanf("%s", user_password);
                printf("Enter user role: ");
                scanf("%s", user_role);
                num_of_users++;

                printf("\nUser account created for %s!\n\n", user_name);
                break;

            case 2:

                printf("\nDeleting an existing user account...\n\n");
                printf("Enter name of user to delete: ");
                scanf("%s", user_name);

                /* here we would write the code to delete the user account from the system */

                printf("\nUser account for %s has been deleted!\n\n", user_name);
                break;

            case 3:

                printf("\nViewing all user accounts...\n\n");

                /* here we would write the code to retrieve all user names and details from the system */

                printf("Total number of user accounts: %d\n\n", num_of_users);
                break;

            case 4:

                printf("\nEditing an existing user account...\n\n");
                printf("Enter name of user to edit: ");
                scanf("%s", user_name);

                /* here we would write the code to retrieve the user's details and allow the user to edit them */

                printf("\nUser account for %s has been updated!\n\n", user_name);
                break;

            case 5:

                printf("\nExiting the program...\n\n");
                exit(0);

            default:

                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}