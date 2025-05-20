//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 100
#define PADDLE_SPEED 5
#define BALL_WIDTH 5
#define BALL_HEIGHT 5
#define BALL_SPEED 2
#define AI_AI_SCORE 0
#define HUMAN_SCORE 1
#define LEFT 0
#define RIGHT 1
#define SCORE_WIDTH 10
#define SCORE_HEIGHT 10

int main() {
    srand(time(NULL));
    int humanScore = 0;
    int aiScore = 0;
    int paddlePosX[2] = {200, 600};
    int paddlePosY[2] = {350, 350};
    int ballX = 300;
    int ballY = 300;
    int paddleSpeed[2] = {0, 0};
    int paddleMove[2] = {0, 0};
    int paddleDirection[2] = {RIGHT, LEFT};
    int ballDirection = RIGHT;
    int gameOver = 0;

    while (!gameOver) {
        // Handle AI Move
        if (aiScore < 10 && aiScore > 0) {
            if (ballX <= paddlePosX[LEFT] && ballY <= paddlePosY[LEFT] && ballX >= paddlePosX[LEFT] + PADDLE_WIDTH && ballY >= paddlePosY[LEFT]) {
                paddleMove[LEFT] = PADDLE_SPEED;
                paddleDirection[LEFT] = RIGHT;
            } else if (ballX <= paddlePosX[RIGHT] && ballY <= paddlePosY[RIGHT] && ballX >= paddlePosX[RIGHT] + PADDLE_WIDTH && ballY >= paddlePosY[RIGHT]) {
                paddleMove[RIGHT] = PADDLE_SPEED;
                paddleDirection[RIGHT] = LEFT;
            } else {
                paddleMove[RIGHT] = -PADDLE_SPEED;
                paddleDirection[RIGHT] = RIGHT;
            }
        }

        // Handle Human Move
        scanf("%d", &paddleMove[HUMAN_SCORE]);

        // Handle Ball Movement
        if (ballDirection == RIGHT) {
            if (ballX <= SCORE_WIDTH - BALL_WIDTH) {
                ballX = SCORE_WIDTH - BALL_WIDTH;
                ballDirection = LEFT;
            } else {
                ballX += BALL_SPEED;
            }
        } else {
            if (ballX >= SCORE_WIDTH + BALL_WIDTH) {
                ballX = SCORE_WIDTH + BALL_WIDTH;
                ballDirection = RIGHT;
            } else {
                ballX += BALL_SPEED;
            }
        }

        if (ballY <= SCORE_HEIGHT - BALL_HEIGHT) {
            ballY = SCORE_HEIGHT - BALL_HEIGHT;
            ballDirection = RIGHT;
        } else {
            ballY += BALL_SPEED;
        }

        // Handle Paddle Movement
        if (paddlePosX[HUMAN_SCORE] < 0) {
            paddlePosX[HUMAN_SCORE] = 0;
        } else if (paddlePosX[HUMAN_SCORE] > SCORE_WIDTH) {
            paddlePosX[HUMAN_SCORE] = SCORE_WIDTH;
        }

        if (paddlePosY[HUMAN_SCORE] < 0) {
            paddlePosY[HUMAN_SCORE] = 0;
        } else if (paddlePosY[HUMAN_SCORE] > SCORE_HEIGHT) {
            paddlePosY[HUMAN_SCORE] = SCORE_HEIGHT;
        }

        if (paddleMove[HUMAN_SCORE] > 0) {
            paddlePosY[HUMAN_SCORE] += paddleMove[HUMAN_SCORE];
        } else {
            paddlePosY[HUMAN_SCORE] -= paddleMove[HUMAN_SCORE];
        }

        // Check for Collision
        if (ballX <= paddlePosX[HUMAN_SCORE] && ballY <= paddlePosY[HUMAN_SCORE] && ballX >= paddlePosX[HUMAN_SCORE] + PADDLE_WIDTH && ballY >= paddlePosY[HUMAN_SCORE]) {
            if (paddleDirection[HUMAN_SCORE] == RIGHT) {
                ballX = paddlePosX[HUMAN_SCORE] + PADDLE_WIDTH;
                ballY = paddlePosY[HUMAN_SCORE];
                ballDirection = RIGHT;
            } else {
                ballX = paddlePosX[HUMAN_SCORE];
                ballY = paddlePosY[HUMAN_SCORE] + PADDLE_HEIGHT;
                ballDirection = LEFT;
            }
        } else if (ballX <= paddlePosX[AI_AI_SCORE] && ballY <= paddlePosY[AI_AI_SCORE] && ballX >= paddlePosX[AI_AI_SCORE] + PADDLE_WIDTH && ballY >= paddlePosY[AI_AI_SCORE]) {
            if (paddleDirection[AI_AI_SCORE] == RIGHT) {
                ballX = paddlePosX[AI_AI_SCORE] + PADDLE_WIDTH;
                ballY = paddlePosY[AI_AI_SCORE];
                ballDirection = RIGHT;
            } else {
                ballX = paddlePosX[AI_AI_SCORE];
                ballY = paddlePosY[AI_AI_SCORE] + PADDLE_HEIGHT;
                ballDirection = LEFT;
            }
        }

        // Check for Game Over
        if (ballX <= 0 || ballX >= SCORE_WIDTH + BALL_WIDTH || ballY <= 0 || ballY >= SCORE_HEIGHT + BALL_HEIGHT) {
            gameOver = 1;
        }

        // Print Score
        printf("%d - %d\n", humanScore, aiScore);
        printf("     Score     ");
        for (int i = 0; i < SCORE_WIDTH; i++) {
            printf("_");
        }
        printf(" \n");
        printf("      1        2 \n");
        printf(" 0 %d %d %d \n", paddlePosX[HUMAN_SCORE], paddlePosX[AI_AI_SCORE], paddlePosY[HUMAN_SCORE] + paddlePosY[AI_AI_SCORE]);
        printf("   %d   %d   %d\n", ballX, ballY, ballDirection);
        printf("\n");

        // Reset Positions
        paddlePosX[HUMAN_SCORE] = 200;
        paddlePosX[AI_AI_SCORE] = 600;
        paddlePosY[HUMAN_SCORE] = 350;
        paddlePosY[AI_AI_SCORE] = 350;
        ballX = 300;
        ballY = 300;
        ballDirection = RIGHT;
        paddleMove[HUMAN_SCORE] = 0;
        paddleMove[AI_AI_SCORE] = 0;
        paddleDirection[HUMAN_SCORE] = RIGHT;
        paddleDirection[AI_AI_SCORE] = LEFT;
    }

    // Print Final Score
    printf("Game Over! Final Score: Human %d, AI %d\n", humanScore, aiScore);

    return 0;
}