//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SAMPLES 4096
#define FILTER_TAPS 5

// Function to apply FIR filter
void applyFIRFilter(double *input, double *output, double *coefficients, int numSamples) {
    for (int n = 0; n < numSamples; n++) {
        output[n] = 0.0; // Initialize output sample
        for (int k = 0; k < FILTER_TAPS; k++) {
            if (n - k >= 0) {
                output[n] += coefficients[k] * input[n - k];
            }
        }
    }
}

// Function to read samples from a file
int readSamplesFromFile(const char *filename, double *samples) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return -1;
    }
    
    int count = 0;
    while (count < MAX_SAMPLES && fscanf(file, "%lf", &samples[count]) == 1) {
        count++;
    }
    
    fclose(file);
    return count;
}

// Function to write samples to a file
void writeSamplesToFile(const char *filename, double *samples, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%lf\n", samples[i]);
    }

    fclose(file);
}

// Function to print values (For visualizing the output)
void printSamples(double *samples, int count) {
    for (int i = 0; i < count; i++) {
        printf("%lf\n", samples[i]);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return -1;
    }

    double input[MAX_SAMPLES];
    double output[MAX_SAMPLES];
    double coefficients[FILTER_TAPS] = {0.2, 0.2, 0.2, 0.2, 0.2}; // Simple averaging FIR filter

    int numSamples = readSamplesFromFile(argv[1], input);
    if (numSamples < 0) {
        return -1;
    }

    // Apply the FIR filter
    applyFIRFilter(input, output, coefficients, numSamples);

    // Write the filtered samples to output file
    writeSamplesToFile(argv[2], output, numSamples);

    // Print the result to console for verification
    printf("Filtered output samples:\n");
    printSamples(output, numSamples);

    return 0;
}