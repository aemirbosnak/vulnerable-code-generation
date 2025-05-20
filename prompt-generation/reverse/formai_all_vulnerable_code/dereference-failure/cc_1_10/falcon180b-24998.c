//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.674e-11
#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double ax;
    double ay;
    double az;
    double mass;
} particle;

void init_particle(particle *p, double x, double y, double z, double vx, double vy, double vz, double mass) {
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->ax = 0;
    p->ay = 0;
    p->az = 0;
    p->mass = mass;
}

void apply_forces(particle *p1, particle *p2, double dt) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double F = G * p1->mass * p2->mass / (r*r);
    double ax = F*dx/r;
    double ay = F*dy/r;
    double az = F*dz/r;
    p1->ax += ax;
    p1->ay += ay;
    p1->az += az;
    p2->ax -= ax;
    p2->ay -= ay;
    p2->az -= az;
}

void update_velocities(particle *p, double dt) {
    p->vx += p->ax*dt;
    p->vy += p->ay*dt;
    p->vz += p->az*dt;
}

void update_positions(particle *p, double dt) {
    p->x += p->vx*dt;
    p->y += p->vy*dt;
    p->z += p->vz*dt;
}

int main() {
    srand(time(NULL));
    int N = 100;
    particle *stars = malloc(sizeof(particle) * N);
    for (int i = 0; i < N; i++) {
        double x = rand() % 10000 - 5000;
        double y = rand() % 10000 - 5000;
        double z = rand() % 10000 - 5000;
        double vx = (rand() % 100 - 50) * 0.001;
        double vy = (rand() % 100 - 50) * 0.001;
        double vz = (rand() % 100 - 50) * 0.001;
        double mass = rand() % 10000 + 1;
        init_particle(&stars[i], x, y, z, vx, vy, vz, mass);
    }
    double dt = 0.01;
    for (int t = 0; t < 10000; t++) {
        for (int i = 0; i < N-1; i++) {
            for (int j = i+1; j < N; j++) {
                apply_forces(&stars[i], &stars[j], dt);
            }
        }
        for (int i = 0; i < N; i++) {
            update_velocities(&stars[i], dt);
            update_positions(&stars[i], dt);
        }
    }
    return 0;
}