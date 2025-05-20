//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 50
#define CHAR_SET "#@%S?*+-. " // Characters used for the ASCII representation, from darkest to lightest

typedef unsigned char pixel[3]; // A pixel represented by RGB values

// Function to read an image from a PPM file
void read_ppm(const char* filename, pixel** image, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Error: Only P6 PPM format is supported.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", width, height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // consume the newline after maxval

    *image = (pixel*)malloc((*height) * sizeof(pixel) * (*width));
    fread(*image, sizeof(pixel), (*width) * (*height), file);
    fclose(file);
}

// Function to convert a pixel to a brightness value
int pixel_to_brightness(pixel p) {
    // Using the luminance formula to convert RGB to a brightness value
    return (int)(0.299 * p[0] + 0.587 * p[1] + 0.114 * p[2]);
}

// Function to map a brightness value to an ASCII character
char brightness_to_ascii(int brightness) {
    int index = (brightness * (strlen(CHAR_SET) - 1)) / 255;
    return CHAR_SET[index];
}

// Function to convert the image to ASCII art
void image_to_ascii(pixel* image, int width, int height) {
    char ascii_art[MAX_HEIGHT][MAX_WIDTH + 1]; // To store ASCII art
    int ascii_height = height / (256 / MAX_HEIGHT);
    int ascii_width = width / (256 / MAX_WIDTH);

    for (int y = 0; y < ascii_height; y++) {
        for (int x = 0; x < ascii_width; x++) {
            int pixel_index = (y * (256 / MAX_HEIGHT) * width) + (x * (256 / MAX_WIDTH));
            int brightness = pixel_to_brightness(image[pixel_index]);
            ascii_art[y][x] = brightness_to_ascii(brightness);
        }
        ascii_art[y][ascii_width] = '\0'; // null-terminate the string
    }

    // Print ASCII art
    for (int y = 0; y < ascii_height; y++) {
        printf("%s\n", ascii_art[y]);
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pixel* image = NULL;
    int width, height;
    
    read_ppm(argv[1], &image, &width, &height);
    
    image_to_ascii(image, width, height);

    free(image);
    return 0;
}