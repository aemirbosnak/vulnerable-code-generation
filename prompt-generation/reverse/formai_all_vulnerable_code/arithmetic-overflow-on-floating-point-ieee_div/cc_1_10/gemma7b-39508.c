//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: all-encompassing
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

int main()
{
    // Create an array of planets
    Planet planets[NUM_PLANETS] = {
        {"Sun", 1e30, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Mercury", 1e-3, -2.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Venus", 1e-3, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Earth", 1e-3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Mars", 1e-3, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0}
    };

    // Simulate gravity for each planet
    for (int i = 0; i < NUM_PLANETS; i++)
    {
        double acceleration = 0.0;
        for (int j = 0; j < NUM_PLANETS; j++)
        {
            if (i != j)
            {
                double distance = sqrt(pow(planets[i].x - planets[j].x, 2) + pow(planets[i].y - planets[j].y, 2) + pow(planets[i].z - planets[j].z, 2));
                acceleration += 6.674e-11 * planets[j].mass / distance;
            }
        }

        planets[i].vx += acceleration * planets[i].mass * planets[i].x / 1000.0;
        planets[i].vy += acceleration * planets[i].mass * planets[i].y / 1000.0;
        planets[i].vz += acceleration * planets[i].mass * planets[i].z / 1000.0;
    }

    // Print the new positions and velocities of each planet
    for (int i = 0; i < NUM_PLANETS; i++)
    {
        printf("%s: x = %.2f, y = %.2f, z = %.2f, vx = %.2f, vy = %.2f, vz = %.2f\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z, planets[i].vx, planets[i].vy, planets[i].vz);
    }

    return 0;
}