//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>

#define CHAR_WIDTH 6
#define CHAR_HEIGHT 9

// ASCII character set ordered by brightness from darker to lighter
char asciiSet[] = {'#', 'M', 'X', 'H', 'W', 'N', '$', 'O', 'C', '?', '>', '!', ';', ':', ',', '.'};

// Convert RGB values to grayscale value
int toGrayscale(int r, int g, int b) {
    return 0.2989 * r + 0.5870 * g + 0.1140 * b;
}

// Map grayscale value to ASCII character
char toAscii(int gray) {
    int asciiIndex = (int)((double)gray / 255 * (sizeof(asciiSet) / sizeof(char) - 1));
    return asciiSet[asciiIndex];
}

int main() {
    // Open image file
    FILE *imageFile = fopen("example.jpg", "rb");
    if (!imageFile) {
        printf("Failed to open image file\n");
        return 1;
    }

    // Read header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);

    // Get image size
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate padding
    int padding = 0;
    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }

    // Allocate memory for image data
    unsigned char *imageData = (unsigned char*)malloc(width * height * 3 * sizeof(unsigned char));
    if (!imageData) {
        printf("Failed to allocate memory for image data\n");
        return 1;
    }

    // Read image data
    fread(imageData, sizeof(unsigned char), width * height * 3, imageFile);
    fclose(imageFile);

    // Convert image to ASCII art
    for (int i = 0; i < height; i += CHAR_HEIGHT) {
        for (int j = 0; j < width; j += CHAR_WIDTH) {
            // Calculate average grayscale value for character area
            int graySum = 0;
            for (int k = 0; k < CHAR_HEIGHT; k++) {
                for (int l = 0; l < CHAR_WIDTH; l++) {
                    int pixelIndex = ((i + k) * width + (j + l)) * 3;
                    if (pixelIndex >= width * height * 3) {
                        continue;
                    }
                    int r = (int)imageData[pixelIndex + 2];
                    int g = (int)imageData[pixelIndex + 1];
                    int b = (int)imageData[pixelIndex];
                    graySum += toGrayscale(r, g, b);
                }
            }
            int grayAvg = graySum / (CHAR_WIDTH * CHAR_HEIGHT);

            // Map grayscale value to ASCII character
            printf("%c", toAscii(grayAvg));
        }
        printf("\n");
    }

    // Free memory
    free(imageData);

    return 0;
}