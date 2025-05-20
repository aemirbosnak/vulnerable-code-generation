//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 100
#define COLS 100

// Define ASCII characters for different shading levels
char asciiChars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// Convert an image pixel to an ASCII character
char pixelToAscii(int pixelVal) {
    // Scale the pixel value to the range of 0-9
    int scaledVal = pixelVal / 25;

    // If the scaled value is out of bounds, return the last ASCII character
    if (scaledVal < 0 || scaledVal > 9) {
        return asciiChars[9];
    }

    // Otherwise, return the corresponding ASCII character
    return asciiChars[scaledVal];
}

int main() {
    FILE *imageFile = fopen("input.pgm", "r");

    if (imageFile == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    char buffer[100];
    int numRows = 0;
    int numCols = 0;
    int maxPixelVal = 0;
    int pixels[ROWS][COLS];

    // Read the PGM file header
    fgets(buffer, sizeof(buffer), imageFile);
    fgets(buffer, sizeof(buffer), imageFile);
    sscanf(buffer, "%d %d", &numCols, &numRows);
    fgets(buffer, sizeof(buffer), imageFile);
    sscanf(buffer, "%d", &maxPixelVal);

    // Read the pixel values from the PGM file
    int row = 0;
    int col = 0;
    while (!feof(imageFile) && row < numRows) {
        int pixelVal = fgetc(imageFile);

        if (pixelVal == '\n' || pixelVal == '\r') {
            continue;
        }

        pixels[row][col] = pixelVal;
        col++;

        if (col == numCols) {
            col = 0;
            row++;
        }
    }

    fclose(imageFile);

    // Write the ASCII art representation of the image to a file
    FILE *asciiFile = fopen("output.txt", "w");

    if (asciiFile == NULL) {
        printf("Error: Could not open output file\n");
        return 1;
    }

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            char asciiChar = pixelToAscii(pixels[row][col]);
            fprintf(asciiFile, "%c", asciiChar);
        }

        fprintf(asciiFile, "\n");
    }

    fclose(asciiFile);

    return 0;
}