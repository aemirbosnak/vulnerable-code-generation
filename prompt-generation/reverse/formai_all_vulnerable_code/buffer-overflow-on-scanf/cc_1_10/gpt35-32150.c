//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Function to get grayscale value of a pixel
int getGrayScale(int r, int g, int b) {
    return (r + g + b) / 3;
}

// Function to convert grayscale value to ASCII character
char getAsciiChar(int grayScale) {
    char asciiChar = ' ';

    if (grayScale >= 0 && grayScale < 25) {
        asciiChar = '@';
    }
    else if (grayScale >= 25 && grayScale < 50) {
        asciiChar = '#';
    }
    else if (grayScale >= 50 && grayScale < 75) {
        asciiChar = '8';
    }
    else if (grayScale >= 75 && grayScale < 100) {
        asciiChar = '&';
    }
    else if (grayScale >= 100 && grayScale < 125) {
        asciiChar = 'o';
    }
    else if (grayScale >= 125 && grayScale < 150) {
        asciiChar = ':';
    }
    else if (grayScale >= 150 && grayScale < 175) {
        asciiChar = '*';
    }
    else if (grayScale >= 175 && grayScale < 200) {
        asciiChar = '.';
    }
    else if (grayScale >= 200 && grayScale < 225) {
        asciiChar = ' ';
    }

    return asciiChar;
}

int main() {
    char imageFileName[100];
    char asciiArt[MAX_HEIGHT][MAX_WIDTH + 1];

    printf("Enter the name of the image file: ");
    scanf("%s", imageFileName);

    FILE *imageFile = fopen(imageFileName, "rb");
    if (imageFile == NULL) {
        printf("File not found!\n");
        return 0;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = 0;
    int rowSize = width * 3;
    while ((rowSize + padding) % 4 != 0) {
        padding++;
    }

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Image is too big!\n");
        return 0;
    }

    for (int i = 0; i < height; i++) {
        unsigned char buffer[MAX_WIDTH * 3 + padding];
        fread(buffer, sizeof(unsigned char), rowSize + padding, imageFile);

        for (int j = 0; j < width * 3; j += 3) {
            int r = buffer[j + 2];
            int g = buffer[j + 1];
            int b = buffer[j];

            int grayScale = getGrayScale(r, g, b);

            asciiArt[i][j / 3] = getAsciiChar(grayScale);
        }
    }

    fclose(imageFile);

    for (int i = 0; i < height; i++) {
        printf("%s\n", asciiArt[i]);
    }

    return 0;
}