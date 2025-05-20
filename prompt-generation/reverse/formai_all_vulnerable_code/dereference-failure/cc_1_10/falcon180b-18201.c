//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64
#define ALPHA_VALUE 0.5

// Function to read image data from file
void readImage(int **imageData, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    *imageData = (int *)malloc(sizeof(int) * IMAGE_WIDTH * IMAGE_HEIGHT);
    fread(*imageData, sizeof(int), IMAGE_WIDTH * IMAGE_HEIGHT, fp);
    fclose(fp);
}

// Function to write image data to file
void writeImage(int *imageData, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fwrite(imageData, sizeof(int), IMAGE_WIDTH * IMAGE_HEIGHT, fp);
    fclose(fp);
}

// Function to apply watermark to image
void applyWatermark(int *imageData, int *watermarkData, int alpha) {
    int i, j;
    for (i = 0; i < IMAGE_WIDTH; i++) {
        for (j = 0; j < IMAGE_HEIGHT; j++) {
            int watermarkValue = watermarkData[(j / WATERMARK_HEIGHT) * WATERMARK_WIDTH + (i / WATERMARK_WIDTH)];
            int imageValue = imageData[j * IMAGE_WIDTH + i];

            int newValue = (int)((double)imageValue * (1 - alpha) + (double)watermarkValue * alpha);
            imageData[j * IMAGE_WIDTH + i] = newValue;
        }
    }
}

// Function to save watermark data to file
void saveWatermark(int *watermarkData, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fwrite(watermarkData, sizeof(int), WATERMARK_WIDTH * WATERMARK_HEIGHT, fp);
    fclose(fp);
}

int main() {
    int *imageData, *watermarkData;

    // Read image data from file
    readImage(&imageData, "image.raw");

    // Generate watermark data
    watermarkData = (int *)malloc(sizeof(int) * WATERMARK_WIDTH * WATERMARK_HEIGHT);
    for (int i = 0; i < WATERMARK_WIDTH * WATERMARK_HEIGHT; i++) {
        watermarkData[i] = 255;
    }

    // Apply watermark to image
    applyWatermark(imageData, watermarkData, ALPHA_VALUE);

    // Save watermarked image to file
    writeImage(imageData, "watermarked_image.raw");

    // Save watermark data to file
    saveWatermark(watermarkData, "watermark.raw");

    return 0;
}