//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>

// Function to convert an RGB pixel to grayscale
int convertPixelToGrayscale(int red, int green, int blue) {
    int grayValue = (red + green + blue) / 3;
    return grayValue;
}

// Function to convert a grayscale value to ASCII character
char convertGrayscaleToAscii(int grayValue) {
    char asciiChar = '.';
    if (grayValue >= 0 && grayValue <= 30) {
        asciiChar = '@';
    } else if (grayValue > 30 && grayValue <= 60) {
        asciiChar = '#';
    } else if (grayValue > 60 && grayValue <= 90) {
        asciiChar = '8';
    } else if (grayValue > 90 && grayValue <= 120) {
        asciiChar = '&';
    } else if (grayValue > 120 && grayValue <= 150) {
        asciiChar = 'o';
    } else if (grayValue > 150 && grayValue <= 180) {
        asciiChar = ':';
    } else if (grayValue > 180 && grayValue <= 210) {
        asciiChar = '*';
    } else if (grayValue > 210 && grayValue <= 240) {
        asciiChar = '.';
    } else if (grayValue > 240 && grayValue <= 255) {
        asciiChar = ' ';
    }
    return asciiChar;
}

int main() {
    FILE *inputFile = fopen("sherlock.bmp", "rb");
    FILE *outputFile = fopen("sherlock.txt", "w");

    // BMP header is 54 bytes long
    unsigned char header[54];
    // Read the header from the input file
    fread(header, sizeof(unsigned char), 54, inputFile);

    // Get image width, height, and bit depth from the header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];

    printf("Image size: %dx%d\n", width, height);
    printf("Bit depth: %d bits\n", bitDepth);

    // Calculate row padding (each row must be a multiple of 4 bytes)
    int rowPadding = (4 - (width * 3) % 4) % 4;

    // Read the image pixel data
    unsigned char pixel[3];
    int grayscaleValue;
    char asciiChar;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Read the pixel bytes (BGR order)
            fread(pixel, sizeof(unsigned char), 3, inputFile);
            // Convert the pixel to grayscale
            grayscaleValue = convertPixelToGrayscale(pixel[2], pixel[1], pixel[0]);
            // Convert the grayscale value to ASCII character
            asciiChar = convertGrayscaleToAscii(grayscaleValue);
            // Print the ASCII character to the output file
            fputc(asciiChar, outputFile);
        }
        // Skip over padding bytes
        fseek(inputFile, rowPadding, SEEK_CUR);
        // Print newline character to the output file
        fputc('\n', outputFile);
    }

    printf("File conversion successful!\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}