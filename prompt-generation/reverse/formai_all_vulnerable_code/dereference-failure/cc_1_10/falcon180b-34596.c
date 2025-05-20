//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the sampling frequency and duration
#define SAMPLING_FREQUENCY 44100
#define DURATION 5

// Define the number of samples per second
#define SAMPLES_PER_SECOND SAMPLING_FREQUENCY

// Define the number of samples for the duration
#define NUM_SAMPLES (SAMPLES_PER_SECOND * DURATION)

// Define the maximum amplitude
#define MAX_AMPLITUDE 32767

// Define the sine wave frequency
#define SINE_WAVE_FREQUENCY 440

// Define the time step for each sample
#define TIME_STEP (1.0 / SAMPLING_FREQUENCY)

// Define the sine wave function
int sine_wave(double t) {
    return sin(2 * M_PI * SINE_WAVE_FREQUENCY * t);
}

// Define the main function
int main() {
    // Allocate memory for the samples
    double *samples = (double *) malloc(NUM_SAMPLES * sizeof(double));

    // Initialize the time variable
    double t = 0;

    // Loop through the duration and generate the sine wave
    for (int i = 0; i < NUM_SAMPLES; i++) {
        // Calculate the current time
        t += TIME_STEP;

        // Calculate the current sample value
        samples[i] = sine_wave(t) * MAX_AMPLITUDE;
    }

    // Write the samples to a file
    FILE *output_file = fopen("sine_wave.raw", "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    for (int i = 0; i < NUM_SAMPLES; i++) {
        fwrite(&samples[i], sizeof(double), 1, output_file);
    }

    fclose(output_file);

    // Free the memory allocated for the samples
    free(samples);

    return 0;
}