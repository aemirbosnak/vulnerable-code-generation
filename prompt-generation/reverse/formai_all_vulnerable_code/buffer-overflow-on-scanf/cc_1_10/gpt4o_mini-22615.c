//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: unmistakable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define GRAVITY 9.81 // Acceleration due to gravity (m/s^2)
#define MAX_TIME 10.0 // Maximum time to simulate (seconds)
#define TIME_STEP 0.1 // Time step for the simulation (seconds)

void calculate_trajectory(double velocity, double angle) {
    double radians = angle * (M_PI / 180.0); // Convert angle to radians
    double initial_velocity_x = velocity * cos(radians); // Calculate initial x velocity
    double initial_velocity_y = velocity * sin(radians); // Calculate initial y velocity
    
    // Time variables
    double time = 0.0;
    double position_x, position_y;

    printf("Time(s)    Position X(m)    Position Y(m)\n");
    printf("-------------------------------------------------\n");
    
    // Continue simulation until the projectile hits the ground
    while (time <= MAX_TIME) {
        position_x = initial_velocity_x * time; // x = v_x * t
        position_y = initial_velocity_y * time - 0.5 * GRAVITY * time * time; // y = v_y * t - 0.5 * g * t^2
        
        // Check if the projectile has hit the ground
        if (position_y < 0) {
            position_y = 0; // Set to 0 to represent ground
        }

        printf("%-10.2f %-15.2f %-15.2f\n", time, position_x, position_y);

        // Break loop if the projectile hits the ground
        if (position_y == 0) {
            break;
        }

        time += TIME_STEP; // Increment time
    }
}

int main() {
    double initial_velocity, launch_angle;

    // User inputs
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &initial_velocity);
    
    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &launch_angle);

    // Validate inputs
    if (initial_velocity <= 0) {
        printf("Velocity must be positive.\n");
        return 1;
    }

    if (launch_angle < 0 || launch_angle > 90) {
        printf("Launch angle must be between 0 and 90 degrees.\n");
        return 1;
    }

    // Calculate and display the trajectory
    calculate_trajectory(initial_velocity, launch_angle);

    return 0;
}