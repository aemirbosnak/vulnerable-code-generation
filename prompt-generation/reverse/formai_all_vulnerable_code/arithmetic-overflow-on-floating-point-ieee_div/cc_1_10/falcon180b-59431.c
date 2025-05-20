//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Constants
#define G 6.674e-11 // Gravitational constant
#define PI 3.14159265358979323846 // Pi

// Structures
typedef struct {
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
    double ax, ay, az; // Acceleration
    double m; // Mass
} planet;

// Functions
void init_planet(planet *p, double x, double y, double z, double vx, double vy, double vz, double m) {
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->m = m;
}

void update_acceleration(planet *p, planet *q) {
    double dx = p->x - q->x;
    double dy = p->y - q->y;
    double dz = p->z - q->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p->m * q->m / (r*r);
    p->ax += dx * f;
    p->ay += dy * f;
    p->az += dz * f;
}

void update_velocity(planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void update_position(planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void print_planet(planet *p) {
    printf("%.2f %.2f %.2f\n", p->x, p->y, p->z);
}

int main() {
    srand(time(NULL));

    // Initialize planets
    planet earth;
    init_planet(&earth, 0, 0, 0, 0, 0, 0, 5.972e24);
    planet moon;
    init_planet(&moon, 384400, 0, 0, 0, 0, 0, 7.3477e22);
    planet sun;
    init_planet(&sun, 0, 0, 0, 0, 0, 0, 1.9885e30);

    // Simulation loop
    double dt = 0.01;
    int i = 0;
    while (i < 1000) {
        update_acceleration(&earth, &sun);
        update_acceleration(&moon, &earth);
        update_acceleration(&moon, &sun);
        update_velocity(&earth, dt);
        update_velocity(&moon, dt);
        update_position(&earth, dt);
        update_position(&moon, dt);
        print_planet(&earth);
        print_planet(&moon);
        i++;
    }

    return 0;
}