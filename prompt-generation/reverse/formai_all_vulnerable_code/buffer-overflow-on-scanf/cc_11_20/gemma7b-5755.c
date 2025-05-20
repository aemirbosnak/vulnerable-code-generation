//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, w, h, score = 0, game_over = 0;
    char board[10][10] = {{0}};

    // Game setup
    w = 5;
    h = 5;
    x = 2;
    y = 2;

    // Draw the initial board
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            board[i][j] = '#';
        }
    }

    board[x][y] = 'O';

    // Game loop
    while (!game_over)
    {
        // Get the user's move
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Check if the move is valid
        if (x < 0 || x >= w || y < 0 || y >= h)
        {
            printf("Invalid move!\n");
            continue;
        }

        // Check if the move is a breakout
        if (board[x][y] == '#')
        {
            game_over = 1;
            printf("Game over! Your score is: %d\n", score);
        }
        else
        {
            // Move the ball
            board[x][y] = 'O';
            board[x - 1][y] = '#';

            // Increment the score
            score++;
        }

        // Print the board
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}