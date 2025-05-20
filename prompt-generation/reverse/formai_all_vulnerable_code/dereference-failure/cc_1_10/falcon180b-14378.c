//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.674 // Gravitational constant
#define PI 3.14159265358979323846 // Pi
#define MAX_BODIES 100 // Maximum number of bodies
#define MAX_STEPS 1000 // Maximum number of steps

typedef struct {
    double x, y, z; // Position of body
    double vx, vy, vz; // Velocity of body
    double ax, ay, az; // Acceleration of body
    double m; // Mass of body
} Body;

void init_body(Body *b, double x, double y, double z, double m) {
    b->x = x;
    b->y = y;
    b->z = z;
    b->vx = 0;
    b->vy = 0;
    b->vz = 0;
    b->ax = 0;
    b->ay = 0;
    b->az = 0;
    b->m = m;
}

void apply_gravity(Body *a, Body *b) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dz = b->z - a->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * a->m * b->m / (r*r);
    a->ax -= dx * f;
    a->ay -= dy * f;
    a->az -= dz * f;
    b->ax += dx * f;
    b->ay += dy * f;
    b->az += dz * f;
}

void update_velocity(Body *b, double dt) {
    b->vx += b->ax * dt;
    b->vy += b->ay * dt;
    b->vz += b->az * dt;
}

void update_position(Body *b, double dt) {
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    b->z += b->vz * dt;
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_BODIES + 2; // Random number of bodies between 2 and MAX_BODIES
    Body *bodies = malloc(n * sizeof(Body));
    for (int i = 0; i < n; i++) {
        init_body(&bodies[i], rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50, rand() % 100 + 1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            apply_gravity(&bodies[i], &bodies[j]);
        }
    }
    for (int i = 0; i < MAX_STEPS; i++) {
        for (int j = 0; j < n; j++) {
            update_velocity(&bodies[j], 0.01);
            update_position(&bodies[j], 0.01);
        }
    }
    free(bodies);
    return 0;
}