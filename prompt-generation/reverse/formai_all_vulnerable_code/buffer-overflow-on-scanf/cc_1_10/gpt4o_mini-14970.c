//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: secure
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define GRAVITY -9.81             // Acceleration due to gravity (m/s^2)
#define PI 3.14159265358979323846 // Value of Pi for angle calculations

typedef struct {
    double x;      // Position in the x-direction
    double y;      // Position in the y-direction
    double vx;     // Velocity in the x-direction
    double vy;     // Velocity in the y-direction
} Particle;

// Function to initialize the particle
void initialize_particle(Particle *p, double initial_velocity, double angle) {
    p->vx = initial_velocity * cos(angle * (PI / 180.0));
    p->vy = initial_velocity * sin(angle * (PI / 180.0));
    p->x = 0.0;
    p->y = 0.0;
}

// Function to update the particle's position
void update_position(Particle *p, double delta_time) {
    p->x += p->vx * delta_time;
    p->vy += GRAVITY * delta_time; // Update velocity due to gravity
    p->y += p->vy * delta_time;
}

// Function to print the particle's current position
void print_position(Particle *p, double time) {
    printf("Time: %.2f s, Position: (%.2f, %.2f)\n", time, p->x, p->y);
}

// Function to run the simulation
void run_simulation(double initial_velocity, double angle, double duration, double time_step) {
    Particle p;
    initialize_particle(&p, initial_velocity, angle);

    for (double t = 0; t <= duration; t += time_step) {
        if (p.y < 0) { // Stop simulation if the particle hits the ground
            break;
        }
        print_position(&p, t);
        update_position(&p, time_step);
    }
}

int main() {
    double initial_velocity;
    double angle;
    double duration;
    double time_step;

    // Getting user input
    printf("Enter initial velocity (m/s): ");
    if (scanf("%lf", &initial_velocity) != 1 || initial_velocity < 0) {
        fprintf(stderr, "Invalid input for initial velocity. Exiting...\n");
        return EXIT_FAILURE;
    }

    printf("Enter launch angle (degrees): ");
    if (scanf("%lf", &angle) != 1) {
        fprintf(stderr, "Invalid input for angle. Exiting...\n");
        return EXIT_FAILURE;
    }

    printf("Enter total duration (s): ");
    if (scanf("%lf", &duration) != 1 || duration < 0) {
        fprintf(stderr, "Invalid input for duration. Exiting...\n");
        return EXIT_FAILURE;
    }

    printf("Enter time step (s): ");
    if (scanf("%lf", &time_step) != 1 || time_step <= 0) {
        fprintf(stderr, "Invalid input for time step. Exiting...\n");
        return EXIT_FAILURE;
    }

    // Run the simulation
    run_simulation(initial_velocity, angle, duration, time_step);

    return EXIT_SUCCESS;
}