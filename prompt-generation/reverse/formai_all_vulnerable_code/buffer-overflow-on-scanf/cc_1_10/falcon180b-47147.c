//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void create_signal(int N, float *signal) {
    int i;
    for(i = 0; i < N; i++) {
        signal[i] = sin(2 * PI * i / N);
    }
}

void apply_filter(int N, float *signal, float *filter_coeffs, float *output) {
    int i, j;
    for(i = 0; i < N; i++) {
        output[i] = 0;
        for(j = 0; j < N; j++) {
            output[i] += signal[j] * filter_coeffs[i - j];
        }
    }
}

int main(int argc, char *argv[]) {
    int N, M;
    float *signal, *filter_coeffs, *output;

    // Get signal length from user
    printf("Enter signal length: ");
    scanf("%d", &N);

    // Allocate memory for signal, filter coefficients, and output
    signal = (float *) malloc(N * sizeof(float));
    filter_coeffs = (float *) malloc(N * sizeof(float));
    output = (float *) malloc(N * sizeof(float));

    // Create signal
    create_signal(N, signal);

    // Get filter coefficients from user
    printf("Enter filter coefficients:\n");
    for(int i = 0; i < N; i++) {
        scanf("%f", &filter_coeffs[i]);
    }

    // Apply filter
    apply_filter(N, signal, filter_coeffs, output);

    // Print filtered signal
    printf("Filtered signal:\n");
    for(int i = 0; i < N; i++) {
        printf("%f\n", output[i]);
    }

    // Free memory
    free(signal);
    free(filter_coeffs);
    free(output);

    return 0;
}