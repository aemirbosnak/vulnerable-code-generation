//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Create a 5x5 grid of squares
    int grid[25] = {0};

    // Place the Breakout paddle
    grid[12] = 1;

    // Set up the ball's position and direction
    int ball_x = 3;
    int ball_y = 0;
    int ball_dx = 1;
    int ball_dy = 1;

    // Game loop
    while (!grid[ball_x] || ball_y >= 4) {

        // Move the ball
        ball_x += ball_dx;
        ball_y += ball_dy;

        // Check if the ball has hit a wall
        if (ball_x < 0 || ball_x >= 5) {
            ball_dx *= -1;
        }

        // Check if the ball has hit the paddle
        if (ball_y == 0 && grid[ball_x] == 1) {
            ball_dy *= -1;
        }

        // Draw the grid
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d ", grid[i * 5 + j]);
            }
            printf("\n");
        }

        // Sleep for a bit
        sleep(0.05);
    }

    // Game over!
    printf("Game over!\n");

    return 0;
}