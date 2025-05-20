//FormAI DATASET v1.0 Category: Digital signal processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int main() {
    // Open the input file for reading
    FILE *input_file = fopen(INPUT_FILE, "r");
    if (!input_file) {
        printf("Error: Failed to open input file.\n");
        return 1;
    }

    // Open the output file for writing
    FILE *output_file = fopen(OUTPUT_FILE, "w");
    if (!output_file) {
        printf("Error: Failed to open output file.\n");
        return 1;
    }

    // Initialize filter coefficients
    float b[] = {0.25, 0.5, 0.25};

    // Initialize buffer for storing input samples
    float input[3] = {0};

    // Read input samples from file and filter them
    float sample;
    while (fscanf(input_file, "%f", &sample) == 1) {
        // Shift input samples in buffer
        input[2] = input[1];
        input[1] = input[0];
        input[0] = sample;

        // Calculate output sample using filter coefficients
        float output = b[0]*input[0] + b[1]*input[1] + b[2]*input[2];

        // Write output sample to file
        fprintf(output_file, "%.2f\n", output);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("LPF applied successfully to input samples from '%s' and output written to '%s'\n", INPUT_FILE, OUTPUT_FILE);

    return 0;
}