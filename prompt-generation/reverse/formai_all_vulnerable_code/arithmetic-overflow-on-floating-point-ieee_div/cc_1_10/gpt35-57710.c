//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81                  // acceleration due to gravity (m/s^2)

typedef struct {
    double mass;                // mass of the planet (in kg)
    double radius;              // radius of the planet (in meters)
    double x;                   // x-coordinate of the planet (in meters)
    double y;                   // y-coordinate of the planet (in meters)
    double vx;                  // velocity in x-direction (in m/s)
    double vy;                  // velocity in y-direction (in m/s)
    double ax;                  // acceleration in x-direction (in m/s^2)
    double ay;                  // acceleration in y-direction (in m/s^2)
} planet;

void update_planet(planet *p, double dt) {
    double r = sqrt(p->x * p->x + p->y * p->y);  // distance from the planet to the origin
    double F = G * p->mass / (r * r);            // gravitational force on the planet
    double angle = atan2(p->y, p->x);            // angle between the planet and the x-axis

    p->ax = -F * cos(angle) / p->mass;           // acceleration in x-direction
    p->ay = -F * sin(angle) / p->mass;           // acceleration in y-direction

    p->vx += p->ax * dt;                         // update velocity in x-direction
    p->vy += p->ay * dt;                         // update velocity in y-direction

    p->x += p->vx * dt;                          // update position in x-direction
    p->y += p->vy * dt;                          // update position in y-direction
}

int main() {
    planet earth = {
        .mass = 5.97e24,        // mass of the earth
        .radius = 6.37e6,       // radius of the earth
        .x = 0,                 // earth starts at the origin
        .y = 0,
        .vx = 0,                // earth starts with zero velocity
        .vy = 0
    };

    planet moon = {
        .mass = 7.34e22,        // mass of the moon
        .radius = 1.74e6,       // radius of the moon
        .x = 3.84e8,            // moon starts about 384,000 km away from the earth
        .y = 0,
        .vx = 0,                // moon starts with zero velocity
        .vy = 1022              // moon starts with an initial velocity of 1022 m/s in y-direction
    };

    double t = 0;               // start time
    double dt = 3600;           // time step is 1 hour
    double T = 24 * 365 * 3600; // total simulation time is 24 hours x 365 days x 3600 seconds
    int steps = T / dt;         // number of simulation steps

    for (int i = 0; i < steps; i++) {
        update_planet(&earth, dt);
        update_planet(&moon, dt);
        printf("t = %.2f s: Earth position: (%.2f, %.2f) m; Moon position: (%.2f, %.2f) m\n", t, earth.x, earth.y, moon.x, moon.y);
        t += dt;
    }

    return 0;
}