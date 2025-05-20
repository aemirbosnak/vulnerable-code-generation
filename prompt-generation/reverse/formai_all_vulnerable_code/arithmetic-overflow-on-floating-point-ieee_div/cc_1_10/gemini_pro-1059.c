//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G 6.674e-11
typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double m;
} Body;
void evolve(Body *bodies, int nbodies, double dt) {
    for (int i = 0; i < nbodies; i++) {
        for (int j = i + 1; j < nbodies; j++) {
            double dx = bodies[i].x - bodies[j].x;
            double dy = bodies[i].y - bodies[j].y;
            double dz = bodies[i].z - bodies[j].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double force = G * bodies[i].m * bodies[j].m / (r * r);
            double ax = force * dx / r;
            double ay = force * dy / r;
            double az = force * dz / r;
            bodies[i].vx += ax * dt;
            bodies[i].vy += ay * dt;
            bodies[i].vz += az * dt;
            bodies[j].vx -= ax * dt;
            bodies[j].vy -= ay * dt;
            bodies[j].vz -= az * dt;
        }
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}
int main() {
    Body bodies[] = {
        {0, 0, 0, 0, 0, 0, 1.989e30},
        {0, 0, 0, 0, 0, 0, 5.972e24},
        {0, 0, 0, 0, 0, 0, 7.348e22},
        {0, 0, 0, 0, 0, 0, 6.419e23},
        {0, 0, 0, 0, 0, 0, 1.899e27},
        {0, 0, 0, 0, 0, 0, 5.685e26},
        {0, 0, 0, 0, 0, 0, 8.683e25},
        {0, 0, 0, 0, 0, 0, 1.024e26},
    };
    int nbodies = sizeof(bodies) / sizeof(bodies[0]);
    double dt = 86400;
    for (int i = 0; i < 10000; i++) {
        evolve(bodies, nbodies, dt);
    }
    for (int i = 0; i < nbodies; i++) {
        printf("Body %d: %.3f %.3f %.3f\n", i, bodies[i].x, bodies[i].y, bodies[i].z);
    }
    return 0;
}