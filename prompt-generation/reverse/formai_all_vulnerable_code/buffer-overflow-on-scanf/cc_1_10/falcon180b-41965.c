//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define PI 3.14159265358979323846

void FFT(double x[], int n, int dir) {
    int i, j, k, m;
    double theta, w, wr, wi, v, u;

    theta = PI / n;
    w = cos(theta);
    wr = -1.0 * sin(theta);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                x[i] = x[i] * (n / (double) n);
            } else if (i > j) {
                x[i] = x[i] + x[j];
            } else {
                x[i] = x[i] - x[j];
            }
        }
    }

    for (m = 1; m < n; m *= 2) {
        theta = theta / 2.0;
        w = cos(theta);
        wr = sin(theta);

        for (i = 0; i < n; i += m) {
            for (j = 0; j < n; j += m) {
                v = w * x[j] + wr * x[j + m / 2];
                u = w * x[j + m / 2] - wr * x[j];
                x[j] = x[j] + v;
                x[j + m / 2] = x[j + m / 2] + u;
            }
        }
    }
}

void DSP(double x[], int n) {
    int i;
    double sum = 0.0;

    for (i = 0; i < n; i++) {
        sum += x[i];
    }

    printf("The sum of the array is %lf\n", sum);
}

int main() {
    double x[N];
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    FFT(x, n, 1); // FFT forward
    DSP(x, n);

    FFT(x, n, -1); // FFT backward

    return 0;
}