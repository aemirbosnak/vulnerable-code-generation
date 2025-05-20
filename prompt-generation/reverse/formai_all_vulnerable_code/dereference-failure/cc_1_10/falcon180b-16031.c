//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to generate a sine wave with given frequency and amplitude
void generate_sine_wave(double freq, double amp, int sample_rate, int num_samples, double *wave) {
    double t = 0.0;
    int i = 0;
    while (i < num_samples) {
        wave[i] = amp * sin(2 * PI * freq * t);
        t += 1.0 / sample_rate;
        i++;
    }
}

// Function to apply low-pass filter to a waveform
void low_pass_filter(double *wave, int num_samples) {
    double alpha = 0.7; // Filter coefficient
    int i = 0;
    while (i < num_samples) {
        wave[i] = alpha * wave[i] + (1 - alpha) * wave[i - 1];
        i++;
    }
}

int main() {
    int sample_rate = 44100; // Sampling rate in Hz
    int num_samples = 44100; // Number of samples in one second
    double freq = 440.0; // Frequency of sine wave in Hz
    double amp = 0.5; // Amplitude of sine wave
    double *wave = (double *) malloc(num_samples * sizeof(double));

    // Generate sine wave
    generate_sine_wave(freq, amp, sample_rate, num_samples, wave);

    // Apply low-pass filter
    low_pass_filter(wave, num_samples);

    // Write waveform to file
    FILE *fp = fopen("waveform.txt", "w");
    for (int i = 0; i < num_samples; i++) {
        fprintf(fp, "%.8f\n", wave[i]);
    }
    fclose(fp);

    free(wave);
    return 0;
}