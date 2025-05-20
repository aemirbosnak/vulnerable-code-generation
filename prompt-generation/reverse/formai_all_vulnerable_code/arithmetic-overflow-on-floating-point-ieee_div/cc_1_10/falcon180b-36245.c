//Falcon-180B DATASET v1.0 Category: Simulation of the Solar System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 6.67430e-11

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
    double m;
} Planet;

void init(Planet *p, double x, double y, double z, double vx, double vy, double vz, double m) {
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->m = m;
}

void update(Planet *p, double dt) {
    double r, v, a;
    r = sqrt(p->x*p->x + p->y*p->y + p->z*p->z);
    v = sqrt(p->vx*p->vx + p->vy*p->vy + p->vz*p->vz);
    a = G * p->m / (r*r);
    p->ax = -p->vx * a;
    p->ay = -p->vy * a;
    p->az = -p->vz * a;
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void print(Planet *p) {
    printf("%.2f %.2f %.2f %.2f %.2f %.2f\n", p->x, p->y, p->z, p->vx, p->vy, p->vz);
}

int main() {
    Planet earth, moon;
    init(&earth, 0, 0, 0, 0, 0, 0, 5.972e24);
    init(&moon, 384400, 0, 0, -1022, 0, 0, 7.347e22);
    double dt = 86400; // one day
    int nsteps = 365*10; // simulate 10 years
    for (int i = 0; i < nsteps; i++) {
        update(&earth, dt);
        update(&moon, dt);
        printf("Earth: ");
        print(&earth);
        printf("Moon: ");
        print(&moon);
    }
    return 0;
}