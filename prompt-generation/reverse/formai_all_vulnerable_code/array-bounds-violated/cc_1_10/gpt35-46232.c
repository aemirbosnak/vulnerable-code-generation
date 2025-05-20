//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

// Function to convert an image to ASCII art
void convertToASCII(char* filename) {
    FILE* fptr;
    char output[MAX_WIDTH][MAX_HEIGHT];
    char *ASCII = "@#S%?*+-;. ";

    // Open the image file
    fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Get the dimensions of the image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fptr);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Skip the header
    fseek(fptr, 54, SEEK_SET);

    // Read the pixel data
    unsigned char pixelData[3 * width];
    for (int i =0; i < height; i++) {
        fread(pixelData, sizeof(unsigned char), 3 * width, fptr);
        int index = 0;
        for (int j = 0; j < 3 * width; j += 3) {
            int greyScale = (pixelData[j] + pixelData[j+1] + pixelData[j+2]) / 3;
            output[i][index] = ASCII[(int)(greyScale / 25.5)];
            index++;
        }
    }

    // Close the file
    fclose(fptr);

    // Output the ASCII art to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", output[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Convert the image to ASCII art
    convertToASCII("example.bmp");

    return 0;
}