//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.674e-11f

typedef struct Planet {
    char name[20];
    float mass;
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
} Planet;

int main() {
    // Create an array of planets
    Planet planets[] = {
        {"Sun", 1.98e30f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
        {"Earth", 5.97e24f, 1.51e11f, -1.51e11f, 0.0f, 0.0f, 0.0f, 0.0f},
        {"Mars", 0.64e24f, 2.48e10f, -2.48e10f, 0.0f, 0.0f, 0.0f, 0.0f},
        {"Jupiter", 5.9e24f, 5.20e11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}
    };

    // Simulate gravity between planets
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            float dx = planets[i].x - planets[j].x;
            float dy = planets[i].y - planets[j].y;
            float dz = planets[i].z - planets[j].z;

            float distance = sqrtf(dx * dx + dy * dy + dz * dz);

            float force = GRAVITY_CONSTANT * planets[i].mass * planets[j].mass / distance;

            // Calculate the acceleration of each planet due to gravity
            planets[i].vx += force * dx / planets[i].mass;
            planets[i].vy += force * dy / planets[i].mass;
            planets[i].vz += force * dz / planets[i].mass;

            planets[j].vx -= force * dx / planets[j].mass;
            planets[j].vy -= force * dy / planets[j].mass;
            planets[j].vz -= force * dz / planets[j].mass;
        }
    }

    // Print the final positions and velocities of the planets
    for (int i = 0; i < 4; i++) {
        printf("Planet: %s\n", planets[i].name);
        printf("x: %.2f, y: %.2f, z: %.2f\n", planets[i].x, planets[i].y, planets[i].z);
        printf("vx: %.2f, vy: %.2f, vz: %.2f\n", planets[i].vx, planets[i].vy, planets[i].vz);
        printf("\n");
    }

    return 0;
}