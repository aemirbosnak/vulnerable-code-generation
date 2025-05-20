//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void generate_sine_wave(float* signal, int length, float frequency, float amplitude);
void apply_low_pass_filter(float* signal, int length, float cutoff_frequency);
void display_signal(float* signal, int length);

int main() {
    int length = 1000;
    float frequency = 50;
    float amplitude = 1;
    float cutoff_frequency = 10;

    float* signal = (float*)malloc(length * sizeof(float));

    // Generate sine wave
    generate_sine_wave(signal, length, frequency, amplitude);

    // Apply low-pass filter
    apply_low_pass_filter(signal, length, cutoff_frequency);

    // Display signal
    display_signal(signal, length);

    free(signal);
    return 0;
}

void generate_sine_wave(float* signal, int length, float frequency, float amplitude) {
    for (int i = 0; i < length; i++) {
        signal[i] = amplitude * sin(2 * M_PI * frequency * i / length);
    }
}

void apply_low_pass_filter(float* signal, int length, float cutoff_frequency) {
    float a = (1 - cos(2 * M_PI * cutoff_frequency / length)) / 2;
    float b = 1 - a;

    for (int i = 0; i < length; i++) {
        signal[i] = a * signal[i] + b * signal[i-1];
    }
}

void display_signal(float* signal, int length) {
    for (int i = 0; i < length; i++) {
        printf("%f ", signal[i]);
    }
    printf("\n");
}