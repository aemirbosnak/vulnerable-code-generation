//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Declare variables
    int choice, inventory[3] = {0, 0, 0};
    char location = 'a';

    // Start the adventure
    while (location != 'z')
    {
        // Display the current location
        switch (location)
        {
            case 'a':
                printf("You are in the Forest Clearing.\n");
                break;
            case 'b':
                printf("You are in the Haunted Castle.\n");
                break;
            case 'c':
                printf("You are in the Dragon's Lair.\n");
                break;
            default:
                printf("Error: Invalid location.\n");
                break;
        }

        // Present available choices
        printf("Choose your next move:\n");
        printf("1. Travel north.\n");
        printf("2. Travel south.\n");
        printf("3. Travel east.\n");
        printf("4. Travel west.\n");
        printf("Enter your choice: ");

        // Get the user's choice
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice)
        {
            case 1:
                location = 'b';
                break;
            case 2:
                location = 'c';
                break;
            case 3:
                location = 'a';
                break;
            case 4:
                location = 'd';
                break;
            default:
                printf("Error: Invalid choice.\n");
                break;
        }

        // Check if the user has collected any items
        if (inventory[0] > 0)
        {
            printf("You have collected a sword.\n");
        }
        if (inventory[1] > 0)
        {
            printf("You have collected a potion.\n");
        }
        if (inventory[2] > 0)
        {
            printf("You have collected a shield.\n");
        }
    }

    // End the adventure
    printf("You have reached the end of the adventure. Thank you for playing!\n");
}