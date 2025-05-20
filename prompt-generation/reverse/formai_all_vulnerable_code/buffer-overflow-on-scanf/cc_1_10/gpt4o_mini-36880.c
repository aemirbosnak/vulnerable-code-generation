//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define G 9.81 // Acceleration due to gravity in m/s^2
#define TIME_STEP 0.1 // Time step for simulation in seconds

void simulateProjectile(double velocity, double angle) {
    double angle_rad = angle * (M_PI / 180.0); // Convert angle to radians
    double vx = velocity * cos(angle_rad); // Horizontal velocity
    double vy = velocity * sin(angle_rad); // Vertical velocity

    double x = 0.0; // Initial x position
    double y = 0.0; // Initial y position
    double time = 0.0; // Simulation time

    printf("Time (s) \t X Position (m) \t Y Position (m)\n");
    printf("-------------------------------------------------\n");

    // Run the simulation until the projectile hits the ground
    while (y >= 0.0) {
        // Print the current position and time
        printf("%.2f \t\t %.2f \t\t %.2f\n", time, x, y);

        // Update time
        time += TIME_STEP;

        // Update positions based on time and velocities
        x = vx * time; // Update horizontal position
        y = vy * time - 0.5 * G * time * time; // Update vertical position considering gravity
    }

    printf("-------------------------------------------------\n");
    printf("The projectile hit the ground at x = %.2f m\n", x);
}

int main() {
    double initial_velocity, launch_angle;

    // User inputs
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &initial_velocity);
    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &launch_angle);

    // Validate input values
    if (initial_velocity < 0 || launch_angle < 0) {
        printf("Velocity and angle must be non-negative values.\n");
        return 1; // Exit if inputs are invalid
    }

    // Simulate projectile motion
    simulateProjectile(initial_velocity, launch_angle);

    return 0; // Successful completion
}