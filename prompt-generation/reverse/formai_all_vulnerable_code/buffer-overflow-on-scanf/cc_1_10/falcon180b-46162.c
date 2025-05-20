//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define PI 3.1415926535
#define DELTA (2*PI/N)

void hamming_window(double *window, int n) {
    int i;
    for (i = 0; i < n; i++) {
        window[i] = 0.54 - 0.46 * cos(2*PI*i/(n-1));
    }
}

void fft(double *x, double *y, int n) {
    int i, j, k, m;
    double theta, w, wk, t1, t2;

    for (i = 0; i < n; i++) {
        y[i] = x[i];
    }

    for (m = 1; m < n; m *= 2) {
        theta = PI/m;
        w = cos(theta);
        wk = sin(theta);

        for (i = 0; i < n; i += m*2) {
            for (j = 0; j < m; j++) {
                t1 = y[i+j] * w;
                t2 = y[i+j+m] * wk;
                y[i+j] = y[i+j] + t1;
                y[i+j+m] = y[i+j+m] + t2;
            }
        }
    }
}

void power_spectrum(double *y, int n) {
    int i;
    for (i = 0; i < n; i++) {
        y[i] = 2*y[i]/n;
    }
}

void main() {
    int i, n;
    double x[N], window[N], y[N], ps[N];

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    printf("Enter the signal:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    hamming_window(window, n);

    for (i = 0; i < n; i++) {
        x[i] *= window[i];
    }

    fft(x, y, n);

    power_spectrum(y, n);

    printf("The power spectrum is:\n");
    for (i = 0; i < n; i++) {
        printf("%lf\n", ps[i]);
    }
}