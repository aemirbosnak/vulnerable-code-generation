//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant

struct Vector3 {
    double x, y, z;
};

struct Planet {
    char name[20];
    double mass;
    struct Vector3 position, velocity, acceleration;
};

int main() {
    struct Planet planets[5] = { // define 5 planets
        {"Sun", 1.989e30, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        {"Mercury", 3.3011e23, {4.6001e10, 0, 0}, {0, 5.886e4, 0}, {0, 0, 0}},
        {"Venus", 4.8675e24, {1.0747e11, 0, 0}, {0, 3.5e4, 0}, {0, 0, 0}},
        {"Earth", 5.972e24, {1.471e11, 0, 0}, {0, 2.9783e4, 0}, {0, 0, 0}},
        {"Mars", 6.4171e23, {2.0662e11, 0, 0}, {0, 2.4077e4, 0}, {0, 0, 0}}
    };

    const int steps = 8760; // simulate for 1 year with 1 hour time steps
    const double dt = 3600; // 1 hour in seconds

    for (int s = 0; s < steps; s++) { // simulate for each time step
        for (int i = 0; i < 5; i++) { // calculate acceleration for each planet
            planets[i].acceleration.x = 0;
            planets[i].acceleration.y = 0;
            planets[i].acceleration.z = 0;

            for (int j = 0; j < 5; j++) {
                if (i == j) {
                    continue;
                }

                double distance = sqrt(pow(planets[j].position.x - planets[i].position.x, 2) +
                                       pow(planets[j].position.y - planets[i].position.y, 2) +
                                       pow(planets[j].position.z - planets[i].position.z, 2));

                double force = G * planets[i].mass * planets[j].mass / pow(distance, 2);

                planets[i].acceleration.x += force * (planets[j].position.x - planets[i].position.x) / distance / planets[i].mass;
                planets[i].acceleration.y += force * (planets[j].position.y - planets[i].position.y) / distance / planets[i].mass;
                planets[i].acceleration.z += force * (planets[j].position.z - planets[i].position.z) / distance / planets[i].mass;
            }
        }

        for (int i = 0; i < 5; i++) { // update position and velocity for each planet
            planets[i].position.x += planets[i].velocity.x * dt + 0.5 * planets[i].acceleration.x * pow(dt, 2);
            planets[i].position.y += planets[i].velocity.y * dt + 0.5 * planets[i].acceleration.y * pow(dt, 2);
            planets[i].position.z += planets[i].velocity.z * dt + 0.5 * planets[i].acceleration.z * pow(dt, 2);

            planets[i].velocity.x += planets[i].acceleration.x * dt;
            planets[i].velocity.y += planets[i].acceleration.y * dt;
            planets[i].velocity.z += planets[i].acceleration.z * dt;
        }
    }

    for (int i = 0; i < 5; i++) { // print the final positions and velocities for each planet
        printf("%s:\n", planets[i].name);
        printf("  position = (%.6e, %.6e, %.6e) m\n", planets[i].position.x, planets[i].position.y, planets[i].position.z);
        printf("  velocity = (%.6e, %.6e, %.6e) m/s\n", planets[i].velocity.x, planets[i].velocity.y, planets[i].velocity.z);
    }

    return 0;
}