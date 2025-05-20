//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 1024 // Number of samples
#define PI 3.14159265358979323846 // Pi

// Function to generate a sine wave of given frequency and amplitude
void generateSineWave(double frequency, double amplitude, double* wave, int length) {
    double phase = 0;
    for (int i = 0; i < length; i++) {
        wave[i] = amplitude * sin(2 * PI * frequency * phase);
        phase += 2 * PI * frequency / N;
    }
}

// Function to apply a low-pass filter to the signal
void lowPassFilter(double* signal, double* filteredSignal, int length, double cutoffFrequency) {
    double alpha = 2 * cutoffFrequency / PI;
    for (int i = 0; i < length; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += signal[j] * cos(2 * PI * j / N);
        }
        filteredSignal[i] = sum / (1 - alpha);
    }
}

// Function to apply a high-pass filter to the signal
void highPassFilter(double* signal, double* filteredSignal, int length, double cutoffFrequency) {
    double alpha = 2 * cutoffFrequency / PI;
    for (int i = 0; i < length; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += signal[j] * cos(2 * PI * j / N);
        }
        filteredSignal[i] = (1 - alpha) * signal[i] - alpha * sum;
    }
}

// Function to plot the input and output signals
void plotSignals(double* input, double* output, int length) {
    printf("Time\tInput\tOutput\n");
    for (int i = 0; i < length; i++) {
        printf("%d\t%f\t%f\n", i, input[i], output[i]);
    }
}

int main() {
    // Generate a sine wave of frequency 10 Hz and amplitude 1
    double frequency = 10;
    double amplitude = 1;
    double* wave = (double*) malloc(N * sizeof(double));
    generateSineWave(frequency, amplitude, wave, N);

    // Apply a low-pass filter with cutoff frequency 5 Hz
    double cutoffFrequency = 5;
    double* filteredWave = (double*) malloc(N * sizeof(double));
    lowPassFilter(wave, filteredWave, N, cutoffFrequency);

    // Apply a high-pass filter with cutoff frequency 20 Hz
    double* highPassFilteredWave = (double*) malloc(N * sizeof(double));
    highPassFilter(filteredWave, highPassFilteredWave, N, cutoffFrequency);

    // Plot the input and output signals
    plotSignals(wave, filteredWave, N);
    plotSignals(filteredWave, highPassFilteredWave, N);

    free(wave);
    free(filteredWave);
    free(highPassFilteredWave);

    return 0;
}