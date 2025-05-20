//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

// Constants
#define PI 3.14159265
#define TIME_STEP 0.01  // Time increment per iteration
#define SIMULATION_TIME 10.0  // Total time for the simulation
#define DISPLAY_INTERVAL 100  // Interval for displaying results

// Structure to hold parameters of the harmonic oscillator
typedef struct {
    double mass;       // Mass (kg)
    double k;         // Spring constant (N/m)
    double b;         // Damping coefficient (Ns/m)
    double x0;        // Initial displacement (m)
    double v0;        // Initial velocity (m/s)
} oscillator_params;

// Core function to simulate the oscillator motion
void simulate_oscillator(oscillator_params *params) {
    double time = 0.0; // Initialize time
    double x = params->x0; // Initialize position
    double v = params->v0; // Initialize velocity

    printf("Time (s)\tPosition (m)\tVelocity (m/s)\n");
    printf("-----------------------------------------------\n");

    // Main simulation loop
    while (time <= SIMULATION_TIME) {
        // Print the current state
        if ((int)(time / TIME_STEP) % DISPLAY_INTERVAL == 0) {
            printf("%.2f\t\t%.4f\t\t%.4f\n", time, x, v);
        }

        // Update values using the equations of motion
        double accel = (-params->k / params->mass) * x - (params->b / params->mass) * v; // a = -kx/m - bv/m
        v += accel * TIME_STEP; // Update velocity
        x += v * TIME_STEP; // Update position

        // Increment time
        time += TIME_STEP;

        // Pause for a short duration to simulate real-time output
        usleep(50000); // Sleep for 50 milliseconds
    }

    printf("Simulation complete.\n");
}

int main() {
    oscillator_params params;

    // Gather user inputs for the oscillator parameters
    printf("Harmonic Oscillator Simulation\n");
    printf("================================\n");
    
    printf("Enter mass (kg): ");
    scanf("%lf", &params.mass);
    
    printf("Enter spring constant (N/m): ");
    scanf("%lf", &params.k);
    
    printf("Enter damping coefficient (Ns/m): ");
    scanf("%lf", &params.b);
    
    printf("Enter initial displacement (m): ");
    scanf("%lf", &params.x0);
    
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &params.v0);

    // Start the simulation
    simulate_oscillator(&params);

    return 0;
}