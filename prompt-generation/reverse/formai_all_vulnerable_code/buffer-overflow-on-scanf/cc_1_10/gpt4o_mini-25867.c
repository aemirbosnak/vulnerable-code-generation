//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: medieval
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

void generate_signal(double *signal, int length, double frequency, double sampling_rate) {
    for (int n = 0; n < length; n++) {
        signal[n] = sin(2 * M_PI * frequency * n / sampling_rate);
    }
}

void apply_hamming_window(double *signal, int length) {
    for (int n = 0; n < length; n++) {
        signal[n] *= 0.54 - 0.46 * cos((2 * M_PI * n) / (length - 1));
    }
}

void compute_dft(double *signal, int length, double *real, double *imag) {
    for (int k = 0; k < length; k++) {
        real[k] = 0;
        imag[k] = 0;
        for (int n = 0; n < length; n++) {
            real[k] += signal[n] * cos(2 * M_PI * k * n / length);
            imag[k] -= signal[n] * sin(2 * M_PI * k * n / length);
        }
    }
}

void compute_magnitude(double *real, double *imag, double *magnitude, int length) {
    for (int k = 0; k < length; k++) {
        magnitude[k] = sqrt(real[k] * real[k] + imag[k] * imag[k]);
    }
}

void print_signal(double *signal, int length) {
    printf("The signal is as follows:\n");
    for (int n = 0; n < length; n++) {
        printf("%d: %f\n", n, signal[n]);
    }
}

void print_spectrum(double *magnitude, int length) {
    printf("The magnitude spectrum is as follows:\n");
    for (int k = 0; k < length; k++) {
        printf("%d: %f\n", k, magnitude[k]);
    }
}

int main() {
    int length;
    double signal[MAX_LENGTH];
    double real[MAX_LENGTH], imag[MAX_LENGTH];
    double magnitude[MAX_LENGTH];
    double frequency = 5.0; // Frequency of the signal
    double sampling_rate = 100.0; // Sampling rate

    printf("Enter the length of the signal (up to %d): ", MAX_LENGTH);
    scanf("%d", &length);
    if (length > MAX_LENGTH || length <= 0) {
        printf("Invalid length. Please choose a number between 1 and %d.\n", MAX_LENGTH);
        return 1;
    }

    generate_signal(signal, length, frequency, sampling_rate);
    print_signal(signal, length);

    apply_hamming_window(signal, length);
    compute_dft(signal, length, real, imag);
    compute_magnitude(real, imag, magnitude, length);
    
    print_spectrum(magnitude, length);

    printf("The computation hath concluded successfully! Rejoice!\n");
    
    return 0;
}