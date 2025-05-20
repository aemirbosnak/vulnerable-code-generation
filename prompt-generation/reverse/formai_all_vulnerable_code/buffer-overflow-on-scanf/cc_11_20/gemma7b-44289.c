//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void main()
{
    printf("You wake up in a cozy cottage, the smell of warm bread and fresh-baked pastries filling your senses.\n");
    printf("The sun shines warmly through the window, casting long shadows across the floor.\n");
    printf("A gentle breeze whispers secrets through the leaves, carrying the scent of wildflowers.\n");

    // Create a map of the cottage
    int map[5][5] = {{0, 1, 0, 0, 0},
                           {0, 1, 1, 0, 0},
                           {0, 1, 1, 1, 0},
                           {0, 0, 1, 1, 0},
                           {0, 0, 0, 1, 1}};

    // Player's current position
    int x = 2;
    int y = 2;

    // Move the player
    int direction = 0;

    // Loop until the player chooses a direction
    while (direction == 0)
    {
        printf("What direction do you want to go (N, S, E, W)? ");
        char input[10];
        scanf("%s", input);

        // Check if the input is valid
        if (input[0] == 'n' || input[0] == 'N')
        {
            direction = 1;
        }
        else if (input[0] == 's' || input[0] == 'S')
        {
            direction = 2;
        }
        else if (input[0] == 'e' || input[0] == 'E')
        {
            direction = 3;
        }
        else if (input[0] == 'w' || input[0] == 'W')
        {
            direction = 4;
        }
        else
        {
            printf("Invalid input.\n");
        }
    }

    // Move the player in the chosen direction
    switch (direction)
    {
        case 1:
            y--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x++;
            break;
        case 4:
            x--;
            break;
    }

    // Check if the player has reached the end of the map
    if (map[x][y] == 1)
    {
        printf("You have reached the end of the map!\n");
    }
    else
    {
        // Display the player's new position
        printf("You are now at (%d, %d).\n", x, y);
    }

    return;
}