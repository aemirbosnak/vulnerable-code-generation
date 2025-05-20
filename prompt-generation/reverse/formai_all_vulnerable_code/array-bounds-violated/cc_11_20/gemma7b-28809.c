//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 20

#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 20

#define BALL_SIZE 5

int main()
{
    int x_ball = WIDTH / 2;
    int y_ball = HEIGHT - 1;
    int x_paddle_1 = 0;
    int y_paddle_1 = HEIGHT - 1;
    int x_paddle_2 = WIDTH - PADDLE_WIDTH - 1;
    int y_paddle_2 = HEIGHT - 1;

    int direction_ball = 1;
    int direction_paddle_1 = 0;
    int direction_paddle_2 = 0;

    int score_1 = 0;
    int score_2 = 0;

    char board[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            board[y][x] = ' ';
        }
    }

    board[y_ball][x_ball] = 'O';
    board[y_paddle_1][x_paddle_1] = 'P';
    board[y_paddle_2][x_paddle_2] = 'P';

    printf("   /|/\n");
    printf("  |||| |\n");
    printf("  \__) \n");
    printf("   \__)\n");

    while (!((score_1 == 11) || (score_2 == 11)))
    {
        // Ball movement
        x_ball += direction_ball;
        y_ball--;

        // Paddle movement
        if (direction_paddle_1 && y_paddle_1 > 0)
        {
            y_paddle_1--;
        }
        if (direction_paddle_2 && y_paddle_2 < HEIGHT - PADDLE_HEIGHT - 1)
        {
            y_paddle_2++;
        }

        // Collision detection
        if (board[y_ball][x_ball] == 'P' && x_ball == x_paddle_1)
        {
            direction_ball = -1;
            score_1++;
        }
        if (board[y_ball][x_ball] == 'P' && x_ball == x_paddle_2)
        {
            direction_ball = 1;
            score_2++;
        }

        // Board update
        board[y_ball][x_ball] = 'O';
        board[y_paddle_1][x_paddle_1] = 'P';
        board[y_paddle_2][x_paddle_2] = 'P';

        // Display the board
        printf("   /|/\n");
        printf("  |||| |\n");
        printf("  \__) \n");
        printf("   \__)\n");

        sleep(0.1);
    }

    // Game over
    printf("Game Over!\n");
    printf("Score: %d - %d\n", score_1, score_2);

    return 0;
}