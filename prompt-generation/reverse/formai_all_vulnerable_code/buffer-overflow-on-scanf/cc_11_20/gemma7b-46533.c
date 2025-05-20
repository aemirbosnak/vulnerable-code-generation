//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIVES 3

int main()
{
    int lives = MAX_LIVES;
    int score = 0;
    int current_position = 0;
    char direction = ' ';

    // Board setup
    int board[5][5] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 1, 1, 1, 0},
                              {0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0}};

    // Game loop
    while (lives > 0)
    {
        // Display the board
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Get the user's move
        printf("Enter your move (left/right/up/down): ");
        scanf("%c", &direction);

        // Move the paddle
        switch (direction)
        {
            case 'l':
                current_position--;
                break;
            case 'r':
                current_position++;
                break;
            case 'u':
                board[current_position][0] = 1;
                break;
            case 'd':
                board[current_position][4] = 1;
                break;
            default:
                printf("Invalid move.\n");
                break;
        }

        // Check if the paddle has reached a boundary
        if (current_position < 0 || current_position > 4)
        {
            lives--;
            printf("Game over. You lost with a score of %d.\n", score);
        }

        // Increment the score if the paddle reaches the goal
        if (board[current_position][2] == 1)
        {
            score++;
            board[current_position][2] = 0;
        }
    }

    return 0;
}