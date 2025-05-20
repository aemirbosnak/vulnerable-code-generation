//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: rigorous
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define G 6.67408e-11 // Gravitational constant

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
    double fx, fy, fz;
} Particle;

void calcForces(Particle *p, int n) {
    for (int i = 0; i < n; i++) {
        p[i].fx = p[i].fy = p[i].fz = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            double dx = p[j].x - p[i].x;
            double dy = p[j].y - p[i].y;
            double dz = p[j].z - p[i].z;
            double r2 = dx * dx + dy * dy + dz * dz;
            double f = G * p[i].mass * p[j].mass / r2;
            p[i].fx += f * dx / sqrt(r2);
            p[i].fy += f * dy / sqrt(r2);
            p[i].fz += f * dz / sqrt(r2);
        }
    }
}

void moveParticles(Particle *p, int n, double dt) {
    for (int i = 0; i < n; i++) {
        p[i].x += p[i].vx * dt + 0.5 * p[i].fx * dt * dt;
        p[i].y += p[i].vy * dt + 0.5 * p[i].fy * dt * dt;
        p[i].z += p[i].vz * dt + 0.5 * p[i].fz * dt * dt;
        p[i].vx += p[i].fx * dt;
        p[i].vy += p[i].fy * dt;
        p[i].vz += p[i].fz * dt;
    }
}

int main() {
    srand(time(NULL));
    int n = 100; // Number of particles
    double m = 1; // Mass of each particle
    double r = 10; // Radius of the sphere
    double dt = 0.001; // Time step
    double t = 0; // Time

    Particle *p = malloc(n * sizeof(Particle));
    for (int i = 0; i < n; i++) {
        p[i].mass = m;
        p[i].x = r * (2 * rand() / (double)RAND_MAX - 1);
        p[i].y = r * (2 * rand() / (double)RAND_MAX - 1);
        p[i].z = r * (2 * rand() / (double)RAND_MAX - 1);
        p[i].vx = 0;
        p[i].vy = 0;
        p[i].vz = 0;
    }

    while (t < 100) {
        calcForces(p, n);
        moveParticles(p, n, dt);
        t += dt;

        // Output the positions of the particles
        for (int i = 0; i < n; i++) {
            printf("%f %f %f\n", p[i].x, p[i].y, p[i].z);
        }
    }

    free(p);
    return 0;
}