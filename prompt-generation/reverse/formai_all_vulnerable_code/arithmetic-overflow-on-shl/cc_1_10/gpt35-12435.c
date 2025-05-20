//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to add watermark to image
void addWatermark(char *imagePath, char *watermarkPath, char *outputPath) {
    FILE *image, *watermark, *output;
    unsigned char imageHeader[54], watermarkHeader[54]; // Header size is 54 bytes
    unsigned int imageSize, watermarkSize;

    // Open image file in binary read mode
    image = fopen(imagePath, "rb");
    if (image == NULL) {
        printf("Error: Unable to open %s\n", imagePath);
        return;
    }

    // Open watermark file in binary read mode
    watermark = fopen(watermarkPath, "rb");
    if (watermark == NULL) {
        printf("Error: Unable to open %s\n", watermarkPath);
        return;
    }

    // Open output file in binary write mode
    output = fopen(outputPath, "wb");
    if (output == NULL) {
        printf("Error: Unable to create %s\n", outputPath);
        return;
    }

    // Read image header
    fread(imageHeader, sizeof(unsigned char), 54, image);

    // Read watermark header
    fread(watermarkHeader, sizeof(unsigned char), 54, watermark);

    // Check if image and watermark dimensions match
    if (imageHeader[18] != watermarkHeader[18] || imageHeader[22] != watermarkHeader[22]) {
        printf("Error: Image and Watermark dimensions do not match!\n");
        return;
    }

    // Calculate image size
    imageSize = (imageHeader[5] << 24) | (imageHeader[4] << 16) | (imageHeader[3] << 8) | imageHeader[2];

    // Calculate watermark size
    watermarkSize = (watermarkHeader[5] << 24) | (watermarkHeader[4] << 16) | (watermarkHeader[3] << 8) | watermarkHeader[2];

    // Write image header to output file
    fwrite(imageHeader, sizeof(unsigned char), 54, output);

    // Add watermark to image
    for (unsigned int i = 54; i < imageSize; i += 3) {
        unsigned char pixel[3];
        unsigned char watermarkPixel[3];

        // Read pixel values from image
        fread(pixel, sizeof(unsigned char), 3, image);

        // Read pixel values from watermark
        fread(watermarkPixel, sizeof(unsigned char), 3, watermark);

        // Modify pixel values to add watermark
        if (watermarkPixel[0] == 255) {
            pixel[0] |= 1;
        } else {
            pixel[0] &= ~1;
        }

        if (watermarkPixel[1] == 255) {
            pixel[1] |= 1;
        } else {
            pixel[1] &= ~1;
        }

        if (watermarkPixel[2] == 255) {
            pixel[2] |= 1;
        } else {
            pixel[2] &= ~1;
        }

        // Write modified pixel values to output file
        fwrite(pixel, sizeof(unsigned char), 3, output);
    }

    // Close all files
    fclose(image);
    fclose(watermark);
    fclose(output);

    // Display success message
    printf("Watermark added to image successfully!\n");
}

int main() {
    char imagePath[] = "image.bmp";
    char watermarkPath[] = "watermark.bmp";
    char outputPath[] = "output.bmp";

    // Add watermark to image
    addWatermark(imagePath, watermarkPath, outputPath);

    return 0;
}