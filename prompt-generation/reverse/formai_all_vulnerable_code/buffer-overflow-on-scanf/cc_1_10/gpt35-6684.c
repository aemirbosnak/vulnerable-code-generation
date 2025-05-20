//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to compute the discrete Fourier transform of a signal
void dft(double *x, int N, double *X_real, double *X_imag) {
    int k, n;
    double arg;
    double cos_arg, sin_arg;
    for (k = 0; k < N; k++) {
        X_real[k] = 0.0;
        X_imag[k] = 0.0;
        for (n = 0; n < N; n++) {
            arg = 2 * PI * k * n / (double) N;
            cos_arg = cos(arg);
            sin_arg = sin(arg);
            X_real[k] += x[n] * cos_arg;
            X_imag[k] -= x[n] * sin_arg;
        }
    }
}

int main() {
    int n, N;
    double *x;
    double *X_real, *X_imag;

    printf("Enter the length of the signal: ");
    scanf("%d", &N);

    x = (double *) malloc(N * sizeof(double));
    X_real = (double *) malloc(N * sizeof(double));
    X_imag = (double *) malloc(N * sizeof(double));

    printf("Enter the signal values in time domain:\n");
    for (n = 0; n < N; n++) {
        scanf("%lf", &x[n]);
    }

    dft(x, N, X_real, X_imag);

    printf("The signal in frequency domain is:\n");
    for (n = 0; n < N; n++) {
        printf("(%f + %fi)\n", X_real[n], X_imag[n]);
    }

    free(x);
    free(X_real);
    free(X_imag);

    return 0;
}