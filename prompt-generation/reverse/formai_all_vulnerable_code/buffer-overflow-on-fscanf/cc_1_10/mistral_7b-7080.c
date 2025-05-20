//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SAMPLE_RATE 10000
#define N 15
#define PI M_PI

typedef struct {
    double coeffs[N + 1];
} fir_filter;

void read_coeffs(const char *filename, fir_filter *filter) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= N; ++i) {
        if (fscanf(file, "%lf", &filter->coeffs[i]) != 1) {
            fprintf(stderr, "Error reading coefficients from file\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

void process_signal(const fir_filter *filter, double input_signal[], double output_signal[], int length) {
    for (int i = 0; i < length; ++i) {
        double sum = 0.0;
        for (int j = 0; j <= N; ++j) {
            sum += filter->coeffs[j] * input_signal[i - j];
        }
        output_signal[i] = sum;
    }
}

int main() {
    fir_filter filter;
    double input_signal[SAMPLE_RATE], output_signal[SAMPLE_RATE];
    double amplitude = 1.0, frequency = 2.0 * PI / 1000.0;
    int length = SAMPLE_RATE;

    read_coeffs("coeffs.txt", &filter);

    for (int i = 0; i < length; ++i) {
        input_signal[i] = amplitude * sin(frequency * i);
    }

    process_signal(&filter, input_signal, output_signal, length);

    FILE *output_file = fopen("output.txt", "w");
    for (int i = 0; i < length; ++i) {
        fprintf(output_file, "%lf\n", output_signal[i]);
    }
    fclose(output_file);

    return EXIT_SUCCESS;
}