//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Function to flip the image horizontally
void flipHorizontally(unsigned char image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
    int i, j;
    unsigned char temp;

    for(i = 0; i < height; i++) {
        for(j = 0; j < width/2; j++) {
            temp = image[j][i];
            image[j][i] = image[width-j-1][i];
            image[width-j-1][i] = temp;
        }
    }
}

// Function to change the brightness of the image
void changeBrightness(unsigned char image[MAX_WIDTH][MAX_HEIGHT], int width, int height, int value) {
    int i, j;
    unsigned char pixel;

    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            pixel = image[j][i];
            // Increase the pixel value by the brightness value
            pixel += value;
            // Limit the pixel value between 0 and 255
            if(pixel > 255) {
                pixel = 255;
            } else if(pixel < 0) {
                pixel = 0;
            }
            // Assign the new pixel value back to the image
            image[j][i] = pixel;
        }
    }
}

// Function to change the contrast of the image
void changeContrast(unsigned char image[MAX_WIDTH][MAX_HEIGHT], int width, int height, float value) {
    int i, j;
    unsigned char pixel;

    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            pixel = image[j][i];
            // Multiply the pixel value by the contrast value
            pixel = (unsigned char)(((float)pixel - 128.0) * value + 128.0);
            // Limit the pixel value between 0 and 255
            if(pixel > 255) {
                pixel = 255;
            } else if(pixel < 0) {
                pixel = 0;
            }
            // Assign the new pixel value back to the image
            image[j][i] = pixel;
        }
    }
}

int main() {
    FILE *fpIn, *fpOut;
    unsigned char image[MAX_WIDTH][MAX_HEIGHT];
    char fileName[20];
    int width, height, i, j, brightnessValue;
    float contrastValue;

    // Read the input file
    printf("Enter the name of the input image file: ");
    scanf("%s", fileName);
    fpIn = fopen(fileName, "rb");
    if(fpIn == NULL) {
        printf("Error: Unable to open input file!\n");
        return 0;
    }
    fread(&width, sizeof(int), 1, fpIn);
    fread(&height, sizeof(int), 1, fpIn);
    fread(image, sizeof(unsigned char), width*height, fpIn);
    fclose(fpIn);

    // Flip the image horizontally
    flipHorizontally(image, width, height);

    // Change the brightness of the image
    printf("Enter the brightness value (-255 to 255): ");
    scanf("%d", &brightnessValue);
    changeBrightness(image, width, height, brightnessValue);

    // Change the contrast of the image
    printf("Enter the contrast value (0.0 to 2.0): ");
    scanf("%f", &contrastValue);
    changeContrast(image, width, height, contrastValue);

    // Write the output file
    printf("Enter the name of the output image file: ");
    scanf("%s", fileName);
    fpOut = fopen(fileName, "wb");
    if(fpOut == NULL) {
        printf("Error: Unable to open output file!\n");
        return 0;
    }
    fwrite(&width, sizeof(int), 1, fpOut);
    fwrite(&height, sizeof(int), 1, fpOut);
    fwrite(image, sizeof(unsigned char), width*height, fpOut);
    fclose(fpOut);

    printf("Image processing complete!\n");

    return 0;
}