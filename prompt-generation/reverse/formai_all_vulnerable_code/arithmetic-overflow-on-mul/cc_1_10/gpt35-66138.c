//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB to grayscale
int getGrayscaleValue(int r, int g, int b) {
    return (int)(0.3*r + 0.59*g + 0.11*b);
}

// Function to get ASCII character based on grayscale value
char getAsciiChar(int grayscaleValue) {
    char asciiChar;
    if(grayscaleValue >= 230) {
        asciiChar = ' ';
    } else if(grayscaleValue >= 200) {
        asciiChar = '.';
    } else if(grayscaleValue >= 180) {
        asciiChar = '-';
    } else if(grayscaleValue >= 160) {
        asciiChar = '+';
    } else if(grayscaleValue >= 130) {
        asciiChar = '*';
    } else if(grayscaleValue >= 100) {
        asciiChar = '#';
    } else if(grayscaleValue >= 70) {
        asciiChar = '&';
    } else if(grayscaleValue >= 50) {
        asciiChar = '$';
    } else if(grayscaleValue >= 30) {
        asciiChar = '%';
    } else {
        asciiChar = '@';
    } 
    return asciiChar;
}

int main() {
    char filename[50];
    printf("Enter the filename (including extension): ");
    scanf("%s", filename);

    FILE* imageFile;
    imageFile = fopen(filename, "rb");

    if(imageFile == NULL) {
        printf("File not found.\n");
        return 0;
    }

    // Read the header of the image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);

    // Get the width and height of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the size of the image
    int imageSize = 3 * width * height;
    unsigned char* imageData = (unsigned char*)malloc(sizeof(unsigned char) * imageSize);

    // Read the image data
    fread(imageData, sizeof(unsigned char), imageSize, imageFile);
    fclose(imageFile);

    // Convert the image to ASCII art
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int index = (i * width + j) * 3;
            int r = imageData[index];
            int g = imageData[index + 1];
            int b = imageData[index + 2];
            int grayscaleValue = getGrayscaleValue(r, g, b);
            char asciiChar = getAsciiChar(grayscaleValue);
            printf("%c", asciiChar);
        }
        printf("\n");
    }

    free(imageData);

    return 0;
}