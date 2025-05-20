//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: detailed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 9.81  // Acceleration due to gravity (m/s^2)
#define TIME_STEP 0.1  // Time step for simulation updates

// Structure to represent a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the projectile motion
void simulateProjectileMotion(double initialVelocity, double launchAngle, double timeOfFlight) {
    double angleInRadians = launchAngle * M_PI / 180.0;  // Convert angle to radians
    double initialVelocityX = initialVelocity * cos(angleInRadians);
    double initialVelocityY = initialVelocity * sin(angleInRadians);

    double time = 0.0;
    Point position;

    printf("Simulating projectile motion...\n");
    printf("Initial Velocity: %.2f m/s, Launch Angle: %.2f degrees\n", initialVelocity, launchAngle);
    printf("Time of Flight: %.2f seconds\n", timeOfFlight);
    printf("Projectile Path:\n");

    // Loop through time until we reach the time of flight
    while (time <= timeOfFlight) {
        // Update position based on equations of motion
        position.x = initialVelocityX * time;
        position.y = initialVelocityY * time - (0.5 * G * time * time);

        // Print the position with a simple visual representation
        int horizontalPosition = (int)(position.x * 0.1);  // Scale down for console output
        int verticalPosition = (int)(position.y * 0.1);
        
        // Print space for horizontal movement
        for (int i = 0; i < horizontalPosition; i++) {
            printf(" ");
        }
        
        // Print the projectile's position in the vertical plane
        if (verticalPosition >= 0) {
            printf("*\n");
        } else {
            printf("\n"); // If below ground, just print a newline.
        }

        time += TIME_STEP;  // Increment time by the time step
    }

    printf("Simulation Ended.\n");
}

int main() {
    double initialVelocity;
    double launchAngle;

    // Prompt for initial velocity and launch angle
    printf("Enter the initial velocity of the projectile (in m/s): ");
    scanf("%lf", &initialVelocity);
    
    printf("Enter the launch angle (in degrees): ");
    scanf("%lf", &launchAngle);

    // Calculate time of flight using the formula: T = (2 * V*sin(θ))/g
    double timeOfFlight = (2 * initialVelocity * sin(launchAngle * M_PI / 180.0)) / G;

    // Call the simulation function
    simulateProjectileMotion(initialVelocity, launchAngle, timeOfFlight);

    return 0;
}