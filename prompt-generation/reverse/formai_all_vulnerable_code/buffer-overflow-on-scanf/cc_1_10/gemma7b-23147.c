//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, room, inventory, status = 0;
    char name[20];

    // Initialize the room and inventory
    room = 1;
    inventory = 0;

    // Get the player's name
    printf("What is your name? ");
    scanf("%s", name);

    // Start the adventure
    while (status != 3)
    {
        // Display the room description
        switch (room)
        {
            case 1:
                printf("You are in a cozy cottage.\n");
                break;
            case 2:
                printf("You are in a haunted mansion.\n");
                break;
            case 3:
                printf("You are in a secret cave.\n");
                break;
        }

        // Get the player's choice
        printf("What do you want to do? (1, 2, 3) ");
        scanf("%d", &choice);

        // Process the player's choice
        switch (choice)
        {
            case 1:
                // Go to the next room
                room++;
                break;
            case 2:
                // Search for items in the room
                inventory++;
                break;
            case 3:
                // Attack the enemy
                status++;
                break;
        }
    }

    // End the adventure
    printf("Thank you for playing, %s!", name);
}