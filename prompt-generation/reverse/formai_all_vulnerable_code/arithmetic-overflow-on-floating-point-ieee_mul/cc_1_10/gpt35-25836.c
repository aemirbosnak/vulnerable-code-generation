//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 3
#define GRAVITATIONAL_CONSTANT 6.67408e-11

typedef struct {
    double mass;
    double position[3];
    double velocity[3];
} planet;

void compute_acceleration(planet* current_planet, planet* other_planet, double* acceleration) {
    double displacement_vec[3];
    double distance_squared = 0;
    for (int i=0; i<3; i++) {
        displacement_vec[i] = other_planet->position[i] - current_planet->position[i];
        distance_squared += pow(displacement_vec[i], 2);
    }
    double distance = sqrt(distance_squared);
    double force = GRAVITATIONAL_CONSTANT*current_planet->mass*other_planet->mass/pow(distance, 2);
    for (int i=0; i<3; i++) {
        acceleration[i] = force*displacement_vec[i]/distance/current_planet->mass;
    }
}

void update_velocities(planet* current_planet, planet* other_planet) {
    double acceleration[3];
    compute_acceleration(current_planet, other_planet, acceleration);
    for (int i=0; i<3; i++) {
        current_planet->velocity[i] += acceleration[i];
    }
}

void update_positions(planet* current_planet) {
    for (int i=0; i<3; i++) {
        current_planet->position[i] += current_planet->velocity[i];
    }
}

void simulate(double time_step, int num_steps, planet planets[NUM_PLANETS]) {
    // Recursive base case
    if (num_steps == 0) return;

    // Update velocities and positions
    for (int i=0; i<NUM_PLANETS; i++) {
        for (int j=i+1; j<NUM_PLANETS; j++) {
            update_velocities(&planets[i], &planets[j]);
            update_velocities(&planets[j], &planets[i]);
        }
    }
    for (int i=0; i<NUM_PLANETS; i++) {
        update_positions(&planets[i]);
    }

    // Print positions after time_step
    printf("Positions after time_step %gs:\n", time_step);
    for (int i=0; i<NUM_PLANETS; i++) {
        printf("Planet %d: %.2f, %.2f, %.2f\n", i, planets[i].position[0], planets[i].position[1], planets[i].position[2]);
    }

    // Recursive call
    simulate(time_step, num_steps-1, planets);
}

int main() {
    planet planets[NUM_PLANETS] = {
        {5.97e24, {0, 0, 0}, {0, 0, 0}},
        {6.42e23, {384400000, 0, 0}, {0, 1022, 0}},
        {3.3e23, {0, 42164000, 0}, {-17034, 0, 0}}
    };
    double time_step = 60; // seconds
    int num_steps = 5;

    simulate(time_step, num_steps, planets);

    return 0;
}