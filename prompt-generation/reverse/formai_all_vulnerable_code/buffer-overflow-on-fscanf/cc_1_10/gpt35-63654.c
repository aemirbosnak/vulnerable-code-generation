//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

// Function to flip the image vertically
void flipImageVertically(unsigned char* pixels, int width, int height) {
    for (int row = 0; row < height / 2; row++) {
        for (int col = 0; col < width; col++) {
            int topIndex = row * width + col;
            int bottomIndex = (height - row - 1) * width + col;
            // Swap the top and bottom pixels
            unsigned char temp = pixels[topIndex];
            pixels[topIndex] = pixels[bottomIndex];
            pixels[bottomIndex] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjustImageBrightness(unsigned char* pixels, int width, int height, int adjustmentAmount) {
    for (int i = 0; i < width * height; i++) {
        int newValue = pixels[i] + adjustmentAmount;
        if (newValue > 255) {
            newValue = 255;
        } else if (newValue < 0) {
            newValue = 0;
        }
        pixels[i] = newValue;
    }
}

// Function to adjust the contrast of an image
void adjustImageContrast(unsigned char* pixels, int width, int height, float contrastRatio) {
    for (int i = 0; i < width * height; i++) {
        float pixelValue = (float) pixels[i];
        pixelValue = (pixelValue - 127.5) * contrastRatio + 127.5; // Adjust the pixel value based on contrastRatio
        if (pixelValue > 255) {
            pixelValue = 255;
        } else if (pixelValue < 0) {
            pixelValue = 0;
        }
        pixels[i] = (unsigned char) pixelValue;
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter image filename: ");
    scanf("%s", filename);
    FILE* imageFile = fopen(filename, "r");

    // Check if image file exists
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Read image header data
    char format[3];
    int width, height, maxVal;
    fscanf(imageFile, "%s\n%d %d\n%d\n", format, &width, &height, &maxVal);

    // Check if image format is PGM (Portable Graymap)
    if (strcmp(format, "P5") != 0) {
        printf("Invalid image format. Only PGM files are supported.\n");
        return 1;
    }

    // Allocate memory for pixel data
    unsigned char* pixels = (unsigned char*) malloc(width * height * sizeof(unsigned char));
    if (pixels == NULL) {
        printf("Error allocating memory for pixel data.\n");
        return 1;
    }

    // Read pixel data from image file
    fread(pixels, sizeof(unsigned char), width * height, imageFile);
    fclose(imageFile);

    // Flip the image vertically
    flipImageVertically(pixels, width, height);

    // Adjust the brightness of the image
    int brightnessAmount;
    printf("Enter brightness adjustment amount (between -255 and 255): ");
    scanf("%d", &brightnessAmount);
    adjustImageBrightness(pixels, width, height, brightnessAmount);

    // Adjust the contrast of the image
    float contrastRatio;
    printf("Enter contrast adjustment ratio (between 0 and 10): ");
    scanf("%f", &contrastRatio);
    adjustImageContrast(pixels, width, height, contrastRatio);

    // Write modified pixel data to new image file
    char modifiedFilename[MAX_FILENAME_LENGTH];
    strcpy(modifiedFilename, "modified_");
    strcat(modifiedFilename, filename);
    FILE* modifiedImageFile = fopen(modifiedFilename, "w");
    fprintf(modifiedImageFile, "P5\n%d %d\n%d\n", width, height, maxVal);
    fwrite(pixels, sizeof(unsigned char), width * height, modifiedImageFile);
    fclose(modifiedImageFile);

    // Deallocate memory for pixel data
    free(pixels);

    printf("Image processing complete. Modified image saved as %s.\n", modifiedFilename);
    return 0;
}