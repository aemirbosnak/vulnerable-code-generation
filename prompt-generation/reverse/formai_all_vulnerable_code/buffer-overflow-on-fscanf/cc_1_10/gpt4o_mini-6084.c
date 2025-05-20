//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define WATERMARK "WATERMARK" // The watermark text to embed
#define MAX_IMAGE_SIZE 256    // Max size for simplicity

// Function declarations
void embedWatermark(const char *inputImagePath, const char *outputImagePath);
void extractWatermark(const char *inputImagePath);
void readPGM(const char *filename, unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int *width, int *height);
void writePGM(const char *filename, unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height);

// Main function
int main() {
    const char *inputImage = "input.pgm";
    const char *outputImage = "output.pgm";

    embedWatermark(inputImage, outputImage);
    extractWatermark(outputImage);

    return 0;
}

// Function to embed a watermark into an image
void embedWatermark(const char *inputImagePath, const char *outputImagePath) {
    unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int width, height;
    readPGM(inputImagePath, image, &width, &height);

    // Embedding the watermark in the least significant bits
    int wmLength = sizeof(WATERMARK) / sizeof(WATERMARK[0]);
    for (int i = 0; i < wmLength; i++) {
        int x = i / width;
        int y = i % width;
        if (x < height && y < width) {
            // Manipulate the least significant bit
            image[x][y] = (image[x][y] & 0xFE) | ((WATERMARK[i] >> 7) & 0x01);
        }
    }

    writePGM(outputImagePath, image, width, height);
}

// Function to extract the watermark from an image
void extractWatermark(const char *inputImagePath) {
    unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int width, height;
    readPGM(inputImagePath, image, &width, &height);

    char extractedWatermark[sizeof(WATERMARK)] = {0};
    
    for (int i = 0; i < sizeof(extractedWatermark); i++) {
        int x = i / width;
        int y = i % width;
        if (x < height && y < width) {
            // Extract the least significant bit
            extractedWatermark[i] = (image[x][y] & 0x01) << 7;
        }
    }

    printf("Extracted Watermark: %s\n", extractedWatermark);
}

// Function to read a PGM image
void readPGM(const char *filename, unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read PGM header
    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P5") != 0) {
        fprintf(stderr, "Invalid PGM format: %s\n", format);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", width, height);
    int maxValue;
    fscanf(file, "%d", &maxValue);
    fgetc(file); // consume the newline character

    // Read image data
    fread(image, sizeof(unsigned char), (*width) * (*height), file);
    fclose(file);
}

// Function to write a PGM image
void writePGM(const char *filename, unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P5\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height, file);
    fclose(file);
}