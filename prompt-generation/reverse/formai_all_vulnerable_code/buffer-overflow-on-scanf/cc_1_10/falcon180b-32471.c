//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void FFT(int n, double x[], double y[]) {
    int i, j, k, l, m, is, js, kk, lm, nm, t, s;
    double w, wr, wi, u, v, tempr, tempi, theta;

    for (i = 0; i < n; i++) {
        y[i] = x[i];
    }

    for (m = 1; m < n; m *= 2) {
        for (i = 0; i < n; i += m * 2) {
            for (j = 0; j < m * 2; j += 2) {
                is = i + j;
                js = is + m;
                u = y[is] * y[js];
                v = y[is + 1] * y[js + 1];
                y[is] = u + v;
                y[is + 1] = u - v;
            }
        }
    }

    for (i = 0; i < n / 2; i++) {
        tempr = y[i];
        tempi = y[i + n / 2];
        y[i] = tempr + tempi;
        y[i + n / 2] = tempr - tempi;
    }
}

void main() {
    int n, i;
    double x[100], y[100];

    printf("Enter the number of samples (max 100): ");
    scanf("%d", &n);

    printf("Enter the samples:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    FFT(n, x, y);

    printf("The frequency domain samples are:\n");
    for (i = 0; i < n; i++) {
        printf("%lf\t", y[i]);
    }
}