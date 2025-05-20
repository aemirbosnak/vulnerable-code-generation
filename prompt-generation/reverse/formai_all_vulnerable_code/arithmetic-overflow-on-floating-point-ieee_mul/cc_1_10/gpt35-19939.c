//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: safe
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant

struct planet {
    double x; // x-coordinate
    double y; // y-coordinate
    double vx; // velocity in x-direction
    double vy; // velocity in y-direction
    double mass; // mass of the planet
};

int main() {

    // create an array of planets
    struct planet planets[] = {
        {0, 0, 0, 0, 5.97e24}, // Earth
        {384400e3, 0, 0, 1022, 7.35e22} // Moon
    };

    int num_planets = sizeof(planets) / sizeof(planets[0]); // get number of planets

    // set up simulation parameters
    double delta_t = 100; // time step in seconds
    double t = 0; // initial time
    double simulation_time = 86400 * 365; // one Earth year

    // perform simulation
    while (t < simulation_time) {
        for (int i = 0; i < num_planets; i++) {
            double total_fx = 0;
            double total_fy = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i == j) continue; // don't calculate force on itself
                double distance = sqrt(pow(planets[j].x - planets[i].x, 2) + pow(planets[j].y - planets[i].y, 2));
                double force = G * planets[i].mass * planets[j].mass / pow(distance, 2);
                double fx = force * (planets[j].x - planets[i].x) / distance;
                double fy = force * (planets[j].y - planets[i].y) / distance;
                total_fx += fx;
                total_fy += fy;
            }
            double ax = total_fx / planets[i].mass;
            double ay = total_fy / planets[i].mass;
            planets[i].vx += ax * delta_t;
            planets[i].vy += ay * delta_t;
            planets[i].x += planets[i].vx * delta_t;
            planets[i].y += planets[i].vy * delta_t;
        }
        t += delta_t;
    }

    // print final positions of planets
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: x=%f, y=%f\n", i, planets[i].x, planets[i].y);
    }

    return 0;
}