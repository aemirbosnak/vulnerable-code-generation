//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define PI 3.14159265358979323846

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
    double mass;
} Planet;

void init(Planet *p, double x, double y, double z, double vx, double vy, double vz, double mass) {
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->mass = mass;
}

void force(Planet *p1, Planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p1->mass * p2->mass / (r*r);
    p1->ax -= dx * f;
    p1->ay -= dy * f;
    p1->az -= dz * f;
    p2->ax += dx * f;
    p2->ay += dy * f;
    p2->az += dz * f;
}

void update(Planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    Planet earth, moon;
    init(&earth, 0, 0, 0, 0, 0, 0, 5.972e24);
    init(&moon, 384400, 0, 0, 0, 0, 0, 7.3477e22);

    double dt = 60;
    int steps = 1000;

    for (int i=0; i<steps; i++) {
        force(&earth, &moon);
        force(&moon, &earth);
        update(&earth, dt);
        update(&moon, dt);
    }

    printf("Earth position: %f %f %f\n", earth.x, earth.y, earth.z);
    printf("Moon position: %f %f %f\n", moon.x, moon.y, moon.z);

    return 0;
}