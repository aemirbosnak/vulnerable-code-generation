//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant

#define AU 149597870700 // astronomical unit
#define YEAR 31557600 // seconds in a year

#define N_PLANETS 3 // number of planets in the simulation

/* Planets' data */
typedef struct {
    char name[10]; // planet name
    double mass; // planet mass in kg
    double x, y, z; // planet position in m
    double vx, vy, vz; // planet velocity in m/s
} Planet;

/* Updates the planets' positions and velocities */
void update_planets(Planet *planets, double dt) {
    double ax, ay, az, fx, fy, fz, dx, dy, dz, r, f;
    int i, j;

    for (i = 0; i < N_PLANETS; i++) {
        ax = ay = az = 0;

        for (j = 0; j < N_PLANETS; j++) {
            if (i != j) {
                /* Calculate distance between planets */
                dx = planets[j].x - planets[i].x;
                dy = planets[j].y - planets[i].y;
                dz = planets[j].z - planets[i].z;
                r = sqrt(dx*dx + dy*dy + dz*dz);

                /* Calculate and sum the gravitational forces */
                f = G*planets[i].mass*planets[j].mass/(r*r);
                fx = f*dx/r;
                fy = f*dy/r;
                fz = f*dz/r;
                ax += fx/planets[i].mass;
                ay += fy/planets[i].mass;
                az += fz/planets[i].mass;
            }
        }

        /* Update planet's position and velocity */
        planets[i].x += planets[i].vx*dt + 0.5*ax*dt*dt;
        planets[i].y += planets[i].vy*dt + 0.5*ay*dt*dt;
        planets[i].z += planets[i].vz*dt + 0.5*az*dt*dt;
        planets[i].vx += ax*dt;
        planets[i].vy += ay*dt;
        planets[i].vz += az*dt;
    }
}

int main() {
    /* Create the planets */
    Planet planets[N_PLANETS] = {
            {"Mercury", 3.3022e23, -AU, 0, 0, 0, 47.87e3, 0},
            {"Venus", 4.8685e24, 0, 0, 0, 35.02e3, 0, 0},
            {"Earth", 5.9722e24, AU, 0, 0, 0, 29.78e3, 0}
        };

    /* Set simulation parameters */
    double dt = 10*YEAR; // time step
    double tmax = 100*YEAR; // simulation time

    /* Start simulation */
    double t = 0;
    while (t < tmax) {
        /* Update planets' positions and velocities */
        update_planets(planets, dt);

        /* Print current time and position of the Earth */
        printf("%.2f years, Earth position: (%.2e, %.2e, %.2e) m\n", t/YEAR, planets[2].x, planets[2].y, planets[2].z);

        /* Increase time */
        t += dt;
    }

    return 0;
}