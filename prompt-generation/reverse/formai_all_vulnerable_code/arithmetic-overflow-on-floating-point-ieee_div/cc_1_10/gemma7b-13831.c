//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 5

typedef struct Planet {
    char name;
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

int main() {

    Planet planets[NUM_PLANETS] = {
        {'A', 1e30, 0, 0, 0, 0, 0, 0},
        {'B', 1e25, 1, 0, 0, 0, 0, 0},
        {'C', 1e20, 0, 1, 0, 0, 0, 0},
        {'D', 1e15, 0, 0, 1, 0, 0, 0},
        {'E', 1e10, 0, 0, 0, 0, 1, 0}
    };

    double G = 6.674e-11; // Gravitational constant

    for (int i = 0; i < NUM_PLANETS; i++) {
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                double dx = planets[i].x - planets[j].x;
                double dy = planets[i].y - planets[j].y;
                double dz = planets[i].z - planets[j].z;

                double distance = sqrt(dx * dx + dy * dy + dz * dz);

                double force = G * planets[i].mass * planets[j].mass / distance * distance;

                planets[i].vx += force * dx / planets[i].mass;
                planets[i].vy += force * dy / planets[i].mass;
                planets[i].vz += force * dz / planets[i].mass;
            }
        }
    }

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %c: x = %.2f, y = %.2f, z = %.2f, vx = %.2f, vy = %.2f, vz = %.2f\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z, planets[i].vx, planets[i].vy, planets[i].vz);
    }

    return 0;
}