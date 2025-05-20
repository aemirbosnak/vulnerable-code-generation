//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: peaceful
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11

typedef struct CelestialBody {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} CelestialBody;

int main() {
    // Define the celestial bodies
    CelestialBody sun = {
        .mass = 1e30,
        .x = 0,
        .y = 0,
        .z = 0,
        .vx = 0,
        .vy = 0,
        .vz = 0
    };

    CelestialBody earth = {
        .mass = 5.972e24,
        .x = 1.518e11,
        .y = 0,
        .z = 0,
        .vx = 0,
        .vy = 0,
        .vz = 0
    };

    CelestialBody moon = {
        .mass = 7.348e22,
        .x = 2.36e10,
        .y = 0,
        .z = 0,
        .vx = 0,
        .vy = 0,
        .vz = 0
    };

    // Calculate the force of gravity between each pair of bodies
    double force_sun_earth = G * sun.mass * earth.mass / (earth.x - sun.x) / (earth.y - sun.y) * 1000;
    double force_sun_moon = G * sun.mass * moon.mass / (moon.x - sun.x) / (moon.y - sun.y) * 1000;
    double force_earth_moon = G * earth.mass * moon.mass / (moon.x - earth.x) / (moon.y - earth.y) * 1000;

    // Apply the force of gravity to each body
    earth.vx += force_sun_earth * earth.mass / earth.mass * 0.01;
    moon.vx += force_sun_moon * moon.mass / moon.mass * 0.01;
    moon.vy += force_earth_moon * moon.mass / moon.mass * 0.01;

    // Print the positions and velocities of the celestial bodies
    printf("Sun:\n");
    printf("x: %.2e, y: %.2e, z: %.2e\n", sun.x, sun.y, sun.z);
    printf("vx: %.2e, vy: %.2e, vz: %.2e\n", sun.vx, sun.vy, sun.vz);

    printf("Earth:\n");
    printf("x: %.2e, y: %.2e, z: %.2e\n", earth.x, earth.y, earth.z);
    printf("vx: %.2e, vy: %.2e, vz: %.2e\n", earth.vx, earth.vy, earth.vz);

    printf("Moon:\n");
    printf("x: %.2e, y: %.2e, z: %.2e\n", moon.x, moon.y, moon.z);
    printf("vx: %.2e, vy: %.2e, vz: %.2e\n", moon.vx, moon.vy, moon.vz);

    return 0;
}