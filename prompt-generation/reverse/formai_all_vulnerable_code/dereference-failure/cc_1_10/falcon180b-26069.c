//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define a function to generate a sine wave
void generate_sine_wave(float *wave, int length, float frequency, float amplitude) {
    int i;
    float phase = 0.0;

    for (i = 0; i < length; i++) {
        wave[i] = amplitude * sin(2 * PI * frequency * (i + 1) / length + phase);
    }
}

// Define a function to apply a low-pass filter
void low_pass_filter(float *wave, int length, float cutoff_frequency, float sampling_frequency) {
    int i;
    float b = 2 * cutoff_frequency / sampling_frequency;
    float a = 1 - b;

    for (i = 0; i < length; i++) {
        float x = wave[i];
        float y = a * x + b * wave[i - 1];
        wave[i] = y;
    }
}

int main() {
    int length = 1000;
    float frequency = 100.0;
    float amplitude = 1.0;
    float cutoff_frequency = 50.0;
    float sampling_frequency = 44100.0;

    // Generate a sine wave
    float *wave = (float *) malloc(length * sizeof(float));
    generate_sine_wave(wave, length, frequency, amplitude);

    // Apply a low-pass filter
    low_pass_filter(wave, length, cutoff_frequency, sampling_frequency);

    // Write the filtered wave to a file
    FILE *fp = fopen("filtered_wave.raw", "wb");
    fwrite(wave, sizeof(float), length, fp);
    fclose(fp);

    return 0;
}