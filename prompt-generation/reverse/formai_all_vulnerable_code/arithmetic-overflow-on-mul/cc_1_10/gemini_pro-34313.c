//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N_PLANETS 100
#define G 6.67408e-11 // Gravitational constant

typedef struct {
    double x, y, z; // Coordinates
    double vx, vy, vz; // Velocities
    double m; // Mass
} Planet;

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create planets
    Planet planets[N_PLANETS];
    for (int i = 0; i < N_PLANETS; i++) {
        // Randomize position within a sphere of radius 100
        double r = 100 * sqrt(drand48());
        double theta = 2 * M_PI * drand48();
        double phi = acos(2 * drand48() - 1);
        planets[i].x = r * sin(phi) * cos(theta);
        planets[i].y = r * sin(phi) * sin(theta);
        planets[i].z = r * cos(phi);

        // Randomize velocity within a sphere of radius 10
        r = 10 * sqrt(drand48());
        theta = 2 * M_PI * drand48();
        phi = acos(2 * drand48() - 1);
        planets[i].vx = r * sin(phi) * cos(theta);
        planets[i].vy = r * sin(phi) * sin(theta);
        planets[i].vz = r * cos(phi);

        // Randomize mass within a range of 10^-10 to 10^-2
        planets[i].m = pow(10, -10 + (drand48() * (2 + 10)));
    }

    // Simulate gravity
    double dt = 0.01; // Time step
    for (int t = 0; t < 1000; t++) {
        // Calculate force on each planet
        for (int i = 0; i < N_PLANETS; i++) {
            double fx = 0, fy = 0, fz = 0;
            for (int j = 0; j < N_PLANETS; j++) {
                if (i == j) continue;

                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double dz = planets[j].z - planets[i].z;

                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double m1 = planets[i].m;
                double m2 = planets[j].m;

                fx += G * m1 * m2 * dx / (r * r * r);
                fy += G * m1 * m2 * dy / (r * r * r);
                fz += G * m1 * m2 * dz / (r * r * r);
            }

            // Update acceleration
            planets[i].vx += fx * dt / planets[i].m;
            planets[i].vy += fy * dt / planets[i].m;
            planets[i].vz += fz * dt / planets[i].m;
        }

        // Update position
        for (int i = 0; i < N_PLANETS; i++) {
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
            planets[i].z += planets[i].vz * dt;
        }
    }

    // Print final positions
    for (int i = 0; i < N_PLANETS; i++) {
        printf("Planet %d: (%.2f, %.2f, %.2f)\n", i, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}