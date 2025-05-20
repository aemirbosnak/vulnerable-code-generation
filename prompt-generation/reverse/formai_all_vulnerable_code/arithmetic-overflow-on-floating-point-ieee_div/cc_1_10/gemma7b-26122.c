//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define NUM_PLANETS 5
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

void calculate_gravity(Planet *planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                double dx = planets[i].x - planets[j].x;
                double dy = planets[i].y - planets[j].y;
                double dz = planets[i].z - planets[j].z;
                double distance = sqrt(dx * dx + dy * dy + dz * dz);
                double force = G * planets[i].mass * planets[j].mass / distance * distance;
                planets[j].vx += force * dx / planets[j].mass;
                planets[j].vy += force * dy / planets[j].mass;
                planets[j].vz += force * dz / planets[j].mass;
            }
        }
    }
}

int main() {
    Planet planets[NUM_PLANETS] = {
        {"Sun", 1e30, 0, 0, 0, 0, 0, 0},
        {"Earth", 5.972e24, 1.518e11, 0, 0, 0, 0, 0},
        {"Mars", 0.643e24, 2.48e11, 0, 0, 0, 0, 0},
        {"Jupiter", 5.972e24, 5.20e11, 0, 0, 0, 0, 0},
        {"Venus", 0.81e24, 0, 0, 0, 0, 0, 0}
    };

    calculate_gravity(planets);

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: (%f, %f, %f) velocity: (%f, %f, %f)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z, planets[i].vx, planets[i].vy, planets[i].vz);
    }

    return 0;
}