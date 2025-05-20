//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 11
#define BALL_SIZE 5

#define PLAYER_1_COLOR "Red"
#define PLAYER_2_COLOR "Blue"

// Define the ball structure
typedef struct Ball {
    int x;
    int y;
    int dx;
    int dy;
} Ball;

// Define the paddle structure
typedef struct Paddle {
    int x;
    int y;
    int width;
    int height;
} Paddle;

// Function to initialize the ball
void initialize_ball(Ball *ball) {
    ball->x = BOARD_SIZE / 2;
    ball->y = BOARD_SIZE / 2;
    ball->dx = rand() % 2 ? 1 : -1;
    ball->dy = rand() % 2 ? 1 : -1;
}

// Function to move the ball
void move_ball(Ball *ball) {
    ball->x += ball->dx * 0.05;
    ball->y += ball->dy * 0.05;

    // Boundary checks
    if (ball->x < 0 || ball->x >= BOARD_SIZE) {
        ball->dx *= -1;
    }
    if (ball->y < 0 || ball->y >= BOARD_SIZE) {
        ball->dy *= -1;
    }
}

// Function to move the paddle
void move_paddle(Paddle *paddle, int direction) {
    switch (direction) {
        case 1:
            paddle->y -= 1;
            break;
        case 2:
            paddle->y += 1;
            break;
    }

    // Boundary checks
    if (paddle->y < 0) {
        paddle->y = 0;
    }
    if (paddle->y >= BOARD_SIZE - paddle->height) {
        paddle->y = BOARD_SIZE - paddle->height;
    }
}

// Function to check if the ball has hit the paddle
int has_ball_hit_paddle(Ball *ball, Paddle *paddle) {
    // Check if the ball is within the paddle's bounds
    if (ball->x >= paddle->x && ball->x <= paddle->x + paddle->width && ball->y >= paddle->y && ball->y <= paddle->y + paddle->height) {
        return 1;
    }

    return 0;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the ball and paddle structures
    Ball ball;
    initialize_ball(&ball);

    Paddle paddle_1;
    paddle_1.x = 0;
    paddle_1.y = BOARD_SIZE / 2 - paddle_1.height;
    paddle_1.width = 5;
    paddle_1.height = 100;

    Paddle paddle_2;
    paddle_2.x = BOARD_SIZE - paddle_2.width;
    paddle_2.y = BOARD_SIZE / 2 - paddle_2.height;
    paddle_2.width = 5;
    paddle_2.height = 100;

    // Game loop
    int game_over = 0;
    while (!game_over) {
        // Move the ball
        move_ball(&ball);

        // Check if the ball has hit the paddle
        if (has_ball_hit_paddle(&ball, &paddle_1) || has_ball_hit_paddle(&ball, &paddle_2)) {
            // Change the ball's direction
            ball.dx *= -1;
        }

        // Move the paddle
        move_paddle(&paddle_1, 1);
        move_paddle(&paddle_2, 2);

        // Check if the ball has hit the boundary
        if (ball.x < 0 || ball.x >= BOARD_SIZE) {
            game_over = 1;
        }

        // Display the game state
        printf("%s paddle at (%d, %d)\n", PLAYER_1_COLOR, paddle_1.x, paddle_1.y);
        printf("%s paddle at (%d, %d)\n", PLAYER_2_COLOR, paddle_2.x, paddle_2.y);
        printf("Ball at (%d, %d)\n", ball.x, ball.y);
    }

    // Game over message
    printf("Game over!\n");

    return 0;
}