//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    // Create a 5x5 bingo card
    int board[5][5] = {{0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    // Seed the random number generator
    srand(time(NULL));

    // Generate the bingo numbers
    for (int i = 0; i < 20; i++)
    {
        int number = rand() % 25 + 1;

        // Mark the number on the card
        board[number / 5][number % 5] = 1;
    }

    // Print the bingo card
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", board[i][j]);
        }

        printf("\n");
    }

    // Check if the player has won
    int win = 0;
    for (int i = 0; i < 5; i++)
    {
        // Check if the row has won
        if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1 && board[i][3] == 1 && board[i][4] == 1)
        {
            win = 1;
        }

        // Check if the column has won
        if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1 && board[3][i] == 1 && board[4][i] == 1)
        {
            win = 1;
        }
    }

    // Print the winner's message
    if (win)
    {
        printf("Congratulations! You have won!");
    }
    else
    {
        printf("Sorry, you have not won.");
    }

    return;
}