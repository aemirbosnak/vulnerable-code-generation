//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the sampling rate of the audio signal
#define SAMPLING_RATE 44100

// Define the duration of the audio signal in seconds
#define DURATION 5

// Define the number of samples in the audio signal
#define NUM_SAMPLES (SAMPLING_RATE * DURATION)

// Define the maximum amplitude of the audio signal
#define MAX_AMPLITUDE 32767

// Define the frequency of the sine wave in Hz
#define FREQUENCY 440

// Define the number of harmonics in the audio signal
#define NUM_HARMONICS 10

// Define the amplitude of each harmonic
#define HARMONIC_AMPLITUDE (MAX_AMPLITUDE / NUM_HARMONICS)

// Define the sampling interval in seconds
#define SAMPLING_INTERVAL (1.0 / SAMPLING_RATE)

// Define the function to generate a sine wave
void generate_sine_wave(float *buffer, int num_samples) {
    float phase = 0.0;
    for (int i = 0; i < num_samples; i++) {
        // Calculate the phase of the sine wave
        phase += 2.0 * M_PI * FREQUENCY / SAMPLING_RATE;

        // Generate the sine wave
        float sample = sin(phase);

        // Add harmonics to the sine wave
        for (int j = 1; j <= NUM_HARMONICS; j++) {
            sample += sin(phase * j * SAMPLING_RATE / SAMPLING_INTERVAL) * HARMONIC_AMPLITUDE;
        }

        // Normalize the sample to the maximum amplitude
        float normalized_sample = sample * MAX_AMPLITUDE;

        // Store the sample in the buffer
        buffer[i] = normalized_sample;
    }
}

int main() {
    // Allocate memory for the audio buffer
    float *buffer = (float *) malloc(NUM_SAMPLES * sizeof(float));

    // Generate the audio signal
    generate_sine_wave(buffer, NUM_SAMPLES);

    // Write the audio signal to a file
    FILE *fp = fopen("excited_audio.wav", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fwrite(buffer, sizeof(float), NUM_SAMPLES, fp);

    fclose(fp);

    // Free memory used by the audio buffer
    free(buffer);

    printf("Exciting audio signal generated and saved to file!\n");

    return 0;
}