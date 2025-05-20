//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: protected
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define GRAVITY 9.81 // Acceleration due to gravity (m/s^2)
#define TIME_INCREMENT 0.1 // Time step for simulation (seconds)

void simulateProjectile(double initialVelocity, double launchAngle) {
    // Calculating initial components of velocity
    double angleInRadians = launchAngle * (M_PI / 180.0); // Convert degrees to radians
    double vx = initialVelocity * cos(angleInRadians); // Initial horizontal velocity
    double vy = initialVelocity * sin(angleInRadians); // Initial vertical velocity

    // Initialize position
    double x = 0.0;  // Horizontal position
    double y = 0.0;  // Vertical position
    double time = 0.0;

    printf("Simulating projectile motion...\n");
    printf("Initial Velocity: %.2f m/s\n", initialVelocity);
    printf("Launch Angle: %.2f degrees\n", launchAngle);
    printf("--------------------------------------------------\n");
    printf("Time(s) \t X(m) \t Y(m)\n");
    printf("--------------------------------------------------\n");

    // Simulate projectile motion
    while (y >= 0) {
        // Update positions
        x = vx * time; // Horizontal position
        y = vy * time - 0.5 * GRAVITY * time * time; // Vertical position

        if (y < 0) {
            y = 0; // Ensure y does not go below 0
        }

        printf("%.2f \t %.2f \t %.2f\n", time, x, y);
        time += TIME_INCREMENT; // Increment time
    }

    printf("--------------------------------------------------\n");
    printf("Projectile hit the ground!\n");
}

int main() {
    double initialVelocity;
    double launchAngle;

    printf("Welcome to the Projectile Motion Simulator!\n");
    printf("Please enter the initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);

    printf("Please enter the launch angle (degrees): ");
    scanf("%lf", &launchAngle);

    if (initialVelocity <= 0 || launchAngle < 0 || launchAngle > 90) {
        printf("Invalid input! Please enter a positive velocity and an angle between 0 and 90 degrees.\n");
        return 1;
    }

    // Start simulation
    simulateProjectile(initialVelocity, launchAngle);

    return 0;
}