//Code Llama-13B DATASET v1.0 Category: Digital signal processing ; Style: puzzling
// Puzzling Digital Signal Processing Example Program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 1000
#define MAX_M 1000

int main() {
    int n, m, i, j, k, l;
    double x[MAX_N], y[MAX_M], z[MAX_M];
    double a, b, c, d, e, f;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    for (i = 0; i < m; i++) {
        scanf("%lf", &y[i]);
    }

    for (i = 0; i < m; i++) {
        z[i] = y[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a = 0;
            b = 0;
            c = 0;
            d = 0;
            e = 0;
            f = 0;

            for (k = 0; k < m; k++) {
                a += (x[i] + k) * y[k];
                b += (x[i] + k) * z[k];
                c += (x[i] - k) * y[k];
                d += (x[i] - k) * z[k];
                e += (x[i] + k) * (y[k] - z[k]);
                f += (x[i] - k) * (y[k] - z[k]);
            }

            y[i] = (a + b) / 2;
            z[i] = (c + d) / 2;
        }
    }

    for (i = 0; i < m; i++) {
        printf("%lf\n", y[i]);
    }

    return 0;
}