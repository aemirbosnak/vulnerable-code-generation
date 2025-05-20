//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>

// Define ASCII characters for each grayscale intensity
const char asciiChars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// Function to convert grayscale pixel value to ASCII character
char getAsciiChar(int pixelValue) {
    int charIndex = pixelValue / 25;
    return asciiChars[charIndex];
}

int main() {
    // Open input and output files
    FILE *inputFile = fopen("input_image.pgm", "rb");
    FILE *outputFile = fopen("ascii_image.txt", "w");

    // Check if input file exists
    if (inputFile == NULL) {
        printf("Error: Could not open input file");
        return 1;
    }

    // Read image header
    char magicNumber[3];
    int width, height, maxVal;
    fscanf(inputFile, "%s %d %d %d\n", magicNumber, &width, &height, &maxVal);

    // Check if input file is a PGM (Portable Gray Map) file
    if (magicNumber[0] != 'P' || magicNumber[1] != '5') {
        printf("Error: Invalid input file format");
        return 1;
    }

    // Allocate memory for image data
    unsigned char *imageData = (unsigned char*)malloc(sizeof(unsigned char) * width * height);

    // Read image data
    fread(imageData, sizeof(unsigned char), width * height, inputFile);

    // Close input file
    fclose(inputFile);

    // Write ASCII art to output file
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixelValue = (int)imageData[i * width + j];
            char asciiChar = getAsciiChar(pixelValue);
            fprintf(outputFile, "%c", asciiChar);
        }
        fprintf(outputFile, "\n");
    }

    // Close output file
    fclose(outputFile);

    // Free memory
    free(imageData);

    return 0;
}