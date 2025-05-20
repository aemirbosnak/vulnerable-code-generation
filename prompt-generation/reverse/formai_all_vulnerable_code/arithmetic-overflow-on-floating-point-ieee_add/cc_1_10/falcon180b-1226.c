//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define PI 3.14159265358979323846

// Struct to represent a particle
typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
    double mass;
} Particle;

// Function to calculate force between two particles
void calculate_force(Particle *p1, Particle *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double force_magnitude = G * p1->mass * p2->mass / (r*r);
    p1->ax -= dx * force_magnitude;
    p1->ay -= dy * force_magnitude;
    p1->az -= dz * force_magnitude;
    p2->ax += dx * force_magnitude;
    p2->ay += dy * force_magnitude;
    p2->az += dz * force_magnitude;
}

// Function to update position and velocity of a particle
void update_particle(Particle *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

// Function to print a particle's information
void print_particle(Particle *p) {
    printf("Particle at (%lf, %lf, %lf) with mass %lf\n", p->x, p->y, p->z, p->mass);
}

// Main function
int main() {
    // Initialize particles
    Particle earth, moon;
    earth.mass = 5.972e24;
    earth.x = 0;
    earth.y = 0;
    earth.z = 0;
    earth.vx = 0;
    earth.vy = 0;
    earth.vz = 0;
    moon.mass = 7.347e22;
    moon.x = 384400;
    moon.y = 0;
    moon.z = 0;
    moon.vx = 0;
    moon.vy = 0;
    moon.vz = 0;

    // Simulate for 100 steps
    for (int i = 0; i < 100; i++) {
        calculate_force(&earth, &moon);
        update_particle(&earth, 1);
        update_particle(&moon, 1);
    }

    // Print final positions
    print_particle(&earth);
    print_particle(&moon);

    return 0;
}