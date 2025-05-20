//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 44100
#define WINDOW_SIZE 4096
#define HOP_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *input_file;
    FILE *output_file;
    double *data_in;
    double *data_out;
    fftw_plan plan;
    int i;
    int n;
    int window_size;
    int hop_size;
    int num_samples;

    // Open input file
    input_file = fopen("input.wav", "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read header of input file
    fseek(input_file, 0, SEEK_SET);
    fread(&num_samples, sizeof(int), 1, input_file);
    fread(&window_size, sizeof(int), 1, input_file);
    fread(&hop_size, sizeof(int), 1, input_file);

    // Allocate memory for input and output buffers
    data_in = (double *) malloc(window_size * sizeof(double));
    data_out = (double *) malloc(window_size * sizeof(double));

    // Open output file
    output_file = fopen("output.wav", "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Initialize FFT plan
    plan = fftw_plan_dft_1d(window_size, data_in, data_out, FFTW_FORWARD, FFTW_MEASURE);

    // Process input file
    for (i = 0; i < num_samples; i += hop_size) {
        // Read window of input data
        fseek(input_file, i * sizeof(double), SEEK_SET);
        fread(data_in, sizeof(double), window_size, input_file);

        // Apply window function
        for (n = 0; n < window_size; n++) {
            data_in[n] *= 0.5 * (1 - cos(2 * M_PI * n / (window_size - 1)));
        }

        // Compute FFT of input data
        fftw_execute(plan);

        // Write window of output data
        fwrite(data_out, sizeof(double), window_size, output_file);
    }

    // Clean up
    fclose(input_file);
    fclose(output_file);
    fftw_destroy_plan(plan);
    free(data_in);
    free(data_out);

    return 0;
}