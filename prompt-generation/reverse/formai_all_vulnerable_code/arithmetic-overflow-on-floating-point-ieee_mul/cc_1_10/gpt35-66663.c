//FormAI DATASET v1.0 Category: Physics simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.67430e-11 // Define gravitational constant (SI units)
#define DELTA_T 0.01 // Define time step

int main() {
    // Defining initial conditions for two masses orbiting each other
    double mass_1 = 1000; // kg
    double mass_2 = 2000; // kg
    double initial_distance = 10; // m
    double initial_velocity = 0; // m/s

    // Defining initial positions of the two masses
    double position_1 = -mass_2 / (mass_1 + mass_2) * initial_distance;
    double position_2 = mass_1 / (mass_1 + mass_2) * initial_distance;

    // Defining initial velocities of the two masses
    double velocity_1 = initial_velocity;
    double velocity_2 = initial_velocity;

    // Defining the total simulation time
    double total_time = 100;
    int num_steps = (int) floor(total_time / DELTA_T) + 1;

    // Initializing arrays to store positions and velocities
    double* position_1_arr = (double*) malloc(num_steps * sizeof(double));
    double* position_2_arr = (double*) malloc(num_steps * sizeof(double));
    double* velocity_1_arr = (double*) malloc(num_steps * sizeof(double));
    double* velocity_2_arr = (double*) malloc(num_steps * sizeof(double));

    // Initializing the time variable
    double time = 0;

    // Running the simulation for the specified time
    for (int i = 0; i < num_steps; i++) {
        // Calculating the force between the two masses
        double force = GRAV_CONST * mass_1 * mass_2 / pow(position_2 - position_1, 2);

        // Updating the velocities based on the force
        double acceleration_1 = force / mass_1;
        double acceleration_2 = -force / mass_2;
        velocity_1 += acceleration_1 * DELTA_T;
        velocity_2 += acceleration_2 * DELTA_T;

        // Updating the positions based on the velocities
        position_1 += velocity_1 * DELTA_T;
        position_2 += velocity_2 * DELTA_T;

        // Storing the positions and velocities in the arrays
        position_1_arr[i] = position_1;
        position_2_arr[i] = position_2;
        velocity_1_arr[i] = velocity_1;
        velocity_2_arr[i] = velocity_2;

        // Updating the time
        time += DELTA_T;
    }

    // Printing the final positions and velocities
    printf("Final positions and velocities:\n");
    printf("Mass 1 position: %lf m\n", position_1_arr[num_steps - 1]);
    printf("Mass 2 position: %lf m\n", position_2_arr[num_steps - 1]);
    printf("Mass 1 velocity: %lf m/s\n", velocity_1_arr[num_steps - 1]);
    printf("Mass 2 velocity: %lf m/s\n", velocity_2_arr[num_steps - 1]);

    // Freeing the memory used by the arrays
    free(position_1_arr);
    free(position_2_arr);
    free(velocity_1_arr);
    free(velocity_2_arr);

    return 0;
}