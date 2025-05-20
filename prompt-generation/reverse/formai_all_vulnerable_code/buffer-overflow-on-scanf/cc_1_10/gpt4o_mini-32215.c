//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: genius
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define G 9.81 // Acceleration due to gravity (m/s^2)
#define TIME_STEP 0.1 // Time step for the simulation (s)

void simulateProjectile(double initialVelocity, double launchAngle) {
    double angleRad = launchAngle * M_PI / 180.0; // Convert angle to radians
    double vx = initialVelocity * cos(angleRad); // Initial x velocity
    double vy = initialVelocity * sin(angleRad); // Initial y velocity

    double time = 0.0;
    double x = 0.0, y = 0.0;

    printf("Time(s) \t X(m) \t Y(m)\n");
    printf("------------------------------------\n");

    while (y >= 0) {
        printf("%.2f \t\t %.2f \t %.2f\n", time, x, y);
        
        // Update position
        x = vx * time;
        y = vy * time - 0.5 * G * pow(time, 2);
        
        // Wait to visualize the simulation (time step)
        usleep(500000); // Sleep for 0.5 seconds
        time += TIME_STEP;
    }

    printf("------------------------------------\n");
    printf("Projectile has hit the ground.\n");
}

int main() {
    double initialVelocity, launchAngle;

    printf("Welcome to the Projectile Motion Simulator!\n");
    printf("---------------------------------------------------------\n");

    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);
    printf("Enter launch angle (degrees): ");
    scanf("%lf", &launchAngle);

    if (initialVelocity <= 0 || launchAngle < 0 || launchAngle > 90) {
        printf("Invalid inputs! Ensure velocity > 0 and angle between 0 to 90 degrees.\n");
        return 1;
    }

    printf("Simulating projectile...\n");
    simulateProjectile(initialVelocity, launchAngle);

    return 0;
}