//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int main() {

    Planet planets[NUM_PLANETS] = {
        {"Sun", 1e30, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Mercury", 1e24, -2.0, -1.0, 0.0, -0.05, 0.0, 0.0},
        {"Venus", 1e24, -1.0, 0.0, 0.0, -0.02, 0.0, 0.0},
        {"Earth", 1e24, 0.0, 0.0, 0.0, -0.01, 0.0, 0.0},
        {"Mars", 1e24, 1.0, 0.0, 0.0, -0.005, 0.0, 0.0}
    };

    double G = 6.674e-11; // Gravitational constant

    for (int i = 0; i < NUM_PLANETS; i++) {
        for (int j = i; j < NUM_PLANETS; j++) {
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

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: x = %.2lf, y = %.2lf, z = %.2lf\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}