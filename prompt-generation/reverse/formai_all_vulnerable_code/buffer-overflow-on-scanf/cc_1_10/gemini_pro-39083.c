//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double z;
    double mass;
    double vx;
    double vy;
    double vz;
} particle;

double dist(particle *a, particle *b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    double dz = a->z - b->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    int n;
    scanf("%d", &n);
    particle *particles = malloc(sizeof(particle) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf %lf %lf %lf", &particles[i].x, &particles[i].y, &particles[i].z, &particles[i].mass, &particles[i].vx, &particles[i].vy, &particles[i].vz);
    }
    double G = 6.674e-11;
    double dt = 0.001;
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < n; j++) {
            double fx = 0, fy = 0, fz = 0;
            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                double r = dist(&particles[j], &particles[k]);
                double f = G * particles[j].mass * particles[k].mass / (r * r * r);
                fx += f * (particles[k].x - particles[j].x) / r;
                fy += f * (particles[k].y - particles[j].y) / r;
                fz += f * (particles[k].z - particles[j].z) / r;
            }
            particles[j].vx += fx * dt;
            particles[j].vy += fy * dt;
            particles[j].vz += fz * dt;
        }
        for (int j = 0; j < n; j++) {
            particles[j].x += particles[j].vx * dt;
            particles[j].y += particles[j].vy * dt;
            particles[j].z += particles[j].vz * dt;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lf %lf %lf\n", particles[i].x, particles[i].y, particles[i].z);
    }
    free(particles);
    return 0;
}