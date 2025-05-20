//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: optimized
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant
#define MASS 5.97e24 // mass of Earth
#define RADIUS 6.37e6 // radius of Earth

typedef struct {
    double x;
    double y;
    double z;
} Vector;

typedef struct {
    Vector position;
    Vector velocity;
    double mass;
} Body;

// Function to calculate the distance between two points
double distance(Vector a, Vector b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

// Function to calculate the gravitational force between two bodies
Vector gravitational_force(Body a, Body b) {
    Vector direction;
    direction.x = b.position.x - a.position.x;
    direction.y = b.position.y - a.position.y;
    direction.z = b.position.z - a.position.z;

    double r = distance(a.position, b.position);
    double force = G * a.mass * b.mass / pow(r, 2);

    direction.x *= force / r;
    direction.y *= force / r;
    direction.z *= force / r;

    return direction;
}

// Function to update the position and velocity of a body
void update(Body *body, Vector acceleration, double timestep) {
    body->velocity.x += acceleration.x * timestep;
    body->velocity.y += acceleration.y * timestep;
    body->velocity.z += acceleration.z * timestep;

    body->position.x += body->velocity.x * timestep;
    body->position.y += body->velocity.y * timestep;
    body->position.z += body->velocity.z * timestep;
}

int main() {
    Body earth = {
        {0, 0, 0},
        {0, 0, 0},
        MASS
    };

    Body moon = {
        {3.84e8, 0, 0},
        {0, 1022, 0},
        7.35e22
    };

    double timestep = 60;
    double simulation_duration = 86400 * 365; // 1 year

    for (int i = 0; i < simulation_duration / timestep; i++) {
        Vector force = gravitational_force(earth, moon);
        Vector earth_acceleration = {force.x / earth.mass, force.y / earth.mass, force.z / earth.mass};
        Vector moon_acceleration = {-force.x / moon.mass, -force.y / moon.mass, -force.z / moon.mass};

        update(&earth, earth_acceleration, timestep);
        update(&moon, moon_acceleration, timestep);

        printf("Earth position: (%e, %e, %e)\n", earth.position.x, earth.position.y, earth.position.z);
        printf("Moon position: (%e, %e, %e)\n\n", moon.position.x, moon.position.y, moon.position.z);
    }

    return 0;
}