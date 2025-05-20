//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.6743e-11
// The gravitational constant in N(m/kg)^2
#define TIME_STEP 0.1
// Time step for simulation in seconds

typedef struct Vector3 {
    double x, y, z;
} Vector3;

typedef struct Planet {
    char name[20];
    double mass; // In kg
    Vector3 position; // In m
    Vector3 velocity; // In m/s
} Planet;

int main() {
    Planet earth = {"Earth", 5.972e24, {.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}};
    Planet moon = {"Moon", 7.342e22, {.x = 384400000, .y = 0, .z = 0}, {.x = 0, .y = 1023, .z = 0}};

    for (int i = 0; i < 1000; i++) {
        Vector3 r = {.x = moon.position.x - earth.position.x,
                     .y = moon.position.y - earth.position.y,
                     .z = moon.position.z - earth.position.z};

        double r_magnitude = sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2));
        double force_magnitude = GRAVITATIONAL_CONSTANT * earth.mass * moon.mass / pow(r_magnitude, 2);
        Vector3 force = {.x = force_magnitude * r.x / r_magnitude,
                         .y = force_magnitude * r.y / r_magnitude,
                         .z = force_magnitude * r.z / r_magnitude};

        Vector3 earth_acceleration = {.x = force.x / earth.mass,
                                      .y = force.y / earth.mass,
                                      .z = force.z / earth.mass};
        Vector3 moon_acceleration = {.x = -1 * force.x / moon.mass,
                                     .y = -1 * force.y / moon.mass,
                                     .z = -1 * force.z / moon.mass};

        earth.velocity.x += earth_acceleration.x * TIME_STEP;
        earth.velocity.y += earth_acceleration.y * TIME_STEP;
        earth.velocity.z += earth_acceleration.z * TIME_STEP;

        moon.velocity.x += moon_acceleration.x * TIME_STEP;
        moon.velocity.y += moon_acceleration.y * TIME_STEP;
        moon.velocity.z += moon_acceleration.z * TIME_STEP;

        earth.position.x += earth.velocity.x * TIME_STEP;
        earth.position.y += earth.velocity.y * TIME_STEP;
        earth.position.z += earth.velocity.z * TIME_STEP;

        moon.position.x += moon.velocity.x * TIME_STEP;
        moon.position.y += moon.velocity.y * TIME_STEP;
        moon.position.z += moon.velocity.z * TIME_STEP;

        printf("Earth position: (%f, %f, %f)\n", earth.position.x, earth.position.y, earth.position.z);
        printf("Moon position: (%f, %f, %f)\n", moon.position.x, moon.position.y, moon.position.z);
    }
    return 0;
}