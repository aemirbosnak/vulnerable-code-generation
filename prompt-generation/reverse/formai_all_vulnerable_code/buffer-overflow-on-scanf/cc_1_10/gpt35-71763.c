//FormAI DATASET v1.0 Category: Physics simulation ; Style: introspective
#include<stdio.h>
#include<math.h>

/*
This is a program that simulates the motion of a projectile fired from a cannon.
The user inputs the initial velocity and angle of the projectile and the program
calculates the trajectory of the projectile using basic physics equations.
*/

int main() {

    // Input variables
    double initVelocity, angle;

    // Simulation variables
    double time = 0;
    double x, y;
    double xVelocity, yVelocity;
    double xAcceleration = 0, yAcceleration = -9.81;

    // Prompt user for input
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &initVelocity);
    printf("Enter the angle of fire (degrees): ");
    scanf("%lf", &angle);

    // Convert angle to radians
    angle = angle * M_PI / 180;

    // Calculate velocities
    xVelocity = initVelocity * cos(angle);
    yVelocity = initVelocity * sin(angle);

    // Print simulation header
    printf("\nTime\tX-Position\tY-Position\n");

    // Simulation loop
    while (y >= 0) {

        x = xVelocity * time;
        y = (yVelocity * time) + (0.5 * yAcceleration * pow(time, 2));

        // Print simulation data
        printf("%.2lf\t%.2lf\t%.2lf\n", time, x, y);

        // Update time
        time += 0.1;

    }

    // Print final position
    printf("\nProjectile landed at (%.2lf, 0)\n", x);

    return 0;
}