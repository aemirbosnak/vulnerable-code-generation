//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81   // Acceleration due to gravity (m/s^2)
#define TIME_INTERVAL 0.1 // Time interval for simulation (s)

void simulateProjectile(float angle, float initial_velocity) {
    float angle_rad = angle * (M_PI / 180.0); // Convert angle to radians
    float initial_velocity_x = initial_velocity * cos(angle_rad);
    float initial_velocity_y = initial_velocity * sin(angle_rad);

    float time = 0.0; // Start at time 0
    float max_height = 0.0; // Track maximum height
    float range = 0.0; // Track horizontal range

    printf("Time (s)\tX (m)\tY (m)\n");
    printf("-------------------------------\n");

    // Simulating the motion until the projectile hits the ground (Y=0)
    while (1) {
        float x = initial_velocity_x * time; // Horizontal displacement
        float y = (initial_velocity_y * time) - (0.5 * GRAVITY * time * time); // Vertical displacement

        if (y < 0) { // Projectile has hit the ground
            break;
        }

        // Update maximum height and range
        if (y > max_height) {
            max_height = y;
        }
        
        range = x;

        // Print the current time and positions
        printf("%.2f\t\t%.2f\t%.2f\n", time, x, y);
        time += TIME_INTERVAL; // Increment time
    }

    // Show max height and range after simulation
    printf("-------------------------------\n");
    printf("Maximum Height: %.2f m\n", max_height);
    printf("Range: %.2f m\n", range);
}

int main() {
    float angle, initial_velocity;

    // Input launch angle from user
    printf("Enter launch angle (degrees): ");
    scanf("%f", &angle);

    // Input initial velocity from user
    printf("Enter initial velocity (m/s): ");
    scanf("%f", &initial_velocity);

    // Check for valid input
    if (angle < 0 || angle > 90) {
        printf("Error: Launch angle must be between 0 and 90 degrees.\n");
        return 1;
    }
    if (initial_velocity < 0) {
        printf("Error: Initial velocity must be non-negative.\n");
        return 1;
    }

    // Run the simulation
    simulateProjectile(angle, initial_velocity);

    return 0;
}