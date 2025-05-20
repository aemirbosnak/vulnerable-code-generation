//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define PI 3.14159265358979323846
#define WIDTH 800
#define HEIGHT 600

// Global variables
int ballX, ballY, ballXVel, ballYVel;
int paddle1X, paddle1Y, paddle1Vel, paddle2X, paddle2Y, paddle2Vel;
int score1, score2;

int main(void)
{
    // Initialize ball
    ballX = (WIDTH / 2) - 20;
    ballY = (HEIGHT / 2) - 20;
    ballXVel = 5;
    ballYVel = 5;

    // Initialize paddles
    paddle1X = WIDTH / 2 - 10;
    paddle1Y = (HEIGHT / 2) - 80;
    paddle1Vel = 0;
    paddle2X = WIDTH / 2 + 10;
    paddle2Y = (HEIGHT / 2) - 80;
    paddle2Vel = 0;

    // Initialize scores
    score1 = 0;
    score2 = 0;

    // Initialize clock
    clock_t start, end;
    double elapsed_time;
    start = clock();

    // Main game loop
    while(1)
    {
        // Draw background
        printf("*** Pong Game ***\n");
        printf("Press ESC to quit\n");
        printf("\n");
        printf("Paddle 1: Up/Down Arrow Keys\n");
        printf("Paddle 2: W/S Keys\n");
        printf("\n");

        // Clear screen
        system("clear");

        // Draw paddles
        printf("Paddle 1: (%d, %d)\n", paddle1X, paddle1Y);
        printf("Paddle 2: (%d, %d)\n", paddle2X, paddle2Y);

        // Update ball position
        ballX += ballXVel;
        ballY += ballYVel;

        // Check for ball at edges
        if(ballX <= 0)
        {
            ballXVel = -ballXVel;
        }
        else if(ballX >= WIDTH)
        {
            ballXVel = -ballXVel;
        }
        if(ballY <= 0)
        {
            ballYVel = -ballYVel;
        }
        else if(ballY >= HEIGHT)
        {
            ballYVel = -ballYVel;
        }

        // Check for ball at paddles
        if(ballY >= paddle1Y && ballY <= paddle1Y + 80)
        {
            ballYVel = -ballYVel;
        }
        if(ballY >= paddle2Y && ballY <= paddle2Y + 80)
        {
            ballYVel = -ballYVel;
        }

        // Check for ball at center
        if(abs(ballX - paddle1X) <= 30 && abs(ballX - paddle2X) <= 30)
        {
            score1++;
            score2++;
        }

        // Update paddles
        if(paddle1Vel > 0 && paddle1Y <= paddle1Y + 80)
        {
            paddle1Y += paddle1Vel;
        }
        if(paddle1Vel < 0 && paddle1Y >= 0)
        {
            paddle1Y += paddle1Vel;
        }
        if(paddle2Vel > 0 && paddle2Y <= paddle2Y + 80)
        {
            paddle2Y += paddle2Vel;
        }
        if(paddle2Vel < 0 && paddle2Y >= 0)
        {
            paddle2Y += paddle2Vel;
        }

        // Update paddle positions
        if(ballY >= paddle1Y && ballY <= paddle1Y + 80)
        {
            paddle1Vel = 5;
        }
        else
        {
            paddle1Vel = 0;
        }
        if(ballY >= paddle2Y && ballY <= paddle2Y + 80)
        {
            paddle2Vel = 5;
        }
        else
        {
            paddle2Vel = 0;
        }

        // Update ball position
        ballX += ballXVel;
        ballY += ballYVel;

        // Check for game over
        if(score1 == 10 || score2 == 10)
        {
            printf("Game Over!\n");
            break;
        }

        // Check for keypress
        if(getch() == 27)
        {
            break;
        }

        // Calculate elapsed time
        end = clock();
        elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Elapsed time: %.2f seconds\n", elapsed_time);
    }

    return 0;
}