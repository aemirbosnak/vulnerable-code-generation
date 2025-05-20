//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width, height, ballX, ballY, paddleX, paddleY;
    int ballXSpeed, ballYSpeed;
    int paddleXSpeed, paddleYSpeed;
    int randomSpeed = rand() % 10 + 1;
    int randomDirection = rand() % 2 + 1;

    printf("Welcome to Pong!n");

    printf("Enter the width of the game screen: ");
    scanf("%d", &width);
    printf("Enter the height of the game screen: ");
    scanf("%d", &height);

    printf("Enter the starting position of the ball (x, y): ");
    scanf("%d %d", &ballX, &ballY);
    printf("Enter the starting position of the paddle (x, y): ");
    scanf("%d %d", &paddleX, &paddleY);

    printf("Enter the initial speed of the ball (x, y): ");
    scanf("%d %d", &ballXSpeed, &ballYSpeed);
    printf("Enter the initial speed of the paddle (x, y): ");
    scanf("%d %d", &paddleXSpeed, &paddleYSpeed);

    printf("Enter the random speed modifier (1-10): ");
    scanf("%d", &randomSpeed);
    printf("Enter the random direction modifier (0 or 1): ");
    scanf("%d", &randomDirection);

    while (1) {
        if (randomDirection == 0) {
            ballXSpeed += randomSpeed;
            ballYSpeed += randomSpeed;
        } else {
            ballXSpeed -= randomSpeed;
            ballYSpeed -= randomSpeed;
        }

        ballX += ballXSpeed;
        ballY += ballYSpeed;

        paddleX += paddleXSpeed;
        paddleY += paddleYSpeed;

        if (ballY < 0 || ballY > height - 1) {
            ballYSpeed *= -1;
        }

        if (paddleX < 0) {
            paddleX = 0;
        }

        if (paddleX > width - 1) {
            paddleX = width - 1;
        }

        if (ballX < paddleX && ballX > paddleX - 1 && ballY < paddleY + 1 && ballY > paddleY) {
            ballYSpeed *= -1;
            ballXSpeed *= -1;
        }

        printf("Ball x: %d, y: %d\n", ballX, ballY);
        printf("Paddle x: %d, y: %d\n", paddleX, paddleY);

        if (ballX == width - 1 || ballX == 0) {
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}