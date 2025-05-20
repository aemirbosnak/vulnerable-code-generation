//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define MAX_SIZE 100

double magnitude(double real, double imag) {
    return sqrt(real*real + imag*imag);
}

double phase(double real, double imag) {
    return atan2(imag, real);
}

void printComplex(double real, double imag) {
    printf("(%f + %fi)", real, imag);
}

void printMagnitudePhase(double real, double imag) {
    double mag = magnitude(real, imag);
    double phs = phase(real, imag);

    printf("Magnitude: %f\n", mag);
    printf("Phase: %f\n", phs);
}

int main() {

    double in_real[MAX_SIZE], in_imag[MAX_SIZE];
    int size = 0;

    printf("Enter size of input signal:\n");
    scanf("%d", &size);

    printf("Enter real and imaginary parts of input signal:\n");

    for (int i = 0; i < size; i++) {
        scanf("%lf %lf", &in_real[i], &in_imag[i]);
    }

    printf("\nInput Signal: ");
    for (int i = 0; i < size; i++) {
        printComplex(in_real[i], in_imag[i]);
        printf(" ");
    }
    printf("\n");

    // Fourier transform
    double out_real[MAX_SIZE], out_imag[MAX_SIZE];

    for (int k = 0; k < size; k++) {    // for each output element
        out_real[k] = out_imag[k] = 0;

        for (int n = 0; n < size; n++) {    // for each input element
            double angle = 2 * PI * n * k / size;
            out_real[k] += in_real[n] * cos(angle) + in_imag[n] * sin(angle);
            out_imag[k] -= in_real[n] * sin(angle) - in_imag[n] * cos(angle);
        }
    }

    printf("\nFourier Transform: ");
    for (int k = 0; k < size; k++) {
        printComplex(out_real[k], out_imag[k]);
        printf(" ");
    }
    printf("\n");

    printf("\nMagnitude and Phase: \n");
    for (int k = 0; k < size; k++) {
        printMagnitudePhase(out_real[k], out_imag[k]);
        printf("\n");
    }

    return 0;
}