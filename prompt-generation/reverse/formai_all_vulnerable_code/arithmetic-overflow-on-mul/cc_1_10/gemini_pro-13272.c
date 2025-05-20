//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the original image and watermark
#define MAX_SIZE 1024

// Read the original image from a file
unsigned char* read_image(const char* filename, int* width, int* height) {
    // Open the file
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char buffer[54];
    fread(buffer, sizeof(unsigned char), 54, file);

    // Get the width and height from the header
    *width = buffer[18] + (buffer[19] << 8);
    *height = buffer[22] + (buffer[23] << 8);

    // Allocate memory for the image data
    unsigned char* data = (unsigned char*)malloc(*width * *height * 3);
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(file);
        return NULL;
    }

    // Read the image data
    fread(data, sizeof(unsigned char), *width * *height * 3, file);

    // Close the file
    fclose(file);

    return data;
}

// Write the watermarked image to a file
void write_image(const char* filename, unsigned char* data, int width, int height) {
    // Open the file
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char buffer[54];
    memcpy(buffer, data, 54);

    fwrite(buffer, sizeof(unsigned char), 54, file);

    // Write the image data
    fwrite(data + 54, sizeof(unsigned char), width * height * 3, file);

    // Close the file
    fclose(file);
}

// Embed a watermark in an image
void embed_watermark(unsigned char* image, int width, int height, const char* watermark) {
    // Convert the watermark to a binary string
    int watermark_length = strlen(watermark);
    unsigned char watermark_bits[watermark_length * 8];
    for (int i = 0; i < watermark_length; i++) {
        for (int j = 0; j < 8; j++) {
            watermark_bits[i * 8 + j] = (watermark[i] >> j) & 1;
        }
    }

    // Embed the watermark in the image
    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Embed the watermark bit in the least significant bit of the red channel
            image[3 * (y * width + x)] = (image[3 * (y * width + x)] & 0xFE) | watermark_bits[index];
            index++;
        }
    }
}

// Extract a watermark from an image
char* extract_watermark(unsigned char* image, int width, int height) {
    // Extract the watermark bits from the image
    int watermark_length = (width * height) / 8;
    unsigned char watermark_bits[watermark_length];
    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Extract the watermark bit from the least significant bit of the red channel
            watermark_bits[index] = image[3 * (y * width + x)] & 1;
            index++;
        }
    }

    // Convert the watermark bits to a binary string
    char* watermark = (char*)malloc(watermark_length + 1);
    for (int i = 0; i < watermark_length; i++) {
        for (int j = 0; j < 8; j++) {
            watermark[i] |= watermark_bits[i * 8 + j] << j;
        }
    }
    watermark[watermark_length] = '\0';

    return watermark;
}

// Main function
int main(int argc, char** argv) {
    // Check the command line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <original image> <watermark> <watermarked image>\n", argv[0]);
        return 1;
    }

    // Read the original image
    int width, height;
    unsigned char* image = read_image(argv[1], &width, &height);
    if (image == NULL) {
        return 1;
    }

    // Embed the watermark in the image
    embed_watermark(image, width, height, argv[2]);

    // Write the watermarked image
    write_image(argv[3], image, width, height);

    // Free the memory allocated for the image
    free(image);

    return 0;
}