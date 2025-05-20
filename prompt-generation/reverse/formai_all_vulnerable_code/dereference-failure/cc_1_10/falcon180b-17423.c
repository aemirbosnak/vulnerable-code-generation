//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define PI 3.14159265359

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    short int buffer[BUFFER_SIZE];
    float frequency, amplitude, phase;
    int i, j, k, n;

    // Get input and output filenames from command line arguments
    if (argc!= 6) {
        printf("Usage: %s input_file output_file frequency amplitude phase\n", argv[0]);
        exit(1);
    }
    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);
    frequency = atof(argv[3]);
    amplitude = atof(argv[4]);
    phase = atof(argv[5]);

    // Open input and output files
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Initialize buffer with zeros
    for (i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = 0;
    }

    // Process audio data
    while (fread(buffer, sizeof(short int), BUFFER_SIZE, input_file) == BUFFER_SIZE) {
        for (i = 0; i < BUFFER_SIZE; i++) {
            // Calculate sine wave amplitude
            n = (int)round(SAMPLE_RATE / frequency * (i + 0.5));
            k = (int)round(amplitude * sin(2 * PI * frequency * (i + 0.5) / SAMPLE_RATE + phase));

            // Apply amplitude to buffer
            if (k > 32767) {
                buffer[i] = 32767;
            } else if (k < -32768) {
                buffer[i] = -32768;
            } else {
                buffer[i] = (short int)k;
            }
        }

        // Write buffer to output file
        fwrite(buffer, sizeof(short int), BUFFER_SIZE, output_file);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Audio processing completed successfully.\n");
    return 0;
}