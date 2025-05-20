//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define G 9.81 // Acceleration due to gravity (m/s^2)
#define PI 3.14159
#define TIME_STEP 0.01 // Time step for simulation (seconds)

typedef struct {
    double length; // Length of the pendulum (meters)
    double angle; // Current angle (radians)
    double angular_velocity; // Current angular velocity (radians/second)
} Pendulum;

void initialize_pendulum(Pendulum *pendulum, double length, double initial_angle) {
    pendulum->length = length;
    pendulum->angle = initial_angle * (PI / 180.0); // Convert to radians
    pendulum->angular_velocity = 0.0;
}

void update_pendulum(Pendulum *pendulum) {
    double angular_acceleration = -(G / pendulum->length) * sin(pendulum->angle);
    pendulum->angular_velocity += angular_acceleration * TIME_STEP;
    pendulum->angle += pendulum->angular_velocity * TIME_STEP;
}

void display_pendulum(const Pendulum *pendulum, double time) {
    double x = pendulum->length * sin(pendulum->angle);
    double y = -pendulum->length * cos(pendulum->angle);
    
    printf("Time: %.2f s - Angle: %.2f rad - Position: (%.2f, %.2f)\n", 
           time, pendulum->angle, x, y);
}

int main() {
    Pendulum pendulum;
    double length, initial_angle;
    double total_time, steps;

    // User inputs for pendulum parameters
    printf("Enter the length of the pendulum (m): ");
    scanf("%lf", &length);
    printf("Enter the initial angle (degrees): ");
    scanf("%lf", &initial_angle);
    printf("Enter total simulation time (s): ");
    scanf("%lf", &total_time);

    // Initialize the pendulum
    initialize_pendulum(&pendulum, length, initial_angle);
    
    // Calculate number of steps
    steps = total_time / TIME_STEP;

    // Simulation loop
    for (double time = 0; time <= total_time; time += TIME_STEP) {
        update_pendulum(&pendulum);
        display_pendulum(&pendulum, time);
        usleep(100000); // Sleep for 0.1 seconds to slow down output
    }

    return 0;
}