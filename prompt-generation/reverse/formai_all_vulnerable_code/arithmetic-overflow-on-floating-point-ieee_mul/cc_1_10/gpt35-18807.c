//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant
#define DT 3600 // timestep for calculations in seconds
#define MASS_EARTH 5.972e24 // mass of Earth in kg
#define RADIUS_EARTH 6.371e6 // radius of Earth in meters
#define AU 1.496e11 // astronomical unit in meters

typedef struct Planet {
    char name[20];
    double mass;
    double radius;
    double rx; // position vector components
    double ry;
    double rz;
    double vx; // velocity vector components
    double vy;
    double vz;
} Planet;

int main() {
    srand(time(NULL));

    // set up initial conditions for the Sun and three planets
    Planet sun = {"Sun", 1.989e30, 696340e3, 0, 0, 0, 0, 0, 0};

    Planet earth = {"Earth", 5.972e24, 6371e3, AU, 0, 0, 0, 29.78e3, 0};

    Planet mars = {"Mars", 6.39e23, 3400e3, -1.524 * AU, 0, 0, 0, 24.077e3, 0};

    Planet venus = {"Venus", 4.867e24, 6051e3, 0.723 * AU, 0, 0, 0, 35.02e3, 0};

    Planet planets[3] = {earth, mars, venus};

    int n = sizeof(planets)/sizeof(planets[0]);

    // run simulation for a given number of timesteps
    int num_steps = 365 * 24 * 3600 / DT; // one year in seconds / timestep
    int i, j, k;
    for (i = 0; i < num_steps; i++) {
        for (j = 0; j < n; j++) { // iterate through each planet
            double ax = 0, ay = 0, az = 0; // acceleration vector components
            for (k = 0; k < n; k++) { // iterate through each other planet
                if (j == k) continue; // skip self
                Planet other = planets[k];
                double dx = other.rx - planets[j].rx;
                double dy = other.ry - planets[j].ry;
                double dz = other.rz - planets[j].rz;
                double r = sqrt(dx*dx + dy*dy + dz*dz);
                double f = G * planets[j].mass * other.mass / pow(r, 2);
                ax += f * dx / r / planets[j].mass;
                ay += f * dy / r / planets[j].mass;
                az += f * dz / r / planets[j].mass;
            }
            // update position and velocity of planet
            planets[j].vx += ax * DT;
            planets[j].vy += ay * DT;
            planets[j].vz += az * DT;
            planets[j].rx += planets[j].vx * DT;
            planets[j].ry += planets[j].vy * DT;
            planets[j].rz += planets[j].vz * DT;
        }
    }

    // output final positions of each planet
    for (i = 0; i < n; i++) {
        printf("%s: (%.2e, %.2e, %.2e)\n", planets[i].name, planets[i].rx, planets[i].ry, planets[i].rz);
    }

    return 0;
}