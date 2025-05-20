//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define image dimensions
#define WIDTH 80
#define HEIGHT 60

// Define ASCII characters used for image conversion
#define ASCII_CHARS " .:-=+*#%@"


// Convert 1 pixel to ASCII character
char pixelToChar(int pixelValue) {
    // Calculate the range of pixel values that each ASCII character represents
    int range = 255 / strlen(ASCII_CHARS);

    // Return the ASCII character that corresponds to the pixel value's range
    return ASCII_CHARS[pixelValue / range];
}

// Convert an image to ASCII art
char* imageToAscii(char* imagePath) {
    // Open the image file
    FILE* imageFile = fopen(imagePath, "rb");

    if (!imageFile) {
        printf("Error: Could not open image file\n");
        return NULL;
    }

    // Read the image file header
    char header[54];
    fread(header, sizeof(char), 54, imageFile);

    // Extract image dimensions from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    printf("Image Dimensions: %dx%d\n", width, height);

    // Ensure that the image dimensions are not larger than the ASCII art dimensions
    if (width > WIDTH || height > HEIGHT) {
        printf("Error: Image dimensions are larger than the maximum ASCII art dimensions\n");
        return NULL;
    }

    // Calculate the number of pixels in the image
    int numPixels = width * height;

    // Allocate memory for pixel data
    unsigned char* pixelData = (unsigned char*)malloc(sizeof(unsigned char) * numPixels * 3);

    // Read the pixel data from the image file
    fread(pixelData, sizeof(unsigned char), numPixels * 3, imageFile);

    // Allocate memory for ASCII art string
    char* asciiArt = (char*)malloc(sizeof(char) * (WIDTH * HEIGHT + HEIGHT));

    // Convert each pixel to an ASCII character and add it to the ASCII art string
    int asciiIndex = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixelIndex = (y * width + x) * 3;

            // Calculate the average value of the RGB channels for the current pixel
            int pixelValue = (int)(
                (pixelData[pixelIndex] + pixelData[pixelIndex + 1] + pixelData[pixelIndex + 2]) / 3);

            // Convert the pixel to an ASCII character and add it to the ASCII art string
            asciiArt[asciiIndex] = pixelToChar(pixelValue);

            asciiIndex++;
        }

        asciiArt[asciiIndex] = '\n';
        asciiIndex++;
    }

    // Add null terminator to ASCII art string
    asciiArt[asciiIndex] = '\0';

    // Free memory
    free(pixelData);
    fclose(imageFile);

    return asciiArt;
}

int main() {
    // Example usage of imageToAscii function
    char* asciiArt = imageToAscii("example.bmp");

    if (asciiArt) {
        printf("%s\n", asciiArt);

        // Free memory
        free(asciiArt);
    }

    return 0;
}