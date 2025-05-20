//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Function to read the PGM file and populate the pixel values
int readPGM(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open input file");
        return 0;
    }
    
    char format[3];
    fgets(format, sizeof(format), file);
    if (format[0] != 'P' || format[1] != '5') {
        fprintf(stderr, "Invalid PGM format\n");
        fclose(file);
        return 0;
    }

    fscanf(file, "%d %d", width, height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // consume the newline

    for (int y = 0; y < *height; y++) {
        fread(image[y], sizeof(unsigned char), *width, file);
    }
    
    fclose(file);
    return 1;
}

// Function to map pixel value to ASCII character
char pixelToASCII(unsigned char pixel) {
    const char *ASCII_CHARS = "@%#*+=-:. ";
    int index = (pixel * 9) / 255; // 0-9 range
    return ASCII_CHARS[9 - index]; // reverse order for dark to light mapping
}

// Function to print the ASCII art
void printASCIIArt(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(pixelToASCII(image[y][x]));
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input-file.pgm>\n", argv[0]);
        return 1;
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    if (!readPGM(argv[1], image, &width, &height)) {
        return 1;
    }

    printASCIIArt(image, width, height);

    return 0;
}