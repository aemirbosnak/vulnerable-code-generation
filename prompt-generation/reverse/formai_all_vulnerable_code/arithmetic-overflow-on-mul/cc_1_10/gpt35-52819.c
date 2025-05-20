//FormAI DATASET v1.0 Category: Image Editor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for image
typedef struct {
    int width;
    int height;
    int *pixels;
} Image;

// Function prototypes
void loadImage(Image *image, const char *filename);
void saveImage(Image *image, const char *filename);
void grayscale(Image *image);
void invert(Image *image);

int main() {
    // Create Image struct
    Image image;

    // Load image from file
    loadImage(&image, "example.bmp");

    // Apply grayscale filter
    grayscale(&image);

    // Save modified image to file
    saveImage(&image, "example_gray.bmp");

    // Apply invert filter
    invert(&image);

    // Save modified image to file
    saveImage(&image, "example_invert.bmp");

    // Free allocated memory
    free(image.pixels);
    image.pixels = NULL;

    return 0;
}

// Function to load image from file
void loadImage(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    // Header data
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Image dimensions
    image->width = *(int*)&header[18];
    image->height = *(int*)&header[22];

    // Calculate size of pixel array
    int size = 3 * image->width * image->height;
    image->pixels = (int*)malloc(sizeof(int) * size);

    // Read pixel data
    unsigned char data[size];
    fread(data, sizeof(unsigned char), size, file);
    fclose(file);

    // Convert pixel data to integers
    int i, j;
    for (i = 0, j = 0; i < size; i += 3, j++) {
        image->pixels[j] = (int)data[i];
        image->pixels[j] |= (int)data[i+1] << 8;
        image->pixels[j] |= (int)data[i+2] << 16;
    }
}

// Function to save image to file
void saveImage(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    // Header data
    unsigned char header[54] = {
        0x42, 0x4D,              // Bitmap signature
        0x36, 0xCF, 0x18, 0x00,  // File size (24-bit BMP = width*height*3 + 54)
        0x00, 0x00,              // Reserved
        0x00, 0x00,              // Reserved
        0x36, 0x00, 0x00, 0x00,  // Offset to pixel array
        0x28, 0x00, 0x00, 0x00,  // Header size (40 bytes for BMP V3)
        0x00, 0x02, 0x00, 0x00,  // Width
        0x00, 0x02, 0x00, 0x00,  // Height
        0x01, 0x00,              // Color planes (1)
        0x18, 0x00,              // Bits per pixel (24)
        0x00, 0x00, 0x00, 0x00,  // Compression (None)
        0x00, 0xCF, 0x18, 0x00,  // Image size (24-bit BMP = width*height*3)
        0x13, 0x0B, 0x00, 0x00,  // Horizontal resolution (2835 pixels/meter)
        0x13, 0x0B, 0x00, 0x00,  // Vertical resolution (2835 pixels/meter)
        0x00, 0x00, 0x00, 0x00,  // Color palette size (0)
        0x00, 0x00, 0x00, 0x00   // Important colors (0)
    };
    *(int*)&header[18] = image->width;
    *(int*)&header[22] = image->height;

    // Write header data
    fwrite(header, sizeof(unsigned char), 54, file);

    // Write pixel data
    int i, j;
    unsigned char data[3];
    for (i = 0, j = 0; i < 3 * image->width * image->height; i += 3, j++) {
        data[0] = (unsigned char)(image->pixels[j] & 0xFF);
        data[1] = (unsigned char)((image->pixels[j] >> 8) & 0xFF);
        data[2] = (unsigned char)((image->pixels[j] >> 16) & 0xFF);
        fwrite(data, sizeof(unsigned char), 3, file);
    }

    fclose(file);
}

// Function to apply grayscale filter
void grayscale(Image *image) {
    int i;
    for (i = 0; i < image->width * image->height; i++) {
        int r = image->pixels[i] & 0xFF;
        int g = (image->pixels[i] >> 8) & 0xFF;
        int b = (image->pixels[i] >> 16) & 0xFF;
        int gray = (r + g + b) / 3;
        image->pixels[i] = gray | (gray << 8) | (gray << 16);
    }
}

// Function to apply invert filter
void invert(Image *image) {
    int i;
    for (i = 0; i < image->width * image->height; i++) {
        int r = 255 - (image->pixels[i] & 0xFF);
        int g = 255 - ((image->pixels[i] >> 8) & 0xFF);
        int b = 255 - ((image->pixels[i] >> 16) & 0xFF);
        image->pixels[i] = r | (g << 8) | (b << 16);
    }
}