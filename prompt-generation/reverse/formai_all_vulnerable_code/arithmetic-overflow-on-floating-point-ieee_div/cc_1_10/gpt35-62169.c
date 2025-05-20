//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: creative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159
#define G 6.67408e-11
#define AU 1.496e11

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double ax, ay, az; // acceleration
    double mass;
} Body;

int main() {

    // initialize seed for random number generator
    srand(time(NULL));

    // initialize sun
    Body sun = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1.989e30};

    // initialize planets
    Body mercury = {0, 0.3871 * AU, 0, 47362, 0, 0, 0, 0, 0, 3.285e23};
    Body venus = {0, 0.7233 * AU, 0, 35020, 0, 0, 0, 0, 0, 4.867e24};
    Body earth = {0, 1 * AU, 0, 29783, 0, 0, 0, 0, 0, 5.972e24};
    Body mars = {0, 1.5237 * AU, 0, 24077, 0, 0, 0, 0, 0, 6.39e23};
    Body jupiter = {0, 5.2028 * AU, 0, 13070, 0, 0, 0, 0, 0, 1.898e27};
    Body saturn = {0, 9.5388 * AU, 0, 9644, 0, 0, 0, 0, 0, 5.683e26};
    Body uranus = {0, 19.1914 * AU, 0, 6810, 0, 0, 0, 0, 0, 8.681e25};
    Body neptune = {0, 30.0611 * AU, 0, 5430, 0, 0, 0, 0, 0, 1.024e26};

    // array of planets
    Body planets[] = {mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};

    // initialize simulation parameters
    int num_bodies = 9;
    double dt = 86400; // seconds
    int num_steps = 365; // number of days to simulate
    double t = 0; // time
    double x, y, z, r, fx, fy, fz, ax, ay, az, ms, mt, f, dx, dy, dz;

    // simulation loop
    for (int step = 0; step < num_steps; step++) {

        // calculate gravitational forces
        for (int i = 0; i < num_bodies; i++) {
            fx = fy = fz = 0; // reset forces
            for (int j = 0; j < num_bodies; j++) {
                if (i == j) continue;
                dx = planets[j].x - planets[i].x;
                dy = planets[j].y - planets[i].y;
                dz = planets[j].z - planets[i].z;
                r = sqrt(dx*dx + dy*dy + dz*dz);
                f = G * planets[i].mass * planets[j].mass / (r*r);
                fx += f * dx / r;
                fy += f * dy / r;
                fz += f * dz / r;
            }
            planets[i].ax = fx / planets[i].mass;
            planets[i].ay = fy / planets[i].mass;
            planets[i].az = fz / planets[i].mass;
        }

        // update velocities and positions
        for (int i = 0; i < num_bodies; i++) {
            planets[i].vx += planets[i].ax * dt;
            planets[i].vy += planets[i].ay * dt;
            planets[i].vz += planets[i].az * dt;
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
            planets[i].z += planets[i].vz * dt;
        }
        
        // print output for earth every 10 days
        if (step % 10 == 0) {
            printf("t = %8.0f days | x = %12.2e m | y = %12.2e m | z = %12.2e m\n", t / 86400, earth.x, earth.y, earth.z);
        }

        t += dt; // increment time
    }

    return 0;
}