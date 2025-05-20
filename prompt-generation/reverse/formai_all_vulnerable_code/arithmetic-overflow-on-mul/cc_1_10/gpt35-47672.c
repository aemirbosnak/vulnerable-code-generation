//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

// Function to flip the image horizontally
void flipImageHorizontally(byte* img, int width, int height) {
    byte temp;
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            temp = img[i * width + j];
            img[i * width + j] = img[(i + 1) * width - (j + 1)];
            img[(i + 1) * width - (j + 1)] = temp;
        }
    }
}

// Function to adjust the brightness and contrast of the image
void adjustBrightnessContrast(byte* img, int width, int height, int brightness, int contrast) {
    int i, j;
    int pixel;
    double contrastFactor, brightnessFactor;
    
    // Convert brightness and contrast values to factors
    contrastFactor = (double)(259 * (contrast + 255)) / (double)(255 * (259 - contrast));
    brightnessFactor = (double)(brightness - 128);
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel = img[i * width + j];
            // Adjust contrast
            pixel = (int)(contrastFactor * (pixel - 128) + 128);
            // Adjust brightness
            pixel += brightnessFactor;
            // Clamp values to [0, 255]
            if (pixel < 0) pixel = 0;
            if (pixel > 255) pixel = 255;
            img[i * width + j] = (byte)pixel;
        }
    }
}

int main() {
    FILE* fp; // File pointer
    byte* img; // Pointer to image buffer
    int width, height; // Width and height of the image
    int brightness, contrast; // Brightness and contrast values
    int i;

    // Open the file
    fp = fopen("image.raw", "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Read the image dimensions
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Allocate memory for the image buffer
    img = (byte*)malloc(width * height * sizeof(byte));

    // Read the image data
    fread(img, sizeof(byte), width * height, fp);

    // Close the file
    fclose(fp);

    // Flip the image horizontally
    flipImageHorizontally(img, width, height);

    // Adjust brightness and contrast
    brightness = 50;
    contrast = 30;
    adjustBrightnessContrast(img, width, height, brightness, contrast);

    // Save the modified image
    fp = fopen("modified_image.raw", "wb");
    if (fp == NULL) {
        printf("Error: Unable to create file.\n");
        return 1;
    }

    // Write the image dimensions
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);

    // Write the image data
    fwrite(img, sizeof(byte), width * height, fp);

    // Close the file
    fclose(fp);

    // Free the memory allocated for the image buffer
    free(img);

    return 0;
}