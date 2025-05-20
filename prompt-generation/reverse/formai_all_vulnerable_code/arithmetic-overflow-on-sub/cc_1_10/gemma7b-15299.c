//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2
#define PADDLE_SIZE 4

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};

    int ball_x = BOARD_SIZE / 2;
    int ball_y = BOARD_SIZE - 1;

    int paddle_x = 0;
    int paddle_y = BOARD_SIZE - 1;

    int direction = 1;

    clock_t start_time = clock();

    while (!board[ball_y][ball_x] && clock() - start_time < 600000)
    {
        // Move the ball
        board[ball_y][ball_x] = 1;
        ball_x += direction * 2;
        board[ball_y][ball_x] = 0;

        // Move the paddle
        if (ball_x - paddle_x > PADDLE_SIZE / 2)
        {
            paddle_x++;
        }
        else if (ball_x - paddle_x < -PADDLE_SIZE / 2)
        {
            paddle_x--;
        }

        // Check if the ball has hit the paddle
        if (board[paddle_y][paddle_x] == 1)
        {
            direction *= -1;
        }

        // Update the clock
        start_time = clock();
    }

    // Game over
    printf("Game over!\n");

    return 0;
}