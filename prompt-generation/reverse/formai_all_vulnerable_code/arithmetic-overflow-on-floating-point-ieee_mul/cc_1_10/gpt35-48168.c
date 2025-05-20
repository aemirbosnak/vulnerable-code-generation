//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surrealist
/* Welcome to the Surreal Planet Gravity Simulator! */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define Constants */

#define G 6.67E-11 // Gravitational Constant
#define TIMESTEP 0.001 // Timestep for simulation
#define DURATION 50.0 // Simulation Duration

/* Define Structures */

typedef struct {
    double x;
    double y;
} Vector2D; // 2D Vector used for positions and velocities

typedef struct {
    Vector2D position;
    Vector2D velocity;
    double mass;
} Body; // Celestial Body with position, velocity, and mass

/* Define Functions */

Vector2D calculate_gravitational_force(Body body1, Body body2) {
    double distance_sqr = pow(body1.position.x - body2.position.x, 2) + pow(body1.position.y - body2.position.y, 2);
    double distance = sqrt(distance_sqr);
    double force_magnitude = G * body1.mass * body2.mass / distance_sqr;
    Vector2D force;
    force.x = force_magnitude * (body2.position.x - body1.position.x) / distance;
    force.y = force_magnitude * (body2.position.y - body1.position.y) / distance;
    return force;
} // Calculates force between two bodies

void update_velocity_and_position(Body *body, Vector2D acceleration, double timestep) {
    body->velocity.x += acceleration.x * timestep;
    body->velocity.y += acceleration.y * timestep;
    body->position.x += body->velocity.x * timestep;
    body->position.y += body->velocity.y * timestep;
} // Updates velocity and position of a body

void simulate_gravity(Body *bodies, int num_bodies, double duration, double timestep) {
    double current_time = 0.0;
    while (current_time <= duration) {
        for (int i = 0; i < num_bodies; i++) {
            Vector2D acceleration;
            acceleration.x = 0.0;
            acceleration.y = 0.0;
            for (int j = 0; j < num_bodies; j++) {
                if (i != j) {
                    Vector2D force = calculate_gravitational_force(bodies[i], bodies[j]);
                    acceleration.x += force.x / bodies[i].mass;
                    acceleration.y += force.y / bodies[i].mass;
                }
            }
            update_velocity_and_position(&bodies[i], acceleration, timestep);
        }
        current_time += timestep;
    }
} // Simulates gravity on all bodies over a period of time

int main() {
    /* Initialize Bodies */

    Body sun;
    sun.position.x = 0.0;
    sun.position.y = 0.0;
    sun.mass = 1.989E30;
    sun.velocity.x = 0.0;
    sun.velocity.y = 0.0;

    Body earth;
    earth.position.x = 147E9;
    earth.position.y = 0.0;
    earth.mass = 5.972E24;
    earth.velocity.x = 0.0;
    earth.velocity.y = 29979.0;

    Body moon;
    moon.position.x = 147E9 + 384400E3;
    moon.position.y = 0.0;
    moon.mass = 7.342E22;
    moon.velocity.x = 0.0;
    moon.velocity.y = 3075.0 + 29979.0;

    Body mars;
    mars.position.x = 228E9;
    mars.position.y = 0.0;
    mars.mass = 6.39E23;
    mars.velocity.x = 0.0;
    mars.velocity.y = 24077.0;

    Body phobos;
    phobos.position.x = 228E9 + 9376E3;
    phobos.position.y = 0.0;
    phobos.mass = 1.06E16;
    phobos.velocity.x = 0.0;
    phobos.velocity.y = 21207.0 + 24077.0;

    Body deimos;
    deimos.position.x = 228E9 + 23463E3;
    deimos.position.y = 0.0;
    deimos.mass = 2.4E15;
    deimos.velocity.x = 0.0;
    deimos.velocity.y = 13456.0 + 24077.0;

    Body jupiter;
    jupiter.position.x = 778E9;
    jupiter.position.y = 0.0;
    jupiter.mass = 1.898E27;
    jupiter.velocity.x = 0.0;
    jupiter.velocity.y = 13069.0;

    Body io;
    io.position.x = 778E9 + 421700E3;
    io.position.y = 0.0;
    io.mass = 8.93E22;
    io.velocity.x = 0.0;
    io.velocity.y = 17616.0 + 13069.0;

    Body europa;
    europa.position.x = 778E9 + 671034E3;
    europa.position.y = 0.0;
    europa.mass = 4.8E22;
    europa.velocity.x = 0.0;
    europa.velocity.y = 13740.0 + 13069.0;

    Body ganymede;
    ganymede.position.x = 778E9 + 1070412E3;
    ganymede.position.y = 0.0;
    ganymede.mass = 1.4819E23;
    ganymede.velocity.x = 0.0;
    ganymede.velocity.y = 10861.0 + 13069.0;

    Body callisto;
    callisto.position.x = 778E9 + 1882709E3;
    callisto.position.y = 0.0;
    callisto.mass = 1.075E23;
    callisto.velocity.x = 0.0;
    callisto.velocity.y = 8205.0 + 13069.0;

    /* Simulate Gravity */

    Body bodies[] = {sun, earth, moon, mars, phobos, deimos, jupiter, io, europa, ganymede, callisto};
    int num_bodies = sizeof(bodies) / sizeof(bodies[0]);
    simulate_gravity(bodies, num_bodies, DURATION, TIMESTEP);

    /* Display Results */

    printf("The Surreal Planet Gravity Simulator has completed.\n\n");
    printf("Final positions and velocities of all bodies:\n\n");
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d:\n", i + 1);
        printf("    Position: (%.2f, %.2f)\n", bodies[i].position.x, bodies[i].position.y);
        printf("    Velocity: (%.2f, %.2f)\n", bodies[i].velocity.x, bodies[i].velocity.y);
        printf("    Mass: %g kg\n", bodies[i].mass);
    }

    return 0;
}