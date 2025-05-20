//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
    double mass;
} particle;

void init_particle(particle *p, double x, double y, double z, double vx, double vy, double vz, double mass) {
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->mass = mass;
}

void calc_acceleration(particle *p1, particle *p2, double dx, double dy, double dz, double *ax, double *ay, double *az) {
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p1->mass * p2->mass / (r*r);

    *ax = f * dx / r;
    *ay = f * dy / r;
    *az = f * dz / r;
}

void update_particle(particle *p, double dt) {
    double ax, ay, az;
    calc_acceleration(p, p, 0, 0, 0, &ax, &ay, &az);
    p->vx += ax * dt;
    p->vy += ay * dt;
    p->vz += az * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void print_particle(particle *p) {
    printf("(%f, %f, %f)\n", p->x, p->y, p->z);
}

int main() {
    particle p1, p2;
    init_particle(&p1, 0, 0, 0, 0, 0, 0, 1);
    init_particle(&p2, 1, 0, 0, 0, 0, 0, 1);

    while (1) {
        update_particle(&p1, 0.01);
        update_particle(&p2, 0.01);
        print_particle(&p1);
        print_particle(&p2);
    }

    return 0;
}