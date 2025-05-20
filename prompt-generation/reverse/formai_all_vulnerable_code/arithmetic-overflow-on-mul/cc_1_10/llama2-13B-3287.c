//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 9.8
#define WORLD_SIZE 100

// Structure to represent a ball
typedef struct {
    float x, y, vx, vy; // position and velocity
} Ball;

// Function to simulate the physics of multiple balls
void simulate(Ball *balls, int num_balls) {
    for (int i = 0; i < num_balls; i++) {
        // Update position and velocity based on gravity and velocity
        balls[i].vx += GRAVITY;
        balls[i].vy += GRAVITY;

        // Apply collision detection and resolution
        for (int j = i + 1; j < num_balls; j++) {
            float dx = balls[i].x - balls[j].x;
            float dy = balls[i].y - balls[j].y;
            float dist = sqrt(dx * dx + dy * dy);

            if (dist < 5) {
                // Collision detected! Resolve the collision
                float angle = atan2(dy, dx);
                float v = sqrt(balls[i].vx * balls[i].vx + balls[j].vx * balls[j].vx);
                balls[i].vx = cos(angle) * v;
                balls[j].vx = cos(angle) * v;
                balls[i].vy = sin(angle) * v;
                balls[j].vy = sin(angle) * v;
            }
        }
    }
}

int main() {
    // Create an array of balls
    Ball balls[10];

    // Initialize the balls
    for (int i = 0; i < 10; i++) {
        balls[i].x = rand() % WORLD_SIZE;
        balls[i].y = rand() % WORLD_SIZE;
        balls[i].vx = 2 * rand() % WORLD_SIZE / 10;
        balls[i].vy = 2 * rand() % WORLD_SIZE / 10;
    }

    // Simulate the physics
    simulate(balls, 10);

    // Print the final positions of the balls
    for (int i = 0; i < 10; i++) {
        printf("Ball %d: (%f, %f)\n", i, balls[i].x, balls[i].y);
    }

    return 0;
}