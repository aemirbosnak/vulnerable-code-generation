//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: random
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int numPlanets = 3; // number of planets in our system
    double G = 6.6743e-11; // gravitational constant
    double dt = 0.01; // time step
    double u = 1.0; // distance unit
    double m[] = {5.97e24, 7.34e22, 1.99e30}; // masses of the planets in kg
    double r[][3] = {{0, 0, 0}, {3.84403e8, 0, 0}, {1.49598e11, 0, 0}}; // initial positions of the planets in meters
    double v[][3] = {{0, 0, 0}, {0, 1.022e3, 0}, {0, 0, 29.78e3}}; // initial velocities of the planets in m/s

    double force[numPlanets][3]; // force on each planet
    double acceleration[numPlanets][3]; // acceleration of each planet
    double newton[numPlanets][numPlanets][3]; // force between each pair of planets

    for (int i = 0; i < numPlanets; i++) {
        for (int j = i+1; j < numPlanets; j++) {
            double dist[3] = {r[j][0]-r[i][0], r[j][1]-r[i][1], r[j][2]-r[i][2]};
            double mag = sqrt(dist[0]*dist[0] + dist[1]*dist[1] + dist[2]*dist[2]);
            double scalar = G * m[i] * m[j] / pow(mag, 3);
            newton[i][j][0] = scalar * dist[0];
            newton[i][j][1] = scalar * dist[1];
            newton[i][j][2] = scalar * dist[2];
            newton[j][i][0] = -newton[i][j][0];
            newton[j][i][1] = -newton[i][j][1];
            newton[j][i][2] = -newton[i][j][2];
        }
    }

    for (int t = 0; t < 365*24*3600/dt; t++) {
        for (int i = 0; i < numPlanets; i++) {
            force[i][0] = 0;
            force[i][1] = 0;
            force[i][2] = 0;
            for (int j = 0; j < numPlanets; j++) {
                if (i != j) {
                    force[i][0] += newton[i][j][0];
                    force[i][1] += newton[i][j][1];
                    force[i][2] += newton[i][j][2];
                }
            }
            acceleration[i][0] = force[i][0] / m[i];
            acceleration[i][1] = force[i][1] / m[i];
            acceleration[i][2] = force[i][2] / m[i];
            v[i][0] += acceleration[i][0] * dt;
            v[i][1] += acceleration[i][1] * dt;
            v[i][2] += acceleration[i][2] * dt;
            r[i][0] += v[i][0] * dt;
            r[i][1] += v[i][1] * dt;
            r[i][2] += v[i][2] * dt;
        }
    }

    return 0;
}