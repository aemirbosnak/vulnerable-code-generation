//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define SAMPLE_RATE 44100
#define DURATION 2 // seconds
#define SIGNAL_FREQUENCY 440 // Hz, A4 note

typedef struct {
    double *input;
    double *output;
    int length;
    double alpha; // smoothing factor
} LowPassFilter;

void generateSineWave(double *signal, int length, double frequency) {
    for (int i = 0; i < length; i++) {
        signal[i] = sin(2 * PI * frequency * (i / (double) SAMPLE_RATE));
    }
}

LowPassFilter* createLowPassFilter(double cutoffFrequency) {
    LowPassFilter *filter = (LowPassFilter *)malloc(sizeof(LowPassFilter));
    filter->length = SAMPLE_RATE * DURATION;
    filter->input = (double *)malloc(filter->length * sizeof(double));
    filter->output = (double *)malloc(filter->length * sizeof(double));
    
    // Calculate the smoothing factor (alpha)
    double rc = 1.0 / (2 * PI * cutoffFrequency);
    double dt = 1.0 / SAMPLE_RATE;
    filter->alpha = dt / (rc + dt);
    
    return filter;
}

void applyLowPassFilter(LowPassFilter *filter) {
    filter->output[0] = filter->input[0]; // Initialize the first output sample
    for (int i = 1; i < filter->length; i++) {
        filter->output[i] = filter->alpha * filter->input[i] + (1 - filter->alpha) * filter->output[i - 1];
    }
}

void freeLowPassFilter(LowPassFilter *filter) {
    free(filter->input);
    free(filter->output);
    free(filter);
}

void saveToFile(const char *filename, double *signal, int length) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < length; i++) {
        fprintf(file, "%f\n", signal[i]);
    }
    fclose(file);
}

int main() {
    double cutoffFrequency;
    
    printf("Enter the cutoff frequency for the low-pass filter (Hz): ");
    scanf("%lf", &cutoffFrequency);

    LowPassFilter *filter = createLowPassFilter(cutoffFrequency);

    // Generate and apply the filter to a sine wave
    generateSineWave(filter->input, filter->length, SIGNAL_FREQUENCY);
    applyLowPassFilter(filter);

    // Save the output to a file
    saveToFile("output_signal.txt", filter->output, filter->length);

    printf("Filter applied. Output saved to 'output_signal.txt'.\n");

    freeLowPassFilter(filter);
    return 0;
}