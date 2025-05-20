//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80
#define ASCII_CHARS " .:-=+*%@#"

// Struct to store pixel information
typedef struct {
    uint8_t r, g, b;
} Pixel;

// Function to load a PPM image
Pixel **loadPPM(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported file format: expected P6\n");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", width, height);
    int maxVal;
    fscanf(file, "%d", &maxVal);
    fgetc(file); // consume newline

    Pixel **image = malloc((*height) * sizeof(Pixel *));
    for (int i = 0; i < *height; i++) {
        image[i] = malloc((*width) * sizeof(Pixel));
        fread(image[i], sizeof(Pixel), *width, file);
    }

    fclose(file);
    return image;
}

// Function to convert a pixel to grayscale
uint8_t toGrayscale(Pixel pixel) {
    return (uint8_t)(0.2989 * pixel.r + 0.5870 * pixel.g + 0.1140 * pixel.b);
}

// Function to map grayscale to ASCII
char mapToAscii(uint8_t gray) {
    int scale = strlen(ASCII_CHARS) - 1; // Scale to reach max ASCII index
    return ASCII_CHARS[(gray * scale) / 255];
}

// Function to convert an image to ASCII
void imageToASCII(Pixel **image, int width, int height) {
    int newWidth = (width > MAX_WIDTH) ? MAX_WIDTH : width;
    int newHeight = (height > MAX_HEIGHT) ? MAX_HEIGHT : height;

    for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {
            uint8_t gray = toGrayscale(image[y][x]);
            char ascii = mapToAscii(gray);
            putchar(ascii);
        }
        putchar('\n');
    }
}

// Cleanup function for allocated memory
void freeImage(Pixel **image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return 1;
    }

    int width, height;
    Pixel **image = loadPPM(argv[1], &width, &height);
    
    if (!image) {
        return 1;
    }

    imageToASCII(image, width, height);
    freeImage(image, height);

    return 0;
}