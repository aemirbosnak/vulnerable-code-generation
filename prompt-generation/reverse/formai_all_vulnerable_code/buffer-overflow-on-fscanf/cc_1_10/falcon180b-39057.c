//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WINDOW_SIZE 1024
#define OVERLAP 512
#define WINDOW_TYPE "hamming"
#define SAMPLE_RATE 44100
#define FREQUENCY 500
#define PI 3.14159265358979323846
#define TWOPI 6.28318530717958647692

float hamming(int n, int N) {
    float alpha = 0.54;
    float beta = 0.46;
    float w = 2.0 * PI * (float)n / (float)N;
    return (1 - alpha) * cos(w) + alpha * cos(2 * w);
}

int main() {
    int n, N, i, j, k;
    float x[WINDOW_SIZE], y[WINDOW_SIZE], w[WINDOW_SIZE];
    float f, phase, theta, gain;
    FILE *fp;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    for (n = 0; n < WINDOW_SIZE; n++) {
        fscanf(fp, "%f", &x[n]);
    }

    fclose(fp);

    for (i = 0; i < WINDOW_SIZE; i++) {
        y[i] = 0.0;
        for (j = 0; j < WINDOW_SIZE; j++) {
            w[j] = hamming(i - j, WINDOW_SIZE);
            y[i] += x[j] * w[j];
        }
    }

    f = FREQUENCY / SAMPLE_RATE;
    theta = f * TWOPI;
    gain = 2.0 * sin(theta / 2.0);

    for (k = 0; k < WINDOW_SIZE; k++) {
        phase = theta * (float)k / (float)WINDOW_SIZE;
        y[k] *= gain * cos(phase);
    }

    for (n = 0; n < WINDOW_SIZE; n++) {
        printf("%f\n", y[n]);
    }

    return 0;
}