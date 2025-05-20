//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 5
#define MAX_HEIGHT 5

// Define the breakout game board
char board[MAX_WIDTH][MAX_HEIGHT] = {
    {' ',' ',' ',' ', ' ', ' '},
    {' ', '#', '#', '#', ' ', ' '},
    {' ', '#', '#', '#', '#', ' '},
    {' ', '#', '#', '#', '#', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '}
};

// Define the paddle position
int paddle_x = MAX_WIDTH / 2;
int paddle_y = MAX_HEIGHT - 1;

// Define the ball position
int ball_x = 0;
int ball_y = MAX_HEIGHT - 1;

// Define the ball speed
int ball_dx = 1;
int ball_dy = -1;

// Game loop flag
int is_game_on = 1;

void draw_board() {
    for (int y = 0; y < MAX_HEIGHT; y++) {
        for (int x = 0; x < MAX_WIDTH; x++) {
            printf("%c ", board[x][y]);
        }
        printf("\n");
    }
}

void move_paddle() {
    // Check if the paddle is moving too far to the left or right
    if (paddle_x < 0) {
        paddle_x = 0;
    } else if (paddle_x >= MAX_WIDTH - 1) {
        paddle_x = MAX_WIDTH - 1;
    }

    // Move the paddle
    board[paddle_x][paddle_y] = 'P';
    board[paddle_x][paddle_y - 1] = ' ';
}

void move_ball() {
    // Update the ball position
    ball_x += ball_dx;
    ball_y += ball_dy;

    // Check if the ball has hit a wall
    if (ball_x < 0 || ball_x >= MAX_WIDTH) {
        ball_dx *= -1;
    }
    if (ball_y < 0) {
        ball_dy *= -1;
    }

    // Check if the ball has hit the paddle
    if (ball_x >= paddle_x && ball_x <= paddle_x + 1 && ball_y == paddle_y) {
        ball_dx *= -1;
    }

    // Update the board
    board[ball_x][ball_y] = 'B';
    board[ball_x][ball_y - 1] = ' ';
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Game loop
    while (is_game_on) {
        draw_board();
        move_paddle();
        move_ball();

        // Check if the ball has hit the top of the screen
        if (ball_y == 0) {
            is_game_on = 0;
        }
    }

    // Game over message
    printf("Game over!\n");

    return 0;
}