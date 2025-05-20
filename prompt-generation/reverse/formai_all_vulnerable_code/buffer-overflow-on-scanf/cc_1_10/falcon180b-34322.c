//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SAMPLE_RATE 44100
#define MAX_SAMPLES 44100
#define MAX_AMPLITUDE 32767

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    short int *input_buffer, *output_buffer;
    int num_samples, i, j;
    float gain = 1.0;

    printf("Enter the name of the input audio file: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    num_samples = ftell(input_file) / 2;
    rewind(input_file);

    input_buffer = (short int*) malloc(num_samples * sizeof(short int));
    fread(input_buffer, sizeof(short int), num_samples, input_file);
    fclose(input_file);

    printf("Enter the name of the output audio file: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    output_buffer = (short int*) malloc(num_samples * sizeof(short int));

    for (i = 0; i < num_samples; i++) {
        output_buffer[i] = (short int) (gain * input_buffer[i]);
    }

    fwrite(output_buffer, sizeof(short int), num_samples, output_file);
    fclose(output_file);

    printf("Amplitude adjustment completed.\n");

    return 0;
}