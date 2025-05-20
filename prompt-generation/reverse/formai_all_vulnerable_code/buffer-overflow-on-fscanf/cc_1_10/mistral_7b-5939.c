//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WINDOW_SIZE 10

void moving_average(float *data, float *output, int size) {
    int i, j;
    float sum;

    for (i = 0; i < size; i++) {
        sum = 0.0;
        for (j = 0; j < WINDOW_SIZE && i + j < size; j++) {
            sum += data[i + j];
        }
        output[i] = sum / WINDOW_SIZE;
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    int i, size;
    float *input_buffer, *output_buffer;

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file.\n");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    size = ftell(input_file);
    rewind(input_file);

    input_buffer = calloc(1, size * sizeof(float));
    output_buffer = calloc(1, size * sizeof(float));

    for (i = 0; i < size; i++) {
        fscanf(input_file, "%f", &input_buffer[i]);
    }

    fclose(input_file);

    moving_average(input_buffer, output_buffer, size);

    output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file.\n");
        free(input_buffer);
        free(output_buffer);
        return 1;
    }

    for (i = 0; i < size; i++) {
        fprintf(output_file, "%.6f\n", output_buffer[i]);
    }

    fclose(output_file);

    free(input_buffer);
    free(output_buffer);

    return 0;
}