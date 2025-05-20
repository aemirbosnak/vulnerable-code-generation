//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} Body;

#define G 6.674e-11  // Gravitational constant
#define DT 0.001     // Timestep

void update_velocities(Body *bodies, int n) {
    for (int i = 0; i < n; i++) {
        bodies[i].vx += DT * G * bodies[i].mass / pow(bodies[i].x * bodies[i].x + bodies[i].y * bodies[i].y, 1.5);
        bodies[i].vy += DT * G * bodies[i].mass / pow(bodies[i].x * bodies[i].x + bodies[i].y * bodies[i].y, 1.5);
    }
}

void update_positions(Body *bodies, int n) {
    for (int i = 0; i < n; i++) {
        bodies[i].x += DT * bodies[i].vx;
        bodies[i].y += DT * bodies[i].vy;
    }
}

int main() {
    // Initial conditions
    Body bodies[] = {
        {1e30, 0, 0, 0, 0},  // Sun
        {3e24, -8e11, -3e11, 0, 0},  // Mercury
        {4e24, -1.5e11, 0, 0, 0},  // Venus
        {6e24, -2.3e11, 0, 0, 0},  // Earth
        {5e24, -3e11, 0, 0, 0},  // Mars
        {1.9e27, -7e11, 0, 0, 0},  // Jupiter
        {5.6e26, -1.4e11, 0, 0, 0},  // Saturn
        {8.6e25, -2.2e11, 0, 0, 0},  // Uranus
        {1e25, -3e11, 0, 0, 0},  // Neptune
    };
    int n = sizeof(bodies) / sizeof(Body);

    // Simulation loop
    for (int i = 0; i < 100000; i++) {
        update_velocities(bodies, n);
        update_positions(bodies, n);

        // Print positions
        if (i % 100 == 0) {
            printf("Positions at t = %.3f:\n", i * DT);
            for (int j = 0; j < n; j++) {
                printf("Body %d: (%.3f, %.3f)\n", j, bodies[j].x, bodies[j].y);
            }
        }
    }

    return 0;
}