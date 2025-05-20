//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 8
#define G_CONST 6.67408e-11 // Gravitational constant

typedef struct {
    char name[32];
    double mass;    // in kilograms
    double radius;  // in meters
    double px;      // x position in meters
    double py;      // y position in meters
    double vx;      // x velocity in meters/second
    double vy;      // y velocity in meters/second
} planet_t;

planet_t planets[NUM_PLANETS] = {
    {"Mercury",   3.302e23, 2.44e6,  0.0, 0.0, 0.0, 0.0},
    {"Venus",     4.869e24, 6.05e6,  0.0, 0.0, 0.0, 0.0},
    {"Earth",     5.974e24, 6.38e6,  0.0, 0.0, 0.0, 0.0},
    {"Mars",      6.419e23, 3.40e6,  0.0, 0.0, 0.0, 0.0},
    {"Jupiter",   1.899e27, 6.99e7,  0.0, 0.0, 0.0, 0.0},
    {"Saturn",    5.685e26, 5.82e7,  0.0, 0.0, 0.0, 0.0},
    {"Uranus",    8.682e25, 2.54e7,  0.0, 0.0, 0.0, 0.0},
    {"Neptune",   1.024e26, 2.46e7,  0.0, 0.0, 0.0, 0.0}
};

void update_planets(int t) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        for (int j = i + 1; j < NUM_PLANETS; j++) {
            double dx = planets[j].px - planets[i].px;
            double dy = planets[j].py - planets[i].py;
            double r = sqrt(dx*dx + dy*dy);
            double f = G_CONST * planets[i].mass * planets[j].mass / (r*r);
            double fx = f * dx / r;
            double fy = f * dy / r;
            planets[i].vx += fx / planets[i].mass * t;
            planets[i].vy += fy / planets[i].mass * t;
            planets[j].vx -= fx / planets[j].mass * t;
            planets[j].vy -= fy / planets[j].mass * t;
        }
    }

    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].px += planets[i].vx * t;
        planets[i].py += planets[i].vy * t;
    }
}

int main() {
    int n_steps = 10000;
    int dt = 60*60*24; // 1 day in seconds

    for (int i = 0; i < n_steps; i++) {
        update_planets(dt);
    }

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: (%.0f, %.0f)\n", planets[i].name, planets[i].px, planets[i].py);
    }

    return 0;
}