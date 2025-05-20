//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_VALUE 255

typedef struct Pixel {
    int x;
    int y;
    int value;
} Pixel;

int main() {
    // Load image file
    FILE *fp;
    fp = fopen("input.bmp", "rb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    // Read BMP file header
    char header[54];
    fread(header, 1, 54, fp);

    // Check if BMP file is valid
    if (header[0]!= 'B' || header[1]!= 'M') {
        printf("Error: Invalid BMP file.\n");
        return 1;
    }

    // Get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Check if image size is within limits
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image size too large.\n");
        return 1;
    }

    // Allocate memory for image
    Pixel *image = malloc(width * height * sizeof(Pixel));

    // Read image data from file
    fseek(fp, 54, SEEK_SET);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fread(&image[y * width + x].value, 1, 1, fp);
        }
    }

    // Close input file
    fclose(fp);

    // Apply image processing
    int brightness = 50;
    int contrast = 50;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = (int)((double)image[y * width + x].value * (1.0 + contrast / 100.0) + brightness);
            if (value < 0) {
                value = 0;
            } else if (value > MAX_VALUE) {
                value = MAX_VALUE;
            }
            image[y * width + x].value = value;
        }
    }

    // Flip image horizontally
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            Pixel temp = image[y * width + x];
            image[y * width + x] = image[y * width + width - 1 - x];
            image[y * width + width - 1 - x] = temp;
        }
    }

    // Save modified image
    fp = fopen("output.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Failed to save image.\n");
        return 1;
    }

    // Write BMP file header
    fwrite("BM", 2, 1, fp);
    fwrite(&header[2], 52, 1, fp);

    // Write image data to file
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fwrite(&image[y * width + x].value, 1, 1, fp);
        }
    }

    // Close output file
    fclose(fp);

    // Print success message
    printf("Image processing completed.\n");

    return 0;
}