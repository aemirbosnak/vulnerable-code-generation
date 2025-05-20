//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Gravitational constant
#define G 6.674e-11

// Mass of the Earth (kg)
#define M_EARTH 5.972e24

// Radius of the Earth (m)
#define R_EARTH 6.371e6

// Time step (s)
#define DT 0.01

// Number of particles
#define N 100

// Particle structure
typedef struct {
    double x, y, z;    // Position (m)
    double vx, vy, vz;  // Velocity (m/s)
    double m;          // Mass (kg)
} Particle;

// Initialize the particles
void initialize_particles(Particle *particles) {
    for (int i = 0; i < N; i++) {
        // Generate random position within a sphere of radius R_EARTH
        double r = R_EARTH * sqrt(drand48());
        double theta = acos(2 * drand48() - 1);
        double phi = 2 * M_PI * drand48();
        particles[i].x = r * sin(theta) * cos(phi);
        particles[i].y = r * sin(theta) * sin(phi);
        particles[i].z = r * cos(theta);

        // Generate random velocity
        double v = 100 * sqrt(drand48());
        theta = acos(2 * drand48() - 1);
        phi = 2 * M_PI * drand48();
        particles[i].vx = v * sin(theta) * cos(phi);
        particles[i].vy = v * sin(theta) * sin(phi);
        particles[i].vz = v * cos(theta);

        // Set mass
        particles[i].m = 1000;
    }
}

// Update the positions and velocities of the particles
void update_particles(Particle *particles) {
    for (int i = 0; i < N; i++) {
        // Calculate the net force on the particle
        double fx = 0, fy = 0, fz = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                double dx = particles[j].x - particles[i].x;
                double dy = particles[j].y - particles[i].y;
                double dz = particles[j].z - particles[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double f = G * particles[i].m * particles[j].m / (r * r);
                fx += f * dx / r;
                fy += f * dy / r;
                fz += f * dz / r;
            }
        }

        // Update the velocity
        particles[i].vx += fx * DT / particles[i].m;
        particles[i].vy += fy * DT / particles[i].m;
        particles[i].vz += fz * DT / particles[i].m;

        // Update the position
        particles[i].x += particles[i].vx * DT;
        particles[i].y += particles[i].vy * DT;
        particles[i].z += particles[i].vz * DT;
    }
}

// Main function
int main() {
    // Allocate memory for the particles
    Particle *particles = malloc(N * sizeof(Particle));

    // Initialize the particles
    initialize_particles(particles);

    // Update the particles for a number of time steps
    for (int i = 0; i < 10000; i++) {
        update_particles(particles);
    }

    // Free the memory
    free(particles);

    return 0;
}