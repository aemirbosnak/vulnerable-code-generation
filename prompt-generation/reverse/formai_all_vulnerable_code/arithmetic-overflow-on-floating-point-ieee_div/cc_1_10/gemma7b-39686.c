//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: calm
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11

typedef struct Particle {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Particle;

int main() {
    Particle particle1 = {1e-3, 0, 0, 0, 0, 0, 0};
    Particle particle2 = {2e-3, 1, 0, 0, 0, 0, 0};
    Particle particle3 = {3e-3, 0, 1, 0, 0, 0, 0};

    double dt = 0.01;
    int nSteps = 100000;

    for (int i = 0; i < nSteps; i++) {
        // Calculate acceleration of each particle due to gravity
        double ax1 = G * (particle2.mass * (particle1.x - particle2.x) / (particle1.x - particle2.x) * (particle1.y - particle2.y) / (particle1.y - particle2.y) * particle1.mass) + G * (particle3.mass * (particle1.x - particle3.x) / (particle1.x - particle3.x) * (particle1.y - particle3.y) / (particle1.y - particle3.y) * particle1.mass);
        double ay1 = G * (particle2.mass * (particle1.y - particle2.y) / (particle1.x - particle2.x) * (particle1.x - particle2.y) / (particle1.x - particle2.y) * particle1.mass) + G * (particle3.mass * (particle1.y - particle3.y) / (particle1.x - particle3.x) * (particle1.x - particle3.y) / (particle1.x - particle3.y) * particle1.mass);

        double ax2 = G * (particle1.mass * (particle2.x - particle1.x) / (particle2.x - particle1.x) * (particle2.y - particle1.y) / (particle2.y - particle1.y) * particle2.mass) + G * (particle3.mass * (particle2.x - particle3.x) / (particle2.x - particle3.x) * (particle2.y - particle3.y) / (particle2.y - particle3.y) * particle2.mass);
        double ay2 = G * (particle1.mass * (particle2.y - particle1.y) / (particle2.x - particle1.x) * (particle2.x - particle1.y) / (particle2.x - particle1.y) * particle2.mass) + G * (particle3.mass * (particle2.y - particle3.y) / (particle2.x - particle3.x) * (particle2.x - particle3.y) / (particle2.x - particle3.y) * particle2.mass);

        double ax3 = G * (particle1.mass * (particle3.x - particle1.x) / (particle3.x - particle1.x) * (particle3.y - particle1.y) / (particle3.x - particle1.x) * particle3.mass) + G * (particle2.mass * (particle3.x - particle2.x) / (particle3.x - particle2.x) * (particle3.y - particle2.y) / (particle3.x - particle2.x) * particle3.mass);
        double ay3 = G * (particle1.mass * (particle3.y - particle1.y) / (particle3.x - particle1.x) * (particle3.x - particle1.y) / (particle3.x - particle1.y) * particle3.mass) + G * (particle2.mass * (particle3.y - particle2.y) / (particle2.x - particle2.x) * (particle3.x - particle2.y) / (particle2.x - particle2.y) * particle3.mass);

        // Update position and velocity of each particle
        particle1.x += ax1 * dt * dt;
        particle1.y += ay1 * dt * dt;
        particle2.x += ax2 * dt * dt;
        particle2.y += ay2 * dt * dt;
        particle3.x += ax3 * dt * dt;
        particle3.y += ay3 * dt * dt;

        // Print the position of each particle
        printf("Particle 1: (%f, %f)\n", particle1.x, particle1.y);
        printf("Particle 2: (%f, %f)\n", particle2.x, particle2.y);
        printf("Particle 3: (%f, %f)\n", particle3.x, particle3.y);
    }

    return 0;
}