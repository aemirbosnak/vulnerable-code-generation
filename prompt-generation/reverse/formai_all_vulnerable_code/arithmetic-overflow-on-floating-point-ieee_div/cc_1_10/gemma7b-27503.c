//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: careful
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

int main() {
    Planet planets[4] = {
        {"Sun", 1e30, 0, 0, 0, 0, 0, 0},
        {"Earth", 5.97e24, 1.51e11, 0, 0, 0, 0, 0},
        {"Mars", 0.643e24, 2.28e11, 0, 0, 0, 0, 0},
        {"Venus", 0.81e24, 0, 0, 0, 0, 0, 0}
    };

    double time = 0;
    double dt = 0.01;

    while (time < 10) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i != j) {
                    double dx = planets[i].x - planets[j].x;
                    double dy = planets[i].y - planets[j].y;
                    double dz = planets[i].z - planets[j].z;

                    double distance = sqrt(dx * dx + dy * dy + dz * dz);

                    double force = G * planets[i].mass * planets[j].mass / distance * distance;

                    double ax = force * dx / planets[j].mass;
                    double ay = force * dy / planets[j].mass;
                    double az = force * dz / planets[j].mass;

                    planets[j].vx += ax * dt;
                    planets[j].vy += ay * dt;
                    planets[j].vz += az * dt;
                }
            }
        }

        time += dt;
    }

    for (int i = 0; i < 4; i++) {
        printf("%s's position at time %f: (%f, %f, %f)\n", planets[i].name, time, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}