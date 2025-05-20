//FormAI DATASET v1.0 Category: Physics simulation ; Style: real-life
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define GRAVITY 9.81

// Function to calculate the period of the pendulum
double period(double length) {
    return 2 * PI * sqrt(length / GRAVITY);
}

int main() {
    double length, initial_angle, time_step, total_time;
    printf("Enter the length of the pendulum (in meters): ");
    scanf("%lf", &length);
    printf("Enter the initial angle (in degrees): ");
    scanf("%lf", &initial_angle);
    printf("Enter the time step (in seconds): ");
    scanf("%lf", &time_step);
    printf("Enter the total time (in seconds): ");
    scanf("%lf", &total_time);

    // Convert initial angle to radians
    initial_angle *= PI / 180.0;

    // Calculate the period of the pendulum
    double T = period(length);

    // Number of time steps to simulate
    int num_steps = (int) (total_time / time_step);

    // Initialize arrays to store angle and angular velocity
    double angle[num_steps];
    double velocity[num_steps];

    // Set the initial conditions
    angle[0] = initial_angle;
    velocity[0] = 0;

    // Perform the simulation
    for (int i = 1; i < num_steps; i++) {
        // Calculate the current acceleration
        double acceleration = - GRAVITY / length * sin(angle[i-1]);

        // Use the Euler-Cromer method to calculate the new velocity and angle
        velocity[i] = velocity[i-1] + acceleration * time_step;
        angle[i] = angle[i-1] + velocity[i] * time_step;
    }

    // Print the results
    printf("\nAngle vs. Time:\n");
    printf("Time (s)\tAngle (deg)\n");
    for (int i = 0; i < num_steps; i++) {
        printf("%lf\t%lf\n", i * time_step, angle[i] * 180.0 / PI);
    }

    return 0;
}