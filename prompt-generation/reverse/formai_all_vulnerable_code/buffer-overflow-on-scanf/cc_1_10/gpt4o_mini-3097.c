//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: authentic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define G 9.81 // Acceleration due to gravity (m/s^2)

void calculate_trajectory(double velocity, double angle, double time_step) {
    double angle_rad = angle * (M_PI / 180); // Convert angle from degrees to radians
    double vx = velocity * cos(angle_rad);   // Horizontal component of velocity
    double vy = velocity * sin(angle_rad);   // Vertical component of velocity

    double time_of_flight = (2 * vy) / G; // Time until projectile hits the ground
    int steps = (int)(time_of_flight / time_step);

    printf("Time (s)\tX (m)\t\tY (m)\n");
    printf("-------------------------------------\n");

    for (int i = 0; i <= steps; i++) {
        double t = i * time_step;  // Current time
        double x = vx * t;          // Horizontal position
        double y = (vy * t) - (0.5 * G * t * t); // Vertical position

        if (y < 0) {
            y = 0; // Prevents the projectile from going below ground
        }

        printf("%.2f\t\t%.2f\t\t%.2f\n", t, x, y);
        usleep(50000); // Sleep for a short duration to simulate real-time motion
    }
}

int main() {
    double velocity, angle, time_step;

    printf("Projectile Motion Simulator\n");
    printf("============================\n");
    
    // User input for projectile parameters
    printf("Enter initial velocity (m/s): ");
    if (scanf("%lf", &velocity) != 1 || velocity <= 0) {
        fprintf(stderr, "Invalid input! Please enter a positive number for velocity.\n");
        return EXIT_FAILURE;
    }

    printf("Enter launch angle (degrees): ");
    if (scanf("%lf", &angle) != 1 || angle < 0 || angle > 90) {
        fprintf(stderr, "Invalid input! Angle must be between 0 and 90 degrees.\n");
        return EXIT_FAILURE;
    }

    printf("Enter time step for simulation (s): ");
    if (scanf("%lf", &time_step) != 1 || time_step <= 0) {
        fprintf(stderr, "Invalid input! Please enter a positive number for time step.\n");
        return EXIT_FAILURE;
    }

    // Calculate and display the trajectory
    calculate_trajectory(velocity, angle, time_step);

    return EXIT_SUCCESS;
}