//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2

int main()
{

    // Game Board
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};

    // Ball Position
    int ball_x = 2;
    int ball_y = 3;

    // Ball Direction
    int ball_dx = 1;
    int ball_dy = -1;

    // Score
    int score = 0;

    // Game Loop
    while (!board[ball_y][ball_x] && score < 5)
    {
        // Update Ball Position
        ball_x += ball_dx;
        ball_y += ball_dy;

        // Check if Ball has Hit a Wall
        if (ball_x < 0 || ball_x >= BOARD_SIZE)
        {
            ball_dx *= -1;
        }
        if (ball_y < 0 || ball_y >= BOARD_SIZE)
        {
            ball_dy *= -1;
        }

        // Increment Score if Ball Hits a Brick
        if (board[ball_y][ball_x] != 0)
        {
            score++;
            board[ball_y][ball_x] = 0;
        }

        // Display Board
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Sleep
        sleep(1);
    }

    // Game Over
    printf("Game Over! Your score is: %d", score);

    return 0;
}