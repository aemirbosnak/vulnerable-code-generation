//Falcon2-11B DATASET v1.0 Category: Audio processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <alsa/asoundlib.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    size_t input_size = ftell(input);
    if (input_size == -1) {
        fprintf(stderr, "Could not determine file size\n");
        exit(EXIT_FAILURE);
    }

    fseek(input, 0, SEEK_END);
    size_t output_size = input_size + 2;
    char *output_buffer = malloc(output_size);
    if (output_buffer == NULL) {
        fprintf(stderr, "Could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    char *output_pointer = output_buffer;
    int bytes_read;
    while ((bytes_read = fread(output_pointer, 1, input_size, input)) > 0) {
        output_pointer += bytes_read;
    }
    if (bytes_read!= input_size) {
        fprintf(stderr, "Error reading input file\n");
        exit(EXIT_FAILURE);
    }

    // Write the header
    output_pointer[0] = 0x01; // Little-endian (LSB first)
    output_pointer[1] = 0x01; // 16-bit format
    output_pointer += 2;

    // Write the data
    for (size_t i = 0; i < input_size; i += 2) {
        int16_t sample = *((int16_t *)output_pointer);
        output_pointer += 2;
        if (sample < -32768) {
            sample += 65536;
        }
        if (sample > 32767) {
            sample -= 65536;
        }
        *((int16_t *)output_pointer) = sample;
        output_pointer += 2;
    }

    // Write the footer
    output_pointer[0] = 0x00; // Little-endian (LSB first)
    output_pointer[1] = 0x00; // No padding
    output_pointer += 2;

    int error = 0;
    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (output_fd == -1) {
        fprintf(stderr, "Error opening output file\n");
        exit(EXIT_FAILURE);
    }

    error = write(output_fd, output_buffer, output_size);
    if (error!= output_size) {
        fprintf(stderr, "Error writing output file\n");
        exit(EXIT_FAILURE);
    }

    close(output_fd);
    free(output_buffer);
    exit(EXIT_SUCCESS);
}