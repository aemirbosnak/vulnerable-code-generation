//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: safe
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

#define BALL_X 2
#define BALL_Y 2

#define PADDLE_X 1
#define PADDLE_Y 0

#define SPEED 5

int main() {
    int x, y, ball_x, ball_y, paddle_x, paddle_y, score = 0;
    char board[HEIGHT][WIDTH] = {{0}};

    // Initialize the board
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            board[y][x] = ' ';
        }
    }

    // Place the paddle
    board[paddle_y][paddle_x] = 'P';

    // Place the ball
    board[ball_y][ball_x] = 'B';

    // Game loop
    while (!board[ball_y][ball_x] == 'O') {
        // Get the direction of the ball
        int dx = rand() % 2 - 1;
        int dy = rand() % 2 - 1;

        // Move the ball
        ball_x += dx * SPEED;
        ball_y += dy * SPEED;

        // Check if the ball has hit a wall
        if (ball_x < 0 || ball_x >= WIDTH) {
            dx *= -1;
        }
        if (ball_y < 0 || ball_y >= HEIGHT) {
            dy *= -1;
        }

        // Update the board
        board[ball_y][ball_x] = 'B';
        board[paddle_y][paddle_x] = 'P';

        // Display the board
        for (x = 0; x < WIDTH; x++) {
            for (y = 0; y < HEIGHT; y++) {
                printf("%c ", board[y][x]);
            }
            printf("\n");
        }

        // Check if the ball has hit the paddle
        if (board[ball_y][ball_x] == 'P') {
            score++;
            ball_x = BALL_X;
            ball_y = BALL_Y;
        }
    }

    // Game over
    printf("Game over! Your score is: %d", score);

    return 0;
}