//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Global variables
int width, height, max_color;
char palette[] = {' ', '.', '*', ':', 'o', '&', '8', '#', '@'};

// Function to load file
void loadFile(char* filePath, int* pixels) {
    // Open file for reading
    FILE* fp = fopen(filePath, "rb");

    // Read file header
    fscanf(fp, "P6\n%d %d\n%d\n", &width, &height, &max_color);

    // Allocate memory for pixel array
    int pixels_size = width * height * 3;
    unsigned char* buffer = (unsigned char*) malloc(pixels_size * sizeof(unsigned char));

    // Read pixel data
    fread(buffer, sizeof(unsigned char), pixels_size, fp);

    // Close file
    fclose(fp);

    // Convert RGB to grayscale
    for(int i=0; i<pixels_size; i+=3) {
        int grayScale = (0.21 * buffer[i]) + (0.72 * buffer[i+1]) + (0.07 * buffer[i+2]);
        pixels[i/3] = grayScale;
    }

    // Free buffer memory
    free(buffer);
}

// Function to convert pixel to ASCII character
char getChar(int pixel) {
    int palette_size = sizeof(palette) / sizeof(palette[0]);
    int index = roundf((pixel * (palette_size - 1)) / 255.0);
    return palette[index];
}

int main() {
    // Load image file
    char filePath[] = "medieval_castle.ppm";
    int pixels[width * height];
    loadFile(filePath, pixels);

    // Convert pixels to ASCII art string
    char asciiArt[width * height + height];
    int asciiIndex = 0;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int pixel = pixels[i * width + j];
            asciiArt[asciiIndex++] = getChar(pixel);
        }
        asciiArt[asciiIndex++] = '\n';
    }
    asciiArt[asciiIndex] = '\0';

    // Print ASCII art
    printf("%s", asciiArt);

    return 0;
}