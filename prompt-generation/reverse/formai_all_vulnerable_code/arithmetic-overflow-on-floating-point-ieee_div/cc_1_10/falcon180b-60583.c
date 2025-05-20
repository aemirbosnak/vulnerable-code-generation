//Falcon-180B DATASET v1.0 Category: Simulation of the Solar System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define DAY 24*60*60
#define YEAR 365.25*DAY

typedef struct {
    double x, y, z, vx, vy, vz, mass;
} planet;

void advance(planet p, double dt) {
    double r = sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
    double v = sqrt(p.vx*p.vx + p.vy*p.vy + p.vz*p.vz);
    double f = G*p.mass/r*r;
    p.vx += f*p.x/r;
    p.vy += f*p.y/r;
    p.vz += f*p.z/r;
    p.x += p.vx*dt;
    p.y += p.vy*dt;
    p.z += p.vz*dt;
}

int main() {
    planet sun = {0, 0, 0, 0, 0, 0, 1};
    planet mercury = {5.8, 0, 0, 1.6, 0, 0, 0.06};
    planet venus = {10.8, 0, 0, 1.6, 0, 0, 0.82};
    planet earth = {15.1, 0, 0, 1.6, 0, 0, 1};
    planet mars = {24.1, 0, 0, 1.6, 0, 0, 0.11};
    planet jupiter = {31.7, 0, 0, 1.6, 0, 0, 318};
    planet saturn = {40.6, 0, 0, 1.6, 0, 0, 95};
    planet uranus = {50.7, 0, 0, 1.6, 0, 0, 15};
    planet neptune = {60.8, 0, 0, 1.6, 0, 0, 17};

    double dt = DAY/1000;
    int n = 0;

    while (n < 100000) {
        advance(sun, dt);
        advance(mercury, dt);
        advance(venus, dt);
        advance(earth, dt);
        advance(mars, dt);
        advance(jupiter, dt);
        advance(saturn, dt);
        advance(uranus, dt);
        advance(neptune, dt);
        n++;
    }

    return 0;
}