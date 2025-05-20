//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant
#define dt 86400 // simulation timestep (1 day)

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double mass; // mass
} planet;

typedef struct {
    double x, y; // position
    double mass; // mass
} star;

planet planets[3] = { {0, 0, 0, 0, 5.97e24}, {0, 6.4e6, 420, 0, 1000}, {0, -6.4e6, -420, 0, 1000} }; // Earth, Moon1, Moon2
star sun = {0, 0, 1.989e30};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void update_planets() {
    for (int i = 0; i < 3; i++) {
        double ax = 0, ay = 0; // acceleration
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            double d = distance(planets[i].x, planets[i].y, planets[j].x, planets[j].y);
            double f = G * planets[i].mass * planets[j].mass / pow(d, 2); // force between planets
            double theta = atan2(planets[j].y - planets[i].y, planets[j].x - planets[i].x); // angle between planets
            ax += f * cos(theta) / planets[i].mass;
            ay += f * sin(theta) / planets[i].mass;
        }
        double ds = distance(planets[i].x, planets[i].y, sun.x, sun.y);
        double fs = G * planets[i].mass * sun.mass / pow(ds, 2); // force between planet and sun
        double theta_s = atan2(sun.y - planets[i].y, sun.x - planets[i].x); // angle between planet and sun
        ax += fs * cos(theta_s) / planets[i].mass;
        ay += fs * sin(theta_s) / planets[i].mass;
        planets[i].vx += ax * dt;
        planets[i].vy += ay * dt;
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
    }
}

void print_planets() {
    printf("Earth: (%f, %f)\n", planets[0].x, planets[0].y);
    printf("Moon1: (%f, %f)\n", planets[1].x, planets[1].y);
    printf("Moon2: (%f, %f)\n", planets[2].x, planets[2].y);
}

int main() {
    int num_steps = 365;
    for (int i = 0; i < num_steps; i++) {
        printf("Step %d:\n", i);
        update_planets();
        print_planets();
    }
    return 0;
}