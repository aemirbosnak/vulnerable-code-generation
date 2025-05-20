//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert image to ASCII art
void convertToAscii(char* fileName) {
    FILE* inputFile;
    FILE* outputFile;

    // open input file in binary mode
    inputFile = fopen(fileName, "rb");
    if (!inputFile) {
        printf("Error opening input file.");
        exit(1);
    }

    // create output file in write mode
    outputFile = fopen(strcat(fileName, "_ascii.txt"), "w");
    if (!outputFile) {
        printf("Error creating output file.");
        exit(1);
    }

    // read data from input file
    int width, height;
    unsigned char *imageData;
    fscanf(inputFile, "P5\n%d %d\n255\n", &width, &height);
    imageData = (unsigned char*)malloc(width*height*sizeof(unsigned char));
    fread(imageData, sizeof(unsigned char), width*height, inputFile);
    fclose(inputFile);

    // ASCII conversion logic
    char ascii_chars[11] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int num_chars = 10;

    // calculate brightness of each pixel and convert to ASCII character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = imageData[i*width + j];
            int brightness = pixel / 25;
            char ascii_char = ascii_chars[brightness % num_chars];
            fprintf(outputFile, "%c", ascii_char);
        }
        fprintf(outputFile, "\n");
    }
    fclose(outputFile);
    free(imageData);
}

int main() {
    char fileName[50];

    // get file name from user
    printf("Enter file name: ");
    scanf("%s", fileName);

    // call function to convert image to ASCII art
    convertToAscii(fileName);
    
    printf("ASCII art created successfully.");
    return 0;
}