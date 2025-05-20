//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PADDLE_SIZE 10
#define MAX_BALL_SIZE 5
#define BALL_SPEED 5

int main()
{
    // Initialize the random number generator
    srand(time(NULL));

    // Create the paddles
    int paddle1_x = 10;
    int paddle1_y = 50;
    int paddle2_x = 790;
    int paddle2_y = 50;

    // Create the ball
    int ball_x = 350;
    int ball_y = 250;
    int ball_dx = BALL_SPEED;
    int ball_dy = BALL_SPEED;

    // Game loop
    while (1)
    {
        // Draw the paddles and the ball
        printf("***********************************************\n");
        printf("           /\n");
        printf("          ||\\/\n");
        printf("           \__)  |  /|\n");
        printf("           / \__) \__) |\n");
        printf("           / \__) \__) |\n");
        printf("           / \__) \__) |\n");
        printf("           / \__) \__) |\n");
        printf("           / \__) \__) |\n");
        printf("***********************************************\n\n");

        // Move the ball
        ball_x += ball_dx * 0.01 * clock() / 1000;
        ball_y += ball_dy * 0.01 * clock() / 1000;

        // Check if the ball has hit a paddle
        if (ball_x + MAX_BALL_SIZE / 2 >= paddle2_x && ball_y <= paddle2_y && ball_y >= paddle2_y - MAX_PADDLE_SIZE)
        {
            ball_dx *= -1;
        }
        else if (ball_x - MAX_BALL_SIZE / 2 <= paddle1_x && ball_y <= paddle1_y && ball_y >= paddle1_y - MAX_PADDLE_SIZE)
        {
            ball_dx *= -1;
        }

        // Check if the ball has reached the edge of the screen
        if (ball_x >= 800 || ball_x <= 0)
        {
            ball_dx *= -1;
        }
        if (ball_y >= 600 || ball_y <= 0)
        {
            ball_dy *= -1;
        }

        // Sleep for a bit
        sleep(0.01);
    }

    return 0;
}