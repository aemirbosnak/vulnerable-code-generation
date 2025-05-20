//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 60

// ASCII characters to represent pixel brightness
const char *ASCII_CHARS = "@%#*+=-:. ";

// Function to convert pixel intensity to ASCII character
char pixelToASCII(int pixelValue) {
    return ASCII_CHARS[(pixelValue * strlen(ASCII_CHARS)) / 256];
}

// Function to read image from file
unsigned char* readImage(const char* filename, int* width, int* height) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Assuming a simple 24-bit bitmap image format
    fseek(fp, 18, SEEK_SET);
    fread(width, sizeof(int), 1, fp);
    fread(height, sizeof(int), 1, fp);

    // Allocate memory for the image data
    unsigned char *imageData = malloc((*width) * (*height) * 3);
    fseek(fp, 54, SEEK_SET);  // Move to the pixel data

    fread(imageData, 3, (*width) * (*height), fp);
    fclose(fp);
    return imageData;
}

// Function to convert the image to ASCII art
void convertToAsciiArt(unsigned char* imageData, int width, int height) {
    for (int i = height - 1; i >= 0; i--) {  // Draw from bottom to top
        for (int j = 0; j < width; j++) {
            // Calculate the index of the pixel in the image data
            int pixelIndex = (i * width + j) * 3;
            // Calculate the average intensity of the pixel
            int r = imageData[pixelIndex + 2]; // Red
            int g = imageData[pixelIndex + 1]; // Green
            int b = imageData[pixelIndex];     // Blue
            int avgIntensity = (r + g + b) / 3;

            // Print the corresponding ASCII character based on intensity
            putchar(pixelToASCII(avgIntensity));
        }
        putchar('\n');  // New line for the next row
    }
}

// Function to free allocated memory
void freeImage(unsigned char* imageData) {
    free(imageData);
}

// Main function to drive the ASCII art conversion
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image-file.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    unsigned char *imageData = readImage(argv[1], &width, &height);

    // Resize the image if it's larger than the desired output size
    if (width > WIDTH) {
        height = (height * WIDTH) / width; // Adjust height based on width change
        width = WIDTH;
    }
    if (height > HEIGHT) {
        width = (width * HEIGHT) / height; // Adjust width based on height change
        height = HEIGHT;
    }

    convertToAsciiArt(imageData, width, height);
    freeImage(imageData);

    return EXIT_SUCCESS;
}