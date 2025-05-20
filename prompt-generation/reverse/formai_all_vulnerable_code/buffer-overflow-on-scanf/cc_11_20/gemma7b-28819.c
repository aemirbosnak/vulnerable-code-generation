//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the game state
    int inventory[] = {0, 0, 0};
    int current_room = 1;
    char direction = ' ';

    // Loop until the player wins or loses
    while (1)
    {
        // Print the current room
        switch (current_room)
        {
            case 1:
                printf("You are in a dark forest.\n");
                break;
            case 2:
                printf("You are in a haunted mansion.\n");
                break;
            case 3:
                printf("You are in a secret laboratory.\n");
                break;
        }

        // Get the player's input
        printf("Enter direction (N/S/E/W): ");
        scanf("%c", &direction);

        // Move the player
        switch (direction)
        {
            case 'N':
                current_room++;
                break;
            case 'S':
                current_room--;
                break;
            case 'E':
                inventory[0]++;
                break;
            case 'W':
                inventory[1]++;
                break;
        }

        // Check if the player has won or lost
        if (inventory[2] == 1)
        {
            printf("You have won!\n");
            break;
        }
        else if (current_room == 0)
        {
            printf("You have lost.\n");
            break;
        }
    }

    return 0;
}