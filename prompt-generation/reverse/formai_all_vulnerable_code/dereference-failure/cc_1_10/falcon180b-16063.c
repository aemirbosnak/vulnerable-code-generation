//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant
#define PI 3.14159265358979323846

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

void update_acceleration(particle *p1, particle *p2, double dx, double dy, double dz, double dt) {
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double force_magnitude = G * p1->mass * p2->mass / (r*r);
    double ax = force_magnitude * dx / r;
    double ay = force_magnitude * dy / r;
    double az = force_magnitude * dz / r;
    p1->ax += ax;
    p1->ay += ay;
    p1->az += az;
    p2->ax -= ax;
    p2->ay -= ay;
    p2->az -= az;
}

void update_velocity(particle *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void update_position(particle *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    int num_particles = 1000;
    particle *particles = malloc(sizeof(particle) * num_particles);

    for (int i = 0; i < num_particles; i++) {
        double x = (double)i / num_particles * 10.0;
        double y = 0.0;
        double z = 0.0;
        double vx = 0.0;
        double vy = 0.0;
        double vz = 0.0;
        double mass = 1.0;
        init_particle(&particles[i], x, y, z, vx, vy, vz, mass);
    }

    for (int i = 0; i < num_particles; i++) {
        for (int j = i + 1; j < num_particles; j++) {
            double dx = particles[j].x - particles[i].x;
            double dy = particles[j].y - particles[i].y;
            double dz = particles[j].z - particles[i].z;
            double r = sqrt(dx*dx + dy*dy + dz*dz);
            double dt = 0.01;
            update_acceleration(&particles[i], &particles[j], dx, dy, dz, dt);
            update_acceleration(&particles[j], &particles[i], dx, dy, dz, dt);
        }
    }

    for (int i = 0; i < num_particles; i++) {
        update_velocity(&particles[i], 0.01);
        update_position(&particles[i], 0.01);
    }

    free(particles);
    return 0;
}