//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void real_fft(double *x, double *y, int n) {
    int i, j, k, l;
    double c, s, t, u, w;
    for (i = 0; i < n; i++) {
        y[i] = x[i];
    }
    for (l = 1; l < n; l *= 2) {
        w = PI / l;
        for (i = 0; i < n; i += 2 * l) {
            for (j = 0; j < l; j++) {
                c = cos(w * j);
                s = sin(w * j);
                for (k = 0; k < l; k++) {
                    t = y[i + j + k];
                    u = y[i + j + k + l];
                    y[i + j + k] = t + u;
                    y[i + j + k + l] = t - u;
                    t = y[i + j + k + l] * c;
                    u = y[i + j + k + l] * s;
                    y[i + j + k] = y[i + j + k] - t + u;
                    y[i + j + k + l] = y[i + j + k] + t + u;
                }
            }
        }
    }
}

void real_ifft(double *x, double *y, int n) {
    int i, j, k, l;
    double c, s, t, u, w;
    for (i = 0; i < n; i++) {
        y[i] = x[i];
    }
    for (l = 1; l < n; l *= 2) {
        w = PI / l;
        for (i = 0; i < n; i += 2 * l) {
            for (j = 0; j < l; j++) {
                c = cos(w * j);
                s = sin(w * j);
                for (k = 0; k < l; k++) {
                    t = y[i + j + k];
                    u = y[i + j + k + l];
                    y[i + j + k] = t + u;
                    y[i + j + k + l] = t - u;
                    t = y[i + j + k + l] * c;
                    u = y[i + j + k + l] * s;
                    y[i + j + k] = y[i + j + k] - t - u;
                    y[i + j + k + l] = y[i + j + k] + t - u;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        y[i] /= n;
    }
}

int main(void) {
    int n;
    double *x, *y, *z;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    x = malloc(n * sizeof(double));
    y = malloc(n * sizeof(double));
    z = malloc(n * sizeof(double));
    printf("Enter the input sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }
    real_fft(x, y, n);
    real_ifft(y, z, n);
    printf("The output sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("%lf ", z[i]);
    }
    printf("\n");
    free(x);
    free(y);
    free(z);
    return 0;
}