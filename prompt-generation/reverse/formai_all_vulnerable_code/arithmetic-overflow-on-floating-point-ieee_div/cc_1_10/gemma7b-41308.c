//Gemma-7B DATASET v1.0 Category: Simulation of the Solar System ; Style: Ken Thompson
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

typedef struct CelestialObject {
    char name[20];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} CelestialObject;

CelestialObject solarSystem[10] = {
    {"Sun", 3e30, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {"Mercury", 1e30, -5.2e11, 0.0, 0.0, 2.96e3, 0.0, -3.26e3},
    {"Venus", 4.8e30, -2.2e11, 0.0, 0.0, 6.02e3, 0.0, -3.54e3},
    {"Earth", 5.9e24, -1.5e11, 0.0, 0.0, 0.0, 0.0, -1.6e3},
    {"Mars", 0.64e24, -2.0e11, 0.0, 0.0, 0.0, 0.0, -1.6e3},
    {"Jupiter", 5.9e26, -5.2e11, 0.0, 0.0, 9.01e3, 0.0, -1.06e3},
    {"Saturn", 5.8e26, -2.2e11, 0.0, 0.0, 6.02e3, 0.0, -1.6e3},
    {"Uranus", 1.0e26, -1.5e11, 0.0, 0.0, 0.0, 0.0, -1.6e3},
    {"Neptune", 1.0e26, -2.0e11, 0.0, 0.0, 0.0, 0.0, -1.6e3},
    {"Pluto", 1.3e22, -2.2e11, 0.0, 0.0, 0.0, 0.0, -1.6e3}
};

void updatePositions(int n) {
    for (int i = 0; i < n; i++) {
        double t = solarSystem[i].vx * solarSystem[i]. vz * 0.01;
        solarSystem[i].x += t * solarSystem[i].vx * 0.01;
        solarSystem[i].y += t * solarSystem[i].vy * 0.01;
        solarSystem[i].z += t * solarSystem[i].vz * 0.01;
    }
}

void updateVelocities(int n) {
    for (int i = 0; i < n; i++) {
        double a = 6.674e-11 * solarSystem[i].mass / solarSystem[i].x * solarSystem[i].x;
        solarSystem[i].vx += a * 0.01;
        a = 6.674e-11 * solarSystem[i].mass / solarSystem[i].y * solarSystem[i].y;
        solarSystem[i].vy += a * 0.01;
        a = 6.674e-11 * solarSystem[i].mass / solarSystem[i].z * solarSystem[i].z;
        solarSystem[i].vz += a * 0.01;
    }
}

int main() {
    int n = 10;
    for (int i = 0; i < 100000; i++) {
        updatePositions(n);
        updateVelocities(n);
    }

    for (int i = 0; i < n; i++) {
        printf("%s: (%f, %f, %f)\n", solarSystem[i].name, solarSystem[i].x, solarSystem[i].y, solarSystem[i].z);
    }

    return 0;
}