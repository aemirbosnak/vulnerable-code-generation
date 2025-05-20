//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

// Function to flip the image horizontally
void horizontalFlip(int rows, int cols, unsigned char *image) {
    int i, j;
    unsigned char temp;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols/2; j++) {
            temp = image[i*cols + j];
            image[i*cols + j] = image[i*cols + cols - j - 1];
            image[i*cols + cols - j - 1] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void brightnessAdjustment(int rows, int cols, unsigned char *image, int adjustmentValue) {
    int i, j;
    int pixelValue;
    float multiplier = (float)(adjustmentValue + MAX_PIXEL_VALUE) / (float)MAX_PIXEL_VALUE;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            pixelValue = (int)image[i*cols + j] * multiplier;
            pixelValue = (pixelValue > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : pixelValue;
            image[i*cols + j] = (unsigned char)pixelValue;
        }
    }
}

// Function to adjust the contrast of the image
void contrastAdjustment(int rows, int cols, unsigned char *image, int adjustmentValue) {
    int i, j;
    int pixelValue;
    float multiplier = (float)(adjustmentValue + MAX_PIXEL_VALUE) / (float)(MAX_PIXEL_VALUE - adjustmentValue);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            pixelValue = (int)image[i*cols + j] * multiplier - adjustmentValue;
            pixelValue = (pixelValue < 0) ? 0 : ((pixelValue > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : pixelValue);
            image[i*cols + j] = (unsigned char)pixelValue;
        }
    }
}

int main() {
    FILE *fp;
    unsigned char *image;
    char *filename = "image.pgm";
    char *outputFilename;
    char *flipFilename;
    int rows, cols, maxVal, adjustmentValue;
    int i, j;

    // Read the image file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        exit(1);
    }

    // Read the file header
    fscanf(fp, "P5\n%d %d\n%d\n", &cols, &rows, &maxVal);

    // Allocate memory for the image data
    image = (unsigned char*)malloc(rows*cols*sizeof(unsigned char));

    // Read the image data
    fread(image, sizeof(unsigned char), rows*cols, fp);

    // Close the file
    fclose(fp);

    // Flip the image horizontally
    horizontalFlip(rows, cols, image);
    
    // Save the flipped image to a new file
    flipFilename = "flipped_image.pgm";
    fp = fopen(flipFilename, "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", cols, rows, maxVal);
    fwrite(image, sizeof(unsigned char), rows*cols, fp);
    fclose(fp);
    printf("Flipped image saved to file %s\n", flipFilename);

    // Adjust the brightness of the image
    printf("Enter an integer value to adjust the brightness of the image: ");
    scanf("%d", &adjustmentValue);
    brightnessAdjustment(rows, cols, image, adjustmentValue);

    // Save the brightness-adjusted image to a new file
    outputFilename = "brightness_adjusted_image.pgm";
    fp = fopen(outputFilename, "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", cols, rows, maxVal);
    fwrite(image, sizeof(unsigned char), rows*cols, fp);
    fclose(fp);
    printf("Brightness-adjusted image saved to file %s\n", outputFilename);

    // Adjust the contrast of the image
    printf("Enter an integer value to adjust the contrast of the image: ");
    scanf("%d", &adjustmentValue);
    contrastAdjustment(rows, cols, image, adjustmentValue);

    // Save the contrast-adjusted image to a new file
    outputFilename = "contrast_adjusted_image.pgm";
    fp = fopen(outputFilename, "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", cols, rows, maxVal);
    fwrite(image, sizeof(unsigned char), rows*cols, fp);
    fclose(fp);
    printf("Contrast-adjusted image saved to file %s\n", outputFilename);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}