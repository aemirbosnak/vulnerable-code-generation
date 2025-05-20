//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void generate_signal(double* signal, int length);
void apply_filter(double* signal, double* filter, int length);
void print_signal(double* signal, int length);

int main() {
    int length = 1024;
    double* signal = (double*)malloc(length * sizeof(double));
    double* filter = (double*)malloc(length * sizeof(double));

    // Generate a sine wave signal
    generate_signal(signal, length);

    // Apply a low-pass filter to the signal
    apply_filter(signal, filter, length);

    // Print the original and filtered signals
    printf("Original signal:\n");
    print_signal(signal, length);

    printf("\nFiltered signal:\n");
    print_signal(signal, length);

    free(signal);
    free(filter);
    return 0;
}

void generate_signal(double* signal, int length) {
    double frequency = 100;
    double amplitude = 1;
    double phase = 0;

    for (int i = 0; i < length; i++) {
        signal[i] = amplitude * sin(2 * M_PI * frequency * i / length + phase);
    }
}

void apply_filter(double* signal, double* filter, int length) {
    for (int i = 0; i < length; i++) {
        signal[i] *= filter[i];
    }
}

void print_signal(double* signal, int length) {
    for (int i = 0; i < length; i++) {
        printf("%f ", signal[i]);
    }
    printf("\n");
}