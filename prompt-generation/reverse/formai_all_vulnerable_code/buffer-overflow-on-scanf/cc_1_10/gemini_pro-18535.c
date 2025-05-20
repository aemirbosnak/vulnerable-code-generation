//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Planet;

int main() {
    int n;
    scanf("%d", &n);
    Planet *planets = malloc(n * sizeof(Planet));

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf %lf %lf", &planets[i].mass, &planets[i].x, &planets[i].y, &planets[i].z, &planets[i].vx, &planets[i].vy);
    }

    // Set the gravitational constant to 1.
    const double G = 1;

    // Simulate the motion of the planets for 100 time steps.
    for (int t = 0; t < 100; t++) {
        // Calculate the gravitational force on each planet.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double dz = planets[j].z - planets[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double force = G * planets[i].mass * planets[j].mass / (r * r);
                planets[i].vx += force * dx / r;
                planets[i].vy += force * dy / r;
                planets[i].vz += force * dz / r;
                planets[j].vx -= force * dx / r;
                planets[j].vy -= force * dy / r;
                planets[j].vz -= force * dz / r;
            }
        }

        // Update the position of each planet.
        for (int i = 0; i < n; i++) {
            planets[i].x += planets[i].vx;
            planets[i].y += planets[i].vy;
            planets[i].z += planets[i].vz;
        }
    }

    // Print the final positions of the planets.
    for (int i = 0; i < n; i++) {
        printf("%lf %lf %lf\n", planets[i].x, planets[i].y, planets[i].z);
    }

    free(planets);
    return 0;
}