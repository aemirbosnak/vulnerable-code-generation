//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These macros represent the ASCII characters that correspond to different shades of gray
#define GRAYSCALE_CHAR_1 ' '
#define GRAYSCALE_CHAR_2 '.'
#define GRAYSCALE_CHAR_3 '-'
#define GRAYSCALE_CHAR_4 '='
#define GRAYSCALE_CHAR_5 '+'
#define GRAYSCALE_CHAR_6 '*'
#define GRAYSCALE_CHAR_7 '#'
#define GRAYSCALE_CHAR_8 '@'

// This function takes in an RGB value and returns a corresponding grayscale value
int convertRGBtoGrayscale(unsigned char r, unsigned char g, unsigned char b) {
    return (0.21*r + 0.72*g + 0.07*b);
}

// This function takes in a row of pixels from an image and returns a corresponding row of grayscale values
int* convertRowToGrayscale(unsigned char* row, int width) {
    int* grayscaleRow = (int*)malloc(sizeof(int)*width);
    for(int i = 0; i < width*3; i += 3) {
        grayscaleRow[i/3] = convertRGBtoGrayscale(row[i], row[i+1], row[i+2]);
    }
    return grayscaleRow;
}

// This function takes in a 2D array of grayscale values and its dimensions and prints the corresponding ASCII art
void printASCIIart(int** grayscaleData, int width, int height) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int grayscaleValue = grayscaleData[i][j];
            if(grayscaleValue < 32) {
                printf("%c", GRAYSCALE_CHAR_1);
            }
            else if(grayscaleValue < 64) {
                printf("%c", GRAYSCALE_CHAR_2);
            }
            else if(grayscaleValue < 96) {
                printf("%c", GRAYSCALE_CHAR_3);
            }
            else if(grayscaleValue < 128) {
                printf("%c", GRAYSCALE_CHAR_4);
            }
            else if(grayscaleValue < 160) {
                printf("%c", GRAYSCALE_CHAR_5);
            }
            else if(grayscaleValue < 192) {
                printf("%c", GRAYSCALE_CHAR_6);
            }
            else if(grayscaleValue < 224) {
                printf("%c", GRAYSCALE_CHAR_7);
            }
            else {
                printf("%c", GRAYSCALE_CHAR_8);
            }
        }
        printf("\n"); // move to next line after every row
    }
}

int main() {
    FILE* imageFile = fopen("example_image.bmp", "rb");
    if(imageFile == NULL) {
        printf("Could not open file!\n");
        return -1;
    }

    // read the header of the image file and extract the width, height and pixel data
    unsigned char header[54];
    unsigned int width, height;
    unsigned char* pixelData;

    fread(header, sizeof(unsigned char), 54, imageFile);
    width = *(unsigned int*)&header[18];
    height = *(unsigned int*)&header[22];
    int rowSize = 3*width;
    int paddingSize = (4 - (rowSize % 4)) % 4; // compute padding size
    int dataSize = (rowSize + paddingSize)*height;
    pixelData = (unsigned char*)malloc(dataSize);
    fread(pixelData, sizeof(unsigned char), dataSize, imageFile);

    // convert the pixel data to grayscale values
    int** grayscaleData = (int**)malloc(sizeof(int*)*height);
    for(int i = 0; i < height; i++) {
        grayscaleData[i] = convertRowToGrayscale(&pixelData[i*(rowSize+paddingSize)], width);
    }

    printASCIIart(grayscaleData, width, height); // print the ASCII art
    fclose(imageFile);
    free(pixelData);
    for(int i = 0; i < height; i++) {
        free(grayscaleData[i]);
    }
    free(grayscaleData);

    return 0;
}