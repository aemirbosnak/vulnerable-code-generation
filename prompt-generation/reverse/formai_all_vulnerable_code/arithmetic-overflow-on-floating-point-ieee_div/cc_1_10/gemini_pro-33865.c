//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define DT 1e3

typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Body;

Body bodies[] = {
    {1.989e30,  0.0,   0.0,   0.0,   0.0,   0.0,   0.0}, // Sun
    {5.972e24,  0.0,   0.0,   0.0,  -12.2e3,  29.7e3, -1.1e3}, // Earth
    {1.898e27,  0.0,   0.0,   0.0,  -47.3e3, -10.9e3,  2.1e3}, // Venus
    {6.417e23,  0.0,   0.0,   0.0,   -59.0e3,  -13.8e3,  2.8e3}, // Mercury
    {1.08e26,   0.0,   0.0,   0.0,  -35.1e3,  -6.0e3,   -2.5e3}, // Mars
    {5.684e26,  0.0,   0.0,   0.0,  -49.2e3,  14.0e3,  -2.9e3}, // Jupiter
    {8.683e25,  0.0,   0.0,   0.0,  -62.7e3,  20.1e3,  4.1e3}, // Saturn
    {1.024e26,  0.0,   0.0,   0.0,  -50.8e3,  30.6e3, -2.1e3}, // Uranus
    {4.366e25,  0.0,   0.0,   0.0,  -41.5e3,  41.8e3,  1.8e3}, // Neptune
    {1.303e22,  0.0,   0.0,   0.0,  -36.3e3,  57.0e3,  1.6e3}, // Pluto
};

const int NUM_BODIES = sizeof(bodies) / sizeof(Body);

void update_forces(Body *bodies) {
    for (int i = 0; i < NUM_BODIES; i++) {
        bodies[i].vx = 0.0;
        bodies[i].vy = 0.0;
        bodies[i].vz = 0.0;
        for (int j = 0; j < NUM_BODIES; j++) {
            if (i == j) {
                continue;
            }
            double dx = bodies[i].x - bodies[j].x;
            double dy = bodies[i].y - bodies[j].y;
            double dz = bodies[i].z - bodies[j].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double f = G * bodies[i].mass * bodies[j].mass / (r * r * r);
            bodies[i].vx += f * dx / r;
            bodies[i].vy += f * dy / r;
            bodies[i].vz += f * dz / r;
        }
    }
}

void update_positions(Body *bodies) {
    for (int i = 0; i < NUM_BODIES; i++) {
        bodies[i].x += bodies[i].vx * DT;
        bodies[i].y += bodies[i].vy * DT;
        bodies[i].z += bodies[i].vz * DT;
    }
}

int main() {
    for (int i = 0; i < 10000; i++) {
        update_forces(bodies);
        update_positions(bodies);
    }

    for (int i = 0; i < NUM_BODIES; i++) {
        printf("%f %f %f\n", bodies[i].x, bodies[i].y, bodies[i].z);
    }

    return 0;
}