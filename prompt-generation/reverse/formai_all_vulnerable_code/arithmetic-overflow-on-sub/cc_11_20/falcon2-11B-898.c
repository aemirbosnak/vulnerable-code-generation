//Falcon2-11B DATASET v1.0 Category: Breakout Game Clone ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ballX, ballY, paddleX, paddleY, ballSpeedX, ballSpeedY, paddleSpeed;
    int width, height, brickX, brickY, brickWidth, brickHeight;
    int score, gameOver = 0;

    // Set up the game screen
    srand(time(NULL));
    width = 800;
    height = 600;
    brickX = (width - (brickWidth * 4)) / 2;
    brickY = (height - (brickHeight * 4)) / 2;
    brickWidth = 50;
    brickHeight = 20;

    // Initialize ball and paddle positions
    ballX = (width - (brickWidth * 4)) / 2;
    ballY = (height - (brickHeight * 4)) / 2;
    paddleX = (width - (brickWidth * 4)) / 2;
    paddleY = height - (brickHeight * 4);
    ballSpeedX = 3;
    ballSpeedY = 2;
    paddleSpeed = 10;

    // Start the game
    while (!gameOver) {
        // Move the ball
        ballX += ballSpeedX;
        ballY += ballSpeedY;

        // Move the paddle
        paddleX += paddleSpeed;

        // Check for collisions
        if (ballY <= 0 || ballY >= height - brickHeight) {
            ballSpeedY = -ballSpeedY;
        }
        if (ballX <= 0 || ballX >= width - brickWidth) {
            ballSpeedX = -ballSpeedX;
        }
        if (paddleX <= 0 || paddleX >= width - brickWidth) {
            paddleSpeed = -paddleSpeed;
        }

        // Check for collisions with bricks
        if (ballX <= (brickX + brickWidth / 2) && ballX >= brickX && ballY <= (brickY + brickHeight) && ballY >= brickY - brickHeight) {
            ballSpeedY = -ballSpeedY;
            ballSpeedX = rand() % 2 == 0? -ballSpeedX : ballSpeedX;
            score++;
        }

        // Draw the game screen
        printf("Score: %d\n", score);
        printf("Game Over: %d\n", gameOver);
        printf("Ball X: %d\n", ballX);
        printf("Ball Y: %d\n", ballY);
        printf("Paddle X: %d\n", paddleX);
        printf("Paddle Y: %d\n", paddleY);
        printf("Ball Speed X: %d\n", ballSpeedX);
        printf("Ball Speed Y: %d\n", ballSpeedY);
        printf("Paddle Speed: %d\n", paddleSpeed);
        printf("Brick X: %d\n", brickX);
        printf("Brick Y: %d\n", brickY);
        printf("Brick Width: %d\n", brickWidth);
        printf("Brick Height: %d\n", brickHeight);
        printf("Width: %d\n", width);
        printf("Height: %d\n", height);

        // Pause for 10 milliseconds
        sleep(10);
    }

    // End the game
    printf("Game Over!\n");
    return 0;
}