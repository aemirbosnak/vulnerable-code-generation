//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: dynamic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define R 6.371e6
#define G 6.673e-11
#define M 1.989e30

typedef struct {
    double x, y, z;
} Planet;

typedef struct {
    double x, y, z;
    double vx, vy, vz;
} Velocity;

Planet planets[8] = {
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}
};

Velocity velocities[8] = {
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}
};

double compute_acceleration(double distance) {
    return G / (distance * distance * distance);
}

void update_velocities(double time) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            double distance = pow(pow(planets[i].x - planets[j].x, 2) + pow(planets[i].y - planets[j].y, 2) + pow(planets[i].z - planets[j].z, 2), 0.5);
            double acceleration = compute_acceleration(distance);
            velocities[i].vx += (planets[j].x - planets[i].x) / distance * acceleration;
            velocities[i].vy += (planets[j].y - planets[i].y) / distance * acceleration;
            velocities[i].vz += (planets[j].z - planets[i].z) / distance * acceleration;
        }
    }
}

void update_positions(double time) {
    for (int i = 0; i < 8; i++) {
        planets[i].x += velocities[i].vx * time;
        planets[i].y += velocities[i].vy * time;
        planets[i].z += velocities[i].vz * time;
    }
}

int main() {
    srand(time(NULL));

    double time = 0.0;
    double dt = 0.01;

    while (time < 10.0) {
        update_velocities(dt);
        update_positions(dt);
        printf("%f %f %f\n", planets[0].x, planets[0].y, planets[0].z);
        printf("%f %f %f\n", planets[1].x, planets[1].y, planets[1].z);
        printf("%f %f %f\n", planets[2].x, planets[2].y, planets[2].z);
        printf("%f %f %f\n", planets[3].x, planets[3].y, planets[3].z);
        printf("%f %f %f\n", planets[4].x, planets[4].y, planets[4].z);
        printf("%f %f %f\n", planets[5].x, planets[5].y, planets[5].z);
        printf("%f %f %f\n", planets[6].x, planets[6].y, planets[6].z);
        printf("%f %f %f\n", planets[7].x, planets[7].y, planets[7].z);
        printf("\n");
        time += dt;
    }

    return 0;
}