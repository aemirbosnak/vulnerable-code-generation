//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>

char *messages[] = {"Welcome back, administrator!",
                    "Here are the available commands:",
                    "1. View server status",
                    "2. Restart server",
                    "3. Create new user",
                    "4. Change user password",
                    "5. Delete user",
                    "6. Exit program"
                    };

int main()
{
    int command;

    printf("%s\n", messages[0]);
    printf("%s\n", messages[1]);

    for(int i=2; i<7; i++)
    {
        printf("%s\n", messages[i]);
    }

    printf("\nPlease enter the number of the command you wish to execute: ");
    scanf("%d", &command);

    while(command < 1 || command > 6)
    {
        printf("Invalid command entered. Please try again: ");
        scanf("%d", &command);
    }

    switch(command)
    {
        case 1:
            printf("Server is currently running.\n");
            break;

        case 2:
            printf("Restarting server...\n");
            // Code to restart server goes here
            printf("Server restarted successfully.\n");
            break;

        case 3:
            printf("Enter a username for the new user: ");
            char * username = (char *)malloc(16 * sizeof(char));
            scanf("%s", username);
            printf("User %s created successfully.\n", username);
            free(username);
            break;

        case 4:
            printf("Enter the username whose password you want to change: ");
            char * user_to_change = (char *)malloc(16 * sizeof(char));
            scanf("%s", user_to_change);
            printf("Enter the new password for user %s: ", user_to_change);
            char * new_password = (char *)malloc(16 * sizeof(char));
            scanf("%s", new_password);
            printf("Password for user %s changed successfully.\n", user_to_change);
            free(user_to_change);
            free(new_password);
            break;

        case 5:
            printf("Enter the username of the user you want to delete: ");
            char * user_to_delete = (char *)malloc(16 * sizeof(char));
            scanf("%s", user_to_delete);
            printf("Deleting user %s...\n", user_to_delete);
            // Code to delete user goes here
            printf("User %s deleted successfully.\n", user_to_delete);
            free(user_to_delete);
            break;

        case 6:
            printf("Exiting program...\n");
            exit(0);
    }

    return 0;
}