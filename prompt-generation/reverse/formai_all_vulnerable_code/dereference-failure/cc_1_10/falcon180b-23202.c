//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define PI 3.14159265358979323846

struct particle {
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
    double mass;
};

void init_particle(struct particle *p, double x, double y, double z, double vx, double vy, double vz, double mass) {
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->mass = mass;
}

void update_acceleration(struct particle *p, double dt) {
    double r = sqrt(p->x*p->x + p->y*p->y + p->z*p->z);
    double force = G * p->mass / (r*r*r);
    p->ax = force * p->x / r;
    p->ay = force * p->y / r;
    p->az = force * p->z / r;
}

void update_velocity(struct particle *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void update_position(struct particle *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    int n = 10;
    struct particle *particles = malloc(n * sizeof(struct particle));

    for (int i = 0; i < n; i++) {
        double x = rand() % 1000 - 500;
        double y = rand() % 1000 - 500;
        double z = rand() % 1000 - 500;
        double vx = rand() % 20 - 10;
        double vy = rand() % 20 - 10;
        double vz = rand() % 20 - 10;
        double mass = rand() % 1000 + 1;

        init_particle(&particles[i], x, y, z, vx, vy, vz, mass);
    }

    double dt = 0.01;
    int steps = 1000;

    for (int step = 0; step < steps; step++) {
        for (int i = 0; i < n; i++) {
            update_acceleration(&particles[i], dt);
            update_velocity(&particles[i], dt);
            update_position(&particles[i], dt);
        }
    }

    free(particles);

    return 0;
}