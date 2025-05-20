//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define N 1000

double x[N], y[N];

void generate_signal(double fc, double fs) {
    int i;
    double t = 0;

    for (i = 0; i < N; i++) {
        t += 1.0 / fs;
        x[i] = cos(2 * PI * fc * t);
    }
}

void apply_lowpass_filter(double fc, double fs) {
    int i;
    double b[3];
    double a[3];

    b[0] = 1;
    b[1] = 2;
    b[2] = 1;

    a[0] = 1;
    a[1] = -2 * cos(PI * fc / fs);
    a[2] = 1;

    for (i = 0; i < N; i++) {
        y[i] = b[0] * x[i] + b[1] * x[i - 1] + b[2] * x[i - 2]
            - a[1] * y[i - 1] - a[2] * y[i - 2];
    }
}

void print_signal(double fc, double fs) {
    int i;

    for (i = 0; i < N; i++) {
        printf("%f ", x[i]);
    }
    printf("\n");

    for (i = 0; i < N; i++) {
        printf("%f ", y[i]);
    }
    printf("\n");
}

int main() {
    double fc, fs;

    printf("Enter the cutoff frequency (Hz): ");
    scanf("%lf", &fc);

    printf("Enter the sampling frequency (Hz): ");
    scanf("%lf", &fs);

    generate_signal(fc, fs);
    apply_lowpass_filter(fc, fs);
    print_signal(fc, fs);

    return 0;
}