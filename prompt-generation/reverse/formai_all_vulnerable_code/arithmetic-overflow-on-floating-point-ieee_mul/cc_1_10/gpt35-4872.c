//FormAI DATASET v1.0 Category: Physics simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11
#define DT 0.1

struct particle {
    double x, y, z;
    double vx, vy, vz;
    double fx, fy, fz;
    double mass;
};

void compute_force(struct particle *p1, struct particle *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;

    double dist = sqrt(dx*dx + dy*dy + dz*dz);
    double dist3 = pow(dist, 3);

    double f = G * p1->mass * p2->mass / dist3;

    p1->fx -= f * dx;
    p1->fy -= f * dy;
    p1->fz -= f * dz;

    p2->fx += f * dx;
    p2->fy += f * dy;
    p2->fz += f * dz;
}

void compute_forces(struct particle *particles, int n) {
    for (int i = 0; i < n; i++) {
        particles[i].fx = 0;
        particles[i].fy = 0;
        particles[i].fz = 0;

        for (int j = 0; j < i; j++) {
            compute_force(&particles[i], &particles[j]);
        }
    }
}

void update_positions(struct particle *particles, int n) {
    for (int i = 0; i < n; i++) {
        particles[i].x += particles[i].vx * DT;
        particles[i].y += particles[i].vy * DT;
        particles[i].z += particles[i].vz * DT;

        particles[i].vx += particles[i].fx / particles[i].mass * DT;
        particles[i].vy += particles[i].fy / particles[i].mass * DT;
        particles[i].vz += particles[i].fz / particles[i].mass * DT;
    }
}

int main() {
    int n = 3;
    struct particle particles[n];

    particles[0] = (struct particle) {0, 0, 0, 0, 0, 0, 0, 0, 10};
    particles[1] = (struct particle) {10, 0, 0, 0, 100, 0, 0, 0, 1};
    particles[2] = (struct particle) {0, 10, 0, 50, 0, 0, 0, 0, 1};

    for (int i = 0; i < 100; i++) {
        compute_forces(particles, n);
        update_positions(particles, n);

        printf("Step %d\n", i);

        for (int j = 0; j < n; j++) {
            printf("%lf %lf %lf\n", particles[j].x, particles[j].y, particles[j].z);
        }
    }

    return 0;
}