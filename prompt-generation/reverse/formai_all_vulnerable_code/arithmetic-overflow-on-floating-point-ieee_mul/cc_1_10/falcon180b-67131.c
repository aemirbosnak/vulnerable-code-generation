//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define M 1000
#define PI 3.14159265358979323846

double x[N], y[M];

int main() {
    int i, j, n;
    double t, dt, f, freq, amp, phase;

    printf("Enter the sampling frequency (in Hz): ");
    scanf("%lf", &f);

    printf("Enter the time duration (in seconds): ");
    scanf("%lf", &t);

    dt = 1.0 / f;

    printf("Enter the number of samples (must be even): ");
    scanf("%d", &n);

    printf("Enter the frequency (in Hz): ");
    scanf("%lf", &freq);

    printf("Enter the amplitude: ");
    scanf("%lf", &amp);

    printf("Enter the phase (in degrees): ");
    scanf("%lf", &phase);

    for (i = 0; i < n; i++) {
        t = i * dt;
        x[i] = amp * sin(2 * PI * freq * t + phase * PI / 180);
    }

    for (j = 0; j < M; j++) {
        y[j] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < M; j++) {
            y[j] += x[i] * sin(2 * PI * j * i / M);
        }
    }

    for (j = 0; j < M; j++) {
        y[j] *= dt;
    }

    for (j = 0; j < M; j++) {
        printf("%lf\n", y[j]);
    }

    return 0;
}