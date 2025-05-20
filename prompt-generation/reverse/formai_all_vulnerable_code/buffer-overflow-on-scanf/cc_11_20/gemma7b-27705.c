//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int numPlayers = 0;
    int ballNumber = 0;
    int bingoNumbers[10] = {0};
    char board[5][5] = {' ', ' ', ' ', ' ', ' ',
                              ' ', ' ', ' ', ' ', ' ',
                              ' ', ' ', ' ', ' ', ' ',
                              ' ', ' ', ' ', ' ', ' '};

    // Get number of players
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    // Create bingo numbers for each player
    for (int i = 0; i < numPlayers; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            bingoNumbers[j] = rand() % 49 + 1;
        }
    }

    // Draw the bingo balls
    while (ballNumber < 10)
    {
        ballNumber++;
        int ballNumberDrawn = rand() % 49 + 1;

        // Check if the ball number has been drawn by any player
        for (int i = 0; i < numPlayers; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (bingoNumbers[j] == ballNumberDrawn)
                {
                    board[bingoNumbers[j] / 5][bingoNumbers[j] % 5] = 'X';
                }
            }
        }
    }

    // Print the winning board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Print the winner
    printf("The winner is: ");
    for (int i = 0; i < numPlayers; i++)
    {
        int won = 1;
        for (int j = 0; j < 10; j++)
        {
            if (board[bingoNumbers[j] / 5][bingoNumbers[j] % 5] != 'X')
            {
                won = 0;
            }
        }

        if (won)
        {
            printf("%d ", i + 1);
        }
    }

    return 0;
}