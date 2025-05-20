//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11

#define NUM_PLANETS 5

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

Planet planets[NUM_PLANETS] = {
    {"Sun", 1e30, 0, 0, 0, 0, 0, 0},
    {"Mars", 0.64e24, -2.2e11, 0, 0, -2.4e3, 0, 0},
    {"Earth", 5.97e24, -1.51e11, 0, 0, -1.6e3, 0, 0},
    {"Venus", 4.86e24, -1.2e11, 0, 0, -0.5e3, 0, 0},
    {"Jupiter", 5.9e24, -8.8e11, 0, 0, -0.1e3, 0, 0}
};

void calculate_gravity(Planet *planet) {
    double total_force = 0;
    for (int i = 0; i < NUM_PLANETS; i++) {
        if (planet != &planets[i]) {
            double distance = sqrt(pow(planets[i].x - planet->x, 2) + pow(planets[i].y - planet->y, 2) + pow(planets[i].z - planet->z, 2));
            double force = G * planets[i].mass * planet->mass / distance * distance;
            total_force += force;
        }
    }

    planet->vx += total_force * planets[0].mass * planet->x / planet->mass * 0.01;
    planet->vy += total_force * planets[0].mass * planet->y / planet->mass * 0.01;
    planet->vz += total_force * planets[0].mass * planet->z / planet->mass * 0.01;
}

int main() {
    for (int i = 0; i < NUM_PLANETS; i++) {
        calculate_gravity(&planets[i]);
    }

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: (%f, %f, %f) velocity: (%f, %f, %f)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z, planets[i].vx, planets[i].vy, planets[i].vz);
    }

    return 0;
}