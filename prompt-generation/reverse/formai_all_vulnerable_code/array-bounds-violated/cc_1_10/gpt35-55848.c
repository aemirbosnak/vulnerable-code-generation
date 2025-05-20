//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert an image to ASCII art */
void imageToAscii(char* imagePath, char* outPath, int width, int height) {
    /* Open the image file */
    FILE* imgFile = fopen(imagePath, "rb");
    if (imgFile == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", imagePath);
        return;
    }

    /* Check file size */
    fseek(imgFile, 0, SEEK_END);
    long imgSize = ftell(imgFile);
    fseek(imgFile, 0, SEEK_SET);

    /* Read image data into memory */
    char* imgData = (char*) malloc(imgSize);
    if (imgData == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        fclose(imgFile);
        return;
    }
    fread(imgData, imgSize, 1, imgFile);
    fclose(imgFile);

    /* Determine ASCII character mapping */
    char asciiChars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int numChars = sizeof(asciiChars) / sizeof(asciiChars[0]);

    /* Open output file */
    FILE* outFile = fopen(outPath, "w");
    if (outFile == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing.\n", outPath);
        free(imgData);
        return;
    }

    /* Convert each pixel to an ASCII character */
    int i, j, k;
    double lum;
    int index;
    char c;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = (i * width + j) * 3;
            lum = (0.2126 * imgData[index] + 0.7152 * imgData[index + 1] + 0.0722 * imgData[index + 2]) / 255.0;
            k = (int) (lum * (numChars - 1));
            c = asciiChars[k];
            fputc(c, outFile);
        }
        fputc('\n', outFile);
    }

    /* Close output file */
    fclose(outFile);

    /* Free image data memory */
    free(imgData);

    printf("Successfully converted %s to ASCII art in %s.\n", imagePath, outPath);
}

/* Example usage */
int main() {
    char* imagePath = "image.png";
    char* outFilepath = "ascii.txt";
    int width = 80;
    int height = 60;
    imageToAscii(imagePath, outFilepath, width, height);
    return 0;
}