//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BLOCK_SIZE 4
#define MAX_WIDTH 100

const char grayScale[] = "$@B%8&WM#*oahkbdpwmZO0QCJY.>!':~^-^_/|\\<>) ii;,\"^`'. ";

// Method to calculate average grayscale value of pixel block 
int getBlockAvgGrayScaleValue(unsigned char *block, int width){
    long sum = 0;
    for(int i=0;i<BLOCK_SIZE;i++){
        for(int j=0;j<BLOCK_SIZE;j++){
            int index = i * width + j;
            sum += block[index];
        }
    }
    return sum / (BLOCK_SIZE * BLOCK_SIZE);
}

// Method to get ASCII character based on grayscale value
char getAsciiChar(int grayScaleValue){
    int scaleLength = strlen(grayScale);
    int valueInterval = (256 + 1) / scaleLength;
    int index = grayScaleValue / valueInterval;
    if(index > scaleLength - 1) index = scaleLength - 1;
    return grayScale[index];
}

int main(int argc, char **argv){

    if(argc != 2){
        printf("Usage : image2ascii <image_file>");
        return 1;
    }

    char *fileName = argv[1];

    FILE *file = fopen(fileName, "rb");
    if(file == NULL){
        printf("Unable to open file : %s", fileName);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);

    int height, width;
    fseek(file, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    if(width > MAX_WIDTH){
        printf("Image width is too high, max width is : %d", MAX_WIDTH);
        return 1;
    }

    int paddingSize = (4 - (width * 3) % 4) % 4;
    long pixelDataOffset = 18 + 4 + (width * 3) + paddingSize;
    fseek(file, pixelDataOffset, SEEK_SET);

    // Allocate memory for pixel data
    unsigned char *pixels = (unsigned char*) malloc(width * height * 3 * sizeof(unsigned char));
    fread(pixels, sizeof(unsigned char), width * height * 3, file);

    fclose(file);

    int blockCount = (height / BLOCK_SIZE) * (width / BLOCK_SIZE);
    char asciiArt[blockCount];

    int charIndex = 0;
    for(int i=0;i<height;i+=BLOCK_SIZE){
        for(int j=0;j<width;j+=BLOCK_SIZE){
            int index = i * width + j;
            int avgGrayScaleValue = getBlockAvgGrayScaleValue(pixels + index, width);
            char asciiChar = getAsciiChar(avgGrayScaleValue);
            asciiArt[charIndex++] = asciiChar;
        }
    }

    asciiArt[charIndex] = '\0';

    // Output the ASCII art
    printf("%s", asciiArt);

    return 0;
}