//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant
#define DT 0.1 // time step interval
#define STEPS 1000 // number of time steps

typedef struct {
    double x;
    double y;
    double z;
} Vector3;

typedef struct {
    Vector3 position;
    Vector3 velocity;
    double mass;
} Planet;

void update_velocity(Planet *a, Planet *b) {
    // calculate gravitational force
    Vector3 distance = { b->position.x - a->position.x, b->position.y - a->position.y, b->position.z - a->position.z };
    double r = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
    double force = G * a->mass * b->mass / pow(r, 2);
    Vector3 direction = { distance.x / r, distance.y / r, distance.z / r };
    Vector3 grav_force = { force * direction.x, force * direction.y, force * direction.z };

    // update velocities
    a->velocity.x += grav_force.x * DT / a->mass;
    a->velocity.y += grav_force.y * DT / a->mass;
    a->velocity.z += grav_force.z * DT / a->mass;

    b->velocity.x -= grav_force.x * DT / b->mass;
    b->velocity.y -= grav_force.y * DT / b->mass;
    b->velocity.z -= grav_force.z * DT / b->mass;
}

void update_position(Planet *planet) {
    planet->position.x += planet->velocity.x * DT;
    planet->position.y += planet->velocity.y * DT;
    planet->position.z += planet->velocity.z * DT;
}

int main() {
    // initialize planets
    Planet earth = { {0, 0, 0}, {0, 0, 0}, 5.97e24 }; // mass = 5.97e24 kg
    Planet moon = { {384400000, 0, 0}, {0, 1022, 0}, 7.35e22 }; // mass = 7.35e22 kg

    // simulate gravity
    for (int i = 0; i < STEPS; i++) {
        update_velocity(&earth, &moon);
        update_position(&earth);
        update_position(&moon);

        // output position of earth and moon
        printf("Iteration %d: Earth (%.2f, %.2f, %.2f), Moon (%.2f, %.2f, %.2f)\n", i+1,
               earth.position.x, earth.position.y, earth.position.z, moon.position.x, moon.position.y, moon.position.z);
    }

    return 0;
}