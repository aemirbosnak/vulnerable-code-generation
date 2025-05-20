//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 40

// Converts an RGB color to a grayscale value
unsigned char convertToGrayscale(unsigned char r, unsigned char g, unsigned char b) {
    return (unsigned char)(0.2126 * r + 0.7152 * g + 0.0722 * b);
}

// Converts a grayscale value to an ASCII character
char convertToAscii(unsigned char grayscale) {
    const char *asciiChars = " .,-~:;=!*#$@";
    int range = 256 / strlen(asciiChars);
    return asciiChars[grayscale / range];
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *imageFile = fopen(argv[1], "rb");
    if(!imageFile) {
        printf("Could not open image file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Read image header
    char type[3];
    unsigned int width, height;
    int maxVal;
    fscanf(imageFile, "%s\n%u %u\n%i\n", type, &width, &height, &maxVal);

    printf("Image type: %s\nDimensions: %ux%u\nMaximum color value: %i\n", type, width, height, maxVal);

    // Only P6 images are supported (binary RGB)
    if(type[0] != 'P' || type[1] != '6') {
        printf("Unsupported image type: %s\n", type);
        fclose(imageFile);
        return EXIT_FAILURE;
    }

    // Resize image to fit 80x40 terminal
    if(width > WIDTH || height > HEIGHT) {
        printf("Resizing image...\n");
        float scaleX = (float)WIDTH / width;
        float scaleY = (float)HEIGHT / height;
        float scale = scaleX < scaleY ? scaleX : scaleY;
        width = (unsigned int)(width * scale);
        height = (unsigned int)(height * scale);
    }

    // Read image data
    unsigned char pixel[3];
    unsigned char grayscale;
    char asciiPixels[HEIGHT][WIDTH + 1];
    for(unsigned int i = 0; i < height; i++) {
        for(unsigned int j = 0; j < width; j++) {
            // Read RGB values
            fread(pixel, sizeof(unsigned char), 3, imageFile);
            // Convert to grayscale
            grayscale = convertToGrayscale(pixel[0], pixel[1], pixel[2]);
            // Convert to ASCII character
            asciiPixels[i][j] = convertToAscii(grayscale);
        }
        asciiPixels[i][width] = '\0';
        fseek(imageFile, (long int)width * 2, SEEK_CUR);
    }

    fclose(imageFile);

    // Print ASCII art
    printf("\n");
    for(unsigned int i = 0; i < height; i++) {
        printf("%s\n", asciiPixels[i]);
    }

    return EXIT_SUCCESS;
}