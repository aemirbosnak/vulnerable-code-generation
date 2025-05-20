//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.674e-11
#define DAY 86400000  // 1 day in milliseconds

struct planet {
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
    double mass;
};

void init_planet(struct planet *p, double x, double y, double z, double vx, double vy, double vz, double mass) {
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->ax = 0;
    p->ay = 0;
    p->az = 0;
    p->mass = mass;
}

void update_acceleration(struct planet *p1, struct planet *p2, double dt) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);

    double f = G * p1->mass * p2->mass / (r*r);

    p1->ax += dx * f / r;
    p1->ay += dy * f / r;
    p1->az += dz * f / r;

    p2->ax -= dx * f / r;
    p2->ay -= dy * f / r;
    p2->az -= dz * f / r;
}

void update_velocity(struct planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void update_position(struct planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    srand(time(NULL));

    struct planet earth, moon, sun;

    init_planet(&earth, 0, 0, 0, 0, 0, 0, 5.972e24);
    init_planet(&moon, 384400, 0, 0, 0, 0, 0, 7.3477e22);
    init_planet(&sun, 0, 0, 0, 0, 0, 0, 1.9885e30);

    double dt = DAY / 1000;

    while (1) {
        update_acceleration(&earth, &sun, dt);
        update_acceleration(&moon, &earth, dt);
        update_acceleration(&moon, &sun, dt);

        update_velocity(&earth, dt);
        update_velocity(&moon, dt);

        update_position(&earth, dt);
        update_position(&moon, dt);

        printf("Earth: (%f, %f, %f)\n", earth.x, earth.y, earth.z);
        printf("Moon: (%f, %f, %f)\n", moon.x, moon.y, moon.z);

        system("clear");
    }

    return 0;
}