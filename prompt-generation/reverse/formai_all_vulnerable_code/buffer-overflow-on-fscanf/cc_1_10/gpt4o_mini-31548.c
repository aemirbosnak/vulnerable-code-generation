//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// ASCII characters for different levels of brightness
const char ASCII_CHARS[] = "@#S%?*+;:,. ";
const int ASCII_LEN = sizeof(ASCII_CHARS) - 1;

// Function to convert an image to grayscale
void rgb_to_grayscale(unsigned char r, unsigned char g, unsigned char b, unsigned char *gray) {
    *gray = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
}

// Function to map the grayscale value to an ASCII character
char grayscale_to_ascii(unsigned char gray) {
    int index = (gray * (ASCII_LEN - 1)) / 255;
    return ASCII_CHARS[ASCII_LEN - 1 - index]; // Invert for brightness
}

// Function to read a PPM image file
int read_ppm(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Cannot open file %s\n", filename);
        return 0;
    }

    char format[3];
    fscanf(file, "%s\n", format);
    if (strcmp(format, "P6") != 0) {
        printf("Invalid PPM file format\n");
        fclose(file);
        return 0;
    }

    fscanf(file, "%d %d\n255\n", width, height);
    for (int y = 0; y < *height; y++) {
        for (int x = 0; x < *width; x++) {
            fread(image[y][x], sizeof(unsigned char), 3, file);
        }
    }

    fclose(file);
    return 1;
}

// Function to convert the image to ASCII art
void image_to_ascii(unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char gray;
            rgb_to_grayscale(image[y][x][0], image[y][x][1], image[y][x][2], &gray);
            putchar(grayscale_to_ascii(gray));
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH][3];
    int width, height;
    
    if (!read_ppm(argv[1], image, &width, &height)) {
        return EXIT_FAILURE;
    }

    // Limit the output size by resizing the image if needed
    if (width > MAX_WIDTH) {
        height = (height * MAX_WIDTH) / width;
        width = MAX_WIDTH;
    }
    if (height > MAX_HEIGHT) {
        width = (width * MAX_HEIGHT) / height;
        height = MAX_HEIGHT;
    }

    // Convert the image to ASCII art
    image_to_ascii(image, width, height);
    
    return EXIT_SUCCESS;
}