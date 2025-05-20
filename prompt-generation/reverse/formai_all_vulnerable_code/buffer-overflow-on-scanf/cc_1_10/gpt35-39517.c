//FormAI DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the System Administration Example Program!\n");
    printf("Please choose one of the following options:\n\n");
    printf("1. Display system information\n");
    printf("2. Manage users\n");
    printf("3. Manage files\n");
    printf("4. Exit program\n");

    int option;
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            printf("\nSystem Information:\n");
            // Code to display system information goes here
            break;

        case 2:
            printf("\nUser Management:\n");
            printf("Please choose one of the following options:\n\n");
            printf("1. Create a new user account\n");
            printf("2. Delete an existing user account\n");
            printf("3. Change password for an existing user account\n");

            int userChoice;
            scanf("%d", &userChoice);

            switch (userChoice)
            {
                case 1:
                    printf("Enter the username you want to create: ");
                    char username[20];
                    scanf("%s", username);
                    // Code to create a new user account goes here
                    break;

                case 2:
                    printf("Enter the username you want to delete: ");
                    char delUser[20];
                    scanf("%s", delUser);
                    // Code to delete an existing user account goes here
                    break;

                case 3:
                    printf("Enter the username for password change: ");
                    char usrname[20];
                    scanf("%s", usrname);
                    // Code to change password for an existing user account goes here
                    break;

                default:
                    printf("Invalid choice.\n");
            }
            break;

        case 3:
            printf("\nFile Management:\n");
            printf("Please choose one of the following options:\n\n");
            printf("1. Create a new file\n");
            printf("2. Delete an existing file\n");
            
            int fileChoice;
            scanf("%d", &fileChoice);

            switch (fileChoice)
            {
                case 1:
                    printf("Enter the filename you want to create: ");
                    char filename[20];
                    scanf("%s", filename);
                    // Code to create a new file goes here
                    break;

                case 2:
                    printf("Enter the name of file you want to delete: ");
                    char delFile[20];
                    scanf("%s", delFile);
                    // Code to delete an existing file goes here
                    break;

                default:
                    printf("Invalid choice.\n");
            }
            break;

        case 4:
            printf("\nExiting the program...\n");
            exit(0);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}