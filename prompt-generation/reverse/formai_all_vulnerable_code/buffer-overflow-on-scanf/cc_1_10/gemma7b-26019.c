//Gemma-7B DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");
    printf("Welcome to the C System Administration Interface!\n");

    // Create a variable to store the command
    char command[255];

    // Prompt the user to enter a command
    printf("Enter a command: ");

    // Get the user's input
    fgets(command, 255, stdin);

    // Check if the command is valid
    if (strcmp(command, "help") == 0)
    {
        printf("Available commands:\n");
        printf("help\n");
        printf("shutdown\n");
        printf("restart\n");
        printf("users\n");
    }
    else if (strcmp(command, "shutdown") == 0)
    {
        printf("Are you sure you want to shut down the system? (y/n) ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'y')
        {
            system("shutdown -h now");
        }
    }
    else if (strcmp(command, "restart") == 0)
    {
        printf("Are you sure you want to restart the system? (y/n) ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'y')
        {
            system("shutdown -r now");
        }
    }
    else if (strcmp(command, "users") == 0)
    {
        system("who");
    }
    else
    {
        printf("Invalid command.\n");
    }

    // Pause the console
    system("pause");

    return 0;
}