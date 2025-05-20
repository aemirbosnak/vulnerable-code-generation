//FormAI DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Declare variables */
    int option;
    char username[20], password[20];
    
    /* Print menu of options */
    printf("Welcome to the System Administration menu!\n");
    printf("Please choose an option:\n");
    printf("1. Add User Account\n");
    printf("2. Delete User Account\n");
    printf("3. Change User Password\n");
    printf("4. View User Accounts\n");
    printf("0. Exit\n");
    
    /* Get user input */
    scanf("%d", &option);
    
    /* Execute selected option */
    switch(option)
    {
        case 1:
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            /* Add user account to system */
            printf("User account added successfully!\n");
            break;
        case 2:
            printf("Enter username: ");
            scanf("%s", username);
            /* Delete user account from system */
            printf("User account deleted successfully!\n");
            break;
        case 3:
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter new password: ");
            scanf("%s", password);
            /* Change user password */
            printf("User password changed successfully!\n");
            break;
        case 4:
            /* View list of user accounts */
            printf("User Accounts:\n");
            // code to list all user accounts
            break;
        case 0:
            /* Exit program */
            printf("Exiting System Administration menu...\n");
            exit(0);
        default:
            printf("Invalid option selected. Please try again.\n");
            break;
    }
    
    return 0;
}