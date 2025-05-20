//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    // Open the image file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return EXIT_FAILURE;
    }

    // Read the image header
    unsigned char header[54];
    fread(header, sizeof(header), 1, fp);

    // Get the image width and height
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Create a 2D array to store the image data
    pixel **image = malloc(sizeof(pixel *) * height);
    for (int i = 0; i < height; i++) {
        image[i] = malloc(sizeof(pixel) * width);
    }

    // Read the image data
    fread(image, sizeof(pixel), width * height, fp);

    // Close the image file
    fclose(fp);

    // Open the text file
    fp = fopen("text.txt", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening text file\n");
        return EXIT_FAILURE;
    }

    // Get the text file size
    fseek(fp, 0, SEEK_END);
    int text_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Read the text file data
    char *text = malloc(text_size + 1);
    fread(text, sizeof(char), text_size, fp);
    text[text_size] = '\0';

    // Close the text file
    fclose(fp);

    // Embed the text in the image
    int text_index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // If the text index is greater than the text size, stop embedding
            if (text_index >= text_size) {
                break;
            }

            // Get the current pixel
            pixel *pixel = &image[i][j];

            // Get the least significant bit of each color channel
            unsigned char r_lsb = pixel->r & 1;
            unsigned char g_lsb = pixel->g & 1;
            unsigned char b_lsb = pixel->b & 1;

            // Set the least significant bit of the red channel to the text bit
            pixel->r = (pixel->r & ~1) | ((text[text_index] >> 6) & 1);

            // Set the least significant bit of the green channel to the text bit
            pixel->g = (pixel->g & ~1) | ((text[text_index] >> 4) & 1);

            // Set the least significant bit of the blue channel to the text bit
            pixel->b = (pixel->b & ~1) | ((text[text_index] >> 2) & 1);

            // Increment the text index
            text_index++;
        }
    }

    // Open the output image file
    fp = fopen("output.bmp", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening output image file\n");
        return EXIT_FAILURE;
    }

    // Write the image header
    fwrite(header, sizeof(header), 1, fp);

    // Write the image data
    fwrite(image, sizeof(pixel), width * height, fp);

    // Close the output image file
    fclose(fp);

    // Free the image data
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    // Free the text data
    free(text);

    return EXIT_SUCCESS;
}