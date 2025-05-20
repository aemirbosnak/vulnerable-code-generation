//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Function to load a PGM (Portable Gray Map)
int loadPGM(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    char header[3];
    fscanf(file, "%2s", header);
    if (header[0] != 'P' || header[1] != '5') {
        printf("Unsupported file format: %s\n", header);
        fclose(file);
        return -1;
    }

    fscanf(file, "%d %d", width, height);
    int maxGray;
    fscanf(file, "%d", &maxGray);
    fgetc(file); // Read the newline character

    for (int y = 0; y < *height; ++y) {
        fread(image[y], 1, *width, file);
    }

    fclose(file);
    return 0;
}

// Function to map pixel brightness to ASCII characters
char pixelToASCII(unsigned char pixel) {
    const char *asciiChars = "@#S%?*+;:. ";
    int index = (pixel * (sizeof(asciiChars) - 1)) / 255; // Scale pixel value to range
    return asciiChars[index];
}

// Function to convert image to ASCII art
void convertToASCII(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    printf("\e[1;37m"); // Set the text color to white
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            char asciiChar = pixelToASCII(image[y][x]);
            printf("%c", asciiChar);
        }
        printf("\n");
    }
    printf("\e[0m"); // Reset text color
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image.pgm>\n", argv[0]);
        return 1;
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    // Load the PGM image
    if (loadPGM(argv[1], image, &width, &height) != 0) {
        return 1;
    }

    // Convert to ASCII and display
    printf("Converting image to ASCII art...\n\n");
    convertToASCII(image, width, height);
    printf("Enjoy your ASCII art!\n");

    return 0;
}