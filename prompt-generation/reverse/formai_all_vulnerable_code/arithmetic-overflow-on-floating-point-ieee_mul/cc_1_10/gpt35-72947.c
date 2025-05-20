//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

// Planet structure
typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double mass; // mass
} Planet;

// function to calculate planet gravity
void planetGravity(Planet *p1, Planet *p2, double *fx, double *fy) {
    double distance, force;

    // calculate distance between the two planets
    distance = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));

    // calculate the force of gravity between the two planets
    force = G * p1->mass * p2->mass / pow(distance, 2);

    // calculate the direction of the force
    *fx = force * (p2->x - p1->x) / distance;
    *fy = force * (p2->y - p1->y) / distance;
}

int main() {
    int numPlanets = 3, i, j, t;
    double fx, fy, ax, ay;

    // array of planets
    Planet planets[] = {
        {0, 0, 0, 0, 5.972e24},
        {100000, 0, 0, 8000, 1000},
        {0, 100000, -8000, 0, 1000}
    };

    // simulate planet gravity
    for (t = 0; t < 10000; t++) {
        // calculate acceleration for each planet
        for (i = 0; i < numPlanets; i++) {
            ax = 0;
            ay = 0;

            for (j = 0; j < numPlanets; j++) {
                if (i != j) {
                    planetGravity(&planets[i], &planets[j], &fx, &fy);
                    ax += fx / planets[i].mass;
                    ay += fy / planets[i].mass;
                }
            }

            // update velocity and position of the planet
            planets[i].vx += ax;
            planets[i].vy += ay;
            planets[i].x += planets[i].vx;
            planets[i].y += planets[i].vy;
        }

        // print out the position of each planet
        printf("time: %d\n", t);
        for (i = 0; i < numPlanets; i++) {
            printf("Planet %d: (%lf, %lf)\n", i, planets[i].x, planets[i].y);
        }
    }
    
    return 0;
}