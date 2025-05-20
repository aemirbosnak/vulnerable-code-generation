//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: irregular
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    // define constants
    double pi = 3.14159265359;
    double G = 6.67430e-11;

    // define array of planets with their respective masses, distances, and velocities
    double masses[] = {1.98e30, 5.97e24, 6.39e23, 3.3e23, 1.9e27};
    double distances[] = {0, 1.496e11, 2.28e11, 7.78e11, 1.4e12};
    double velocities[] = {0, 0, 0, 0, 0};
    int num_planets = 5;

    // define variables for simulation
    double t = 0; // time
    double dt = 86400; // timestep in seconds
    double x, y; // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double r; // distance
    double F, fx, fy; // force components
    double total_energy, ke, pe; // energy

    // loop through time steps
    while (t < 31536000) { // simulate for one year
        total_energy = 0;
        for (int i = 0; i < num_planets; i++) {
            // calculate forces on each planet
            fx = 0;
            fy = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    r = sqrt(pow(distances[j]*cos(t/864), 2) + pow(distances[j]*sin(t/864), 2)); // calculate distance
                    F = G * masses[i] * masses[j] / pow(r, 2); // calculate force magnitude
                    fx += F * cos(atan2(distances[j]*sin(t/864), distances[j]*cos(t/864)) - pi); // calculate force components
                    fy += F * sin(atan2(distances[j]*sin(t/864), distances[j]*cos(t/864)) - pi);
                }
            }

            // update planet's position, velocity, and acceleration
            x = distances[i] * cos(t/864);
            y = distances[i] * sin(t/864);
            vx = velocities[i] + fx / masses[i] * dt;
            vy = velocities[i] + fy / masses[i] * dt;
            ax = fx / masses[i];
            ay = fy / masses[i];

            // calculate total energy of system
            ke = 0.5 * masses[i] * (pow(vx, 2) + pow(vy, 2));
            pe = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    r = sqrt(pow(distances[j]*cos(t/864) - x, 2) + pow(distances[j]*sin(t/864) - y, 2)); // calculate distance
                    pe -= G * masses[i] * masses[j] / r; // calculate potential energy
                }
            }
            total_energy += ke + pe;

            // update arrays with new values
            distances[i] = sqrt(pow(x + vx*dt, 2) + pow(y + vy*dt, 2));
            velocities[i] = sqrt(pow(vx + ax*dt, 2) + pow(vy + ay*dt, 2));
            fx = 0;
            fy = 0;
        }
        printf("Time: %f s, Total Energy: %e J\n", t, total_energy); // print out current time and total energy
        t += dt; // increment time
    }

    return 0;
}