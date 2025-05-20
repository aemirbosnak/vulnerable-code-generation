//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 150

// This function converts a single pixel to its ASCII art equivalent
char pixelToChar(int pixelVal, int maxVal) {
    int range = maxVal / 10;
    if (pixelVal >= maxVal - range) {
        return '@';
    } else if (pixelVal >= maxVal - 2 * range) {
        return '#';
    } else if (pixelVal >= maxVal - 3 * range) {
        return '$';
    } else if (pixelVal >= maxVal - 4 * range) {
        return '%';
    } else if (pixelVal >= maxVal - 5 * range) {
        return '*';
    } else if (pixelVal >= maxVal - 6 * range) {
        return '=';
    } else if (pixelVal >= maxVal - 7 * range) {
        return '-';
    } else if (pixelVal >= maxVal - 8 * range) {
        return ':';
    } else if (pixelVal >= maxVal - 9 * range) {
        return '.';
    } else {
        return ' ';
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: no filename specified\n");
        return -1;
    }

    char *filename = argv[1];

    FILE *filePtr = fopen(filename, "rb");

    if (!filePtr) {
        printf("Error: cannot open file %s\n", filename);
        return -1;
    }

    // Get image dimensions from file header
    int width, height;
    fseek(filePtr, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, filePtr);
    fread(&height, sizeof(int), 1, filePtr);

    // Limit width to MAX_WIDTH
    if (width > MAX_WIDTH) {
        height = (int)((float)height / ((float)width / MAX_WIDTH));
        width = MAX_WIDTH;
    }

    int maxVal = 255;
    fseek(filePtr, 28, SEEK_SET);

    // Allocate memory for pixel data
    unsigned char *pixels = (unsigned char*)malloc(sizeof(unsigned char) * width * height);

    // Read pixel data from file
    fread(pixels, sizeof(unsigned char), width * height, filePtr);

    fclose(filePtr);

    // Initialize ASCII art matrix with spaces
    char asciiArt[MAX_WIDTH][height];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < MAX_WIDTH; x++) {
            asciiArt[x][y] = ' ';
        }
    }

    // Convert pixels to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixelVal = (int)pixels[x + y * width];
            asciiArt[x][y] = pixelToChar(pixelVal, maxVal);
        }
    }

    // Print ASCII art to screen
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < MAX_WIDTH; x++) {
            printf("%c ", asciiArt[x][y]);
        }
        printf("\n");
    }

    // Free memory
    free(pixels);

    return 0;
}