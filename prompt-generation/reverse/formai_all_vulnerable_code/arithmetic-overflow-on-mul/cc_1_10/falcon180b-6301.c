//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // Number of particles
#define LX 10 // Box length in x direction
#define LY 10 // Box length in y direction
#define V0 1 // Initial velocity of particles
#define T 1000 // Simulation time
#define DT 0.01 // Time step

double x[N], y[N], vx[N], vy[N], fx[N], fy[N]; // Particle positions and forces
double r[N]; // Radii of particles
int i, j, k; // Loop variables
double pi = 3.1415926535897932384626; // Value of pi

void init() {
    srand(time(NULL)); // Seed the random number generator with the current time
    for (i = 0; i < N; i++) {
        x[i] = rand() % LX; // Randomly place particles in the box
        y[i] = rand() % LY;
        vx[i] = V0 * (2 * rand() % 3 - 1); // Randomly assign initial velocities to particles
        vy[i] = V0 * (2 * rand() % 3 - 1);
        r[i] = 0.1; // Set the radii of particles
    }
}

void forces() {
    for (i = 0; i < N; i++) {
        fx[i] = 0;
        fy[i] = 0;
        for (j = 0; j < N; j++) {
            if (i!= j && sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) < 2 * r[i]) { // Check for collisions
                double dx = x[i] - x[j];
                double dy = y[i] - y[j];
                double dist = sqrt(pow(dx, 2) + pow(dy, 2));
                double nx = dx / dist;
                double ny = dy / dist;
                double mag = (V0 * V0) / (2 * pi * r[i] * r[j]);
                fx[i] -= nx * mag;
                fy[i] -= ny * mag;
            }
        }
    }
}

void update() {
    for (i = 0; i < N; i++) {
        x[i] += vx[i] * DT;
        y[i] += vy[i] * DT;
        if (x[i] < 0) {
            x[i] = LX - x[i]; // Reflect particles off the walls
        } else if (x[i] > LX) {
            x[i] = x[i] - LX;
        }
        if (y[i] < 0) {
            y[i] = LY - y[i];
        } else if (y[i] > LY) {
            y[i] = y[i] - LY;
        }
    }
}

void print() {
    for (i = 0; i < N; i++) {
        printf("%.2f %.2f\n", x[i], y[i]); // Print particle positions
    }
}

int main() {
    init();
    for (k = 0; k < T; k++) {
        forces();
        update();
        print();
    }
    return 0;
}