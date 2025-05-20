//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the sampling frequency
#define SAMPLE_FREQ 44100

// Define the time duration of the signal
#define TIME_DURATION 5

// Define the number of samples
#define NUM_SAMPLES (SAMPLE_FREQ * TIME_DURATION)

// Define the sampling period
#define SAMPLING_PERIOD (1.0 / SAMPLE_FREQ)

// Define the frequency of the sine wave
#define SINE_FREQUENCY 440

// Define the sampling rate
#define SAMPLING_RATE (1.0 / SAMPLING_PERIOD)

int main() {
    // Allocate memory for the signal
    double *signal = (double *) malloc(NUM_SAMPLES * sizeof(double));

    // Initialize the signal to zero
    for (int i = 0; i < NUM_SAMPLES; i++) {
        signal[i] = 0.0;
    }

    // Generate a sine wave
    for (int i = 0; i < NUM_SAMPLES; i++) {
        double time = i * SAMPLING_PERIOD;
        double frequency = SINE_FREQUENCY * SAMPLING_RATE;
        double phase = 2.0 * M_PI * frequency * time;
        double amplitude = sin(phase);
        signal[i] += amplitude;
    }

    // Print the signal
    printf("Signal:\n");
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%f\n", signal[i]);
    }

    // Free the memory
    free(signal);

    return 0;
}