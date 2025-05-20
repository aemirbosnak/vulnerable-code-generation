//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_COLOR 255

typedef struct {
    unsigned char r, g, b;
} Color;

Color image[WIDTH][HEIGHT];

int main(void) {
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) { perror("Error opening file"); exit(1); }

    // Read header
    unsigned char header[54];
    fread(header, 54, 1, fp);

    // Check if it's a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Not a valid BMP file\n");
        exit(1);
    }

    // Get image dimensions
    unsigned int width = *(int*)&header[18];
    unsigned int height = *(int*)&header[22];

    // Check if image is too large
    if (width > WIDTH || height > HEIGHT) {
        fprintf(stderr, "Error: Image too large\n");
        exit(1);
    }

    // Read image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&image[j][i], sizeof(Color), 1, fp);
        }
    }

    fclose(fp);

    // Convert image to ASCII art
    char ascii[WIDTH][HEIGHT];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int gray = (image[j][i].r + image[j][i].g + image[j][i].b) / 3;
            ascii[j][i] = " .':-=+*#%@";
        }
    }

    // Print ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii[j][i]);
        }
        printf("\n");
    }

    return 0;
}