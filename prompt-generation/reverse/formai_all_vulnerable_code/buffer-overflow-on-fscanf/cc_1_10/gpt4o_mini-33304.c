//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SAMPLES 1024
#define ALPHA 0.1 // Filter coefficient for the low-pass filter

// Function to apply a simple low-pass filter to the signal
void low_pass_filter(double *input, double *output, int num_samples) {
    // Initialize the output with the first input sample
    output[0] = input[0]; 

    // Apply the filtering equation
    for (int i = 1; i < num_samples; i++) {
        output[i] = ALPHA * input[i] + (1 - ALPHA) * output[i - 1];
    }
}

// Function to read the input signal from a file
int read_signal(const char *filename, double *signal, int max_samples) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return -1;
    }

    int count = 0;
    while (count < max_samples && fscanf(file, "%lf", &signal[count]) == 1) {
        count++;
    }
    fclose(file);
    return count; // Return the number of samples read
}

// Function to write the output signal to a file
void write_signal(const char *filename, double *signal, int num_samples) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < num_samples; i++) {
        fprintf(file, "%lf\n", signal[i]);
    }
    fclose(file);
}

// Main function to orchestrate the filtering process
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Input and output filenames
    const char *input_filename = argv[1];
    const char *output_filename = argv[2];

    // Buffers to hold the input and output signals
    double signal[MAX_SAMPLES];
    double filtered_signal[MAX_SAMPLES];

    // Read the input signal
    int num_samples = read_signal(input_filename, signal, MAX_SAMPLES);
    if (num_samples < 0) {
        return EXIT_FAILURE;
    }

    // Apply the low-pass filter
    low_pass_filter(signal, filtered_signal, num_samples);

    // Write the output signal to the file
    write_signal(output_filename, filtered_signal, num_samples);

    printf("Processing complete! Filtered signal written to %s\n", output_filename);
    return EXIT_SUCCESS;
}