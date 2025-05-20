//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant
#define N 4 // number of planets

int main () {

    double m[N] = {5.7e24, 8.5e24, 1.9e27, 5.7e23}; // masses of planets
    double x[N] = {0, 1.5e11, -4e11, -1e11}; // x-coordinates of planets
    double y[N] = {0, 0, 0, 2e11}; // y-coordinates of planets
    double vx[N] = {0, 30000, 0, -20000}; // x-velocities of planets
    double vy[N] = {0, 0, 20000, 0}; // y-velocities of planets

    double ax[N], ay[N]; // acceleration in x and y directions
    double dt = 60*60*24; // time step of 1 day

    int i, j, k;
    for (k = 0; k < 365*10; k++) { // simulate 10 years

        // calculate acceleration for each planet
        for (i = 0; i < N; i++) {
            ax[i] = 0;
            ay[i] = 0;
            for (j = 0; j < N; j++) {
                if (j != i) {
                    double d = sqrt(pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2));
                    double f = G * m[i] * m[j] / pow(d, 2);
                    ax[i] += f * (x[j] - x[i]) / d / m[i];
                    ay[i] += f * (y[j] - y[i]) / d / m[i];
                }
            }
        }

        // update position and velocity of each planet
        for (i = 0; i < N; i++) {
            x[i] += vx[i] * dt + 0.5 * ax[i] * pow(dt, 2);
            y[i] += vy[i] * dt + 0.5 * ay[i] * pow(dt, 2);
            vx[i] += ax[i] * dt;
            vy[i] += ay[i] * dt;
        }

        // check for collisions
        for (i = 0; i < N; i++) {
            for (j = i+1; j < N; j++) {
                double d = sqrt(pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2));
                if (d < 6371e3) {
                    printf("Warning! Collision detected between Planet %d and Planet %d.\n", i+1, j+1);
                }
            }
        }
    }

    printf("Simulation complete.\n");

    return 0;
}