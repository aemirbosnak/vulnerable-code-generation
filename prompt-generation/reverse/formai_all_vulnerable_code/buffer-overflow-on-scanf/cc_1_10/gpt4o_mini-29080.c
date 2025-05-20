//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 9.81           // Acceleration due to gravity (m/s^2)

// Function declarations
void simulate_harmonic_oscillator(double mass, double k, double dt, double total_time);
void print_output(double time, double position, double velocity);

// Main function
int main() {
    double mass, spring_constant, timestep, total_time;

    // User inputs
    printf("Enter mass of the object (kg): ");
    scanf("%lf", &mass);
    printf("Enter spring constant (N/m): ");
    scanf("%lf", &spring_constant);
    printf("Enter timestep for simulation (s): ");
    scanf("%lf", &timestep);
    printf("Enter total simulation time (s): ");
    scanf("%lf", &total_time);

    // Simulate the motion of the harmonic oscillator
    simulate_harmonic_oscillator(mass, spring_constant, timestep, total_time);

    return 0;
}

// Function to simulate the simple harmonic oscillator
void simulate_harmonic_oscillator(double mass, double k, double dt, double total_time) {
    double position = 0.1; // Initial position (m)
    double velocity = 0.0; // Initial velocity (m/s)
    double time = 0.0;     // Start time (s)

    // Print headers for output table
    printf("\nTime (s)\tPosition (m)\tVelocity (m/s)\n");
  
    // Time integration using Euler's method
    while (time <= total_time) {
        // Print current state
        print_output(time, position, velocity);

        // Calculate acceleration
        double acceleration = - (k / mass) * position;

        // Update position and velocity using Euler's method
        velocity += acceleration * dt;
        position += velocity * dt;

        // Increment time
        time += dt;
    }
}

// Function to print the output for each time step
void print_output(double time, double position, double velocity) {
    printf("%.2f\t\t%.4f\t\t%.4f\n", time, position, velocity);
}