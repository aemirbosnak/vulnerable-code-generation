//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 5x5 grid of numbers
    int grid[25] = {0};

    // Place the treasure in a random location
    grid[rand() % 25] = 100;

    // Initialize the player's position
    int x = 0, y = 0;

    // Display the grid
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", grid[i * 5 + j]);
        }
        printf("\n");
    }

    // Move the player
    char move;

    // Loop until the player finds the treasure or quits
    while (grid[x * 5 + y] != 100 && move != 'q')
    {
        // Get the player's move
        printf("Enter your move (h/v/r/l/q): ");
        scanf("%c", &move);

        // Move the player
        switch (move)
        {
            case 'h':
                x--;
                break;
            case 'v':
                y--;
                break;
            case 'r':
                x++;
                break;
            case 'l':
                y++;
                break;
            case 'q':
                exit(0);
                break;
        }

        // Display the grid
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%d ", grid[i * 5 + j]);
            }
            printf("\n");
        }
    }

    // You found the treasure!
    printf("You found the treasure!");

    return 0;
}