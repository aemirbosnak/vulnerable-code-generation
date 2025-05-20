//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define G 9.81
#define PI 3.14159265358979323846
#define STEP 0.01

/* Function prototypes */
void init(double *x, double *v);
void force(double *x, double *v);
void boundary(double *x, double *v);
void output(double *x, double *v);

int main() {
    double *x, *v;
    int i;

    /* Allocate memory for x and v arrays */
    x = (double *) malloc(N * sizeof(double));
    v = (double *) malloc(N * sizeof(double));

    /* Initialize arrays */
    for (i = 0; i < N; i++) {
        x[i] = 0.0;
        v[i] = 0.0;
    }

    /* Time loop */
    for (i = 0; i < 1000; i++) {
        init(x, v);
        force(x, v);
        boundary(x, v);
        output(x, v);
    }

    /* Free memory */
    free(x);
    free(v);

    return 0;
}

void init(double *x, double *v) {
    int i;

    /* Initialize positions and velocities */
    for (i = 0; i < N; i++) {
        x[i] = i / (double) N;
        v[i] = 0.0;
    }
}

void force(double *x, double *v) {
    int i;

    /* Calculate forces */
    for (i = 0; i < N; i++) {
        v[i] = v[i] - G * (x[i] - 0.5) * STEP;
    }
}

void boundary(double *x, double *v) {
    int i;

    /* Apply boundary conditions */
    for (i = 0; i < N; i++) {
        if (x[i] < 0.0) {
            x[i] = 0.0;
            v[i] = -v[i];
        } else if (x[i] > 1.0) {
            x[i] = 1.0;
            v[i] = -v[i];
        }
    }
}

void output(double *x, double *v) {
    int i;

    /* Print positions and velocities */
    for (i = 0; i < N; i++) {
        printf("%f %f\n", x[i], v[i]);
    }
}