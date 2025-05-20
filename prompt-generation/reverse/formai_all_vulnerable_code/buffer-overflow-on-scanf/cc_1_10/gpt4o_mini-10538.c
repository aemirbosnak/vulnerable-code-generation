//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: enthusiastic
#include <stdio.h>
#include <math.h>
#include <unistd.h> // For sleep function
#include <stdlib.h>

#define GRAVITY 9.81 // Acceleration due to gravity (m/s^2)
#define TIME_STEP 0.1 // Time increment for simulation (seconds)
#define MAX_HEIGHT 20 // Maximum height displayed on the graph
#define MAX_DISTANCE 100 // Maximum distance displayed on the graph

void drawProjectilePath(float angle, float speed) {
    float radianAngle = angle * (M_PI / 180.0); // Convert angle to radians
    float timeOfFlight = (2 * speed * sin(radianAngle)) / GRAVITY; // Total time of flight
    int steps = (int)(timeOfFlight / TIME_STEP) + 1; // Number of steps in the simulation

    printf("\nSimulating Projectile Motion!\n");
    printf("Angle: %.2f degrees\n", angle);
    printf("Initial Speed: %.2f m/s\n", speed);
    printf("Total flight time: %.2f seconds\n\n", timeOfFlight);

    float x, y;
    for (int i = 0; i < steps; i++) {
        float t = i * TIME_STEP;
        x = speed * cos(radianAngle) * t; // Horizontal distance
        y = speed * sin(radianAngle) * t - (0.5 * GRAVITY * t * t); // Vertical distance

        // Break out of the loop if the projectile hits the ground
        if (y < 0) break;

        // Print the trajectory
        int heightIndicator = (int)(y / (MAX_HEIGHT / 10)); // Scale height for display
        int distanceIndicator = (int)(x / (MAX_DISTANCE / 70)); // Scale distance for display

        // Print spaces before the projectile position
        for (int j = 0; j < distanceIndicator; j++) {
            printf(" ");
        }
        printf("*\n");

        // Sleep for a while to visualize the motion
        usleep(100000); // 100 milliseconds
    }
    printf("\nSimulation complete!\n");
}

int main() {
    float angle, speed;

    // Enthusiastic introduction
    printf("***********************************************************\n");
    printf("                      Projectile Motion Simulator            \n");
    printf("***********************************************************\n");
    printf("Welcome! Let's launch a projectile and see its glorious flight!\n\n");

    // Get input from the user
    printf("Please enter the launch angle (in degrees): ");
    scanf("%f", &angle);
    printf("Please enter the launch speed (in m/s): ");
    scanf("%f", &speed);

    // Validate user input to avoid unrealistic scenarios
    if (angle < 0 || angle > 90 || speed <= 0) {
        printf("Invalid input! Make sure it's 0 < angle <= 90 degrees and speed > 0.\n");
        return 1; // Exit with error
    }

    // Call the simulation function
    drawProjectilePath(angle, speed);

    return 0;
}