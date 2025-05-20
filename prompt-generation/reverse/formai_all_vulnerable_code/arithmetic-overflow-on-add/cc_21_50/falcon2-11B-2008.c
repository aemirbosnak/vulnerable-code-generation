//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define BALL_RADIUS 10
#define PADDLE_WIDTH 50
#define PADDLE_HEIGHT 200
#define PADDLE_SPEED 5
#define AI_PADDLE_SPEED -3
#define SCORE_WIDTH 100
#define SCORE_HEIGHT 50

typedef struct {
    int x;
    int y;
    int vx;
    int vy;
} Ball;

typedef struct {
    int x;
    int y;
    int vx;
    int vy;
} Paddle;

int main() {
    // Initialize game variables
    Ball ball;
    Paddle player, ai;
    int playerScore, aiScore;
    int screenWidth, screenHeight;
    int paddleWidth, paddleHeight, paddleSpeed, aiPaddleSpeed;
    int scoreWidth, scoreHeight;

    // Set up game window
    screenWidth = SCREEN_WIDTH;
    screenHeight = SCREEN_HEIGHT;
    scoreWidth = SCORE_WIDTH;
    scoreHeight = SCORE_HEIGHT;

    srand(time(NULL));

    // Set up paddles
    player.x = screenWidth / 2 - paddleWidth / 2;
    player.y = screenHeight - paddleHeight / 2;
    player.vx = 0;
    player.vy = 0;

    ai.x = screenWidth / 2 - paddleWidth / 2;
    ai.y = screenHeight - paddleHeight / 2;
    ai.vx = aiPaddleSpeed;
    ai.vy = 0;

    // Set up ball
    ball.x = screenWidth / 2 - BALL_RADIUS;
    ball.y = screenHeight / 2 - BALL_RADIUS;
    ball.vx = 0;
    ball.vy = 0;

    // Set up scores
    playerScore = 0;
    aiScore = 0;

    while (1) {
        // Clear screen
        printf("\033[2J");
        printf("\033[1;1H");

        // Update ball position
        ball.vx = ball.vx + ball.vy * 0.8;
        ball.vy = ball.vy - 0.5;
        ball.x += ball.vx;
        ball.y += ball.vy;

        // Update paddle positions
        if (player.x < 0 || player.x > screenWidth - paddleWidth || player.y < 0 || player.y > screenHeight - paddleHeight) {
            player.vy = -player.vy;
        }
        if (ai.x < 0 || ai.x > screenWidth - paddleWidth || ai.y < 0 || ai.y > screenHeight - paddleHeight) {
            ai.vy = -ai.vy;
        }
        player.x += player.vx;
        ai.x += ai.vx;

        // Update scores
        if (ball.y <= 0 || ball.y >= screenHeight - BALL_RADIUS) {
            ball.vy = -ball.vy;
        }
        if (ball.x <= 0 || ball.x >= screenWidth - BALL_RADIUS) {
            ball.vx = -ball.vx;
        }
        if (ball.x < paddleWidth / 2 && ball.x > -paddleWidth / 2 && ball.y < paddleHeight / 2 && ball.y > -paddleHeight / 2) {
            ball.vy = -ball.vy;
        }
        if (ball.x < 0 && ball.x > -paddleWidth / 2 && ball.y < 0 && ball.y > -paddleHeight / 2) {
            playerScore++;
        }
        if (ball.x > screenWidth - paddleWidth / 2 && ball.x < screenWidth - paddleWidth / 2 - BALL_RADIUS && ball.y < 0 && ball.y > -paddleHeight / 2) {
            aiScore++;
        }

        // Update scores on screen
        printf("Player: %d\nAI: %d\n", playerScore, aiScore);

        // Update ball and paddles positions
        printf("Ball x: %d, y: %d\n", ball.x, ball.y);
        printf("Player x: %d, y: %d, vx: %d, vy: %d\n", player.x, player.y, player.vx, player.vy);
        printf("AI x: %d, y: %d, vx: %d, vy: %d\n", ai.x, ai.y, ai.vx, ai.vy);

        // Update paddles positions
        printf("Paddle x: %d, y: %d, vx: %d, vy: %d\n", player.x, player.y, player.vx, player.vy);
        printf("AI Paddle x: %d, y: %d, vx: %d, vy: %d\n", ai.x, ai.y, ai.vx, ai.vy);

        // Update screen
        printf("\033[2J");
        printf("\033[1;1H");
        printf("\033[%d;%dH", 0, 0);
        printf("\033[1;%dm", ball.y);
        printf("\033[1;%dm", screenHeight - ball.y);
        printf("\033[1;%dm", ball.x);
        printf("\033[1;%dm", screenWidth - ball.x);
        printf("\033[1;%dm", player.x);
        printf("\033[1;%dm", player.y);
        printf("\033[1;%dm", ai.x);
        printf("\033[1;%dm", ai.y);
        printf("\033[1;%dm", playerScore);
        printf("\033[1;%dm", aiScore);

        // Sleep to slow down the game
        sleep(1);
    }
    return 0;
}