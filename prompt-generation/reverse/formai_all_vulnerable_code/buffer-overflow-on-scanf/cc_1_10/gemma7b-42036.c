//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    int location = 1;
    char current_room[20];
    strcpy(current_room, "Baker Street");

    // Game loop
    while (1)
    {
        // Display room description
        printf("You are in the %s. What do you want to do? ", current_room);

        // Get user input
        char command[20];
        scanf("%s", command);

        // Process user input
        if (strcmp(command, "look") == 0)
        {
            // Display room items
            printf("The room contains: ");
            // List of room items
        }
        else if (strcmp(command, "search") == 0)
        {
            // Search for items
            printf("You found: ");
            // List of items found
        }
        else if (strcmp(command, "exit") == 0)
        {
            // Exit the game
            printf("Thank you for playing, %s. Goodbye!", name);
            exit(0);
        }
        else
        {
            // Invalid command
            printf("Invalid command. Please try again.");
        }
    }

    return 0;
}