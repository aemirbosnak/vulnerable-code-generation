//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    system("clear");
    printf("Welcome to the Invasive Terminal Game!\n");
    printf("Prepare to be invaded...\n");

    // Create a 5x5 grid
    int grid[25] = {0};
    for(int i = 0; i < 25; i++)
    {
        grid[i] = 0;
    }

    // Place the invader
    grid[rand() % 25] = 1;

    // Game loop
    while(1)
    {
        // Display the grid
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                printf("%d ", grid[i * 5 + j]);
            }
            printf("\n");
        }

        // Get the user's move
        int move = 0;
        printf("Enter your move (1-25): ");
        scanf("%d", &move);

        // Check if the move is valid
        if(move < 1 || move > 25)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is a hit
        if(grid[move - 1] == 1)
        {
            printf("BOOM! You've hit the invader!\n");
            grid[move - 1] = 2;
        }
        else
        {
            printf("Miss. Try again.\n");
        }

        // Check if the invader has been defeated
        int won = 0;
        for(int i = 0; i < 25; i++)
        {
            if(grid[i] == 2)
            {
                won = 1;
            }
        }

        // If the invader has been defeated, the game is over
        if(won)
        {
            printf("You have won! Congratulations!\n");
            break;
        }
    }

    return 0;
}