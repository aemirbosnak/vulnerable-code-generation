//FormAI DATASET v1.0 Category: System administration ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char servername[20];
    char username[20];
    char password[20];

    printf("Welcome to the Server Management Tool!\n\n");

    while (1)
    {
        printf("\nPlease choose an option:\n");
        printf("1. Add a new server\n");
        printf("2. Remove a server\n");
        printf("3. View all servers\n");
        printf("4. Exit the program\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter server name: ");
                scanf("%s", servername);
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                // Code to add server to database goes here
                printf("\nServer added successfully!\n");
                break;

            case 2:
                printf("\nEnter server name to remove: ");
                scanf("%s", servername);

                // Code to remove server from database goes here
                printf("\nServer removed successfully!\n");
                break;

            case 3:
                printf("\nList of all servers:\n");

                // Code to retrieve list of all servers from database goes here
                // and display them to the user
                break;

            case 4:
                printf("\nThank you for using the Server Management Tool!\n");
                exit(0);

            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}