//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
// C Basic Image Processing: Simple tasks example program
// Flipping an image, changing brightness/contrast
// Statistical style

#include <stdio.h>
#include <stdlib.h>

// Function to flip the image horizontally
void flipHorizontally(unsigned char* image, int width, int height, int bytesPerPixel)
{
    int row, col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width / 2; col++) {
            int offset1 = bytesPerPixel * (row * width + col);
            int offset2 = bytesPerPixel * (row * width + width - col - 1);
            int byteIndex;
            for (byteIndex = 0; byteIndex < bytesPerPixel; byteIndex++) {
                unsigned char temp = image[offset1 + byteIndex];
                image[offset1 + byteIndex] = image[offset2 + byteIndex];
                image[offset2 + byteIndex] = temp;
            }
        }
    }
}

// Function to change the brightness and contrast of the image
void changeBrightnessContrast(unsigned char* image, int width, int height, int bytesPerPixel, int brightness, float contrast)
{
    int row, col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            int offset = bytesPerPixel * (row * width + col);
            int byteIndex;
            for (byteIndex = 0; byteIndex < bytesPerPixel; byteIndex++) {
                int currentValue = image[offset + byteIndex];
                currentValue += brightness;
                float newValue = (currentValue - 128) * contrast + 128;
                if (newValue < 0) {
                    newValue = 0;
                }
                if (newValue > 255) {
                    newValue = 255;
                }
                image[offset + byteIndex] = (unsigned char)newValue;
            }
        }
    }
}

int main()
{
    // Load the image from file
    FILE* inputFile = fopen("input.bmp", "rb");
    if (!inputFile) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    // Read the BMP header info
    unsigned char bmpHeader[54];
    fread(bmpHeader, sizeof(unsigned char), 54, inputFile);
    int width = *(int*)&bmpHeader[18];
    int height = *(int*)&bmpHeader[22];
    int bytesPerPixel = *(unsigned short*)&bmpHeader[28] / 8;

    // Allocate memory for the image
    int imageSize = width * height * bytesPerPixel;
    unsigned char* image = (unsigned char*)malloc(imageSize);

    // Read the image data
    fread(image, sizeof(unsigned char), imageSize, inputFile);

    // Close the input file
    fclose(inputFile);

    // Perform image processing tasks
    flipHorizontally(image, width, height, bytesPerPixel);
    changeBrightnessContrast(image, width, height, bytesPerPixel, 50, 1.5);

    // Save the processed image to file
    FILE* outputFile = fopen("output.bmp", "wb");
    if (!outputFile) {
        printf("Error: Could not open output file\n");
        free(image);
        return 1;
    }

    // Write the BMP header info
    fwrite(bmpHeader, sizeof(unsigned char), 54, outputFile);

    // Write the image data
    fwrite(image, sizeof(unsigned char), imageSize, outputFile);

    // Close the output file
    fclose(outputFile);

    // Free memory
    free(image);

    return 0;
}