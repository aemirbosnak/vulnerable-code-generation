//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

typedef struct Planet {
    char name[20];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

void calculate_gravity(Planet *planet, Planet *other_planet) {
    double dx = other_planet->x - planet->x;
    double dy = other_planet->y - planet->y;
    double dz = other_planet->z - planet->z;

    double distance = sqrt(dx * dx + dy * dy + dz * dz);

    double force = G * planet->mass * other_planet->mass / distance * distance;

    planet->vx += force * dx / planet->mass;
    planet->vy += force * dy / planet->mass;
    planet->vz += force * dz / planet->mass;
}

int main() {
    Planet earth = {"Earth", 5.972e24, 0, 0, 0, 0, 0, 0};
    Planet sun = {"Sun", 1.989e30, 0, 0, 0, 0, 0, 0};

    while (1) {
        calculate_gravity(&earth, &sun);
        calculate_gravity(&sun, &earth);

        earth.x += earth.vx * 0.01;
        earth.y += earth.vy * 0.01;
        earth.z += earth.vz * 0.01;

        printf("Earth's position: (%f, %f, %f)\n", earth.x, earth.y, earth.z);

        sleep(1);
    }

    return 0;
}