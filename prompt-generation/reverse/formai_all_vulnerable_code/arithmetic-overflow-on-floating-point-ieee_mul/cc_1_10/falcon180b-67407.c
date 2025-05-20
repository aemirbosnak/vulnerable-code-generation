//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: retro
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535897932384626433832795

// Function to generate a sine wave
void generate_sine_wave(double frequency, double amplitude, double duration, double sampling_rate) {
    int i, n;
    double t, phase;
    double *wave;

    // Allocate memory for the wave
    wave = (double *) malloc(sampling_rate * duration * sizeof(double));

    // Set the initial phase to zero
    phase = 0.0;

    // Generate the wave
    for (i = 0; i < sampling_rate * duration; i++) {
        // Calculate the time in seconds
        t = i / sampling_rate;

        // Calculate the current value of the wave
        wave[i] = amplitude * sin(2 * PI * frequency * t + phase);

        // Update the phase for the next sample
        phase += 2 * PI * frequency / sampling_rate;
    }

    // Print the wave
    printf("Sine wave:\n");
    for (i = 0; i < sampling_rate * duration; i++) {
        printf("%f\n", wave[i]);
    }

    // Free the memory for the wave
    free(wave);
}

int main() {
    double frequency, amplitude, duration, sampling_rate;

    // Get user input for the wave parameters
    printf("Enter the frequency of the sine wave (in Hz): ");
    scanf("%lf", &frequency);

    printf("Enter the amplitude of the sine wave: ");
    scanf("%lf", &amplitude);

    printf("Enter the duration of the sine wave (in seconds): ");
    scanf("%lf", &duration);

    printf("Enter the sampling rate (in Hz): ");
    scanf("%lf", &sampling_rate);

    // Generate the sine wave
    generate_sine_wave(frequency, amplitude, duration, sampling_rate);

    return 0;
}