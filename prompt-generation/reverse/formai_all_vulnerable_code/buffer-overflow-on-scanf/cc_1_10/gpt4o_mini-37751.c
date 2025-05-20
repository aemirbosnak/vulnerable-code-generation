//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define GRAVITY 9.81
#define TIME_INCREMENT 0.1
#define MAX_TIME 10.0

void simulateProjectile(double initialVelocity, double launchAngle) {
    double angleRad = launchAngle * (M_PI / 180.0); // Convert degrees to radians
    double time = 0.0;
    double horizontalVelocity = initialVelocity * cos(angleRad);
    double verticalVelocity = initialVelocity * sin(angleRad);
    double maxHeight = (verticalVelocity * verticalVelocity) / (2 * GRAVITY);
    double range = (horizontalVelocity * (verticalVelocity + sqrt(verticalVelocity * verticalVelocity + 2 * GRAVITY * maxHeight))) / GRAVITY;

    printf("Initial Velocity: %.2f m/s\n", initialVelocity);
    printf("Launch Angle: %.2f degrees\n", launchAngle);
    printf("Maximum Height: %.2f m\n", maxHeight);
    printf("Range: %.2f m\n", range);
    printf("\nTime(s)\tX(m)\tY(m)\n");

    while (time <= MAX_TIME) {
        double x = horizontalVelocity * time;
        double y = (verticalVelocity * time) - (0.5 * GRAVITY * time * time);

        if (y < 0) {
            // Stop simulation if projectile hits the ground
            break;
        }

        printf("%.2f\t%.2f\t%.2f\n", time, x, y);
        time += TIME_INCREMENT;
        usleep(50000); // Slow down the output for better visibility
    }

    printf("\nProjectile simulation completed.\n");
}

int main() {
    double initialVelocity;
    double launchAngle;

    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);
    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &launchAngle);

    if (initialVelocity <= 0 || launchAngle < 0 || launchAngle > 90) {
        printf("Invalid parameters! Ensure velocity > 0 and angle between 0 and 90 degrees.\n");
        return 1;
    }

    simulateProjectile(initialVelocity, launchAngle);
    return 0;
}