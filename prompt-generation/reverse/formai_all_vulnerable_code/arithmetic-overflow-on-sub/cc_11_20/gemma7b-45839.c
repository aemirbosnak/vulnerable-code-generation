//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2
#define PADDLE_SIZE 3

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0}};

    int ball_x = 2;
    int ball_y = 0;
    int paddle_x = 1;
    int paddle_y = BOARD_SIZE - 1;

    time_t start_time = time(NULL);

    // Game Loop
    while (!board[ball_y][ball_x] && time(NULL) - start_time < 60)
    {
        // Ball Movement
        ball_x++;
        ball_y++;

        // Paddle Movement
        if (board[paddle_y][paddle_x] == 1)
        {
            // Left
            if (paddle_x > 0 && board[paddle_y][paddle_x - 1] == 0)
            {
                paddle_x--;
            }

            // Right
            else if (paddle_x < BOARD_SIZE - 1 && board[paddle_y][paddle_x + 1] == 0)
            {
                paddle_x++;
            }
        }

        // Ball Collision
        if (board[ball_y][ball_x] == 1)
        {
            board[ball_y][ball_x] = 2;
            ball_x--;
            ball_y--;
        }

        // Paddle Collision
        if (board[paddle_y][paddle_x] == 2)
        {
            board[paddle_y][paddle_x] = 0;
            ball_x++;
            ball_y--;
        }

        // Draw the Board
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Sleep
        sleep(0.1);
    }

    // Game Over
    printf("Game Over!");

    return 0;
}