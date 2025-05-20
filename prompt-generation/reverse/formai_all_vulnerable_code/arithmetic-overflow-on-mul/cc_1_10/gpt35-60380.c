//FormAI DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HEADER_SIZE 54
#define RGB_SIZE 3

int main(int argc, char *argv[]) {

    // Open input file
    FILE *inFile = fopen(argv[1], "rb");

    // Check if the input file has been successfully opened
    if (inFile == NULL) {
        printf("Error: Unable to open input file.");
        return 1;
    }

    // Open output file
    FILE *outFile = fopen(argv[2], "wb");

    // Check if the output file has been successfully opened
    if (outFile == NULL) {
        printf("Error: Unable to open output file.");
        return 1;
    }

    // Read header
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, inFile);
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, outFile);

    // Extract image dimensions and bit depth information from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];

    // Calculate padding of input file
    int padding = (4 - (width * RGB_SIZE) % 4) % 4;

    // Determine required padding for output file
    int outPadding = (4 - (width * RGB_SIZE) % 4) % 4;

    // Allocate memory for input image data
    unsigned char *inData = (unsigned char*)malloc((width * RGB_SIZE + padding) * height);

    // Read input image data
    fread(inData, sizeof(unsigned char), (width * RGB_SIZE + padding) * height, inFile);

    // Allocate memory for output image data
    unsigned char *outData = (unsigned char*)malloc((width * RGB_SIZE + outPadding) * height);

    // Copy input image data to output image data
    memcpy(outData, inData, (width * RGB_SIZE + padding) * height);

    // Filter image using brightness adjustment
    float brightness = atof(argv[3]);
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            unsigned char *pixel = outData + (i*(width * RGB_SIZE + outPadding)) + (j*RGB_SIZE);
            pixel[0] = fmin(255, pixel[0] + brightness);
            pixel[1] = fmin(255, pixel[1] + brightness);
            pixel[2] = fmin(255, pixel[2] + brightness);
        }
    }

    // Write output image data to file
    fwrite(outData, sizeof(unsigned char), (width * RGB_SIZE + outPadding) * height, outFile);

    // Free allocated memory
    free(inData);
    free(outData);

    // Close input and output files
    fclose(inFile);
    fclose(outFile);

    return 0;
}