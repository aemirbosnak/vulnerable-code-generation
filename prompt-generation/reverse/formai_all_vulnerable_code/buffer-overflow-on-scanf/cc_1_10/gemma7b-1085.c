//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 255

int main()
{
    char name[MAX_CHAR];
    int choice, health = 100;
    char current_room[MAX_CHAR];

    // Start in the main hall
    strcpy(current_room, "main_hall");

    // Loop until the player chooses to quit
    while (health > 0)
    {
        // Display the current room and options
        printf("You are in %s.\n", current_room);
        printf("Available options: \n");
        printf("1. Attack\n");
        printf("2. Negotiate\n");
        printf("3. Search\n");
        printf("Enter your choice: ");

        // Get the player's choice
        scanf("%d", &choice);

        // Process the player's choice
        switch (choice)
        {
            case 1:
                // Go to the battle room
                strcpy(current_room, "battle_room");
                break;
            case 2:
                // Go to the negotiation room
                strcpy(current_room, "negotiation_room");
                break;
            case 3:
                // Go to the secret room
                strcpy(current_room, "secret_room");
                break;
            default:
                // Invalid choice
                printf("Invalid choice.\n");
                break;
        }

        // Check if the player is still alive
        if (health < 0)
        {
            // Game over
            printf("Game over. You have died.\n");
            break;
        }
    }

    return 0;
}