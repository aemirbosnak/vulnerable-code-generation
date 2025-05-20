//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the game world
    char **world = (char **)malloc(5 * sizeof(char *));
    for(int i = 0; i < 5; i++)
    {
        world[i] = (char *)malloc(10 * sizeof(char));
    }
    world[0][0] = 'H';
    world[0][1] = 'U';
    world[0][2] = 'R';
    world[0][3] = 'O';
    world[0][4] = 'R';

    // Initialize the player's position
    int x = 0;
    int y = 0;

    // Game loop
    while(1)
    {
        // Print the game world
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                printf("%c ", world[i][j]);
            }
            printf("\n");
        }

        // Get the player's input
        char input;
        scanf(" %c", &input);

        // Move the player
        switch(input)
        {
            case 'w':
                y--;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
        }

        // Check if the player has reached the goal
        if(world[y][x] == 'G')
        {
            printf("You have won!\n");
            break;
        }

        // Check if the player has hit a wall
        if(x < 0 || x >= 10 || y < 0 || y >= 5)
        {
            printf("You have hit a wall.\n");
            break;
        }
    }

    // Free the game world
    for(int i = 0; i < 5; i++)
    {
        free(world[i]);
    }
    free(world);

    return 0;
}