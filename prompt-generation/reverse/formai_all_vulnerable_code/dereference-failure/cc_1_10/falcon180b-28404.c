//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, nSamples;
    double sampleRate, duration;
    double *signal, *filteredSignal;
    FILE *inputFile, *outputFile;

    // Open input and output files
    inputFile = fopen("input.wav", "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    outputFile = fopen("output.wav", "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Read header information from input file
    fseek(inputFile, 0, SEEK_SET);
    fread(&nSamples, sizeof(int), 1, inputFile);
    fread(&sampleRate, sizeof(double), 1, inputFile);
    fseek(inputFile, 44, SEEK_SET);

    // Allocate memory for input signal and filtered signal
    signal = (double*) malloc(nSamples * sizeof(double));
    filteredSignal = (double*) malloc(nSamples * sizeof(double));

    // Read input signal from file
    fread(signal, sizeof(double), nSamples, inputFile);

    // Apply low-pass filter to input signal
    for (i = 0; i < nSamples; i++) {
        filteredSignal[i] = signal[i] * 0.5;
    }

    // Write filtered signal to output file
    fwrite(filteredSignal, sizeof(double), nSamples, outputFile);

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("Filtering completed successfully!\n");

    return 0;
}