//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 5

int main() {

    int ballX, ballY, paddleX, paddleY;
    int score1, score2;
    int maxSpeed = 10;

    srand(time(NULL));

    ballX = RADIUS + 1;
    ballY = RADIUS + 1;

    paddleX = RADIUS + 1;
    paddleY = RADIUS + 1;

    while (1) {
        int direction = rand() % 2; // random direction for the ball
        if (direction == 0) {
            ballX -= maxSpeed;
        } else {
            ballX += maxSpeed;
        }

        if (ballX <= RADIUS) {
            ballX = RADIUS;
            direction = rand() % 2; // change direction of the ball if it hits the wall
        } else if (ballX >= 100 - RADIUS) {
            ballX = 100 - RADIUS;
            direction = rand() % 2;
        }

        if (ballX == paddleX && abs(ballY - paddleY) <= RADIUS) {
            ballX = RADIUS + 1;
            ballY = RADIUS + 1;
            direction = rand() % 2; // change direction of the ball if it hits the paddle
        }

        int opponent = rand() % 2; // random direction for the AI opponent
        if (opponent == 0) {
            paddleY -= maxSpeed;
        } else {
            paddleY += maxSpeed;
        }

        if (paddleY <= RADIUS) {
            paddleY = RADIUS;
            opponent = rand() % 2; // change direction of the AI opponent if it hits the wall
        } else if (paddleY >= 100 - RADIUS) {
            paddleY = 100 - RADIUS;
            opponent = rand() % 2;
        }

        if (paddleY == ballY && abs(paddleX - ballX) <= RADIUS) {
            score1++;
            ballX = RADIUS + 1;
            ballY = RADIUS + 1;
            direction = rand() % 2; // change direction of the ball if it hits the AI opponent
        }

        if (ballY == 100 - RADIUS) {
            score2++;
            ballX = RADIUS + 1;
            ballY = RADIUS + 1;
            direction = rand() % 2; // change direction of the ball if it hits the bottom wall
        }

        printf("Ball X: %d, Y: %d\nPaddle X: %d, Y: %d\nScore: Player 1: %d, Player 2: %d\n", ballX, ballY, paddleX, paddleY, score1, score2);
    }

    return 0;
}