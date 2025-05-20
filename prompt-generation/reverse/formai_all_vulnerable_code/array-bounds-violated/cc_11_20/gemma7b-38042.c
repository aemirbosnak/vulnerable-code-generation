//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 21
#define PADDLE_SIZE 5

int main()
{
    int board[BOARD_SIZE] = {0};
    int paddle1[PADDLE_SIZE] = {0};
    int paddle2[PADDLE_SIZE] = {0};
    int ball_x = BOARD_SIZE / 2;
    int ball_y = 0;
    int direction = 1;
    int score1 = 0;
    int score2 = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Game loop
    while (score1 < 11 && score2 < 11)
    {
        // Move the ball
        ball_x += direction * 2;

        // Bounce the ball off the walls
        if (ball_x < 0 || ball_x >= BOARD_SIZE)
        {
            direction *= -1;
        }

        // Move the paddles
        paddle1[0] = ball_y - 3;
        paddle2[0] = ball_y + 3;

        // Check if the ball has hit a paddle
        if (board[ball_x] == 1 && ball_y == paddle1[0])
        {
            direction *= -1;
            score1++;
        }
        else if (board[ball_x] == 2 && ball_y == paddle2[0])
        {
            direction *= -1;
            score2++;
        }

        // Draw the board
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < PADDLE_SIZE; j++)
            {
                if (board[i] == 1 && i == paddle1[0] && j == 0)
                {
                    printf("P");
                }
                else if (board[i] == 2 && i == paddle2[0] && j == 0)
                {
                    printf("P");
                }
                else if (board[i] == 0)
                {
                    printf(".");
                }
            }
            printf("\n");
        }

        // Pause the game
        sleep(0.1);
    }

    // Print the final score
    printf("Game Over!\n");
    printf("Score: %d - %d\n", score1, score2);

    return 0;
}