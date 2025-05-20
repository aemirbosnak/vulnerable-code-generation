//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define N 1000 // Number of samples
#define fs 44100 // Sampling frequency
#define fc 440 // Center frequency of the filter
#define BW 100 // Bandwidth of the filter
#define h 0.01 // Time step

int main() {
    FILE *input_file;
    FILE *output_file;
    float x[N], y[N]; // Input and output signals
    float a, b, c; // Filter coefficients
    int i, j;

    // Open input and output files
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    // Check if files were opened successfully
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    // Read input signal from file
    for (i = 0; i < N; i++) {
        fscanf(input_file, "%f", &x[i]);
    }

    // Calculate filter coefficients
    a = 1;
    b = 2*cos(2*PI*fc/fs);
    c = 1;

    // Apply filter to input signal
    for (i = 0; i < N; i++) {
        y[i] = x[i];
        for (j = 0; j < 2; j++) {
            y[i] += a*y[i-j-1] - b*y[i-j-2];
        }
    }

    // Write output signal to file
    for (i = 0; i < N; i++) {
        fprintf(output_file, "%f\n", y[i]);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}