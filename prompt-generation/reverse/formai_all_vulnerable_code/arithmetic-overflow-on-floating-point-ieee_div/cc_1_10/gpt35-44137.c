//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11     // gravitational constant

typedef struct {
    double x, y, z;     // position
    double vx, vy, vz;  // velocity
    double mass;        // mass
} body;

/**
 * Calculates the force exerted on a body by the gravitational pull of another body.
 * 
 * @param b1 The body exerting the force
 * @param b2 The body on which the force is exerted
 * @return The force vector exerted on b2 by b1
 */
body calculate_force(body b1, body b2) {
    double dx = b2.x - b1.x, dy = b2.y - b1.y, dz = b2.z - b1.z;
    double dist = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * b1.mass * b2.mass / (dist * dist);
    body force = {
        .x = f * dx / dist,
        .y = f * dy / dist,
        .z = f * dz / dist
    };
    return force;
}

/**
 * Updates the position and velocity of a body based on the forces acting upon it.
 * 
 * @param b The body to update
 * @param forces An array of forces acting upon the body
 * @param n The number of bodies in the system
 * @param dt The time step to use for the update
 */
void update_body(body *b, body *forces, int n, double dt) {
    double ax = 0, ay = 0, az = 0;
    for (int i = 0; i < n; i++) {
        if (b == forces + i) continue;
        body f = calculate_force(*b, forces[i]);
        ax += f.x / b->mass;
        ay += f.y / b->mass;
        az += f.z / b->mass;
    }
    b->vx += dt * ax;
    b->vy += dt * ay;
    b->vz += dt * az;
    b->x += dt * b->vx;
    b->y += dt * b->vy;
    b->z += dt * b->vz;
}

int main() {
    // Define the bodies in the system
    body sun = { .x = 0, .y = 0, .z = 0, .vx = 0, .vy = 0, .vz = 0, .mass = 1.989e30 };
    body earth = { .x = 1.496e11, .y = 0, .z = 0, .vx = 0, .vy = 2.978e4, .vz = 0, .mass = 5.972e24 };
    body moon = { .x = 1.496e11 + 3.844e8, .y = 0, .z = 0, .vx = 0, .vy = 2.978e4 + 1.022e3, .vz = 0, .mass = 7.342e22 };
    int n = 3;

    // Simulate the system for 1 year
    double dt = 86400;  // time step of 1 day
    for (int day = 0; day < 365; day++) {
        // Calculate forces acting on each body
        body forces[n];
        forces[0] = sun;
        forces[1] = earth;
        forces[2] = moon;
        update_body(&sun, forces, n, dt);
        update_body(&earth, forces, n, dt);
        update_body(&moon, forces, n, dt);

        // Print the positions of each body
        printf("Day %d\n", day);
        printf("Sun    : (%.3e, %.3e, %.3e)\n", sun.x, sun.y, sun.z);
        printf("Earth  : (%.3e, %.3e, %.3e)\n", earth.x, earth.y, earth.z);
        printf("Moon   : (%.3e, %.3e, %.3e)\n", moon.x, moon.y, moon.z);
        printf("\n");
    }
    return 0;
}