//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complete
#include <stdio.h>
#include <math.h>

#define G 6.674e-11  // gravitational constant

#define TOTAL_TIME 86400 // total simulation time in seconds
#define TIME_STEP 60 // time step in seconds
#define NUM_PLANETS 3 // number of planets

typedef struct {
    double mass; // mass in kg
    double x, y, z; // position in meters
    double vx, vy, vz; // velocity in meters per second
} Planet;

int main() {
    // create an array of planets
    Planet planets[NUM_PLANETS] = {
        {5.97e24, 0, 0, 0, 0, 0, 0}, // Earth
        {6.39e23, 378e6, 0, 0, 0, 463, 0}, // Mars
        {1.99e30, 0, 0, 0, 0, 0, 0} // Sun
    };

    // calculate initial acceleration and set initial time
    double ax, ay, az, r, dx, dy, dz, a;
    double t = 0;
    for (int i = 0; i < NUM_PLANETS; i++) {
        ax = ay = az = 0;
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i == j) continue;
            dx = planets[j].x - planets[i].x;
            dy = planets[j].y - planets[i].y;
            dz = planets[j].z - planets[i].z;
            r = sqrt(dx * dx + dy * dy + dz * dz);
            a = G * planets[j].mass / (r * r);
            ax += a * dx / r;
            ay += a * dy / r;
            az += a * dz / r;
        }
        planets[i].vx += ax * TIME_STEP;
        planets[i].vy += ay * TIME_STEP;
        planets[i].vz += az * TIME_STEP;
    }

    // simulate motion of planets
    while (t < TOTAL_TIME) {
        // update position
        for (int i = 0; i < NUM_PLANETS; i++) {
            planets[i].x += planets[i].vx * TIME_STEP;
            planets[i].y += planets[i].vy * TIME_STEP;
            planets[i].z += planets[i].vz * TIME_STEP;
        }

        // calculate acceleration for next time step
        for (int i = 0; i < NUM_PLANETS; i++) {
            ax = ay = az = 0;
            for (int j = 0; j < NUM_PLANETS; j++) {
                if (i == j) continue;
                dx = planets[j].x - planets[i].x;
                dy = planets[j].y - planets[i].y;
                dz = planets[j].z - planets[i].z;
                r = sqrt(dx * dx + dy * dy + dz * dz);
                a = G * planets[j].mass / (r * r);
                ax += a * dx / r;
                ay += a * dy / r;
                az += a * dz / r;
            }
            planets[i].vx += ax * TIME_STEP;
            planets[i].vy += ay * TIME_STEP;
            planets[i].vz += az * TIME_STEP;
        }

        // print output
        printf("t = %lf:\n", t);
        for (int i = 0; i < NUM_PLANETS; i++) {
            printf("Planet %d: (%lf, %lf, %lf)\n",
                   i+1, planets[i].x, planets[i].y, planets[i].z);
        }

        // update time
        t += TIME_STEP;
    }

    return 0;
}