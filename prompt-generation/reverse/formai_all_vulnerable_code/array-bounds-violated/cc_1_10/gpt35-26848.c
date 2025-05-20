//FormAI DATASET v1.0 Category: Digital signal processing ; Style: accurate
#include <stdio.h>
#include <math.h>

// Function to calculate the magnitude of a complex number
double complexMagnitude(double real, double imag) {
    double magnitude = sqrt(real*real + imag*imag);
    return magnitude;
}

int main() {
    // Define the input signal
    int signalLength = 10;
    double inputSignal[10] = {1.0, 2.0, -1.0, 3.0, 0.0, -2.0, 1.5, -1.5, 2.5, 1.0};

    // Define the filter coefficients
    int filterLength = 3;
    double filterCoefficients[3] = {1.0, -2.0, 1.0};

    // Zero pad the input signal
    int padLength = filterLength - 1;
    double paddedSignal[signalLength + padLength];
    for (int i = 0; i < padLength; i++) {
        paddedSignal[i] = 0.0;
    }
    for (int i = 0; i < signalLength; i++) {
        paddedSignal[i+padLength] = inputSignal[i];
    }
    for (int i = signalLength + padLength; i < signalLength + 2*padLength; i++) {
        paddedSignal[i] = 0.0;
    }

    // Perform convolution
    double outputSignal[signalLength];
    for (int i = 0; i < signalLength; i++) {
        outputSignal[i] = 0.0;
        for (int j = 0; j < filterLength; j++) {
            outputSignal[i] += paddedSignal[i+j] * filterCoefficients[j];
        }
    }

    // Print output signal
    printf("Input Signal: ");
    for (int i = 0; i < signalLength; i++) {
        printf("%.1f ", inputSignal[i]);
    }
    printf("\n");

    printf("Output Signal: ");
    for (int i = 0; i < signalLength; i++) {
        printf("%.1f ", outputSignal[i]);
    }
    printf("\n");

    // Calculate and print magnitude spectrum of output signal
    printf("Magnitude Spectrum: ");
    for (int i = 0; i < signalLength; i++) {
        double magnitude = complexMagnitude(outputSignal[i], 0.0);
        printf("%.1f ", magnitude);
    }
    printf("\n");

    return 0;
}