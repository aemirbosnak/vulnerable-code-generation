//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: romantic
#include <stdio.h>
#include <math.h>
#define G 6.67259e-11

struct Planet {
    double x;
    double y;
    double z;
    double mass;
    double vx;
    double vy;
    double vz;
};

typedef struct Planet Planet;

Planet planets[] = {
    {0, 0, 0, 5.9736e24, 0, 0, 0},
    {1.49598e11, 0, 0, 6.4191e23, 0, 29783, 0},
    {0, 3.84399e8, 0, 7.349e22, 1022, 0, 0},
    {0, 0, 7.1492e6, 3.3022e23, 0, 0, 868.22},
};

int main() {
    int i, j;
    double fx, fy, fz, dist, f;

    int planetCount = sizeof(planets) / sizeof(Planet);

    for (int t = 0; t < 86400; t += 3600) {
        for (i = 0; i < planetCount; i++) {
            fx = fy = fz = 0;

            for (j = 0; j < planetCount; j++) {
                if (j == i) continue;

                dist = sqrt(pow(planets[j].x - planets[i].x, 2) +
                            pow(planets[j].y - planets[i].y, 2) +
                            pow(planets[j].z - planets[i].z, 2));

                f = G * planets[i].mass * planets[j].mass / pow(dist, 2);

                fx += f * (planets[j].x - planets[i].x) / dist;
                fy += f * (planets[j].y - planets[i].y) / dist;
                fz += f * (planets[j].z - planets[i].z) / dist;
            }

            planets[i].vx += fx / planets[i].mass * 3600;
            planets[i].vy += fy / planets[i].mass * 3600;
            planets[i].vz += fz / planets[i].mass * 3600;

            planets[i].x += planets[i].vx * 3600;
            planets[i].y += planets[i].vy * 3600;
            planets[i].z += planets[i].vz * 3600;
        }

        for (i = 0; i < planetCount; i++) {
            printf("Planet %d position: (%.3f, %.3f, %.3f)\n", i+1,
                   planets[i].x, planets[i].y, planets[i].z);
        }
    }

    return 0;
}