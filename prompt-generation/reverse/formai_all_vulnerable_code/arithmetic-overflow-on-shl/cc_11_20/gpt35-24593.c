//FormAI DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    FILE *input_file, *output_file;
    char *data_buffer, *image_buffer;
    long input_file_size, image_file_size;
    int i, j, k, l, byte, bit_counter;

    // Check for correct number of arguments
    if (argc < 4) {
        printf("Usage: %s <data-file> <image-file> <output-file>\n", argv[0]);
        return 1;
    }

    // Open data file
    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening data file %s\n", argv[1]);
        return 1;
    }

    // Determine input file size
    fseek(input_file, 0, SEEK_END);
    input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // Allocate memory for data buffer
    data_buffer = (char *) malloc(input_file_size);
    if (data_buffer == NULL) {
        printf("Error allocating memory for data buffer\n");
        fclose(input_file);
        return 1;
    }

    // Read data file into data buffer
    fread(data_buffer, 1, input_file_size, input_file);

    // Close data file
    fclose(input_file);

    // Open image file
    input_file = fopen(argv[2], "rb");
    if (input_file == NULL) {
        printf("Error opening image file %s\n", argv[2]);
        free(data_buffer);
        return 1;
    }

    // Determine image file size
    fseek(input_file, 0, SEEK_END);
    image_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // Allocate memory for image buffer
    image_buffer = (char *) malloc(image_file_size);
    if (image_buffer == NULL) {
        printf("Error allocating memory for image buffer\n");
        fclose(input_file);
        free(data_buffer);
        return 1;
    }

    // Read image file into image buffer
    fread(image_buffer, 1, image_file_size, input_file);

    // Close image file
    fclose(input_file);

    // Check to make sure the data file will fit into the image file
    if ((input_file_size * 8) > (image_file_size - 54)) {
        printf("Error: Input file is too large for the image file\n");
        free(data_buffer);
        free(image_buffer);
        return 1;
    }

    // Embed data into image
    byte = 0;
    bit_counter = 0;
    for (i = 54; i < image_file_size; i++) {
        for (j = 0; j < 8; j++) {
            byte <<= 1;
            if (bit_counter < (input_file_size * 8)) {
                byte |= ((data_buffer[bit_counter / 8] >> (7 - (bit_counter % 8))) & 1);
                bit_counter++;
            }
            image_buffer[i] = byte;
        }
    }

    // Open output file
    output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        printf("Error opening output file %s\n", argv[3]);
        free(data_buffer);
        free(image_buffer);
        return 1;
    }

    // Write image buffer to output file
    fwrite(image_buffer, 1, image_file_size, output_file);

    // Close output file
    fclose(output_file);

    // Free memory
    free(data_buffer);
    free(image_buffer);

    return 0;
}