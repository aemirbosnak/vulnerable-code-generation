//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAPS 5
#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100
#define PI M_PI

void fir_filter(float *coeffs, float *input, float *output, int length) {
    int i;
    float sum = 0;

    for (i = 0; i < length; i++) {
        sum = 0;
        for (int j = 0; j < TAPS; j++) {
            if (i - j < 0) continue;
            sum += coeffs[j] * input[i - j];
        }
        output[i] = sum;
    }
}

int main() {
    float *input, *output, *coeffs;
    int i, j;
    FILE *file;

    // Allocate memory for input and output buffers
    input = (float *) malloc(BUFFER_SIZE * sizeof(float));
    output = (float *) malloc(BUFFER_SIZE * sizeof(float));

    if (!input || !output) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Load coefficients from file
    file = fopen("coeffs.txt", "r");

    if (!file) {
        printf("Error loading coefficients file!\n");
        return -1;
    }

    coeffs = (float *) malloc(TAPS * sizeof(float));

    for (i = 0; i < TAPS; i++) {
        fscanf(file, "%f", &coeffs[i]);
    }

    fclose(file);

    // Generate input signal (sine wave)
    for (i = 0; i < BUFFER_SIZE; i++) {
        input[i] = 0.5 * sin(2 * PI * i / SAMPLE_RATE);
    }

    // Filter input signal
    fir_filter(coeffs, input, output, BUFFER_SIZE);

    // Free memory and close file
    free(coeffs);
    free(input);
    free(output);

    return 0;
}