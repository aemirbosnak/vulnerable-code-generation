//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define character set
const char charSet[] = " .,-'`:!1+*abcdefghijklmnopqrstuvwxyz<>()\/{}[]?234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ%&@#$";

// Define character width and height
const int charWidth = 6;
const int charHeight = 8;

// Function to load image file
unsigned char* loadImage(char* fileName, int* width, int* height) {
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error: unable to load image file \"%s\"\n", fileName);
        return NULL;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    int imageWidth = *(int*)&header[18];
    int imageHeight = *(int*)&header[22];
    int bitsPerPixel = *(int*)&header[28];

    if (bitsPerPixel != 24) {
        printf("Error: unsupported image format\n");
        fclose(file);
        return NULL;
    }

    int rowSize = (imageWidth * bitsPerPixel + 31) / 32 * 4;
    unsigned char* image = (unsigned char*)malloc(rowSize * imageHeight);

    for (int y = 0; y < imageHeight; y++) {
        int offset = (imageHeight - 1 - y) * rowSize + 54;
        fread(&image[offset], sizeof(unsigned char), rowSize, file);
    }

    *width = imageWidth;
    *height = imageHeight;

    fclose(file);
    return image;
}

// Function to convert image to ASCII art
void convertToAscii(unsigned char* imageData, int imageWidth, int imageHeight) {
    for (int y = 0; y < imageHeight; y += charHeight) {
        for (int x = 0; x < imageWidth; x += charWidth) {
            int luminance = 0;

            for (int dy = 0; dy < charHeight; dy++) {
                for (int dx = 0; dx < charWidth; dx++) {
                    int pixelOffset = (y + dy) * imageWidth * 3 + (x + dx) * 3;
                    int r = imageData[pixelOffset];
                    int g = imageData[pixelOffset + 1];
                    int b = imageData[pixelOffset + 2];
                    luminance += (int)(0.2126 * r + 0.7152 * g + 0.0722 * b + 0.5);
                }
            }

            luminance /= charWidth * charHeight;
            int index = (int)((sizeof(charSet) - 1) * luminance / 255);
            printf("%c", charSet[index]);
        }

        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 0;
    }

    int imageWidth, imageHeight;
    unsigned char* imageData = loadImage(argv[1], &imageWidth, &imageHeight);
    if (imageData == NULL) {
        return 0;
    }

    // Convert image to ASCII art
    convertToAscii(imageData, imageWidth, imageHeight);

    free(imageData);
    return 0;
}