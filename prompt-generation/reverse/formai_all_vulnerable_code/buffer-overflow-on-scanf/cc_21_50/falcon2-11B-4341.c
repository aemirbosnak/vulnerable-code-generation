//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PADDLE_HEIGHT 100
#define MAX_PADDLE_WIDTH 10
#define PADDLE_SPEED 5
#define BALL_SPEED 10

#define MAX_LEFT_PADDLE 0
#define MAX_RIGHT_PADDLE 1

int main() {
    srand(time(NULL));
    int paddleHeight = MAX_PADDLE_HEIGHT;
    int paddleWidth = MAX_PADDLE_WIDTH;
    int paddleX = MAX_PADDLE_WIDTH / 2;
    int paddleY = MAX_PADDLE_HEIGHT / 2;
    int ballX = MAX_PADDLE_WIDTH / 2;
    int ballY = MAX_PADDLE_HEIGHT / 2;
    int leftPaddle = MAX_LEFT_PADDLE;
    int rightPaddle = MAX_RIGHT_PADDLE;
    int scoreLeft = 0;
    int scoreRight = 0;

    while (1) {
        // Handle input
        printf("Hit 'l' to move left paddle up, 'j' to move left paddle down, "
               "'k' to move right paddle up, 'i' to move right paddle down.\n");
        printf("Hit 'q' to quit.\n");
        scanf(" %c %c %c %c", &leftPaddle, &rightPaddle, &scoreLeft, &scoreRight);

        if (leftPaddle == 'l' || leftPaddle == 'j') {
            if (paddleHeight > 0) {
                paddleHeight--;
            }
        }
        if (leftPaddle == 'k' || leftPaddle == 'i') {
            if (paddleHeight < MAX_PADDLE_HEIGHT) {
                paddleHeight++;
            }
        }
        if (rightPaddle == 'l' || rightPaddle == 'j') {
            if (paddleHeight > 0) {
                paddleHeight--;
            }
        }
        if (rightPaddle == 'k' || rightPaddle == 'i') {
            if (paddleHeight < MAX_PADDLE_HEIGHT) {
                paddleHeight++;
            }
        }

        // Move paddles
        if (leftPaddle == 'l') {
            paddleY -= PADDLE_SPEED;
        }
        if (leftPaddle == 'k') {
            paddleY += PADDLE_SPEED;
        }
        if (rightPaddle == 'l') {
            paddleY -= PADDLE_SPEED;
        }
        if (rightPaddle == 'k') {
            paddleY += PADDLE_SPEED;
        }

        // Move ball
        if (ballY < 0) {
            ballY = 0;
            ballX = (rand() % MAX_PADDLE_WIDTH) + MAX_PADDLE_WIDTH / 2;
        } else if (ballY > MAX_PADDLE_HEIGHT) {
            ballY = MAX_PADDLE_HEIGHT;
            ballX = (rand() % MAX_PADDLE_WIDTH) + MAX_PADDLE_WIDTH / 2;
        } else {
            ballX += BALL_SPEED;
        }

        // Check for collision
        if (ballX < 0 || ballX > MAX_PADDLE_WIDTH || ballY < 0 || ballY > MAX_PADDLE_HEIGHT) {
            ballX = (rand() % MAX_PADDLE_WIDTH) + MAX_PADDLE_WIDTH / 2;
            ballY = (rand() % MAX_PADDLE_HEIGHT) + MAX_PADDLE_HEIGHT / 2;
        } else {
            if (ballX < paddleX) {
                if (ballY < paddleY + paddleHeight && ballY + BALL_SPEED > paddleY) {
                    ballY = paddleY + paddleHeight;
                    ballX = (rand() % MAX_PADDLE_WIDTH) + MAX_PADDLE_WIDTH / 2;
                }
            } else if (ballX > paddleX + paddleWidth) {
                if (ballY < paddleY + paddleHeight && ballY + BALL_SPEED > paddleY) {
                    ballY = paddleY + paddleHeight;
                    ballX = (rand() % MAX_PADDLE_WIDTH) + MAX_PADDLE_WIDTH / 2;
                }
            } else {
                if (ballY < paddleY + paddleHeight && ballY + BALL_SPEED > paddleY) {
                    ballY = paddleY + paddleHeight;
                    ballX = (rand() % MAX_PADDLE_WIDTH) + MAX_PADDLE_WIDTH / 2;
                }
            }
        }

        // Update scores
        if (ballY < 0) {
            scoreLeft++;
        } else if (ballY > MAX_PADDLE_HEIGHT) {
            scoreRight++;
        }

        // Print scores
        printf("Score Left: %d, Score Right: %d\n", scoreLeft, scoreRight);

        // Delay
        sleep(1);
    }
    return 0;
}