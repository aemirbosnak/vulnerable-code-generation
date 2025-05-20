//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: scientific
#include <stdio.h>
#include <math.h>

#define g 9.81 // acceleration due to gravity in m/s^2

// Function prototypes
void calculate_trajectory(float v0, float angle, float *time_of_flight, float *max_height);
void display_trajectory(float v0, float angle, float time_of_flight);

int main() {
    float initial_velocity, launch_angle;
    float time_of_flight, max_height;

    // User input for initial velocity and launch angle
    printf("Enter the initial velocity (in m/s): ");
    scanf("%f", &initial_velocity);
    printf("Enter the launch angle (in degrees): ");
    scanf("%f", &launch_angle);

    // Convert angle from degrees to radians
    launch_angle = launch_angle * (M_PI / 180.0);

    // Calculate projectile motion parameters
    calculate_trajectory(initial_velocity, launch_angle, &time_of_flight, &max_height);

    // Display the results
    printf("\nProjectile Motion Simulation Results:\n");
    printf("----------------------------------------\n");
    printf("Initial Velocity (m/s): %.2f\n", initial_velocity);
    printf("Launch Angle (degrees): %.2f\n", launch_angle * (180.0 / M_PI));
    printf("Time of Flight (s): %.2f\n", time_of_flight);
    printf("Maximum Height (m): %.2f\n", max_height);
    printf("\nTrajectory:\n");
    printf("Time (s)  |  Height (m)\n");
    printf("-------------------------\n");

    // Display the trajectory
    display_trajectory(initial_velocity, launch_angle, time_of_flight);

    return 0;
}

// Calculate time of flight and maximum height
void calculate_trajectory(float v0, float angle, float *time_of_flight, float *max_height) {
    float vy = v0 * sin(angle); // initial vertical velocity
    *time_of_flight = (2 * vy) / g; // total time of flight
    *max_height = (vy * vy) / (2 * g); // maximum height
}

// Function to display the trajectory
void display_trajectory(float v0, float angle, float time_of_flight) {
    float time_step = time_of_flight / 10;
    for (int i = 0; i <= 10; ++i) {
        float t = i * time_step;
        float vy = v0 * sin(angle); // initial vertical velocity
        float height = vy * t - 0.5 * g * t * t; // height at time t
        if (height < 0) height = 0; // height shouldn't be negative
        printf("%.2f      |  %.2f\n", t, height);
    }
}