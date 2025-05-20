//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PADDLE_SIZE 10
#define MAX_BALL_SIZE 5
#define BALL_SPEED 5

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the paddles
    int paddle1_x = 0;
    int paddle1_y = MAX_PADDLE_SIZE - 1;
    int paddle2_x = MAX_PADDLE_SIZE - 1;
    int paddle2_y = 0;

    // Create the ball
    int ball_x = MAX_BALL_SIZE / 2;
    int ball_y = MAX_BALL_SIZE / 2;
    int ball_dx = BALL_SPEED;
    int ball_dy = BALL_SPEED;

    // Game loop
    while (1) {
        // Display the game screen
        system("clear");
        printf("   |   |\n");
        printf(" -| | -|\n");
        printf("   | |   |\n");
        printf("   |---|   |\n");
        printf("   | %c |   |\n", paddle1_x + 1);
        printf("   |___) |   |\n");
        printf("   |   |   |\n");
        printf(" -| | -|\n");
        printf("   |   |   |\n");
        printf("   |---|   |\n");
        printf("   | %c |   |\n", paddle2_x + 1);
        printf("   |___) |   |\n");
        printf("   |   |   |\n");

        // Move the ball
        ball_x += ball_dx * 0.01 * time(NULL);
        ball_y += ball_dy * 0.01 * time(NULL);

        // Check if the ball has hit a paddle
        if (ball_x + ball_dx * 0.01 * time(NULL) >= paddle1_x && ball_y <= paddle1_y) {
            ball_dx *= -1;
        }
        if (ball_x - ball_dx * 0.01 * time(NULL) <= paddle2_x && ball_y <= paddle2_y) {
            ball_dx *= -1;
        }

        // Check if the ball has reached the edge of the screen
        if (ball_x >= MAX_PADDLE_SIZE - 1) {
            ball_dx *= -1;
        }
        if (ball_x <= 0) {
            ball_dx *= -1;
        }
        if (ball_y >= MAX_BALL_SIZE - 1) {
            ball_dy *= -1;
        }
        if (ball_y <= 0) {
            ball_dy *= -1;
        }

        // Sleep for a bit
        sleep(0.01);
    }

    return 0;
}