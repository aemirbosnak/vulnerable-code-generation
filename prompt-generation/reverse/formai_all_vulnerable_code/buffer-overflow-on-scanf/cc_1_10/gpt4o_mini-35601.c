//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: ephemeral
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define GRAVITY 9.81 // Acceleration due to gravity (m/s^2)
#define TIME_STEP 0.1 // Time increment for simulation (seconds)

void calculateProjectileMotion(double initialVelocity, double angle) {
    double radianAngle = angle * (M_PI / 180.0);
    double velocityX = initialVelocity * cos(radianAngle);
    double velocityY = initialVelocity * sin(radianAngle);
    
    double timeOfFlight = (2 * velocityY) / GRAVITY;
    double range = velocityX * timeOfFlight;

    printf("Projectile Motion Simulation:\n");
    printf("Initial Velocity: %.2f m/s\n", initialVelocity);
    printf("Launch Angle: %.2f degrees\n", angle);
    printf("Time of Flight: %.2f seconds\n", timeOfFlight);
    printf("Range: %.2f meters\n\n", range);

    printf("Time (s)     | X Position (m) | Y Position (m)\n");
    printf("------------------------------------------------\n");

    for (double t = 0; t <= timeOfFlight; t += TIME_STEP) {
        double positionX = velocityX * t;
        double positionY = (velocityY * t) - (0.5 * GRAVITY * t * t);
        
        // Ensure that we don't print negative Y position after the projectile hits the ground
        if (positionY < 0) positionY = 0;

        printf("%-12.2f | %-15.2f | %-15.2f\n", t, positionX, positionY);
        usleep(200000); // Sleep for 0.2 seconds for a smoother output
    }

    printf("------------------------------------------------\n");
}

int main() {
    double initialVelocity;
    double angle;

    printf("Welcome to the Projectile Motion Simulator!\n");
    printf("Please enter the initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);
    printf("Please enter the launch angle (degrees): ");
    scanf("%lf", &angle);

    calculateProjectileMotion(initialVelocity, angle);

    return 0;
}