//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PIXEL_VALUE 255

unsigned char flipPixelValue(unsigned char pixelValue) {
    return MAX_PIXEL_VALUE - pixelValue;
}

void flipImage(unsigned char **image, int numRows, int numCols) {
    int row, col;
    unsigned char temp;

    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols/2; col++) {
            temp = image[row][col];
            image[row][col] = image[row][numCols - col - 1];
            image[row][numCols - col - 1] = temp;
        }
    }
}

void changeBrightness(unsigned char **image, int numRows, int numCols, float brightnessFactor) {
    int row, col;
    float temp;

    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            temp = image[row][col] * brightnessFactor;
            image[row][col] = (unsigned char)fmin(MAX_PIXEL_VALUE, temp);
        }
    }
}

void changeContrast(unsigned char **image, int numRows, int numCols, float contrastFactor) {
    int row, col;
    float temp;

    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            temp = ((image[row][col] - MAX_PIXEL_VALUE/2) * contrastFactor) + MAX_PIXEL_VALUE/2;
            image[row][col] = (unsigned char)fmin(MAX_PIXEL_VALUE, fmax(0, temp));
        }
    }
}

void runImageProcessing(char *inputFilename, char *outputFilename, float brightnessFactor, float contrastFactor) {
    FILE *inputFile, *outputFile;
    char *magicNum;
    int numCols, numRows, maxPixelValue, row, col;
    unsigned char **image;

    // Open input file
    inputFile = fopen(inputFilename, "rb");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Failed to open input file '%s'\n", inputFilename);
        exit(EXIT_FAILURE);
    }

    // Read image header
    magicNum = malloc(3 * sizeof(char));
    fscanf(inputFile, "%s\n%d %d\n%d\n", magicNum, &numCols, &numRows, &maxPixelValue);

    // Allocate memory for image
    image = (unsigned char **)malloc(numRows * sizeof(unsigned char *));
    for (row = 0; row < numRows; row++) {
        image[row] = (unsigned char *)malloc(numCols * sizeof(unsigned char));
    }

    // Read image data
    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            fread(&image[row][col], sizeof(unsigned char), 1, inputFile);
        }
    }

    // Close input file
    fclose(inputFile);

    // Flip image
    flipImage(image, numRows, numCols);

    // Change brightness
    changeBrightness(image, numRows, numCols, brightnessFactor);

    // Change contrast
    changeContrast(image, numRows, numCols, contrastFactor);

    // Flip image again to restore original orientation
    flipImage(image, numRows, numCols);

    // Open output file
    outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Failed to open output file '%s'\n", outputFilename);
        exit(EXIT_FAILURE);
    }

    // Write image header
    fprintf(outputFile, "%s\n%d %d\n%d\n", magicNum, numCols, numRows, maxPixelValue);

    // Write image data
    for (row = 0; row < numRows; row++) {
        for (col = 0; col < numCols; col++) {
            fwrite(&image[row][col], sizeof(unsigned char), 1, outputFile);
        }
    }

    // Close output file
    fclose(outputFile);

    // Free allocated memory
    free(magicNum);
    for (row = 0; row < numRows; row++) {
        free(image[row]);
    }
    free(image);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Error: Invalid command line arguments.\n");
        fprintf(stderr, "Usage: ./image_processing input_file output_file brightness_factor contrast_factor\n");
        exit(EXIT_FAILURE);
    }

    char *inputFilename = argv[1];
    char *outputFilename = argv[2];
    float brightnessFactor = atof(argv[3]);
    float contrastFactor = atof(argv[4]);

    runImageProcessing(inputFilename, outputFilename, brightnessFactor, contrastFactor);

    return 0;
}