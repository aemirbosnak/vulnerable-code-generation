//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8

void fft(int n, int *a, int *b) {
    if (n == 1) {
        return;
    }

    int n2 = n / 2;
    int *c = (int *)malloc(n * sizeof(int));
    int *d = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        c[i] = a[i];
        d[i] = b[i];
    }

    fft(n2, a, c);
    fft(n2, b, d);

    int *e = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        e[i] = c[i] + d[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = e[i];
    }

    for (int i = 0; i < n; i++) {
        b[i] = e[i + n2];
    }

    free(c);
    free(d);
    free(e);
}

int main() {
    int *a = (int *)malloc(N * sizeof(int));
    int *b = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }

    fft(N, a, b);

    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}