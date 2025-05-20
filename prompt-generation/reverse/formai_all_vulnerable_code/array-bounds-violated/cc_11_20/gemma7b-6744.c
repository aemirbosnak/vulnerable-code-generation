//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

#define BALL_X 2
#define BALL_Y 2

#define PADDLE_X 1
#define PADDLE_Y 0

#define SPEED 5

int main()
{
    int x, y, ball_x, ball_y, paddle_x, paddle_y, score = 0;
    char board[HEIGHT][WIDTH] = {{0}};

    // Initialize the board
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            board[y][x] = ' ';
        }
    }

    // Place the paddle
    board[paddle_y][paddle_x] = 'P';

    // Place the ball
    board[ball_y][ball_x] = 'B';

    // Game loop
    while (!board[ball_y][ball_x] == 'O')
    {
        // Get the direction of the ball
        char direction = getchar();

        // Move the ball
        switch (direction)
        {
            case 'w':
                ball_y--;
                break;
            case 's':
                ball_y++;
                break;
            case 'a':
                ball_x--;
                break;
            case 'd':
                ball_x++;
                break;
        }

        // Check if the ball has hit the paddle
        if (board[ball_y][ball_x] == 'P')
        {
            // Ball has hit the paddle, so increment the score
            score++;

            // Move the paddle to the position of the ball
            board[paddle_y][paddle_x] = 'P';
            board[ball_y][ball_x] = 'B';
        }

        // Move the ball
        board[ball_y][ball_x] = 'B';

        // Print the board
        for (x = 0; x < WIDTH; x++)
        {
            for (y = 0; y < HEIGHT; y++)
            {
                printf("%c ", board[y][x]);
            }
            printf("\n");
        }

        // Check if the ball has hit the border
        if (ball_x < 0 || ball_x >= WIDTH || ball_y < 0 || ball_y >= HEIGHT)
        {
            // Game over, so print the final score
            printf("Game over! Your score is: %d", score);
            break;
        }
    }

    return 0;
}