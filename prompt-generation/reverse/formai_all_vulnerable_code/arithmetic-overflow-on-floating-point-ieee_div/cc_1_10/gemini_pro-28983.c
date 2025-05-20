//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} celestial_body;

celestial_body bodies[] = {
    { 1.989e30, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }, // Sun
    { 5.972e24, 0.0, 0.0, 0.0, 30000.0, 0.0, 0.0 }, // Earth
    { 7.349e22, 0.0, 0.0, 0.0, 20000.0, 0.0, 0.0 }, // Moon
    { 1.899e27, 0.0, 0.0, 0.0, 15000.0, 0.0, 0.0 }, // Mars
    { 5.685e26, 0.0, 0.0, 0.0, 10000.0, 0.0, 0.0 }, // Jupiter
    { 8.683e25, 0.0, 0.0, 0.0, 5000.0, 0.0, 0.0 }, // Saturn
    { 1.024e26, 0.0, 0.0, 0.0, 2000.0, 0.0, 0.0 }, // Uranus
    { 8.605e25, 0.0, 0.0, 0.0, 1000.0, 0.0, 0.0 }, // Neptune
};

int main() {
    int num_bodies = sizeof(bodies) / sizeof(bodies[0]);
    double dt = 1.0;
    double t = 0.0;

    while (t < 1e6) {
        // Calculate the gravitational force between each pair of bodies.
        for (int i = 0; i < num_bodies; i++) {
            for (int j = i + 1; j < num_bodies; j++) {
                double dx = bodies[i].x - bodies[j].x;
                double dy = bodies[i].y - bodies[j].y;
                double dz = bodies[i].z - bodies[j].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double f = G * bodies[i].mass * bodies[j].mass / (r * r);
                bodies[i].vx += f * dx / r * dt;
                bodies[i].vy += f * dy / r * dt;
                bodies[i].vz += f * dz / r * dt;
                bodies[j].vx -= f * dx / r * dt;
                bodies[j].vy -= f * dy / r * dt;
                bodies[j].vz -= f * dz / r * dt;
            }
        }

        // Update the positions of the bodies.
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
            bodies[i].z += bodies[i].vz * dt;
        }

        // Print the positions of the bodies.
        for (int i = 0; i < num_bodies; i++) {
            printf("%d: %f %f %f\n", i, bodies[i].x, bodies[i].y, bodies[i].z);
        }

        t += dt;
    }

    return 0;
}