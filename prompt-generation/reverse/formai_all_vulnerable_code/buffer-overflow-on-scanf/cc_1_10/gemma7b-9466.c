//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char ch;
    int room = 1;
    int inventory[] = {0, 0, 0};

    // Room 1 - The Foyer
    printf("You find yourself in a dimly lit foyer. A grand piano stands in the center of the room, and a mysterious portrait hangs on the wall.\n");

    // Choose a direction
    printf("Please enter the direction you want to go (N, S, E, W): ");
    scanf("%c", &ch);

    switch (ch)
    {
        case 'N':
            room = 2;
            break;
        case 'S':
            room = 3;
            break;
        case 'E':
            room = 4;
            break;
        case 'W':
            room = 5;
            break;
        default:
            printf("Invalid input.\n");
    }

    // Room 2 - The Living Room
    if (room == 2)
    {
        printf("You enter the living room. There is a comfortable sofa, a coffee table, and a bookcase.\n");

        // Inventory management
        printf("You have %d items in your inventory.\n", inventory[0]);
        printf("Please enter the number of the item you want to use (1-3): ");
        scanf("%d", &inventory[0]);

        // Use the item
        switch (inventory[0])
        {
            case 1:
                printf("You use the sharp blade to cut the rope. The rope breaks, and you are able to open the bookcase.\n");
                break;
            case 2:
                printf("You use the screwdriver to pry loose the panel on the wall. You find a hidden key.\n");
                break;
            case 3:
                printf("You use the lockpick to unlock the secret drawer. You find a valuable gemstone.\n");
                break;
            default:
                printf("Invalid item selection.\n");
        }
    }

    // Other rooms and events...

    // Game over
    printf("Congratulations! You have completed the adventure.\n");
}