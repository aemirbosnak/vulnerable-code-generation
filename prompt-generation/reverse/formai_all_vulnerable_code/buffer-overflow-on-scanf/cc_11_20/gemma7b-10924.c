//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char current_room = 'a';
    char direction = ' ';

    // Map of rooms
    char rooms[] = {'a', 'b', 'c', 'd', 'e'};

    // Inventory
    char items[] = {'key', 'sword', 'potion'};

    // Game loop
    while (1)
    {
        // Display current room
        printf("You are in room %c.\n", rooms[current_room]);

        // Get direction
        printf("Enter direction: ");
        scanf("%c", &direction);

        // Move in that direction
        switch (direction)
        {
            case 'w':
                if (current_room == 'a')
                {
                    current_room = 'b';
                }
                else
                {
                    printf("You cannot go that way.\n");
                }
                break;
            case 's':
                if (current_room == 'e')
                {
                    current_room = 'd';
                }
                else
                {
                    printf("You cannot go that way.\n");
                }
                break;
            case 'a':
                if (current_room == 'b')
                {
                    current_room = 'a';
                }
                else
                {
                    printf("You cannot go that way.\n");
                }
                break;
            case 'd':
                if (current_room == 'd')
                {
                    current_room = 'e';
                }
                else
                {
                    printf("You cannot go that way.\n");
                }
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        // Check if the player has won
        if (current_room == 'e' && items[0] == 'key')
        {
            printf("You have won! Congratulations!\n");
            break;
        }
    }

    return 0;
}