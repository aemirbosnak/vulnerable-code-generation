//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define ROWS 40
#define COLUMNS 100
#define SCALE_FACTOR 3
#define MAX_PIXEL 255 // Maximum pixel value in grayscale image

// ASCII character set
char ascii[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int main(void) {
    // Open the input grayscale image file
    FILE *fPtrIn = fopen("input_image.pgm", "rb");

    if (fPtrIn == NULL) {
        printf("Unable to open input image file!\n");
        return EXIT_FAILURE;
    }

    // Open the output ASCII art file
    FILE *fPtrOut = fopen("ascii_art.txt", "w");

    if (fPtrOut == NULL) {
        printf("Unable to create ASCII art file!\n");
        fclose(fPtrIn);
        return EXIT_FAILURE;
    }

    // Read the image header
    char header[100];

    if (fgets(header, 100, fPtrIn) == NULL) {
        printf("Invalid input image file format!\n");
        fclose(fPtrIn);
        fclose(fPtrOut);
        return EXIT_FAILURE;
    }

    // Skip comments
    char c = getc(fPtrIn);

    while (c == '#') {
        while (getc(fPtrIn) != '\n');
        c = getc(fPtrIn);
    }

    // Get image dimensions
    int columns, rows;

    if (ungetc(c, fPtrIn) == EOF || fscanf(fPtrIn, "%d %d", &columns, &rows) != 2) {
        printf("Invalid input image file format!\n");
        fclose(fPtrIn);
        fclose(fPtrOut);
        return EXIT_FAILURE;
    }

    // Get maximum pixel value
    int maxPixel;

    if (fscanf(fPtrIn, "%d", &maxPixel) != 1) {
        printf("Invalid input image file format!\n");
        fclose(fPtrIn);
        fclose(fPtrOut);
        return EXIT_FAILURE;
    }

    // Allocate memory for the image
    int *image = malloc(rows * columns * sizeof(int));

    if (image == NULL) {
        // Unable to allocate memory for the image
        printf("Unable to allocate memory for the image!\n");
        fclose(fPtrIn);
        fclose(fPtrOut);
        return EXIT_FAILURE;
    }

    // Read the image data
    for (int i = 0; i < rows * columns; i++) {
        if (fscanf(fPtrIn, "%d", &image[i]) != 1) {
            printf("Error reading input image file!\n");
            fclose(fPtrIn);
            fclose(fPtrOut);
            free(image);
            return EXIT_FAILURE;
        }
    }

    // Rescale the image size
    int newColumns = columns / SCALE_FACTOR;
    int newRows = rows / SCALE_FACTOR;
    int *newImage = malloc(newRows * newColumns * sizeof(int));

    if (newImage == NULL) {
        // Unable to allocate memory for the rescaled image
        printf("Unable to allocate memory for the rescaled image!\n");
        fclose(fPtrIn);
        fclose(fPtrOut);
        free(image);
        return EXIT_FAILURE;
    }

    // Rescale the image by averaging the pixel values of SCALE_FACTOR x SCALE_FACTOR blocks of pixels
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newColumns; j++) {
            int sum = 0;

            for (int k = 0; k < SCALE_FACTOR; k++) {
                for (int l = 0; l < SCALE_FACTOR; l++) {
                    sum += image[(i * SCALE_FACTOR + k) * columns + j * SCALE_FACTOR + l];
                }
            }

            newImage[i * newColumns + j] = sum / (SCALE_FACTOR * SCALE_FACTOR);
        }
    }

    // Convert the grayscale image to ASCII art
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newColumns; j++) {
            // Determine the ASCII character
            int value = newImage[i * newColumns + j];
            int index = (int)(((float)value / MAX_PIXEL) * (sizeof(ascii) / sizeof(char)));
            fputc(ascii[index], fPtrOut);
        }

        fputc('\n', fPtrOut);
    }

    // Free memory
    free(image);
    free(newImage);

    // Close files
    fclose(fPtrIn);
    fclose(fPtrOut);

    return EXIT_SUCCESS;
}