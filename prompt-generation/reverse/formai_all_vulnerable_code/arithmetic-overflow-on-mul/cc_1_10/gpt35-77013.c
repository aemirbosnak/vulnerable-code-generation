//FormAI DATASET v1.0 Category: Image Editor ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//An image editor program that converts an image to grayscale using the formula: grayscale = 0.2989 * R + 0.5870 * G + 0.1140 * B

int main() {
    char inputFileName[100], outputFileName[100];
    char extension[] = ".bmp";
    FILE *inputFile, *outputFile;
    int rowSize, imageWidth, imageHeight;
    unsigned char *imageData, *outputData;

    printf("Welcome to the Image Editor!\n\n");

    //Prompt user to input filename
    printf("Please enter the filename of the image you want to edit: ");
    scanf("%s", inputFileName);

    //Open input file
    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    //Read BMP header to get image dimensions
    fseek(inputFile, 18, SEEK_SET);
    fread(&imageWidth, sizeof(int), 1, inputFile);
    fread(&imageHeight, sizeof(int), 1, inputFile);

    //Calculate row size (4-byte aligned)
    rowSize = ((imageWidth * 3) + 3) & (~3);

    //Allocate memory for image data and output data
    imageData = (unsigned char*) malloc(rowSize * imageHeight);
    outputData = (unsigned char*) malloc(rowSize * imageHeight);

    //Read image data into memory
    fseek(inputFile, 54, SEEK_SET);
    fread(imageData, sizeof(unsigned char), rowSize * imageHeight, inputFile);

    //Close input file
    fclose(inputFile);

    //Convert image to grayscale
    int i, j, k;
    for (i = 0; i < imageHeight; i++) {
        for (j = 0; j < imageWidth; j++) {
            unsigned char *pixel = imageData + (i * rowSize) + (j * 3);
            unsigned char grayscale = (unsigned char)(0.2989 * pixel[2] + 0.5870 * pixel[1] + 0.1140 * pixel[0]);
            outputData[(i * rowSize) + (j * 3)] = grayscale;
            outputData[(i * rowSize) + (j * 3) + 1] = grayscale;
            outputData[(i * rowSize) + (j * 3) + 2] = grayscale;
        }
    }

    //Prompt user to input output filename
    printf("\nImage converted to grayscale. Please enter a filename to save the edited image: ");
    scanf("%s", outputFileName);

    //Add extension if necessary
    if (strstr(outputFileName, extension) == NULL) {
        strcat(outputFileName, extension);
    }

    //Open output file
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error: Unable to create file.\n");
        return 1;
    }

    //Write BMP header
    unsigned char header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0,
        40, 0, 0, 0,
        0, 0, 0, 0,
        1, 0, 24, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    };
    int fileSize = sizeof(header) + rowSize * imageHeight;
    memcpy(&header[2], &fileSize, sizeof(int));
    memcpy(&header[18], &imageWidth, sizeof(int));
    memcpy(&header[22], &imageHeight, sizeof(int));
    fwrite(header, sizeof(unsigned char), 54, outputFile);

    //Write output data to file
    fwrite(outputData, sizeof(unsigned char), rowSize * imageHeight, outputFile);

    //Close output file
    fclose(outputFile);

    printf("\nImage saved as %s.\n", outputFileName);

    //Free memory
    free(imageData);
    free(outputData);

    printf("\nThank you for using the Image Editor!\n");

    return 0;
}