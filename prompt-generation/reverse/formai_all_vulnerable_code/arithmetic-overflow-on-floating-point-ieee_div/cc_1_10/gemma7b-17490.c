//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <math.h>

#define G 6.674e-11

typedef struct Planet {
    char name[20];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

int main() {
    Planet earth = {"Earth", 5.972e24, 0, 0, 0, 0, 0, 0};
    Planet mars = {"Mars", 0.643e24, 0, 1.52e11, 0, 0, 0, 0};

    double dt = 0.01;
    double t = 0;
    int nsteps = 100000;

    for (int i = 0; i < nsteps; i++) {
        double ax_earth = G * mars.mass / earth.mass * (mars.x - earth.x) / (earth.x - mars.x) * (mars.y - earth.y) / (earth.y - mars.y) * (mars.z - earth.z) / (earth.z - mars.z);
        double ay_earth = G * mars.mass / earth.mass * (mars.y - earth.y) / (earth.x - mars.x) * (mars.z - earth.z) / (earth.z - mars.z);
        double az_earth = G * mars.mass / earth.mass * (mars.z - earth.z) / (earth.x - mars.x) * (mars.y - earth.y) / (earth.z - mars.z);

        double ax_mars = G * earth.mass / mars.mass * (earth.x - mars.x) / (earth.x - mars.x) * (earth.y - mars.y) / (earth.y - mars.y) * (earth.z - earth.z) / (earth.z - mars.z);
        double ay_mars = G * earth.mass / mars.mass * (earth.y - earth.y) / (earth.x - mars.x) * (earth.z - earth.z) / (earth.z - mars.z);
        double az_mars = G * earth.mass / mars.mass * (earth.z - earth.z) / (earth.x - mars.x) * (earth.y - earth.y) / (earth.z - mars.z);

        earth.vx += ax_earth * dt;
        earth.vy += ay_earth * dt;
        earth.vz += az_earth * dt;

        mars.vx += ax_mars * dt;
        mars.vy += ay_mars * dt;
        mars.vz += az_mars * dt;

        t += dt;
    }

    printf("Time: %.2lf\n", t);
    printf("Earth's position: (%.2lf, %.2lf, %.2lf)\n", earth.x, earth.y, earth.z);
    printf("Mars's position: (%.2lf, %.2lf, %.2lf)\n", mars.x, mars.y, mars.z);

    return 0;
}