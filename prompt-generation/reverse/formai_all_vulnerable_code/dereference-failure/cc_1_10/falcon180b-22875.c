//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    double x, y, vx, vy, ax, ay, dt;
    int i, n;

    // Set initial conditions
    x = 0.0;
    y = 0.0;
    vx = 1.0;
    vy = 0.0;
    ax = 0.0;
    ay = -9.8;
    dt = 0.01;

    // Set number of time steps
    n = 1000;

    // Initialize arrays for storing position and velocity
    double *x_array = malloc(n * sizeof(double));
    double *y_array = malloc(n * sizeof(double));
    double *vx_array = malloc(n * sizeof(double));
    double *vy_array = malloc(n * sizeof(double));

    // Initialize arrays
    for (i = 0; i < n; i++) {
        x_array[i] = x;
        y_array[i] = y;
        vx_array[i] = vx;
        vy_array[i] = vy;
    }

    // Perform simulation
    for (i = 0; i < n; i++) {
        x += vx * dt;
        y += vy * dt;
        vx += ax * dt;
        vy += ay * dt;
    }

    // Print results
    printf("Position: \n");
    for (i = 0; i < n; i++) {
        printf("%lf ", x_array[i]);
    }
    printf("\n");

    printf("Velocity: \n");
    for (i = 0; i < n; i++) {
        printf("%lf ", vx_array[i]);
    }
    printf("\n");

    free(x_array);
    free(y_array);
    free(vx_array);
    free(vy_array);

    return 0;
}