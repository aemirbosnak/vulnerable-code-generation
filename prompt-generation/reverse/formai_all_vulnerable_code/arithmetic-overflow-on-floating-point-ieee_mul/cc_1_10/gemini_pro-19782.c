//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Embed a watermark in an image
void embed_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Check if the image is large enough to hold the watermark
    if (width < watermark_width || height < watermark_height) {
        printf("Error: The image is not large enough to hold the watermark.\n");
        return;
    }

    // Embed the watermark in the image
    for (int i = 0; i < watermark_height; i++) {
        for (int j = 0; j < watermark_width; j++) {
            // Get the pixel value from the watermark
            unsigned char watermark_pixel = watermark[i * watermark_width + j];

            // Get the pixel value from the image
            unsigned char image_pixel = image[(i + height / 2) * width + (j + width / 2)];

            // Embed the watermark pixel in the image pixel
            image_pixel = (image_pixel & 0xF0) | (watermark_pixel & 0x0F);

            // Set the pixel value in the image
            image[(i + height / 2) * width + (j + width / 2)] = image_pixel;
        }
    }
}

// Extract a watermark from an image
void extract_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Check if the image is large enough to hold the watermark
    if (width < watermark_width || height < watermark_height) {
        printf("Error: The image is not large enough to hold the watermark.\n");
        return;
    }

    // Extract the watermark from the image
    for (int i = 0; i < watermark_height; i++) {
        for (int j = 0; j < watermark_width; j++) {
            // Get the pixel value from the image
            unsigned char image_pixel = image[(i + height / 2) * width + (j + width / 2)];

            // Extract the watermark pixel from the image pixel
            unsigned char watermark_pixel = image_pixel & 0x0F;

            // Set the pixel value in the watermark
            watermark[i * watermark_width + j] = watermark_pixel;
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc != 5) {
        printf("Usage: %s <input_image> <output_image> <watermark_image> <watermark_scale>\n", argv[0]);
        return 1;
    }

    // Read the input image
    FILE *input_image_file = fopen(argv[1], "rb");
    if (input_image_file == NULL) {
        printf("Error: Could not open the input image file.\n");
        return 1;
    }
    fseek(input_image_file, 0, SEEK_END);
    long input_image_size = ftell(input_image_file);
    rewind(input_image_file);
    unsigned char *input_image = malloc(input_image_size);
    fread(input_image, 1, input_image_size, input_image_file);
    fclose(input_image_file);

    // Read the watermark image
    FILE *watermark_image_file = fopen(argv[3], "rb");
    if (watermark_image_file == NULL) {
        printf("Error: Could not open the watermark image file.\n");
        return 1;
    }
    fseek(watermark_image_file, 0, SEEK_END);
    long watermark_image_size = ftell(watermark_image_file);
    rewind(watermark_image_file);
    unsigned char *watermark_image = malloc(watermark_image_size);
    fread(watermark_image, 1, watermark_image_size, watermark_image_file);
    fclose(watermark_image_file);

    // Get the width and height of the input image
    int width, height;
    width = input_image[18] * 256 + input_image[19];
    height = input_image[22] * 256 + input_image[23];

    // Get the width and height of the watermark image
    int watermark_width, watermark_height;
    watermark_width = watermark_image[18] * 256 + watermark_image[19];
    watermark_height = watermark_image[22] * 256 + watermark_image[23];

    // Scale the watermark image
    float scale = atof(argv[4]);
    watermark_width = (int) (watermark_width * scale);
    watermark_height = (int) (watermark_height * scale);

    // Embed the watermark in the input image
    embed_watermark(input_image, width, height, watermark_image, watermark_width, watermark_height);

    // Write the output image
    FILE *output_image_file = fopen(argv[2], "wb");
    if (output_image_file == NULL) {
        printf("Error: Could not open the output image file.\n");
        return 1;
    }
    fwrite(input_image, 1, input_image_size, output_image_file);
    fclose(output_image_file);

    // Extract the watermark from the output image
    unsigned char *watermark = malloc(watermark_width * watermark_height);
    extract_watermark(input_image, width, height, watermark, watermark_width, watermark_height);

    // Write the watermark image
    FILE *watermark_output_image_file = fopen("watermark_output.bmp", "wb");
    if (watermark_output_image_file == NULL) {
        printf("Error: Could not open the watermark output image file.\n");
        return 1;
    }
    fwrite(watermark, 1, watermark_width * watermark_height, watermark_output_image_file);
    fclose(watermark_output_image_file);

    // Free the allocated memory
    free(input_image);
    free(watermark_image);
    free(watermark);

    return 0;
}