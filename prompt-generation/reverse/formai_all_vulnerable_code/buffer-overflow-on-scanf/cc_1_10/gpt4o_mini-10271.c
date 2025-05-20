//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define GRAVITY 9.81   // Acceleration due to gravity (m/s^2)
#define TIME_STEP 0.1  // Time step for the simulation (seconds)
#define MAX_TIME 20.0  // Maximum time for the simulation (seconds)
#define SCREEN_WIDTH 50  // Width of the output screen

void clearScreen() {
    // Clear the console screen
    printf("\033[H\033[J");
}

void displayTrajectory(float initialVelocity, float angle) {
    float radians = angle * (M_PI / 180); // Convert degrees to radians
    float initialVelocityX = initialVelocity * cos(radians);
    float initialVelocityY = initialVelocity * sin(radians);

    float time = 0.0;
    float maxHeight = (initialVelocityY * initialVelocityY) / (2 * GRAVITY);
    float range = (initialVelocityX * 2 * initialVelocityY) / GRAVITY;

    printf("Max Height: %.2f m\n", maxHeight);
    printf("Range: %.2f m\n", range);
    printf("Projectile trajectory:\n\n");

    while (time <= MAX_TIME) {
        float x = initialVelocityX * time;                   // X position
        float y = initialVelocityY * time - (0.5 * GRAVITY * time * time); // Y position

        if (y < 0) {
            break; // Stop if the projectile hits the ground
        }

        int posY = (int)(y * 10); // Scale the Y value for display
        int posX = (int)(x / (range / SCREEN_WIDTH)); // Scale the X value for display

        printf("%*s", posX + 1, ""); // Print leading spaces for X position
        printf("o\n"); // Print the projectile position
        
        time += TIME_STEP; // Increment time
        usleep(50000); // Sleep for a short duration for better visualization
    }
    printf("\nSimulation completed.\n");
}

int main() {
    float initialVelocity, angle;

    printf("Welcome to the 2D Projectile Motion Simulator!\n");
    printf("Enter the initial velocity (m/s): ");
    if(scanf("%f", &initialVelocity) != 1 || initialVelocity <= 0) {
        fprintf(stderr, "Invalid input for initial velocity.\n");
        return 1;
    }

    printf("Enter the launch angle (degrees): ");
    if(scanf("%f", &angle) != 1 || angle < 0 || angle > 90) {
        fprintf(stderr, "Invalid input for angle.\n");
        return 1;
    }

    clearScreen();
    displayTrajectory(initialVelocity, angle);

    return 0;
}