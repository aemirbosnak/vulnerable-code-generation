//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define GRAVITY 9.81
#define TIME_STEP 0.1
#define FLOOR 0.0
#define BOUNCE_RATIO 0.8

typedef struct {
    double height;  // Height of the ball
    double velocity; // Velocity of the ball
    double time;     // Time simulation
} Ball;

void initializeBall(Ball *ball, double initialHeight, double initialVelocity) {
    ball->height = initialHeight;
    ball->velocity = initialVelocity;
    ball->time = 0.0;
}

void updateBall(Ball *ball) {
    ball->velocity -= GRAVITY * TIME_STEP; // update velocity due to gravity
    ball->height += ball->velocity * TIME_STEP; // update height based on velocity

    // Collision with the ground
    if (ball->height < FLOOR) {
        ball->height = FLOOR; // reset to the floor level
        ball->velocity = -ball->velocity * BOUNCE_RATIO; // reverse and reduce velocity for bounce
    }

    ball->time += TIME_STEP; // increase time
}

void displayBallHeight(double height) {
    int i;
    int totalHeight = 20; // total height for display scaling
    int scaledHeight = (int)(height / totalHeight * 20); // scale height for display
    scaledHeight = scaledHeight < 0 ? 0 : scaledHeight > 20 ? 20 : scaledHeight; 
    
    printf("\r");
    for (i = 0; i < 20; ++i) {
        if (i == totalHeight - scaledHeight) {
            printf("O"); // Ball position
        } else {
            printf(" ");
        }
    }
    fflush(stdout);
}

int main() {
    Ball ball;
    double initialHeight, initialVelocity;

    printf("Enter initial height (m): ");
    scanf("%lf", &initialHeight);
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);

    initializeBall(&ball, initialHeight, initialVelocity);

    printf("\nSimulating bouncing ball...\n");
    printf("Press Ctrl+C to stop the simulation.\n");

    while (1) {
        updateBall(&ball);
        displayBallHeight(ball.height);
        usleep(100000); // Sleep for 0.1 second (100 milliseconds)
    }

    return 0;
}