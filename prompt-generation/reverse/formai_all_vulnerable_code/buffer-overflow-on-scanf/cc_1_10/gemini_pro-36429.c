//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.000001
#define G 6.674e-11

typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Particle;

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of particles: ");
    scanf("%d", &n);

    Particle *particles = malloc(n * sizeof(Particle));

    for (int i = 0; i < n; i++) {
        particles[i].mass = (double)rand() / RAND_MAX;
        particles[i].x = (double)rand() / RAND_MAX;
        particles[i].y = (double)rand() / RAND_MAX;
        particles[i].z = (double)rand() / RAND_MAX;
        particles[i].vx = 0;
        particles[i].vy = 0;
        particles[i].vz = 0;
    }

    double dt = 0.01;
    int steps = 1000;

    for (int step = 0; step < steps; step++) {
        // Calculate the forces on each particle
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dx = particles[j].x - particles[i].x;
                double dy = particles[j].y - particles[i].y;
                double dz = particles[j].z - particles[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                if (r < EPSILON) {
                    r = EPSILON;
                }
                double force = G * particles[i].mass * particles[j].mass / (r * r);
                double ax = force * dx / r;
                double ay = force * dy / r;
                double az = force * dz / r;
                particles[i].vx -= ax * dt;
                particles[i].vy -= ay * dt;
                particles[i].vz -= az * dt;
                particles[j].vx += ax * dt;
                particles[j].vy += ay * dt;
                particles[j].vz += az * dt;
            }
        }

        // Update the positions of each particle
        for (int i = 0; i < n; i++) {
            particles[i].x += particles[i].vx * dt;
            particles[i].y += particles[i].vy * dt;
            particles[i].z += particles[i].vz * dt;
        }
    }

    // Print the final positions of the particles
    for (int i = 0; i < n; i++) {
        printf("Particle %d: (%f, %f, %f)\n", i, particles[i].x, particles[i].y, particles[i].z);
    }

    free(particles);

    return 0;
}