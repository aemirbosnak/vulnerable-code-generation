//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430E-11 // Gravitational constant

typedef struct {
    double x, y, z; // position vector
    double vx, vy, vz; // velocity vector
    double ax, ay, az; // acceleration vector
    double mass;
} Particle;

void update_acceleration(Particle *p, double ax, double ay, double az) {
    p->ax += ax;
    p->ay += ay;
    p->az += az;
}

void update_velocity(Particle *p, double vx, double vy, double vz, double dt) {
    p->vx += vx * dt;
    p->vy += vy * dt;
    p->vz += vz * dt;
}

void update_position(Particle *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

double distance(Particle *p1, Particle *p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2));
}

void gravity(Particle *p1, Particle *p2) {
    double dist = distance(p1, p2);
    double force = G * p1->mass * p2->mass / pow(dist, 2);
    double ax = (p2->x - p1->x) * force / dist / p1->mass;
    double ay = (p2->y - p1->y) * force / dist / p1->mass;
    double az = (p2->z - p1->z) * force / dist / p1->mass;

    update_acceleration(p1, ax, ay, az);
    update_acceleration(p2, -ax, -ay, -az);
}

int main() {
    Particle particles[3] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 1000}, {10E6, 0, 0, 0, 200, 0, 0, 0, 0, 1}, {0, 0, 10E6, 0, 0, -200, 0, 0, 0, 1} };
    int n = sizeof(particles) / sizeof(Particle);
    double dt = 0.01;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            gravity(&particles[i], &particles[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        update_velocity(&particles[i], particles[i].ax, particles[i].ay, particles[i].az, dt);
        update_position(&particles[i], dt);
        printf("Particle %d position: (%.2lf, %.2lf, %.2lf)\n", i + 1, particles[i].x, particles[i].y, particles[i].z);
    }

    return 0;
}