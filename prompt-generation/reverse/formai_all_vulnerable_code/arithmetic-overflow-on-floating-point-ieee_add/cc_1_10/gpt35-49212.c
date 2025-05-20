//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674E-11 // gravitational constant
#define TIMESTEP 0.1 // time interval for simulation
#define N 4 // number of planets

// define a planet data structure
typedef struct {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} Planet;

// function to calculate gravitational force on a planet
void calcForce(Planet *p1, Planet *p2, double *fx, double *fy) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = hypot(dx, dy);
    double force = G * p1->mass * p2->mass / distance / distance;
    *fx += force * dx / distance;
    *fy += force * dy / distance;
}

int main() {
    // initialize planets
    Planet planets[N] = {
        {6.0E24, 0.0, 0.0, 0.0, 0.0}, // Earth
        {2.0E30, 1.5E11, 0.0, 0.0, 3.0E4}, // Sun
        {3.3E23, 1.0E11, 0.0, 0.0, 4.0E4}, // Mercury
        {6.4E23, 2.3E11, 0.0, 0.0, 2.0E4} // Mars
    };

    // simulate gravity
    int i, j, k;
    double fx, fy, ax, ay;
    for (i = 0; i < 10000; i++) {
        // reset net force on each planet
        for (j = 0; j < N; j++) {
            ax = 0.0;
            ay = 0.0;
            Planet *p1 = &planets[j];
            // calculate net force on planet
            for (k = 0; k < N; k++) {
                if (j != k) {
                    Planet *p2 = &planets[k];
                    calcForce(p1, p2, &fx, &fy);
                }
            }
            ax += fx / p1->mass;
            ay += fy / p1->mass;
            // update velocity and position of planet
            p1->vx += ax * TIMESTEP;
            p1->vy += ay * TIMESTEP;
            p1->x += p1->vx * TIMESTEP;
            p1->y += p1->vy * TIMESTEP;
        }
    }

    // print final positions of planets
    for (i = 0; i < N; i++) {
        printf("Planet %d: x = %e, y = %e\n", i, planets[i].x, planets[i].y);
    }
    return 0;
}