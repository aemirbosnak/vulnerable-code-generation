//Gemma-7B DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    system("clear");
    printf("Welcome to the C System Administration Paradise!\n");

    char username[20];
    printf("Please enter your username: ");
    scanf("%s", username);

    char password[20];
    printf("Enter your password: ");
    scanf("%s", password);

    // Validate credentials
    if (strcmp(username, "admin") == 0 && strcmp(password, "secret") == 0)
    {
        printf("Congratulations, you have successfully authenticated!\n");

        // List of available commands
        printf("Available commands:\n");
        printf("1. Create user\n");
        printf("2. Delete user\n");
        printf("3. Modify user\n");
        printf("4. View user list\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                system("adduser");
                break;
            case 2:
                system("deluser");
                break;
            case 3:
                system("moduser");
                break;
            case 4:
                system("viewuser");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    else
    {
        printf("Invalid credentials.\n");
    }

    return 0;
}