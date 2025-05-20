//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_GRADIENT_SIZE 16
#define ASCII_GRADIENT "`^\",:;Il!i><~+_-?][}{1)(/\\tjrcunxzvYXJCLQ0OZmwqpdbkhao*#MW&8%B@$"

// Function to convert color values to grayscale
int colorToGrayscale(int r, int g, int b) {
    return (int) round(0.2126 * r + 0.7152 * g + 0.0722 * b);
}

// Function to get the ASCII character for a grayscale value
char getAsciiChar(int grayscaleValue) {
    int gradientStep = 256 / ASCII_GRADIENT_SIZE;
    int gradientIndex = grayscaleValue / gradientStep;
    return ASCII_GRADIENT[gradientIndex];
}

int main(int argc, char *argv[]) {
    char gradient[MAX_HEIGHT][MAX_WIDTH];
    int grayscale[MAX_HEIGHT][MAX_WIDTH];
    int width, height;
    char inputFilename[256], outputFilename[256];

    printf("Enter the input filename: ");
    scanf("%s", inputFilename);

    FILE *inputFile = fopen(inputFilename, "rb");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Read header
    char buffer[80];
    fgets(buffer, 80, inputFile);

    // Read width and height
    fscanf(inputFile, "%d %d", &width, &height);

    // Read max value and move to the first pixel value
    int maxVal;
    fscanf(inputFile, "%d", &maxVal);
    fgetc(inputFile);

    // Read image data and convert to grayscale
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int r = fgetc(inputFile);
            int g = fgetc(inputFile);
            int b = fgetc(inputFile);

            // Convert RGB to grayscale
            int grayscaleValue = colorToGrayscale(r, g, b);
            grayscale[row][col] = grayscaleValue;

            // Convert grayscale value to ASCII character
            char asciiChar = getAsciiChar(grayscaleValue);
            gradient[row][col] = asciiChar;
        }
    }

    fclose(inputFile);

    printf("Enter the output filename: ");
    scanf("%s", outputFilename);

    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    // Write ASCII art to output file
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            fputc(gradient[row][col], outputFile);
        }
        fputc('\n', outputFile);
    }

    fclose(outputFile);

    printf("Conversion complete. Output written to %s.\n", outputFilename);

    return 0;
}