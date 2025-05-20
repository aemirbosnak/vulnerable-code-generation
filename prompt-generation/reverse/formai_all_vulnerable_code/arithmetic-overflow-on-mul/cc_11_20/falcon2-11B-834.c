//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        fprintf(stderr, "Usage: %s input_image output_image\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Read input image
    FILE *input_image = fopen(argv[1], "rb");
    if(input_image == NULL) {
        fprintf(stderr, "Error opening input image\n");
        exit(EXIT_FAILURE);
    }

    // Read watermark image
    FILE *watermark_image = fopen(argv[2], "rb");
    if(watermark_image == NULL) {
        fprintf(stderr, "Error opening watermark image\n");
        exit(EXIT_FAILURE);
    }

    // Read input image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, input_image);
    fread(&height, sizeof(int), 1, input_image);

    // Allocate memory for output image
    unsigned char *output_image = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    if(output_image == NULL) {
        fprintf(stderr, "Error allocating memory for output image\n");
        exit(EXIT_FAILURE);
    }

    // Read watermark image dimensions
    int watermark_width, watermark_height;
    fread(&watermark_width, sizeof(int), 1, watermark_image);
    fread(&watermark_height, sizeof(int), 1, watermark_image);

    // Check if watermark is compatible with input image
    if(watermark_width!= width || watermark_height!= height) {
        fprintf(stderr, "Watermark is not compatible with input image\n");
        exit(EXIT_FAILURE);
    }

    // Apply watermark to input image
    int x, y;
    for(y = 0; y < height; y++) {
        for(x = 0; x < width; x++) {
            // Check if pixel is black
            if((unsigned char)(fgetc(input_image)) == 0) {
                // Add watermark pixel
                fgetc(watermark_image);
            }
        }
    }

    // Close files
    fclose(input_image);
    fclose(watermark_image);

    // Save output image
    FILE *output_file = fopen(argv[2], "wb");
    if(output_file == NULL) {
        fprintf(stderr, "Error opening output image file\n");
        exit(EXIT_FAILURE);
    }
    fwrite(output_image, width * height * sizeof(unsigned char), 1, output_file);
    fclose(output_file);

    // Free memory
    free(output_image);

    return 0;
}