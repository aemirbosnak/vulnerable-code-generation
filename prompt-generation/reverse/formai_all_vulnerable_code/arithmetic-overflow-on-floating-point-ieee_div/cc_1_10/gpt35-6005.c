//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11            // gravitational constant
#define Msun 1.989e30           // mass of the Sun

typedef struct {
    double x, y, z;             // position
    double vx, vy, vz;          // velocity
    double ax, ay, az;          // acceleration
    double m;                   // mass
} body;

void update_velocity(body *a, body *b, double dt) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dz = b->z - a->z;
    double d = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * a->m * b->m / (d*d*d);
    a->vx += f * dx * dt / a->m;
    a->vy += f * dy * dt / a->m;
    a->vz += f * dz * dt / a->m;
}

void update_position(body *a, double dt) {
    a->x += a->vx * dt;
    a->y += a->vy * dt;
    a->z += a->vz * dt;
}

int main() {
    body sun = {0, 0, 0, 0, 0, 0, 0, 0, 0, Msun};
    body earth = {1.496e11, 0, 0, 0, 29783, 0, 0, 0, 0, 5.972e24};
    double dt = 60*60*24;       // timestep (one day)
    int steps = 365*10;         // simulate 10 years
    int i, j;
    for (i = 0; i < steps; i++) {
        // calculate acceleration
        earth.ax = 0;
        earth.ay = 0;
        earth.az = 0;
        update_velocity(&sun, &earth, dt/2);
        for (j = 0; j < steps; j++) {
            if (i != j) {
                body *b = &earth;
                update_velocity(&earth, b, dt/2);
                update_velocity(b, &earth, dt/2);
            }
        }
        update_position(&earth, dt);
        update_velocity(&sun, &earth, dt/2);
        printf("%d: position = (%e, %e, %e), velocity = (%e, %e, %e)\n", i, earth.x, earth.y, earth.z, earth.vx, earth.vy, earth.vz);
    }
    return 0;
}