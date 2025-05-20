//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant (m^3 kg^-1 s^-2)
#define EARTH_MASS 5.972e24 // Earth's mass (kg)
#define EARTH_RADIUS 6.371e6 // Earth's radius (m)
#define SUN_MASS 1.989e30 // Sun's mass (kg)
#define SUN_RADIUS 6.963e8 // Sun's radius (m)
#define NUM_PLANETS 8 // Number of planets in the solar system

typedef struct {
    double mass; // Mass (kg)
    double radius; // Radius (m)
    double x; // X-coordinate (m)
    double y; // Y-coordinate (m)
    double vx; // X-velocity (m/s)
    double vy; // Y-velocity (m/s)
} Planet;

Planet planets[NUM_PLANETS] = {
    {EARTH_MASS, EARTH_RADIUS, 0, 0, 0, 0}, // Earth
    {SUN_MASS, SUN_RADIUS, 0, 0, 0, 0}, // Sun
    {0.330e24, 3.396e6, 0.579e12, 0, 0, 0}, // Mercury
    {4.869e24, 7.149e7, -1.082e12, 0, 0, 0}, // Venus
    {5.972e24, 6.371e6, 0, 0, 0, 0}, // Earth
    {0.642e23, 3.396e6, 1.524e12, 0, 0, 0}, // Mars
    {1899e24, 7.149e7, -2.480e12, 0, 0, 0}, // Jupiter
    {568e24, 6.378e6, -3.844e12, 0, 0, 0} // Saturn
};

int main() {
    double dt = 1000; // Time step (s)
    double t = 0; // Time (s)

    // Calculate the gravitational force between each planet and the Sun
    for (int i = 0; i < NUM_PLANETS; i++) {
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                double dx = planets[i].x - planets[j].x;
                double dy = planets[i].y - planets[j].y;
                double r = sqrt(dx*dx + dy*dy);
                double F = G * planets[i].mass * planets[j].mass / (r*r);
                planets[i].vx += F * dx / planets[i].mass * dt;
                planets[i].vy += F * dy / planets[i].mass * dt;
            }
        }
    }

    // Update the positions and velocities of the planets
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
    }

    // Print the positions of the planets
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: (%.2e, %.2e)\n", i+1, planets[i].x, planets[i].y);
    }

    return 0;
}