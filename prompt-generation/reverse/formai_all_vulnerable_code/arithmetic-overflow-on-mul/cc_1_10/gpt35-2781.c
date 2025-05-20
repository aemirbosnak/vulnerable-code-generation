//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

// Standard 16 color VGA palette
const char *palette = "@#Oo+:,. ";

void imageToAscii(char *filename) {
    // Open the image file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        return;
    }

    // Read the header to get the image dimensions
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Create a buffer to hold the image data
    unsigned char buffer[width * height * 3];
    fread(buffer, sizeof(unsigned char), width * height * 3, fp);

    // Close the image file
    fclose(fp);

    // Create an empty ASCII art image
    char ascii[MAX_WIDTH][MAX_HEIGHT];
    memset(ascii, ' ', sizeof(char) * MAX_WIDTH * MAX_HEIGHT);

    // Convert the image data to ASCII art
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            // Calculate the pixel index in the buffer
            int index = (y * width + x) * 3;

            // Calculate the average color intensity of the pixel
            int intensity = (buffer[index] + buffer[index+1] + buffer[index+2]) / 3;

            // Map the intensity to a character in the palette
            int paletteIndex = intensity * (strlen(palette) - 1) / 255;

            // Set the corresponding ASCII character in the art image
            if (x < MAX_WIDTH && y < MAX_HEIGHT) {
                ascii[x][y] = palette[paletteIndex];
            }
        }
    }

    // Print the ASCII art image
    for (y = 0; y < MAX_HEIGHT; y++) {
        for (x = 0; x < MAX_WIDTH; x++) {
            printf("%c", ascii[x][y]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [image filename]\n", argv[0]);
        return 1;
    }

    imageToAscii(argv[1]);

    return 0;
}