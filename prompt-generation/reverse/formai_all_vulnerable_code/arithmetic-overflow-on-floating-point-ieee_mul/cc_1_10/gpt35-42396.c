//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11 // Gravitational constant
#define MASS_SUN 1.9885e30 // Mass of Sun
#define RADIUS_SUN 6.9634e8 // Radius of Sun

struct Vec3 {
    double x;
    double y;
    double z;
};

struct Body {
    char name[20];
    double mass; // In kg
    struct Vec3 position; // In m
    struct Vec3 velocity; // In m/s
    struct Vec3 acceleration; // In m/s^2
};

int main() {
    // Define the bodies in the Solar System
    struct Body sun = {"Sun", MASS_SUN, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    struct Body earth = {"Earth", 5.97e24, {1.496e11, 0, 0}, {0, 29783, 0}, {0, 0, 0}};

    // Initialize variables
    double time = 0; // In sec
    double timestep = 86400; // In sec (1 day)
    double simtime = 365 * 86400; // In sec (1 year)

    // Start simulation
    while (time < simtime) {
        // Calculate gravitational force on Earth due to Sun
        double dist = sqrt(pow(earth.position.x - sun.position.x, 2) + pow(earth.position.y - sun.position.y, 2) + pow(earth.position.z - sun.position.z, 2));
        double force = (G * sun.mass * earth.mass) / pow(dist, 2);

        struct Vec3 sun_to_earth = {earth.position.x - sun.position.x, earth.position.y - sun.position.y, earth.position.z - sun.position.z};

        struct Vec3 force_vector = {sun_to_earth.x * force / dist, sun_to_earth.y * force / dist, sun_to_earth.z * force / dist};

        // Calculate acceleration of Earth due to Sun
        struct Vec3 acceleration = {force_vector.x / earth.mass, force_vector.y / earth.mass, force_vector.z / earth.mass};

        // Update velocity of Earth
        earth.velocity.x += acceleration.x * timestep;
        earth.velocity.y += acceleration.y * timestep;
        earth.velocity.z += acceleration.z * timestep;

        // Update position of Earth
        earth.position.x += earth.velocity.x * timestep;
        earth.position.y += earth.velocity.y * timestep;
        earth.position.z += earth.velocity.z * timestep;

        // Update time
        time += timestep;

        // Print position of Earth
        printf("Earth's position at time %lf: (%lf, %lf, %lf)\n", time, earth.position.x, earth.position.y, earth.position.z);
    }

    return 0;
}