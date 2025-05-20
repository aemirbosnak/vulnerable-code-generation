//FormAI DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum values
#define MAX_FILENAME_LENGTH 256
#define MAX_PIXEL_VALUE 255

// Define struct for pixel
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Function to read image from file
Pixel* readImage(char* filename, int* width, int* height) {
    // Open file for reading in binary mode
    FILE* file = fopen(filename, "rb");

    // Check if file was opened successfully
    if (!file) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    // Read file header
    char header[54];
    fread(header, sizeof(char), 54, file);

    // Read width, height, and number of bits per pixel from header
    *width = *(int*) &header[18];
    *height = *(int*) &header[22];
    int bitsPerPixel = *(int*) &header[28];

    // Check if bits per pixel is 24 (RGB color)
    if (bitsPerPixel != 24) {
        printf("Unsupported pixel format. Bits per pixel must be 24.\n");
        fclose(file);
        return NULL;
    }

    // Calculate padding for each row
    int padding = (4 - ((*width * 3) % 4)) % 4;

    // Allocate memory for pixel array
    Pixel* pixels = (Pixel*) malloc((*width * *height) * sizeof(Pixel));

    // Read pixel data from file
    for (int y = 0; y < *height; y++) {
        for (int x = 0; x < *width; x++) {
            // Read pixel values in reverse order (BGR instead of RGB)
            fread(&pixels[(*height - y - 1) * *width + x].blue, sizeof(unsigned char), 1, file);
            fread(&pixels[(*height - y - 1) * *width + x].green, sizeof(unsigned char), 1, file);
            fread(&pixels[(*height - y - 1) * *width + x].red, sizeof(unsigned char), 1, file);
        }

        // Skip padding bytes at end of row
        fseek(file, padding, SEEK_CUR);
    }

    // Close file
    fclose(file);

    printf("Successfully loaded image from file %s\n", filename);

    return pixels;
}

// Function to write image to file
void writeImage(char* filename, Pixel* pixels, int width, int height) {
    // Open file for writing in binary mode
    FILE* file = fopen(filename, "wb");

    // Check if file was opened successfully
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    // Write file header
    char header[54];
    memset(header, 0, sizeof(header));
    header[0] = 'B';
    header[1] = 'M';
    *(int*) &header[2] = 54 + (width * height * 3);
    *(int*) &header[10] = 54;
    *(int*) &header[14] = 40;
    *(int*) &header[18] = width;
    *(int*) &header[22] = height;
    *(short*) &header[26] = 1;
    *(short*) &header[28] = 24;

    fwrite(header, sizeof(char), 54, file);

    // Calculate padding for each row
    int padding = (4 - ((width * 3) % 4)) % 4;

    // Write each pixel to file in reverse order (BGR instead of RGB)
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            Pixel* pixel = &pixels[y * width + x];
            fwrite(&pixel->blue, sizeof(unsigned char), 1, file);
            fwrite(&pixel->green, sizeof(unsigned char), 1, file);
            fwrite(&pixel->red, sizeof(unsigned char), 1, file);
        }

        // Add padding bytes at end of row
        for (int i = 0; i < padding; i++) {
            fputc(0x00, file);
        }
    }

    // Close file
    fclose(file);

    printf("Successfully saved image to file %s\n", filename);
}

// Function to invert the colors of an image
void invertColors(Pixel* pixels, int width, int height) {
    // Loop through each pixel in image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Invert the red, green, and blue values of the pixel
            pixels[y * width + x].red = MAX_PIXEL_VALUE - pixels[y * width + x].red;
            pixels[y * width + x].green = MAX_PIXEL_VALUE - pixels[y * width + x].green;
            pixels[y * width + x].blue = MAX_PIXEL_VALUE - pixels[y * width + x].blue;
        }
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter image filename: ");
    scanf("%s", filename);

    int width, height;
    Pixel* pixels = readImage(filename, &width, &height);

    if (pixels) {
        printf("Image size: %d x %d pixels\n", width, height);

        printf("1. Invert colors\n");

        int choice;
        printf("Enter choice (0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invertColors(pixels, width, height);
                writeImage("inverted.bmp", pixels, width, height);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.");
                break;
        }

        free(pixels);
    }

    return 0;
}