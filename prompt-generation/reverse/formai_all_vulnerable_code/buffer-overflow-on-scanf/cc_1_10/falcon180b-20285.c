//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

int main() {
    FILE *input_file;
    FILE *output_file;
    char input_filename[100];
    char output_filename[100];
    int i, j;
    float buffer[BUFFER_SIZE];
    float *left_channel, *right_channel;
    float *output_buffer;
    int bytes_read;

    srand(time(NULL));

    printf("Enter input filename: ");
    scanf("%s", input_filename);

    printf("Enter output filename: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    left_channel = malloc(BUFFER_SIZE * sizeof(float));
    right_channel = malloc(BUFFER_SIZE * sizeof(float));
    output_buffer = malloc(BUFFER_SIZE * sizeof(float));

    while (!feof(input_file)) {
        bytes_read = fread(buffer, sizeof(float), BUFFER_SIZE, input_file);

        for (i = 0; i < bytes_read / sizeof(float); i++) {
            left_channel[i] = buffer[i * 2];
            right_channel[i] = buffer[i * 2 + 1];
        }

        for (i = 0; i < BUFFER_SIZE; i++) {
            float frequency = rand() % 1000;
            float amplitude = rand() % 10000 / 100;

            left_channel[i] += amplitude * sin(2 * M_PI * frequency * i / SAMPLE_RATE);
            right_channel[i] += amplitude * sin(2 * M_PI * frequency * i / SAMPLE_RATE);
        }

        for (i = 0; i < BUFFER_SIZE; i++) {
            output_buffer[i] = left_channel[i] + right_channel[i];
        }

        fwrite(output_buffer, sizeof(float), BUFFER_SIZE, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");

    return 0;
}