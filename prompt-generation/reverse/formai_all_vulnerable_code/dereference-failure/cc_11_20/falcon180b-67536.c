//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the length of the signal
#define N 512

// Define the sampling frequency
#define Fs 44100

// Define the frequency of the sine wave
#define f 440

int main() {

    // Allocate memory for the signal
    double *signal = (double*) malloc(N * sizeof(double));

    // Initialize the signal with a sine wave
    for (int n = 0; n < N; n++) {
        signal[n] = sin(2 * M_PI * f * n / Fs);
    }

    // Apply a low-pass filter to the signal
    for (int n = 0; n < N; n++) {
        double y = 0;
        for (int k = 0; k < n; k++) {
            y += signal[k] * exp(-k / 10);
        }
        signal[n] = y;
    }

    // Apply a high-pass filter to the signal
    for (int n = 0; n < N; n++) {
        double y = 0;
        for (int k = n; k < N; k++) {
            y += signal[k] * exp(k / 10);
        }
        signal[n] = y;
    }

    // Apply a band-pass filter to the signal
    for (int n = 0; n < N; n++) {
        double y = 0;
        for (int k = n - 10; k < n + 10; k++) {
            y += signal[k] * exp(-k / 10);
        }
        signal[n] = y;
    }

    // Apply a notch filter to the signal
    for (int n = 0; n < N; n++) {
        double y = 0;
        for (int k = 0; k < N; k++) {
            if (k!= n && k!= n - 50 && k!= n + 50) {
                y += signal[k] * exp(-k / 10);
            }
        }
        signal[n] = y;
    }

    // Print the original and filtered signals
    for (int n = 0; n < N; n++) {
        printf("%f ", signal[n]);
    }

    free(signal);

    return 0;
}