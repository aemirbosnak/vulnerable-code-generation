//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define G 6.67408e-11

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
    Planet earth = {"Earth", 5.972e24, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    Planet mars = {"Mars", 0.643e24, 0.0, 1.518e11, 0.0, 0.0, 0.0, 0.0};

    double dt = 0.01;

    for (int t = 0; t < 1000; t++) {
        double ax_earth = G * mars.mass * (mars.x - earth.x) / earth.mass * earth.mass;
        double ay_earth = G * mars.mass * (mars.y - earth.y) / earth.mass * earth.mass;
        double az_earth = G * mars.mass * (mars.z - earth.z) / earth.mass * earth.mass;

        double ax_mars = G * earth.mass * (earth.x - mars.x) / mars.mass * mars.mass;
        double ay_mars = G * earth.mass * (earth.y - mars.y) / mars.mass * mars.mass;
        double az_mars = G * earth.mass * (earth.z - mars.z) / mars.mass * mars.mass;

        earth.vx += ax_earth * dt;
        earth.vy += ay_earth * dt;
        earth.vz += az_earth * dt;

        mars.vx += ax_mars * dt;
        mars.vy += ay_mars * dt;
        mars.vz += az_mars * dt;

        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;
        earth.z += earth.vz * dt;

        mars.x += mars.vx * dt;
        mars.y += mars.vy * dt;
        mars.z += mars.vz * dt;

        printf("%lf, %lf, %lf\n", earth.x, earth.y, earth.z);
    }

    return 0;
}