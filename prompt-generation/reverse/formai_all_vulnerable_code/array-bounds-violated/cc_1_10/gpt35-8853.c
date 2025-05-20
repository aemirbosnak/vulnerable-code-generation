//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII characters that represent the different levels of intensity
char g_asciiChars[] = {' ', '.', '*', ':', 'o', '&', '8', '#', '@'};

// Get the index of the ASCII character based on the intensity level
int getAsciiIndex(char *pixel) {
    int r = pixel[0];
    int g = pixel[1];
    int b = pixel[2];

    // Convert RGB to grayscale value
    int intensity = (r + g + b) / 3;

    // Distribute the intensity across the ASCII characters
    int asciiIndex = intensity / 25;

    return asciiIndex;
}

int main(int argc, char **argv) {
    // Check that an image file has been provided
    if (argc < 2) {
        printf("Please provide an image file as an argument.\n");
        return 1;
    }

    char *filename = argv[1];

    // Open the file in binary mode
    FILE *file = fopen(filename, "rb");

    // Check that the file was opened successfully
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return 1;
    }

    // Read the file headers to get the image width and height
    int width, height;
    fseek(file, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Create a buffer to hold the pixel data
    int buffSize = 3 * width * height;
    unsigned char *buffer = malloc(buffSize);

    // Read the pixel data into the buffer
    fseek(file, 54, SEEK_SET);
    fread(buffer, sizeof(unsigned char), buffSize, file);

    // Close the file
    fclose(file);

    // Print the ASCII art to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Get the RGB values of the pixel
            int index = (i * width + j) * 3;
            char *pixel = &(buffer[index]);

            // Get the ASCII character to represent the pixel
            int asciiIndex = getAsciiIndex(pixel);
            char asciiChar = g_asciiChars[asciiIndex];

            // Print the character to the console
            printf("%c", asciiChar);
        }
        printf("\n");
    }

    // Free the buffer
    free(buffer);

    return 0;
}