//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

#define PADDLE_SIZE 10

// Define the ball structure
typedef struct Ball {
    int x, y;
    int dx, dy;
} Ball;

// Define the paddle structure
typedef struct Paddle {
    int x, y;
    int dx, dy;
} Paddle;

// Function to initialize the ball
void initialize_ball(Ball *ball) {
    ball->x = WIDTH / 2;
    ball->y = HEIGHT / 2;
    ball->dx = 2;
    ball->dy = 1;
}

// Function to initialize the paddles
void initialize_paddles(Paddle *paddle1, Paddle *paddle2) {
    paddle1->x = 0;
    paddle1->y = HEIGHT - PADDLE_SIZE - 1;
    paddle1->dx = 0;
    paddle1->dy = -1;

    paddle2->x = WIDTH - PADDLE_SIZE - 1;
    paddle2->y = HEIGHT - PADDLE_SIZE - 1;
    paddle2->dx = 0;
    paddle2->dy = -1;
}

// Function to move the ball
void move_ball(Ball *ball) {
    ball->x += ball->dx * 0.01 * clock() / CLOCKS_PER_SEC;
    ball->y += ball->dy * 0.01 * clock() / CLOCKS_PER_SEC;
}

// Function to move the paddles
void move_paddles(Paddle *paddle1, Paddle *paddle2) {
    if (paddle1->y < 0) {
        paddle1->dy = 1;
    } else if (paddle1->y > HEIGHT - PADDLE_SIZE - 1) {
        paddle1->dy = -1;
    }

    if (paddle2->y < 0) {
        paddle2->dy = 1;
    } else if (paddle2->y > HEIGHT - PADDLE_SIZE - 1) {
        paddle2->dy = -1;
    }
}

// Function to check if the ball has hit a paddle
int check_collision(Ball *ball, Paddle *paddle1, Paddle *paddle2) {
    // Check if the ball has hit the left paddle
    if (ball->x + ball->dx < 0) {
        return 1;
    }

    // Check if the ball has hit the right paddle
    if (ball->x + ball->dx > WIDTH) {
        return 1;
    }

    // Check if the ball has hit the top paddle
    if (ball->y + ball->dy < 0) {
        return 1;
    }

    // Check if the ball has hit the bottom paddle
    if (ball->y + ball->dy > HEIGHT) {
        return 1;
    }

    return 0;
}

// Function to play the game
void play_game() {
    Ball ball;
    Paddle paddle1;
    Paddle paddle2;

    initialize_ball(&ball);
    initialize_paddles(&paddle1, &paddle2);

    while (!check_collision(&ball, &paddle1, &paddle2)) {
        move_ball(&ball);
        move_paddles(&paddle1, &paddle2);
        printf("%c", ball.x);
        printf("%c", ball.y);
        printf("\n");
    }

    printf("Game Over!");
}

int main() {
    play_game();

    return 0;
}