//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 70 // Define the number of ASCII characters to use

// Array of ASCII characters to represent gray levels
const char asciiChars[MAX_CHAR] = "@%#*+=-:. "; // Characters from dark to light

// Function to read a PGM image
unsigned char *readPGM(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (format[1] != '5') {
        fprintf(stderr, "Unsupported PGM format. Only binary P5 supported.\n");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", width, height);
    int maxVal;
    fscanf(file, "%d", &maxVal);
    fgetc(file); // Eat the newline after maxVal

    int size = (*width) * (*height);
    unsigned char *imageData = (unsigned char *)malloc(size);
    if (imageData == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    fread(imageData, sizeof(unsigned char), size, file);
    fclose(file);
    return imageData;
}

// Function to convert gray values to ASCII
void convertToASCII(unsigned char *imageData, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the index in the image data array
            int idx = y * width + x;
            // Map the pixel value to an ASCII character
            unsigned char gray = imageData[idx];
            int asciiIndex = (gray * (MAX_CHAR - 1)) / 255;
            putchar(asciiChars[asciiIndex]);
        }
        putchar('\n'); // Move to the next line after each row
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_pgm_file>\n", argv[0]);
        return 1;
    }

    int width, height;
    unsigned char *imageData = readPGM(argv[1], &width, &height);
    if (!imageData) {
        return 1;
    }

    printf("Converting PGM image of size %dx%d to ASCII art...\n", width, height);
    convertToASCII(imageData, width, height);

    free(imageData); // Free allocated memory
    return 0;
}