//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define constants
#define G 6.67430e-11
#define MASS_EARTH 5.9742e24
#define RADIUS_EARTH 6371000
#define DELTA_T 60

// Define planet struct
typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass; // mass
} planet;

// Define function to calculate gravitational force
void calc_gravity(planet *p1, planet *p2, double *fx, double *fy, double *fz) {
    double d = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) + pow(p2->z - p1->z, 2));
    double f = G * p1->mass * p2->mass / pow(d, 2);
    *fx = f * (p2->x - p1->x) / d;
    *fy = f * (p2->y - p1->y) / d;
    *fz = f * (p2->z - p1->z) / d;
}

int main() {
    // Initialize time and random seed
    time_t t;
    srand((unsigned) time(&t));

    // Initialize planet array
    planet planets[3] = {
        {.x = 0, .y = 0, .z = 0, .vx = 0, .vy = 0, .vz = 0, .mass = MASS_EARTH},
        {.x = RADIUS_EARTH + 500000, .y = 0, .z = 0, .vx = 0, .vy = 8000, .vz = 0, .mass = 2e5},
        {.x = RADIUS_EARTH - 500000, .y = 0, .z = 0, .vx = 0, .vy = -8000, .vz = 0, .mass = 2e5}
    };

    // Initialize variables
    int i, j, k;
    double fx, fy, fz;
    double ax, ay, az;
    double dx, dy, dz, dvx, dvy, dvz;

    // Run simulation for 1 day (86400 seconds)
    for (i = 0; i < 86400; i += DELTA_T) {
        // Calculate forces on each planet
        for (j = 0; j < 3; j++) {
            ax = 0; ay = 0; az = 0;
            for (k = 0; k < 3; k++) {
                if (j != k) {
                    calc_gravity(&planets[j], &planets[k], &fx, &fy, &fz);
                    ax += fx / planets[j].mass;
                    ay += fy / planets[j].mass;
                    az += fz / planets[j].mass;
                }
            }
            // Update velocity and position
            planets[j].vx += ax * DELTA_T;
            planets[j].vy += ay * DELTA_T;
            planets[j].vz += az * DELTA_T;
            planets[j].x += planets[j].vx * DELTA_T;
            planets[j].y += planets[j].vy * DELTA_T;
            planets[j].z += planets[j].vz * DELTA_T;
        }
        // Print positions of planets every hour (3600 seconds)
        if (i % 3600 == 0) {
            printf("Hour %d:\n", i / 3600);
            for (j = 0; j < 3; j++) {
                printf("Planet %d: (%.2f, %.2f, %.2f)\n", j+1, planets[j].x, planets[j].y, planets[j].z);
            }
        }
    }

    return 0;
}