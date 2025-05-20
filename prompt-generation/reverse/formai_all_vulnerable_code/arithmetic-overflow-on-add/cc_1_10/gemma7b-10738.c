//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PADDLE_SIZE 10
#define MAX_BALL_SPEED 5

int main() {
    int x_paddle_1 = MAX_PADDLE_SIZE / 2;
    int y_paddle_1 = MAX_PADDLE_SIZE - 1;
    int x_paddle_2 = MAX_PADDLE_SIZE / 2;
    int y_paddle_2 = 0;
    int ball_x = MAX_PADDLE_SIZE / 2;
    int ball_y = MAX_PADDLE_SIZE / 2;
    int ball_speed_x = MAX_BALL_SPEED;
    int ball_speed_y = MAX_BALL_SPEED;

    srand(time(NULL));

    // Game loop
    while (1) {
        // Draw the paddles and ball
        system("clear");
        printf("__________________\n");
        printf("           /\n");
        printf("          ;   :\n");
        printf("           \__) \n");
        printf("Paddle 1: (%d, %d)\n", x_paddle_1, y_paddle_1);
        printf("Paddle 2: (%d, %d)\n", x_paddle_2, y_paddle_2);
        printf("Ball: (%d, %d)\n", ball_x, ball_y);

        // Move the ball
        ball_x += ball_speed_x * 0.01 * time(NULL);
        ball_y += ball_speed_y * 0.01 * time(NULL);

        // Check if the ball has hit a paddle
        if (ball_x + ball_speed_x * 0.01 * time(NULL) >= x_paddle_1 && ball_y <= y_paddle_1) {
            ball_speed_x *= -1;
        } else if (ball_x - ball_speed_x * 0.01 * time(NULL) <= x_paddle_2 && ball_y <= y_paddle_2) {
            ball_speed_x *= -1;
        }

        // Check if the ball has hit the boundary
        if (ball_x >= MAX_PADDLE_SIZE || ball_x <= 0) {
            ball_speed_x *= -1;
        }
        if (ball_y >= MAX_PADDLE_SIZE || ball_y <= 0) {
            ball_speed_y *= -1;
        }

        // Sleep for a bit
        sleep(0.05);
    }

    return 0;
}