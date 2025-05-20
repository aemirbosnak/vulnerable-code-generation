//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// You can scale the width and height of the ASCII image
#define WIDTH 80
#define HEIGHT 40

// Change these values to adjust the ASCII range
#define CHARS_PER_LEVEL 25
#define NUM_LEVELS 4

// Change these characters to whatever you prefer
char characters[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

/**
 * Get grayscale value of a pixel at (x,y) in the given image data array
 * The image is represented as a 2D array of grayscale values from 0 to 255
 */
int getPixel(int x, int y, int* imageData, int width) {
    return imageData[y * width + x];
}

/**
 * Convert a grayscale value to an ASCII character
 */
char grayscaleToChar(int grayscaleVal) {
    int range = 256 / NUM_LEVELS;
    int level = grayscaleVal / range;
    level = level >= NUM_LEVELS ? NUM_LEVELS - 1 : level;
    int charIndex = grayscaleVal - level * range;
    charIndex /= CHARS_PER_LEVEL;
    charIndex = charIndex >= sizeof(characters) ? sizeof(characters) - 1 : charIndex;
    return characters[charIndex];
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [input file]\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE* inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    // Read image dimensions from input file
    int width, height;
    fread(&width, sizeof(int), 1, inputFile);
    fread(&height, sizeof(int), 1, inputFile);

    // Allocate memory for image data
    int* imageData = (int*) malloc(sizeof(int) * width * height);

    // Read image data from input file
    fread(imageData, sizeof(int), width * height, inputFile);
    fclose(inputFile);

    // Scale image to fit within specified ASCII dimensions
    float scaleX = (float) width / WIDTH;
    float scaleY = (float) height / HEIGHT;

    // Loop through output rows and columns
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Calculate corresponding pixel in original image
            int origX = (int) (x * scaleX);
            int origY = (int) (y * scaleY);

            // Get grayscale value of that pixel
            int grayscaleVal = getPixel(origX, origY, imageData, width);

            // Convert grayscale value to ASCII character
            char c = grayscaleToChar(grayscaleVal);

            // Print the ASCII character
            putchar(c);
        }
        putchar('\n');
    }

    // Free image data memory
    free(imageData);

    return 0;
}