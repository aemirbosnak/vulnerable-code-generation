//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265

void planetGravity(int n, double x1, double y1, double x2, double y2, double r1, double r2, double* vx1, double* vy1, double* vx2, double* vy2) {
    // Calculate gravity between two planets
    // vx1 and vy1 are the velocities of planet 1
    // vx2 and vy2 are the velocities of planet 2
    *vx1 = (x2 - x1) * (x2 - x1) / (r1 + r2);
    *vy1 = (y2 - y1) * (y2 - y1) / (r1 + r2);
    *vx2 = (x1 - x2) * (x1 - x2) / (r1 + r2);
    *vy2 = (y1 - y2) * (y1 - y2) / (r1 + r2);
}

int main() {
    // Define the number of planets and their positions
    int n = 3;
    double x[n], y[n], r[n];

    // Initialize the positions of the planets
    for (int i = 0; i < n; i++) {
        x[i] = (double)rand() / RAND_MAX;
        y[i] = (double)rand() / RAND_MAX;
    }

    // Calculate the radius of each planet
    for (int i = 0; i < n; i++) {
        r[i] = (double)rand() / RAND_MAX;
    }

    // Calculate the velocities of the planets
    double vx[n], vy[n];
    for (int i = 0; i < n; i++) {
        vx[i] = 0.0;
        vy[i] = 0.0;
    }

    // Calculate the gravity between the planets
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            planetGravity(n, x[i], y[i], x[j], y[j], r[i], r[j], &vx[i], &vy[i], &vx[j], &vy[j]);
        }
    }

    // Print the velocities of the planets
    for (int i = 0; i < n; i++) {
        printf("Planet %d: (%f, %f), v = (%f, %f)\n", i + 1, x[i], y[i], vx[i], vy[i]);
    }

    return 0;
}