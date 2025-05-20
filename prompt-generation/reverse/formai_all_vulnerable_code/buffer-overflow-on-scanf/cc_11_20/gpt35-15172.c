//FormAI DATASET v1.0 Category: Image Editor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FILTER_SIZE 20

int main(int argc, char *argv[]) {
    // Initialize variables
    char inputFileName[MAX_FILE_NAME];
    char outputFileName[MAX_FILE_NAME];
    char filter[MAX_FILTER_SIZE];
    int height, width, maxVal, filterSize;
    unsigned char *inputImage, *outputImage, *filterArray;

    // Get user input for input file name, output file name, filter, and filter size
    printf("Enter input image file name: ");
    scanf("%s", inputFileName);
    printf("Enter output image file name: ");
    scanf("%s", outputFileName);
    printf("Enter filter name (e.g. blur, sharpen): ");
    scanf("%s", filter);
    printf("Enter filter size (odd number): ");
    scanf("%d", &filterSize);

    // Open input file
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    // Read input file header
    char header[3];
    fscanf(inputFile, "%s\n%d %d\n%d\n", header, &width, &height, &maxVal);

    // Allocate memory for input and output images
    inputImage = (unsigned char*) malloc(width * height * sizeof(unsigned char));
    outputImage = (unsigned char*) malloc(width * height * sizeof(unsigned char));

    // Read input image
    fread(inputImage, sizeof(unsigned char), width * height, inputFile);

    // Close input file
    fclose(inputFile);

    // Allocate memory for filter array
    filterArray = (unsigned char*) malloc(filterSize * filterSize * sizeof(unsigned char));

    // Apply filter based on user input
    if (strcmp(filter, "blur") == 0) {
        // Generate blur filter
        for (int i = 0; i < filterSize; i++) {
            for (int j = 0; j < filterSize; j++) {
                filterArray[i*filterSize+j] = 1;
            }
        }
        // Normalize filter
        int filterSum = filterSize * filterSize;
        for (int i = 0; i < filterSize; i++) {
            for (int j = 0; j < filterSize; j++) {
                filterArray[i*filterSize+j] /= filterSum;
            }
        }
        // Apply filter to input image
        for (int x = 1; x < height-1; x++) {
            for (int y = 1; y < width-1; y++) {
                double sum = 0;
                for (int i = 0; i < filterSize; i++) {
                    for (int j = 0; j < filterSize; j++) {
                        sum += inputImage[(x+i-1)*width+(y+j-1)] * filterArray[i*filterSize+j];
                    }
                }
                outputImage[x*width+y] = (unsigned char) sum;
            }
        }
    } else if (strcmp(filter, "sharpen") == 0) {
        // Generate sharpen filter
        filterArray[0] = 0; filterArray[1] = -1; filterArray[2] = 0;
        filterArray[3] = -1; filterArray[4] = 5; filterArray[5] = -1;
        filterArray[6] = 0; filterArray[7] = -1; filterArray[8] = 0;
        // Apply filter to input image
        for (int x = 1; x < height-1; x++) {
            for (int y = 1; y < width-1; y++) {
                double sum = 0;
                for (int i = 0; i < filterSize; i++) {
                    for (int j = 0; j < filterSize; j++) {
                        sum += inputImage[(x+i-1)*width+(y+j-1)] * filterArray[i*filterSize+j];
                    }
                }
                outputImage[x*width+y] = (unsigned char) sum;
            }
        }
    } else {
        printf("Error: Invalid filter name\n");
        return 1;
    }

    // Open output file
    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open output file\n");
        return 1;
    }

    // Write output file header
    fprintf(outputFile, "%s\n%d %d\n%d\n", header, width, height, maxVal);

    // Write output image
    fwrite(outputImage, sizeof(unsigned char), width * height, outputFile);

    // Close output file
    fclose(outputFile);

    // Free allocated memory
    free(inputImage);
    free(outputImage);
    free(filterArray);

    return 0;
}