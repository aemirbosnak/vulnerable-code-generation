//Falcon2-11B DATASET v1.0 Category: Breakout Game Clone ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define PADDING 10

int main() {
    int numBlocks;
    printf("Enter the number of blocks: ");
    scanf("%d", &numBlocks);

    int ballSpeedX = 4;
    int ballSpeedY = -3;

    int x = WIDTH / 2 - PADDING;
    int y = HEIGHT / 2 - PADDING;

    int paddleX = WIDTH / 2 + PADDING;
    int paddleY = HEIGHT / 2 - PADDING;

    int paddleSpeed = 0;

    int score = 0;

    while (1) {
        printf("Enter the paddle movement direction (left or right): ");
        char direction;
        scanf(" %c", &direction);

        if (direction == 'l') {
            paddleSpeed = -5;
        } else if (direction == 'r') {
            paddleSpeed = 5;
        } else {
            paddleSpeed = 0;
        }

        if (x + paddleSpeed >= 0 && x + paddleSpeed <= WIDTH) {
            x += paddleSpeed;
        } else {
            paddleSpeed = 0;
        }

        if (y + paddleSpeed >= 0 && y + paddleSpeed <= HEIGHT) {
            y += paddleSpeed;
        } else {
            paddleSpeed = 0;
        }

        if (y < PADDING) {
            y = PADDING;
        } else if (y > HEIGHT - PADDING) {
            y = HEIGHT - PADDING;
        }

        if (x < PADDING) {
            x = PADDING;
        } else if (x > WIDTH - PADDING) {
            x = WIDTH - PADDING;
        }

        if (x >= paddleX && abs(x - paddleX) <= PADDING) {
            ballSpeedX *= -1;
        } else if (y >= paddleY && abs(y - paddleY) <= PADDING) {
            ballSpeedY *= -1;
        }

        if (x < paddleX && abs(x - paddleX) <= PADDING) {
            ballSpeedX *= -1;
        } else if (y < paddleY && abs(y - paddleY) <= PADDING) {
            ballSpeedY *= -1;
        }

        x += ballSpeedX;
        y += ballSpeedY;

        if (x < 0 || x > WIDTH) {
            ballSpeedX *= -1;
        } else if (y < 0 || y > HEIGHT) {
            ballSpeedY *= -1;
        }

        if (y < 0) {
            score++;
        }

        printf("Score: %d\n", score);

        if (score == numBlocks) {
            break;
        }
    }

    printf("Game over!\n");

    return 0;
}