//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 5

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

Planet planets[NUM_PLANETS] = {
    {"Sun", 1e30, 0, 0, 0, 0, 0, 0},
    {"Mercury", 1e-3, -2.5e11, -5.0e11, 0, 0, 3.0e4, -5.0e3},
    {"Venus", 1e-3, -2.5e11, -2.0e11, 0, 0, -6.0e4, -2.0e3},
    {"Earth", 1e-3, -2.5e11, 0, 0, 0, 0, -1.0e3},
    {"Mars", 1e-3, -2.5e11, 1.5e11, 0, 0, 2.0e4, -4.0e3}
};

double calculate_force(double mass1, double mass2) {
    return 6.674e-11 * mass1 * mass2 / (pow(mass1 + mass2, 2) * 1e24);
}

void update_positions(double dt) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        double acceleration = calculate_force(planets[i].mass, planets[0].mass);
        planets[i].vx += acceleration * dt;
        planets[i].vy += acceleration * dt;
        planets[i].vz += acceleration * dt;
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
        planets[i].z += planets[i].vz * dt;
    }
}

int main() {
    double dt = 0.1;
    int num_steps = 100000;

    for (int step = 0; step < num_steps; step++) {
        update_positions(dt);
    }

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: x = %.2f, y = %.2f, z = %.2f\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}