//Falcon-180B DATASET v1.0 Category: Simulation of the Solar System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846
#define G 6.674e-11
#define DAY 86400000 // 1 day in milliseconds

// Define the celestial bodies in the solar system
typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double ax, ay, az; // acceleration
    double m; // mass
} Body;

Body sun = {0, 0, 0, 0, 0, 0, 1.9885e30}; // center of the solar system
Body earth = {1.496e11, 0, 0, 0, 0, 0, 5.972e24}; // Earth
Body moon = {384400, 0, 0, 0, 0, 0, 7.3477e22}; // Moon
Body mars = {2.279e11, 0, 0, 0, 0, 0, 6.4185e23}; // Mars

int main() {
    srand(time(NULL));

    // Initialize the simulation
    double dt = DAY / 1000; // time step in seconds
    int nsteps = 86400 / dt; // number of steps in one day

    for (int i = 0; i < nsteps; i++) {
        for (int j = 0; j < 3; j++) {
            sun.vx += 0; // sun is fixed
            earth.ax += 0; // earth is fixed
            moon.ax += G * sun.m * moon.m / pow(earth.m + moon.m, 2) * (earth.x - moon.x) / pow(earth.x - moon.x, 3);
            mars.ax += G * sun.m * mars.m / pow(mars.x, 2);
        }

        for (int j = 0; j < 3; j++) {
            sun.vx += sun.ax * dt;
            earth.vx += earth.ax * dt;
            earth.y += earth.vx * dt;
            earth.z += earth.vx * dt;
            moon.vx += moon.ax * dt;
            moon.y += moon.vx * dt;
            moon.z += moon.vx * dt;
            mars.vx += mars.ax * dt;
            mars.y += mars.vx * dt;
            mars.z += mars.vx * dt;
        }
    }

    return 0;
}