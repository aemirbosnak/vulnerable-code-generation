//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WATERMARK_BITS 8
#define WATERMARK_VALUE 0xAA

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    unsigned char watermark_byte;
    int watermark_position, watermark_count;
    int image_size, row, col;
    unsigned char *image_data;

    // Open input file
    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Get image size
    fseek(input_file, 0, SEEK_END);
    image_size = ftell(input_file);
    rewind(input_file);

    // Allocate memory for image data
    image_data = (unsigned char *) malloc(image_size);
    if (image_data == NULL) {
        printf("Error: Could not allocate memory for image data.\n");
        exit(1);
    }

    // Read image data from input file
    fread(image_data, image_size, 1, input_file);
    fclose(input_file);

    // Embed watermark
    watermark_position = 0;
    watermark_count = 0;
    for (row = 0; row < image_size; row += 3) {
        col = 0;
        while (col < image_size) {
            if (watermark_count == 0) {
                watermark_byte = WATERMARK_VALUE;
                watermark_position = (row * image_size) + col;
            } else {
                watermark_byte = 0;
            }

            image_data[watermark_position] = (image_data[watermark_position] & ~(0xFF << WATERMARK_BITS)) | (watermark_byte << WATERMARK_BITS);

            col++;
            watermark_count = (watermark_count + 1) % 3;
        }
    }

    // Save watermarked image to output file
    output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    fwrite(image_data, image_size, 1, output_file);
    fclose(output_file);

    printf("Watermark embedded successfully.\n");

    return 0;
}