//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surrealist
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11    // gravitational constant

// structure to hold information about a planet
typedef struct {
    char name[20];
    double mass;
    double radius;
    double x;
    double y;
    double vx;
    double vy;
} Planet;

// calculate the distance between two points in space
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// simulate the gravitational force between two planets
void gravity(Planet *p1, Planet *p2) {
    double d = distance(p1->x, p1->y, p2->x, p2->y);
    double f = G * p1->mass * p2->mass / pow(d, 2);
    double angle = atan2(p2->y - p1->y, p2->x - p1->x);
    double fx = f * cos(angle);
    double fy = f * sin(angle);
    p1->vx += fx / p1->mass;
    p1->vy += fy / p1->mass;
    p2->vx -= fx / p2->mass;
    p2->vy -= fy / p2->mass;
}

int main() {
    Planet earth = {"Earth", 5.97e24, 6.371e6, 0, 0, 0, 29783};   // initial position and velocity of Earth
    Planet sun = {"Sun", 1.989e30, 696.34e6, 0, 0, 0, 0};          // initial position and velocity of Sun

    double timestep = 24 * 3600;    // time between each iteration of the simulation
    int nsteps = 365;               // number of iterations in the simulation

    for (int i = 0; i < nsteps; i++) {
        gravity(&earth, &sun);
        earth.x += earth.vx * timestep;
        earth.y += earth.vy * timestep;
        printf("%s: x=%lf y=%lf\n", earth.name, earth.x, earth.y);
    }

    return 0;
}