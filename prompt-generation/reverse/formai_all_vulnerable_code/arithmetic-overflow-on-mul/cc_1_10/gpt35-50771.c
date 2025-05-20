//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to convert pixel data to ASCII art
char pixelToChar(int pixelValue) {
    if (pixelValue >= 230) {
        return '@';
    } else if (pixelValue >= 200) {
        return 'M';
    } else if (pixelValue >= 175) {
        return '#';
    } else if (pixelValue >= 150) {
        return 'X';
    } else if (pixelValue >= 125) {
        return 'x';
    } else if (pixelValue >= 100) {
        return '=';
    } else if (pixelValue >= 75) {
        return ':';
    } else if (pixelValue >= 50) {
        return '-';
    } else if (pixelValue >= 25) {
        return '.';
    } else {
        return ' ';
    }
}

//Function to convert RGB values to grayscale
int convertToGrayscale(int red, int green, int blue) {
    return (0.30 * red) + (0.59 * green) + (0.11 * blue);
}

int main() {
    FILE *fp;
    char filename[100];
    char asciiArt[1000][1000]; //Array to hold ASCII art representation
    int width, height, bitDepth;
    int red, green, blue;
    
    //Read image file and open in binary mode
    printf("Enter the filename of the image: ");
    scanf("%s", filename);
    fp = fopen(filename, "rb");

    //Check if file was opened successfully
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    //Read image header
    char header[54];
    fread(header, sizeof(char), 54, fp);

    //Extract image width, height and bit depth information
    width = *(int*)&header[18];
    height = *(int*)&header[22];
    bitDepth = *(int*)&header[28];

    //Check if image is 24 bit depth (RGB)
    if (bitDepth != 24) {
        printf("Error: Invalid bit depth. This program only supports 24-bit depth RGB images.\n");
        return 1;
    }

    //Calculate number of bytes per row of pixels in the image
    int rowSize = width * 3;

    //Adjust row bytes to be a multiple of 4 (required by BMP format)
    while (rowSize % 4 != 0) {
        rowSize++;
    }

    //Allocate memory for pixel data
    unsigned char *pixelData = (unsigned char*)malloc(rowSize * height);

    //Read pixel data into memory
    fread(pixelData, sizeof(unsigned char), rowSize * height, fp);

    //Close file
    fclose(fp);

    //Loop through pixel data to create ASCII art representation
    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //Extract color information from pixel data
            blue = pixelData[index++];
            green = pixelData[index++];
            red = pixelData[index++];

            //Convert RGB to grayscale
            int grayscale = convertToGrayscale(red, green, blue);

            //Convert grayscale value to ASCII character
            char asciiChar = pixelToChar(grayscale);

            //Add ASCII character to output array
            asciiArt[i][j] = asciiChar;
        }
        index += rowSize - (width * 3);
    }

    //Print ASCII art representation of image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c",asciiArt[i][j]);
        }
        printf("\n");
    }

    //Free allocated memory
    free(pixelData);
    
    return 0;
}