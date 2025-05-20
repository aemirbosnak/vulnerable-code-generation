//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 50
#define MAX_CHAR 70

char asciiChars[] = " .:-=+*%@#"; // Characters to represent different luminance levels

// Function to calculate luminance based on RGB values
int getLuminance(unsigned char r, unsigned char g, unsigned char b) {
    return (r * 299 + g * 587 + b * 114) / 1000;
}

// Function to map the luminance value to an ASCII character
char mapToAscii(int luminance) {
    int index = (luminance * (sizeof(asciiChars) - 2)) / 255; // map to the size of the asciiChars
    return asciiChars[index];
}

// Function to read the PPM image file
unsigned char* readPPM(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }
    char buffer[16];
    fgets(buffer, sizeof(buffer), file);
    if (buffer[0] != 'P' || buffer[1] != '6') {
        fprintf(stderr, "Invalid PPM file format\n");
        fclose(file);
        return NULL;
    }
    
    // Read image size and max color value
    fscanf(file, "%d %d", width, height);
    int maxColorValue;
    fscanf(file, "%d", &maxColorValue);
    fgetc(file); // Consume the newline character

    // Allocate memory for the raw image data
    unsigned char *data = (unsigned char*)malloc((*width) * (*height) * 3);
    fread(data, 3, (*width) * (*height), file);
    fclose(file);

    return data;
}

// Function to convert the image to ASCII art
void convertToASCII(unsigned char *image, int width, int height) {
    for (int y = 0; y < height; y += 2) {
        for (int x = 0; x < width; x++) {
            int r = image[(y * width + x) * 3 + 0];
            int g = image[(y * width + x) * 3 + 1];
            int b = image[(y * width + x) * 3 + 2];
            int luminance = getLuminance(r, g, b);
            putchar(mapToAscii(luminance));
        }
        putchar('\n'); // New line after each row
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    unsigned char *image = readPPM(argv[1], &width, &height);
    if (!image) {
        return EXIT_FAILURE;
    }

    // Set terminal size to create a comfortable viewing experience
    printf("\033[8;%d;%dt", HEIGHT, WIDTH);
    
    // Convert the image to ASCII art and print it
    convertToASCII(image, width, height);

    // Free allocated memory
    free(image);
    return EXIT_SUCCESS;
}