//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[5][5] = {{0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    int num_balls = 0;
    int ball_drawn = 0;
    int winner = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the balls
    while (num_balls < 25)
    {
        int number = rand() % 25 + 1;
        if (board[number][number] == 0)
        {
            board[number][number] = 1;
            num_balls++;
        }
    }

    // Draw the balls
    while (ball_drawn < 5)
    {
        int number = rand() % 25 + 1;
        if (board[number][number] == 0)
        {
            board[number][number] = 2;
            ball_drawn++;
        }
    }

    // Check for winner
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 3)
            {
                winner = 1;
            }
        }
    }

    // Print the results
    if (winner == 1)
    {
        printf("Congratulations! You have won!");
    }
    else
    {
        printf("Sorry, you have not won.");
    }

    return 0;
}