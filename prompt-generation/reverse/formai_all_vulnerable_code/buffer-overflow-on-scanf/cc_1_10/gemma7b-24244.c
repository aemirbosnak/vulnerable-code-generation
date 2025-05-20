//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("clear");
    printf("Welcome to the Tower of Terror!\n");
    printf("You wake up in a cold sweat, the hairs on your neck stand on end.\n");
    printf("You have no recollection of how you ended up here, only the feeling that you are trapped.\n");

    // Create a map of the room
    int map[5][5] = {{1, 1, 1, 0, 0},
                           {1, 1, 1, 0, 0},
                           {1, 1, 1, 0, 0},
                           {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0}};

    // Get the player's input
    char input;
    printf("Please enter a direction (N, S, E, W): ");
    scanf("%c", &input);

    // Move the player
    switch (input)
    {
        case 'N':
            map[0][1]++;
            break;
        case 'S':
            map[0][1]--;
            break;
        case 'E':
            map[1][0]++;
            break;
        case 'W':
            map[1][0]--;
            break;
    }

    // Check if the player has won
    if (map[0][1] == 3)
    {
        printf("You have escaped the Tower of Terror!\n");
    }
    else
    {
        printf("You have not escaped the Tower of Terror. Try again.\n");
    }

    return;
}