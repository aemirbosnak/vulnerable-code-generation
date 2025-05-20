//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WIDTH 1000 // Max width of the input image
#define MAX_HEIGHT 1000 // Max height of the input image

int pixelMap[MAX_WIDTH][MAX_HEIGHT]; //Stores the gray scale pixel values of the image

/* Function to load image pixel values from a file into the pixelMap */
bool loadPixelMap(char* fileName, int* width, int* height) {
    FILE* fp;
    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("ERROR: Unable to open file.\n");
        return false;
    }

    fscanf(fp, "%d %d", width, height); // Read image width and height metadata from file

    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fscanf(fp, "%d", &pixelMap[j][i]); // Read pixel values from file row by row
        }
    }

    fclose(fp);
    return true;
}

/* Function to convert pixel values to ASCII art characters */
char convertPixelToChar(int pixelValue) {
    char asciiChar;

    if (pixelValue <= 25) { // 0 - 25 is the darkest shade, represented by "@" character
        asciiChar = '@';
    } else if (pixelValue > 25 && pixelValue <= 50) { // 26 - 50 is the second darkest shade, represented by "#"
        asciiChar = '#';
    } else if (pixelValue > 50 && pixelValue <= 75) { // 51 - 75 is the third darkest shade, represented by "8"
        asciiChar = '8';
    } else if (pixelValue > 75 && pixelValue <= 100) { // 76 - 100 is the fourth darkest shade, represented by "&"
        asciiChar = '&';
    } else if (pixelValue > 100 && pixelValue <= 125) { // 101 - 125 is the fifth darkest shade, represented by "o"
        asciiChar = 'o';
    } else if (pixelValue > 125 && pixelValue <= 150) { // 126 - 150 is the sixth darkest shade, represented by ":"
        asciiChar = ':';
    } else if (pixelValue > 150 && pixelValue <= 175) { // 151 - 175 is the second lightest shade, represented by "*"
        asciiChar = '*';
    } else if (pixelValue > 175 && pixelValue <= 200) { // 176 - 200 is the third lightest shade, represented by "."
        asciiChar = '.';
    } else if (pixelValue > 200 && pixelValue <= 225) { // 201 - 225 is the fourth lightest shade, represented by " "
        asciiChar = ' ';
    } else { // Anything higher than 225 is the lightest shade, represented by "."
        asciiChar = '.';
    }

    return asciiChar;
}

int main() {
    int width, height;

    if (loadPixelMap("input.txt", &width, &height)) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("%c", convertPixelToChar(pixelMap[j][i])); // Print out ASCII art character for each pixel
            }
            printf("\n"); // Move to a new line after each row
        }
    }

    return 0;
}