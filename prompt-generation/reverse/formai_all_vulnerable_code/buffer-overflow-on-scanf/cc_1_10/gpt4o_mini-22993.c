//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: interoperable
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define GRAVITY 9.81 // Gravity constant (m/s^2)
#define TIME_INTERVAL 0.1 // Time step for simulation (seconds)

void calculate_trajectory(float velocity, float angle) {
    // Convert angle to radians
    float angle_rad = angle * (M_PI / 180.0);
    float time_of_flight = (2 * velocity * sin(angle_rad)) / GRAVITY;
    int steps = (int)(time_of_flight / TIME_INTERVAL) + 1;

    float time = 0.0;
    float x, y;

    printf("Time(s)\tX(m)\tY(m)\n");
    printf("-------\t-----\t-----\n");

    for (int i = 0; i < steps; ++i) {
        // Calculate position
        x = velocity * cos(angle_rad) * time;
        y = (velocity * sin(angle_rad) * time) - (0.5 * GRAVITY * time * time);

        // Print the current position
        if (y < 0) {
            break; // Stop if y is below ground level
        }
        printf("%.2f\t%.2f\t%.2f\n", time, x, y);
        time += TIME_INTERVAL;

        // Sleep to create a delay for better visualization
        usleep(100000); // Sleep for 0.1 seconds
    }
}

int main() {
    float initial_velocity, launch_angle;

    printf("Enter the initial velocity of the projectile (m/s): ");
    scanf("%f", &initial_velocity);

    printf("Enter the launch angle of the projectile (degrees): ");
    scanf("%f", &launch_angle);

    printf("\n--- Projectile Motion Simulation ---\n");
    calculate_trajectory(initial_velocity, launch_angle);

    return 0;
}