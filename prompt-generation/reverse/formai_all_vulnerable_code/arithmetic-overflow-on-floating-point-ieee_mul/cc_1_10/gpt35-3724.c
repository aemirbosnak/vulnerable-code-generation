//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 0.0000000000667 // gravitational constant
#define TIME_STEP 86400             // simulation time step (seconds)

typedef struct {
    double x, y;    // position
    double vx, vy;  // velocity
    double fx, fy;  // force
    double mass;    // mass
} body;

int main() {
    body sun = {0, 0, 0, 0, 0, 1.989e30};    // Sun
    body earth = {1.495e11, 0, 0, 29783, 0, 5.972e24};    // Earth
    body moon = {1.496e11, 384400, -1019, 0, 0, 1.62e20}; // Moon

    body bodies[] = {sun, earth, moon};  // array of bodies
    int num_bodies = sizeof(bodies) / sizeof(bodies[0]);   // number of bodies

    double time = 0;
    while (1) {
        // reset forces
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].fx = 0;
            bodies[i].fy = 0;
        }

        // calculate forces
        for (int i = 0; i < num_bodies - 1; i++) {
            for (int j = i + 1; j < num_bodies; j++) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double r = hypot(dx, dy);
                double f = GRAV_CONST * bodies[i].mass * bodies[j].mass / (r * r);
                bodies[i].fx += f * dx / r;
                bodies[i].fy += f * dy / r;
                bodies[j].fx -= f * dx / r;
                bodies[j].fy -= f * dy / r;
            }
        }

        // update velocities and positions
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].vx += bodies[i].fx / bodies[i].mass * TIME_STEP;
            bodies[i].vy += bodies[i].fy / bodies[i].mass * TIME_STEP;
            bodies[i].x += bodies[i].vx * TIME_STEP;
            bodies[i].y += bodies[i].vy * TIME_STEP;
        }

        // output position of Earth and Moon
        printf("Time: %fs, Earth Position: (%fm, %fm), Moon Position: (%fm, %fm)\n", 
            time, earth.x, earth.y, moon.x, moon.y);

        time += TIME_STEP;
    }

    return 0;
}