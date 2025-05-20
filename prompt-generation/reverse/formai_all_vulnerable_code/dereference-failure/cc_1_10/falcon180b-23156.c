//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    const double G = 6.674e-11; // Gravitational constant
    const double tmax = 1000; // Maximum simulation time
    const int n = 10; // Number of particles
    const double h = 1.0 / n; // Time step
    const double m = 1.0; // Mass of each particle
    const double rmin = 0.1; // Minimum distance between particles
    const double rmax = 10.0; // Maximum distance between particles

    // Initialize particle positions and velocities
    double *x = malloc(n * sizeof(double));
    double *v = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        x[i] = (double)i / (n - 1) * (rmax - rmin) + rmin;
        v[i] = 0.0;
    }

    // Initialize forces between particles
    double *f = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double r = x[j] - x[i];
            if (r < rmin) {
                r = rmin;
            }
            if (r > rmax) {
                r = rmax;
            }
            double F = G * m * m / (r * r);
            f[i] += F * (x[j] - x[i]) / r;
            f[j] -= F * (x[j] - x[i]) / r;
        }
    }

    // Run simulation
    double t = 0.0;
    while (t < tmax) {
        for (int i = 0; i < n; i++) {
            x[i] += v[i] * h;
            v[i] += f[i] * h;
        }
        t += h;
    }

    // Print final particle positions
    printf("Final particle positions:\n");
    for (int i = 0; i < n; i++) {
        printf("%f\n", x[i]);
    }

    // Free memory
    free(x);
    free(v);
    free(f);

    return 0;
}