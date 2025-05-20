//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 150 // maximum width of image
#define MAX_HEIGHT 150 // maximum heigth of image

/**
 * This function reads an image from a file and stores 
 * its Pixels into a 2D array.
 */
void readImage(char* filename, int image[][MAX_WIDTH], int* imgWidthPtr, int* imgHeightPtr) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        printf("Unable to open file %s\n", filename);
        exit(1);
    }

    // read image dimensions
    fscanf(in, "%d %d", imgHeightPtr, imgWidthPtr);

    // read image data
    for (int i = 0; i < *imgHeightPtr; i++) {
        for (int j = 0; j < *imgWidthPtr; j++) {
            fscanf(in, "%d", &image[i][j]);
        }
    }
    fclose(in);
}

/**
 * This function prints the 2D array of pixels as ASCII art.
 */
void printAsciiArt(int image[][MAX_WIDTH], int imgWidth, int imgHeight) {
    for (int i = 0; i < imgHeight; i++) {
        for (int j = 0; j < imgWidth; j++) {
            char ascii;
            // map pixel values to ASCII characters
            if (image[i][j] < 50) {
                ascii = '#';
            } else if (image[i][j] < 100) {
                ascii = '$';
            } else if (image[i][j] < 150) {
                ascii = '*';
            } else if (image[i][j] < 200) {
                ascii = '-';
            } else {
                ascii = ' ';
            }
            printf("%c", ascii);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s imageFile\n", argv[0]);
        exit(1);
    }

    int imgWidth, imgHeight;
    int image[MAX_HEIGHT][MAX_WIDTH];
    readImage(argv[1], image, &imgWidth, &imgHeight);

    // print the image as ASCII art
    printAsciiArt(image, imgWidth, imgHeight);

    return 0;
}