//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: mathematical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 9.81 // Acceleration due to gravity (m/s^2)
#define TIME_STEP 0.1 // Time step for the simulation (seconds)

void print_trajectory(double initial_velocity, double angle) {
    // Converting angle to radians
    double angle_rad = angle * (M_PI / 180.0);
    
    // Initial velocities in x and y directions
    double vx = initial_velocity * cos(angle_rad);
    double vy = initial_velocity * sin(angle_rad);
    
    // Initial positions
    double x = 0.0;
    double y = 0.0;

    printf("Time (s)\tX Position (m)\tY Position (m)\n");
    printf("--------------------------------------------------\n");

    // Updating position over time until the projectile hits the ground
    for (double t = 0; y >= 0; t += TIME_STEP) {
        // Update position
        x = vx * t;
        y = vy * t - (0.5 * G * t * t);

        // Print the current state
        printf("%.2f\t\t%.2f\t\t%.2f\n", t, x, fmax(0, y)); // Ensure y doesn't go below 0
    }
}

int main() {
    double initial_velocity, angle;

    // User input for initial velocity and angle
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &initial_velocity);
    printf("Enter the angle of projection (degrees): ");
    scanf("%lf", &angle);

    // Validate input values
    if (initial_velocity <= 0) {
        printf("Velocity must be greater than 0.\n");
        return -1;
    }
    if (angle < 0 || angle > 90) {
        printf("Angle must be between 0 and 90 degrees.\n");
        return -1;
    }

    // Call the function to print the trajectory
    print_trajectory(initial_velocity, angle);

    return 0;
}