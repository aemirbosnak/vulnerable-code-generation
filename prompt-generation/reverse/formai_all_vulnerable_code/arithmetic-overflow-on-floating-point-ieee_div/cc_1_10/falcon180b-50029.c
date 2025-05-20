//Falcon-180B DATASET v1.0 Category: Simulation of the Solar System ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
    double vx, vy, vz;
} planet_t;

const double G = 6.674e-11;
const double DAY = 86400;

void advance(planet_t *planet, double dt) {
    double r = sqrt(planet->x*planet->x + planet->y*planet->y + planet->z*planet->z);
    double m = 1.0; // Sun's mass
    double f = G * m / r / r;
    planet->vx += f * planet->x / r * dt;
    planet->vy += f * planet->y / r * dt;
    planet->vz += f * planet->z / r * dt;
    planet->x += planet->vx * dt;
    planet->y += planet->vy * dt;
    planet->z += planet->vz * dt;
}

int main() {
    planet_t earth, sun;
    sun.x = 0;
    sun.y = 0;
    sun.z = 0;
    sun.vx = 0;
    sun.vy = 0;
    sun.vz = 0;
    earth.x = 1.0;
    earth.y = 0;
    earth.z = 0;
    earth.vx = 0;
    earth.vy = 1.0;
    earth.vz = 0;

    double dt = DAY / 1000.0;
    int steps = 0;

    while (1) {
        advance(&earth, dt);
        advance(&sun, dt);
        printf("Step %d\n", ++steps);
        printf("Earth: (%g, %g, %g)\n", earth.x, earth.y, earth.z);
        printf("Sun: (%g, %g, %g)\n", sun.x, sun.y, sun.z);
        printf("\n");
        fflush(stdout);
    }

    return 0;
}