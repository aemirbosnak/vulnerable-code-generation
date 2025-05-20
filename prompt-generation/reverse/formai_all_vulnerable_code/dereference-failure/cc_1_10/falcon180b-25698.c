//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI (3.14159265358979323846)
#define N (1024)
#define FS (44100)

int main() {
    double t, w, x, y, z, a, b;
    double *xn, *yn, *zn, *wn;
    int i, j;

    xn = (double *) malloc(N * sizeof(double));
    yn = (double *) malloc(N * sizeof(double));
    zn = (double *) malloc(N * sizeof(double));
    wn = (double *) malloc(N * sizeof(double));

    for (i = 0; i < N; i++) {
        xn[i] = 0.0;
        yn[i] = 0.0;
        zn[i] = 0.0;
        wn[i] = 2 * PI * (double) i / (double) N * FS;
    }

    w = 2 * PI * 440 / FS;
    a = 0.5;
    b = 0.8;

    for (i = 0; i < N; i++) {
        t = (double) i / (double) FS;
        x = sin(w * t) + a * sin(3 * w * t) + b * sin(5 * w * t);
        y = cos(w * t) + a * cos(3 * w * t) + b * cos(5 * w * t);
        z = sin(2 * w * t) + a * sin(6 * w * t) + b * sin(10 * w * t);
        xn[i] = x;
        yn[i] = y;
        zn[i] = z;
    }

    for (i = 0; i < N; i++) {
        xn[i] = xn[i] * 32767.0;
        yn[i] = yn[i] * 32767.0;
        zn[i] = zn[i] * 32767.0;
    }

    for (i = 0; i < N; i++) {
        printf("%d %d %d\n", (int) xn[i], (int) yn[i], (int) zn[i]);
    }

    free(xn);
    free(yn);
    free(zn);
    free(wn);

    return 0;
}