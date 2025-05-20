//Falcon2-11B DATASET v1.0 Category: Breakout Game Clone ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rows, cols;
    int ball_x, ball_y, paddle_x, paddle_y;
    int bricks_x, bricks_y;

    printf("Welcome to the Breakout Game!\n");
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    ball_x = cols / 2;
    ball_y = rows / 2;
    paddle_x = cols - 1;
    paddle_y = rows - 1;
    bricks_x = cols / 2;
    bricks_y = rows / 2;

    // Game loop
    while (1) {
        // Draw the game elements
        printf("Rows: %d, Columns: %d\n", rows, cols);
        printf("Ball X: %d, Ball Y: %d\n", ball_x, ball_y);
        printf("Paddle X: %d, Paddle Y: %d\n", paddle_x, paddle_y);
        printf("Bricks X: %d, Bricks Y: %d\n", bricks_x, bricks_y);

        // Move the ball
        if (ball_x > paddle_x) {
            ball_x--;
        } else if (ball_x < paddle_x) {
            ball_x++;
        }

        // Move the paddle
        if (paddle_x > paddle_y) {
            paddle_x--;
        } else if (paddle_x < paddle_y) {
            paddle_x++;
        }

        // Check for collision with bricks
        if (ball_y == bricks_y && ball_x == bricks_x) {
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}