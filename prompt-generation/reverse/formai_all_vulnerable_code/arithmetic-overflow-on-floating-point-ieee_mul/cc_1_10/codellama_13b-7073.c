//Code Llama-13B DATASET v1.0 Category: Planet Gravity Simulation ; Style: artistic
/*
 * C Planet Gravity Simulation
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define G 6.67408e-11 // Gravitational constant
#define EARTH_MASS 5.97237e24 // Mass of Earth
#define EARTH_RADIUS 6.371e6 // Radius of Earth

// Define structs
typedef struct {
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
    double mass; // Mass
} Body;

// Define functions
void update_position(Body *body, double dt) {
    // Calculate acceleration
    double ax = (G * EARTH_MASS * body->x) / (EARTH_RADIUS * EARTH_RADIUS);
    double ay = (G * EARTH_MASS * body->y) / (EARTH_RADIUS * EARTH_RADIUS);
    double az = (G * EARTH_MASS * body->z) / (EARTH_RADIUS * EARTH_RADIUS);

    // Update velocity
    body->vx += ax * dt;
    body->vy += ay * dt;
    body->vz += az * dt;

    // Update position
    body->x += body->vx * dt;
    body->y += body->vy * dt;
    body->z += body->vz * dt;
}

void print_position(Body *body) {
    printf("Position: (%f, %f, %f)\n", body->x, body->y, body->z);
}

// Main function
int main() {
    // Initialize bodies
    Body earth;
    earth.x = 0;
    earth.y = 0;
    earth.z = 0;
    earth.mass = EARTH_MASS;

    Body moon;
    moon.x = 0;
    moon.y = 384400e3;
    moon.z = 0;
    moon.mass = 7.349e22;

    // Set time step
    double dt = 1.0; // seconds

    // Simulate motion
    for (int i = 0; i < 1000; i++) {
        // Update positions
        update_position(&earth, dt);
        update_position(&moon, dt);

        // Print positions
        print_position(&earth);
        print_position(&moon);
    }

    return 0;
}