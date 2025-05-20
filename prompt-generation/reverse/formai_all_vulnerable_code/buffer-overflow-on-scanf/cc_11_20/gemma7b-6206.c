//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Cosmic Cavern!\n");

    // Create a 2D array of stars
    int stars[5][5] = {{1, 1, 0, 1, 1},
                            {1, 0, 1, 0, 1},
                            {0, 1, 1, 1, 0},
                            {1, 0, 1, 0, 1},
                            {1, 1, 0, 1, 1}};

    // Print the stars
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            if (stars[row][col] == 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Get the player's move
    char move;

    // Loop until the player makes a valid move
    while (1)
    {
        printf("Enter your move (N/S/E/W): ");
        scanf(" %c", &move);

        // Check if the move is valid
        if (move == 'N' || move == 'S' || move == 'E' || move == 'W')
        {
            break;
        }
        else
        {
            printf("Invalid move.\n");
        }
    }

    // Check if the player won
    int won = 0;

    // Loop over the rows and columns to see if the player has won
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            // Check if the player has won in a row
            if (stars[row][col] == 2 && stars[row][col-1] == 2 && stars[row][col-2] == 2)
            {
                won = 1;
            }

            // Check if the player has won in a column
            if (stars[row][col] == 2 && stars[row-1][col] == 2 && stars[row-2][col] == 2)
            {
                won = 1;
            }
        }
    }

    // If the player won, print a congratulatory message
    if (won)
    {
        printf("Congratulations! You won!");
    }

    // If the player lost, print a message of defeat
    else
    {
        printf("Sorry, you lost. Better luck next time.");
    }

    return 0;
}