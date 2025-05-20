//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant
#define M_EARTH 5.972e24 // Mass of the Earth (kg)
#define M_SUN 1.989e30 // Mass of the Sun (kg)
#define R_EARTH 6.371e6 // Radius of the Earth (m)
#define R_SUN 6.963e8 // Radius of the Sun (m)
#define DT 86400 // Time step (1 day in seconds)

typedef struct {
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double m;
} Particle;

Particle earth = {0, 0, 0, 0, 0, 0, M_EARTH};
Particle sun = {0, 0, 0, 0, 0, 0, M_SUN};

void calculate_force(Particle *p1, Particle *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p1->m * p2->m / (r*r);
    p1->vx += f * dx / r;
    p1->vy += f * dy / r;
    p1->vz += f * dz / r;
}

void update_position(Particle *p) {
    p->x += p->vx * DT;
    p->y += p->vy * DT;
    p->z += p->vz * DT;
}

int main() {
    int i;

    // Simulate for 1 year
    for (i = 0; i < 365; i++) {
        calculate_force(&earth, &sun);
        update_position(&earth);
    }

    // Print the final position of the Earth
    printf("Earth's final position: (%.2f, %.2f, %.2f)\n", earth.x, earth.y, earth.z);

    return 0;
}