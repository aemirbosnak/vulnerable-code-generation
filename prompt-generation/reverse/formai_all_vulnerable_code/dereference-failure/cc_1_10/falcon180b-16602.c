//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 1000
#define GRAVITY 0.1
#define DAMPING 0.9
#define TIMESTEP 0.01

void generate_initial_conditions(double *x, double *v, int n) {
    for(int i=0; i<n; i++) {
        x[i] = (double)rand()/RAND_MAX * 2.0 - 1.0;
        v[i] = (double)rand()/RAND_MAX * 0.1 - 0.05;
    }
}

void apply_forces(double *x, double *v, double *a, int n) {
    for(int i=0; i<n; i++) {
        a[i] = -GRAVITY*x[i] - DAMPING*v[i];
    }
}

void update_velocities(double *v, double *a, int n) {
    for(int i=0; i<n; i++) {
        v[i] += a[i]*TIMESTEP;
    }
}

void update_positions(double *x, double *v, double *a, int n) {
    for(int i=0; i<n; i++) {
        x[i] += v[i]*TIMESTEP;
    }
}

int main() {
    srand(time(NULL));

    double *x = (double*)malloc(SIZE*sizeof(double));
    double *v = (double*)malloc(SIZE*sizeof(double));
    double *a = (double*)malloc(SIZE*sizeof(double));

    generate_initial_conditions(x, v, SIZE);

    int n = 0;
    while(n < SIZE) {
        apply_forces(x, v, a, SIZE);
        update_velocities(v, a, SIZE);
        update_positions(x, v, a, SIZE);
        n += SIZE/10;
        if(n >= SIZE) break;
    }

    free(x);
    free(v);
    free(a);

    return 0;
}