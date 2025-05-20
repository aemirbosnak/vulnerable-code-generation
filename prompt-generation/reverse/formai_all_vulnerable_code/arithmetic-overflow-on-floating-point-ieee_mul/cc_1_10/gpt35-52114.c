//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: excited
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 8    /* number of planets in simulation */
#define GRAV_CONST 6.673e-11    /* gravitational constant */

/* structure to hold planet information */
typedef struct {
    double mass;    /* mass of planet */
    double x;       /* x-axis position */
    double y;       /* y-axis position */
    double z;       /* z-axis position */
    double vx;      /* x-axis velocity */
    double vy;      /* y-axis velocity */
    double vz;      /* z-axis velocity */
} Planet;

/* function to calculate gravitational force between two planets */
void gravitational_force(Planet planet1, Planet planet2, double *fx, double *fy, double *fz) {
    double distance;
    double force;

    /* calculate distance between two planets */
    distance = sqrt(pow(planet2.x - planet1.x, 2) + pow(planet2.y - planet1.y, 2) + pow(planet2.z - planet1.z, 2));

    /* calculate gravitational force */
    force = GRAV_CONST * planet1.mass * planet2.mass / pow(distance, 2);

    /* calculate x-axis, y-axis, and z-axis components of force */
    *fx = force * (planet2.x - planet1.x) / distance;
    *fy = force * (planet2.y - planet1.y) / distance;
    *fz = force * (planet2.z - planet1.z) / distance;
}

int main() {
    /* initialize planets */
    Planet planets[NUM_PLANETS] = {
        {1.98892e30, 0, 0, 0, 0, 0, 0},     /* sun */
        {3.30e23, 57.91e9, 0, 0, 0, 47.3e3, 0},    /* mercury */
        {4.87e24, 108.21e9, 0, 0, 0, 35.0e3, 0},   /* venus */
        {5.97e24, 149.60e9, 0, 0, 0, 29.8e3, 0},   /* earth */
        {6.42e23, 227.92e9, 0, 0, 0, 24.1e3, 0},   /* mars */
        {1.90e27, 778.57e9, 0, 0, 0, 13.1e3, 0},   /* jupiter */
        {5.68e26, 1.43e12, 0, 0, 0, 9.7e3, 0},     /* saturn */
        {8.68e25, 2.87e12, 0, 0, 0, 6.8e3, 0}      /* uranus */
    };

    double time, dt;
    double fx, fy, fz;
    int i, j;

    /* simulation loop */
    for (time = 0, dt = 3600*24; time < 3600*24*365*10; time += dt) {
        /* calculate forces acting on each planet */
        for (i = 0; i < NUM_PLANETS; i++) {
            planets[i].vx = 0;
            planets[i].vy = 0;
            planets[i].vz = 0;

            for (j = 0; j < NUM_PLANETS; j++) {
                if (j == i) {
                    continue;
                }

                gravitational_force(planets[i], planets[j], &fx, &fy, &fz);

                planets[i].vx += fx / planets[i].mass * dt;
                planets[i].vy += fy / planets[i].mass * dt;
                planets[i].vz += fz / planets[i].mass * dt;
            }
        }

        /* update planet positions and velocities */
        for (i = 0; i < NUM_PLANETS; i++) {
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
            planets[i].z += planets[i].vz * dt;
        }

        /* print planet positions */
        printf("Time: %lf\n", time);

        for (i = 0; i < NUM_PLANETS; i++) {
            printf("Planet %d: (%lf, %lf, %lf)\n", i, planets[i].x, planets[i].y, planets[i].z);
        }
    }

    return 0;
}