//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define dt 0.01 // Time step
#define M 1e24 // Mass of planet
#define R 6.371e6 // Radius of planet
#define MU 0.001 // Friction coefficient
#define N 100 // Number of particles

typedef struct {
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
    double m; // Mass
} Particle;

int main() {
    // Initialize the system
    Particle particles[N];
    for (int i = 0; i < N; i++) {
        particles[i].x = R * (2 * rand() / RAND_MAX - 1);
        particles[i].y = R * (2 * rand() / RAND_MAX - 1);
        particles[i].z = R * (2 * rand() / RAND_MAX - 1);
        particles[i].vx = 0;
        particles[i].vy = 0;
        particles[i].vz = 0;
        particles[i].m = 1e3;
    }

    // Simulate the system
    double t = 0;
    while (t < 10) {
        // Calculate the forces
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                double dx = particles[j].x - particles[i].x;
                double dy = particles[j].y - particles[i].y;
                double dz = particles[j].z - particles[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double F = G * particles[i].m * particles[j].m / (r * r + MU);
                particles[i].vx += F * dt * dx / r;
                particles[i].vy += F * dt * dy / r;
                particles[i].vz += F * dt * dz / r;
                particles[j].vx -= F * dt * dx / r;
                particles[j].vy -= F * dt * dy / r;
                particles[j].vz -= F * dt * dz / r;
            }
        }

        // Update the positions
        for (int i = 0; i < N; i++) {
            particles[i].x += particles[i].vx * dt;
            particles[i].y += particles[i].vy * dt;
            particles[i].z += particles[i].vz * dt;
        }

        // Print the positions
        printf("t = %f\n", t);
        for (int i = 0; i < N; i++) {
            printf("(%f, %f, %f)\n", particles[i].x, particles[i].y, particles[i].z);
        }
        t += dt;
    }
    return 0;
}