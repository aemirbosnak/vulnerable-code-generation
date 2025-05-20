//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define TWO_PI 6.28318530717958647692

// Define the parameters for the sound wave
#define FREQUENCY 440
#define AMPLITUDE 0.5
#define DURATION 2.0

// Define the number of samples we want to generate
#define SAMPLE_RATE 44100
#define NUM_SAMPLES (DURATION * SAMPLE_RATE)

// Define the function to generate a sine wave
double sine(double x) {
    return sin(TWO_PI * FREQUENCY * x);
}

// Define the function to generate the sound wave
void generate_sound_wave(double* buffer) {
    for (int i = 0; i < NUM_SAMPLES; i++) {
        double t = i / SAMPLE_RATE;
        double sample = sine(t) * AMPLITUDE;
        buffer[i] = sample;
    }
}

int main() {
    // Allocate memory for the sound wave buffer
    double* buffer = (double*) malloc(NUM_SAMPLES * sizeof(double));

    // Generate the sound wave
    generate_sound_wave(buffer);

    // Write the sound wave to a file
    FILE* file = fopen("sound.raw", "wb");
    if (file == NULL) {
        printf("Error: could not open file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < NUM_SAMPLES; i++) {
        fwrite(&buffer[i], sizeof(double), 1, file);
    }

    fclose(file);

    // Free the memory used by the buffer
    free(buffer);

    return 0;
}