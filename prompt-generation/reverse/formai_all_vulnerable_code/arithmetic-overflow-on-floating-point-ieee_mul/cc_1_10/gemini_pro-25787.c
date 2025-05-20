//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: inquisitive
// Embark on a cosmic quest to simulate the gravitational dance of planets within the confines of your computer!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define celestial constants for our simulation:
#define G 6.674e-11 // Gravitational constant (N m^2 / kg^2)
#define NUM_PLANETS 3 // The number of celestial wanderers in our simulation

// Declare an elegant structure to represent our celestial bodies:
typedef struct Planet {
    double mass; // Mass (kg) - the essence of their gravitational pull
    double x; // X coordinate (m) - their position in our cosmic tapestry
    double y; // Y coordinate (m) - another dimension to their celestial abode
    double vx; // Velocity in the X direction (m/s) - the speed and direction of their journey
    double vy; // Velocity in the Y direction (m/s) - an orthogonal dance through the void
} Planet;

// Initialize our celestial entourage:
Planet planets[NUM_PLANETS] = {
    {1e24, 0, 0, 0, 0}, // Sun - the gravitational kingpin
    {5.972e24, 1e11, 0, 0, 1000}, // Earth - our oceanic oasis
    {0.6417e24, 2e11, 0, 0, 600} // Mars - the crimson planet
};

// Define a function to calculate the gravitational force between two planets:
double calc_force(Planet p1, Planet p2) {
    double dx = p2.x - p1.x; // Distance between their celestial abodes
    double dy = p2.y - p1.y;
    double r_squared = pow(dx, 2) + pow(dy, 2); // Square of the distance
    return (G * p1.mass * p2.mass) / r_squared; // A force that unites them
}

// Orchestrate the celestial ballet with our time-stepping loop:
int main() {
    double dt = 100; // Time step (s) - the pace of our simulation
    int num_steps = 1000; // Number of time steps - the duration of our cosmic exploration

    // Behold the waltz of celestial bodies:
    for (int i = 0; i < num_steps; i++) {
        // Calculate gravitational forces:
        for (int j = 0; j < NUM_PLANETS; j++) {
            planets[j].vx = 0; // Reset velocities
            planets[j].vy = 0;
            for (int k = 0; k < NUM_PLANETS; k++) {
                if (j == k) continue; // Planets don't attract themselves!
                double force = calc_force(planets[j], planets[k]);
                double dx = planets[k].x - planets[j].x;
                double dy = planets[k].y - planets[j].y;
                planets[j].vx += force * dx / planets[j].mass; // Acceleration in X
                planets[j].vy += force * dy / planets[j].mass; // Acceleration in Y
            }
        }

        // Update positions and velocities:
        for (int j = 0; j < NUM_PLANETS; j++) {
            planets[j].x += planets[j].vx * dt;
            planets[j].y += planets[j].vy * dt;
        }

        // Display celestial positions for each time step:
        printf("Time step %d:\n", i);
        for (int j = 0; j < NUM_PLANETS; j++) {
            printf("Planet %d: (%.2e, %.2e)\n", j, planets[j].x, planets[j].y);
        }
        printf("\n");
    }

    return 0; // Our celestial escapade concludes
}