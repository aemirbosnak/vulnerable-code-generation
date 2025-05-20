//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board dimensions
#define WIDTH 10
#define HEIGHT 20

// Define the positions of the paddle and ball
int paddleX = WIDTH / 2;
int ballX = WIDTH / 2;
int ballY = HEIGHT - 2;

// Define the velocity of the ball
int ballVX = 1;
int ballVY = -1;

// Define the brick layout
int bricks[WIDTH][HEIGHT / 2];

// Boolean to check if game is over
int gameOver = 0;

// Function to initialize the bricks
void initBricks() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT / 2; j++) {
            bricks[i][j] = rand() % 2;
        }
    }
}

// Function to draw the game board
void drawBoard() {
    // Clear the screen
    system("clear");

    // Draw the bricks
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT / 2; j++) {
            if (bricks[i][j] == 1) {
                printf("[]");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Draw the paddle
    for (int i = 0; i < WIDTH; i++) {
        if (i == paddleX) {
            printf("==");
        } else {
            printf("  ");
        }
    }
    printf("\n");

    // Draw the ball
    for (int i = 0; i < WIDTH; i++) {
        if (i == ballX) {
            printf(" O");
        } else {
            printf("  ");
        }
    }
    printf("\n");
}

// Function to update the position of the ball
void updateBall() {
    // Update the x position of the ball
    ballX += ballVX;

    // Reverse the x velocity if the ball hits a wall
    if (ballX == 0 || ballX == WIDTH - 1) {
        ballVX *= -1;
    }

    // Update the y position of the ball
    ballY += ballVY;

    // Reverse the y velocity if the ball hits a wall or paddle
    if (ballY == 0 || (ballY == HEIGHT - 1 && ballX == paddleX)) {
        ballVY *= -1;
    }

    // End the game if the ball hits the bottom wall
    if (ballY == HEIGHT - 1) {
        gameOver = 1;
    }

    // Destroy brick if ball hits it
    if (ballY >= 0 && ballY < HEIGHT / 2 && bricks[ballX][ballY] == 1) {
        bricks[ballX][ballY] = 0;
        ballVY *= -1;
    }
}

// Function to move the paddle
void movePaddle(char direction) {
    if (direction == 'L') {
        if (paddleX > 0) {
            paddleX--;
        }
    } else if (direction == 'R') {
        if (paddleX < WIDTH - 1) {
            paddleX++;
        }
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the bricks
    initBricks();

    // Game loop
    while (!gameOver) {
        // Draw the game board
        drawBoard();

        // Update the position of the ball
        updateBall();

        // Get user input
        printf("Move paddle left (L) or right (R): ");
        char input;
        scanf("%c", &input);

        // Move the paddle
        movePaddle(input);
    }

    printf("Game Over\n");

    return 0;
}