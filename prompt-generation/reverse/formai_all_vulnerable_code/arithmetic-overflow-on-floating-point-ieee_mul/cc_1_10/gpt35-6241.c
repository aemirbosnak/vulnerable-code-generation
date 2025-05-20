//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 9
#define GRAV_CONST 6.6743e-11
#define TIMESTEP 86400 // 1 day in seconds

typedef struct {
    double x, y, z;
} Vector3;

typedef struct {
    char name[20];
    double mass; // kg
    Vector3 position; // m
    Vector3 velocity; // m/s
} Planet;

int main() {
    // seed random number generator
    srand(time(NULL));

    // create planets
    Planet planets[NUM_PLANETS] = {
        {"Sun", 1.989e30, {0, 0, 0}, {0, 0, 0}},
        {"Mercury", 3.3011e23, {0, 57.9e9, 0}, {47000, 0, 0}},
        {"Venus", 4.8675e24, {0, 108.2e9, 0}, {35000, 0, 0}},
        {"Earth", 5.972e24, {0, 149.6e9, 0}, {29783, 0, 0}},
        {"Mars", 6.39e23, {0, 227.9e9, 0}, {24100, 0, 0}},
        {"Jupiter", 1.8982e27, {0, 778.6e9, 0}, {13070, 0, 0}},
        {"Saturn", 5.6834e26, {0, 1433.5e9, 0}, {9690, 0, 0}},
        {"Uranus", 8.6810e25, {0, 2872.5e9, 0}, {6810, 0, 0}},
        {"Neptune", 1.0243e26, {0, 4495.1e9, 0}, {5430, 0, 0}}
    };

    // simulate planets
    int i, j;
    double distance, force;
    Vector3 direction, acceleration;
    for (i = 0; i < NUM_PLANETS; i++) {
        for (j = i + 1; j < NUM_PLANETS; j++) {
            // calculate distance between planets
            distance = sqrt(pow(planets[j].position.x - planets[i].position.x, 2) +
                            pow(planets[j].position.y - planets[i].position.y, 2) +
                            pow(planets[j].position.z - planets[i].position.z, 2));

            // calculate force between planets
            force = GRAV_CONST * planets[i].mass * planets[j].mass / pow(distance, 2);

            // calculate direction of force
            direction.x = (planets[j].position.x - planets[i].position.x) / distance;
            direction.y = (planets[j].position.y - planets[i].position.y) / distance;
            direction.z = (planets[j].position.z - planets[i].position.z) / distance;

            // calculate acceleration of each planet
            acceleration.x = force / planets[i].mass * direction.x;
            acceleration.y = force / planets[i].mass * direction.y;
            acceleration.z = force / planets[i].mass * direction.z;

            // update velocity of each planet
            planets[i].velocity.x += acceleration.x * TIMESTEP;
            planets[i].velocity.y += acceleration.y * TIMESTEP;
            planets[i].velocity.z += acceleration.z * TIMESTEP;
            planets[j].velocity.x -= acceleration.x * TIMESTEP;
            planets[j].velocity.y -= acceleration.y * TIMESTEP;
            planets[j].velocity.z -= acceleration.z * TIMESTEP;
        }

        // update position of each planet
        planets[i].position.x += planets[i].velocity.x * TIMESTEP;
        planets[i].position.y += planets[i].velocity.y * TIMESTEP;
        planets[i].position.z += planets[i].velocity.z * TIMESTEP;

        // print planet information
        printf("%s position: (%.2f, %.2f, %.2f)\n", planets[i].name, 
               planets[i].position.x, planets[i].position.y, planets[i].position.z);
        printf("%s velocity: (%.2f, %.2f, %.2f)\n", planets[i].name, 
               planets[i].velocity.x, planets[i].velocity.y, planets[i].velocity.z);
    }

    return 0;
}