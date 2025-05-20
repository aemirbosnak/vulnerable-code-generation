//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Change this constant to adjust the width of the ASCII art image
#define ASCII_WIDTH 80

// Define a struct to hold image data
typedef struct {
    int width;
    int height;
    int* pixels;
} Image;

// Load image from file
Image* loadImage(char* fileName) {
    FILE* file = fopen(fileName, "rb");

    // Check if the file was opened successfully
    if (!file) {
        printf("Error: Failed to open file %s\n", fileName);
        return NULL;
    }

    // Read header information
    char header[54];
    fread(header, sizeof(char), 54, file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for pixel data
    int* pixels = malloc(width * height * sizeof(int));

    // Read pixel data
    for (int i = 0; i < width * height; i++) {
        unsigned char rgb[3];
        fread(rgb, sizeof(char), 3, file);
        pixels[i] = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
    }

    // Create an Image struct and populate it with the loaded data
    Image* image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = pixels;

    fclose(file);
    return image;
}

// Free memory used by an Image struct
void freeImage(Image* image) {
    free(image->pixels);
    free(image);
}

// Convert an image to ASCII art and print it to the console
void imageToAscii(Image* image) {
    // Calculate the aspect ratio of the image
    float aspectRatio = (float)image->width / (float)image->height;

    // Calculate the height of the ASCII art image
    int asciiHeight = floor(ASCII_WIDTH / aspectRatio);

    // Calculate the width of the ASCII art image
    int asciiWidth = ASCII_WIDTH;

    // Calculate the size of each pixel block in the ASCII art image
    int blockWidth = ceil((float)image->width / (float)asciiWidth);
    int blockHeight = ceil((float)image->height / (float)asciiHeight);

    // Loop through each block in the ASCII art image
    for (int y = 0; y < asciiHeight; y++) {
        for (int x = 0; x < asciiWidth; x++) {
            // Calculate the average color of the pixels in the current block
            int redTotal = 0;
            int greenTotal = 0;
            int blueTotal = 0;
            int pixelCount = 0;

            for (int j = 0; j < blockHeight; j++) {
                for (int i = 0; i < blockWidth; i++) {
                    int imageX = x * blockWidth + i;
                    int imageY = y * blockHeight + j;

                    if (imageX < image->width && imageY < image->height) {
                        int pixelIndex = imageX + imageY * image->width;
                        int pixel = image->pixels[pixelIndex];

                        redTotal += (pixel >> 16) & 0xFF;
                        greenTotal += (pixel >> 8) & 0xFF;
                        blueTotal += pixel & 0xFF;
                        pixelCount++;
                    }
                }
            }

            int averageRed = redTotal / pixelCount;
            int averageGreen = greenTotal / pixelCount;
            int averageBlue = blueTotal / pixelCount;

            // Convert the average color to a single grayscale value
            int gray = 0.2126 * averageRed + 0.7152 * averageGreen + 0.0722 * averageBlue;

            // Choose the ASCII character to represent the grayscale value
            char asciiChar;

            if (gray < 30) {
                asciiChar = '@';
            } else if (gray < 60) {
                asciiChar = '#';
            } else if (gray < 90) {
                asciiChar = '&';
            } else if (gray < 120) {
                asciiChar = '$';
            } else if (gray < 150) {
                asciiChar = '%';
            } else if (gray < 180) {
                asciiChar = '*';
            } else if (gray < 210) {
                asciiChar = 'o';
            } else if (gray < 240) {
                asciiChar = ':';
            } else {
                asciiChar = '.';
            }

            // Print the ASCII character
            putchar(asciiChar);
        }

        // Start a new line after each row
        putchar('\n');
    }
}

int main() {
    Image* image = loadImage("image.bmp");

    if (!image) {
        return 1;
    }

    imageToAscii(image);
    freeImage(image);

    return 0;
}