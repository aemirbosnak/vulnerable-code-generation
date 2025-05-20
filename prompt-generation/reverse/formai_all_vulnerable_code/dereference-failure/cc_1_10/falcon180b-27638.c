//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define NUM_SAMPLES 4410

int main() {
    float *samples;
    float *filtered_samples;
    int i, j;
    FILE *input_file, *output_file;

    samples = malloc(NUM_SAMPLES * sizeof(float));
    filtered_samples = malloc(NUM_SAMPLES * sizeof(float));

    input_file = fopen("input.wav", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen("output.wav", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (i = 0; i < NUM_SAMPLES; i++) {
        fread(&samples[i], sizeof(float), 1, input_file);
    }

    for (i = 0; i < NUM_SAMPLES; i++) {
        filtered_samples[i] = samples[i];
        for (j = 0; j < 4; j++) {
            filtered_samples[i] += samples[i + j] + samples[i - j];
        }
        filtered_samples[i] /= 5;
    }

    for (i = 0; i < NUM_SAMPLES; i++) {
        fwrite(&filtered_samples[i], sizeof(float), 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");

    return 0;
}