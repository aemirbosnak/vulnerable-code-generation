//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH 1000 // Length of the signal

int main() {
    double signal[LENGTH], output[LENGTH]; // Signal and output arrays
    int i, j, n; // Loop variables
    double w, sum; // Variables for FFT calculation
    FILE *inputFile, *outputFile; // File pointers

    // Read signal from input file
    inputFile = fopen("signal.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    for (i = 0; i < LENGTH; i++) {
        fscanf(inputFile, "%lf", &signal[i]);
    }
    fclose(inputFile);

    // Perform FFT on the signal
    for (i = 0; i < LENGTH; i++) {
        signal[i] *= LENGTH; // Window the signal with a rectangular window
    }
    for (i = 0; i < LENGTH; i++) {
        for (j = 0; j < LENGTH; j++) {
            w = 2 * M_PI * i * j / LENGTH;
            sum = 0;
            for (n = 0; n < LENGTH; n++) {
                sum += signal[n] * cos(w * n) + signal[n] * sin(w * n);
            }
            output[i] += sum;
        }
    }

    // Write output to file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    for (i = 0; i < LENGTH; i++) {
        fprintf(outputFile, "%lf\n", output[i]);
    }
    fclose(outputFile);

    return 0;
}