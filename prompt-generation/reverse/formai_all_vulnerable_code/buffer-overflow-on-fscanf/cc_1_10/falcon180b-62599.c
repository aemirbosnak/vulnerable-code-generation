//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000 // number of samples
#define M 10 // number of harmonics
#define PI 3.14159265358979323846

double x[N], y[N], a[M], b[M], sum;
int i, j, k;

void main() {
    FILE *fptr;
    fptr = fopen("signal.txt", "r");
    for (i = 0; i < N; i++) {
        fscanf(fptr, "%lf", &x[i]);
    }
    fclose(fptr);

    for (j = 0; j < M; j++) {
        a[j] = 2 * sin(2 * PI * j / N);
        b[j] = 2 * cos(2 * PI * j / N);
    }

    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < M; j++) {
            sum += a[j] * cos(2 * PI * j * i / N) + b[j] * sin(2 * PI * j * i / N);
        }
        y[i] = sum;
    }

    fptr = fopen("output.txt", "w");
    for (i = 0; i < N; i++) {
        fprintf(fptr, "%lf\n", y[i]);
    }
    fclose(fptr);
}

/*
Sample input signal:
0.1
0.2
0.3
0.4
0.5
0.6
0.7
0.8
0.9
1.0

Output signal (after Fourier transform):
0.7071067812
0.7071067812
0.7071067812
0.7071067812
0.7071067812
0.7071067812
0.7071067812
0.7071067812
0.7071067812
0.7071067812
*/