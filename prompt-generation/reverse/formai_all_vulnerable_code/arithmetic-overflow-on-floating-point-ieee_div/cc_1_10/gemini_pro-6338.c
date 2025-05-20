//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>
#include <math.h>

// Define the gravitational constant
#define G 6.674e-11

// Define the mass of the earth
#define EARTH_MASS 5.972e24

// Define the radius of the earth
#define EARTH_RADIUS 6.371e6

// Define the timestep
#define DT 1000.0

// Function to calculate the gravitational force between two objects
double gravitational_force(double m1, double m2, double r) {
    return (G * m1 * m2) / (r * r);
}

// Function to calculate the acceleration of an object due to gravity
double acceleration_due_to_gravity(double m, double r) {
    return gravitational_force(EARTH_MASS, m, r) / m;
}

// Function to update the position and velocity of an object due to gravity
void update_position_and_velocity(double *x, double *y, double *vx, double *vy, double dt) {
    // Calculate the acceleration due to gravity
    double ax = acceleration_due_to_gravity(1.0, sqrt(*x * *x + *y * *y));
    double ay = acceleration_due_to_gravity(1.0, sqrt(*x * *x + *y * *y));

    // Update the position
    *x += *vx * dt;
    *y += *vy * dt;

    // Update the velocity
    *vx += ax * dt;
    *vy += ay * dt;
}

// Main function
int main() {
    // Initialize the position and velocity of the object
    double x = 0.0;
    double y = 0.0;
    double vx = 1000.0;
    double vy = 1000.0;

    // Run the simulation for a specified number of timesteps
    for (int i = 0; i < 1000; i++) {
        // Update the position and velocity of the object
        update_position_and_velocity(&x, &y, &vx, &vy, DT);

        // Print the position and velocity of the object
        printf("%f %f %f %f\n", x, y, vx, vy);
    }

    return 0;
}