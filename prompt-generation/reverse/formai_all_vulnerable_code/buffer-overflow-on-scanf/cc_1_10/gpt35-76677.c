//FormAI DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 5000 // Maximum size of the image file

/*
 * This program demonstrates the implementation of Image Steganography using C language.
 * Image Steganography refers to the technique of hiding secret data within the image file
 * without affecting the original image file.
 *
 * This program takes an input image file and a message file as input and hides the message
 * within the image file. The program also provides the utility to extract the hidden message
 * from the image file.
 */

/** 
 * Function to read the pixel data of the image file
 */
void readPixelData(FILE *inFile, unsigned char *pixelData, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(pixelData, 3, 1, inFile);
            pixelData += 3;
        }
    }
}

/** 
 * Function to write the pixel data to the image file
 */
void writePixelData(FILE *outFile, unsigned char *pixelData, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fwrite(pixelData, 3, 1, outFile);
            pixelData += 3;
        }
    }
}

/** 
 * Function to convert the integer to binary form (8-bit)
 */
void intToBinary(int num, char *binary) {
    int i;
    for (i = 7; i >= 0; i--) {
        binary[i] = (num % 2) + '0';
        num /= 2;
    }
    binary[8] = '\0';
}

/**
 * Function to hide the message within the image file
 */
void hideMessage(FILE *inFile, FILE *msgFile, FILE *outFile) {
    int i, j, k, size;
    unsigned char pixelData[MAX_SIZE];
    char message[MAX_SIZE], binary[9];

    // Read the input image file and extract the pixel data
    fseek(inFile, 54, SEEK_SET);
    readPixelData(inFile, pixelData, 256, 256);

    // Read the message file and extract the message
    fread(message, MAX_SIZE, 1, msgFile);
    size = strlen(message);

    // Embed the message within the pixel data
    for (i = 0, j = 0, k = 0; i < size * 8; i += 3, k++) {
        intToBinary(message[k], binary);
        if (j == 8) {
            k++;
            j = 0;
        }
        if (k == size) {
            break;
        }
        pixelData[i] &= 0xFC;
        pixelData[i] |= (binary[j] - '0');
        j++;

        pixelData[i + 1] &= 0xFC;
        pixelData[i + 1] |= (binary[j] - '0');
        j++;

        pixelData[i + 2] &= 0xFC;
        pixelData[i + 2] |= (binary[j] - '0');
        j++;
    }

    // Write the modified pixel data to the output image file
    fseek(outFile, 54, SEEK_SET);
    writePixelData(outFile, pixelData, 256, 256);

    // Close the input and output files
    fclose(inFile);
    fclose(msgFile);
    fclose(outFile);

    printf("Message successfully hidden within the image file\n");
}

/**
 * Function to extract the hidden message from the image file
 */
void extractMessage(FILE *inFile) {
    int i, j, k, size;
    unsigned char pixelData[MAX_SIZE];
    char message[MAX_SIZE], binary[9];
    char last3bits;
    int counter = 0;

    // Read the input image file and extract the pixel data
    fseek(inFile, 54, SEEK_SET);
    readPixelData(inFile, pixelData, 256, 256);

    // Extract the hidden message from the pixel data
    for (i = 0, k = 0; i < MAX_SIZE * 3; i += 3, k++) {
        if (k % 8 == 0) {
            last3bits = pixelData[i] & 0x3;
            counter = 0;
            continue;
        }
        binary[counter] = (pixelData[i] & 0x3) + '0';
        counter++;
        binary[counter] = (pixelData[i + 1] & 0x3) + '0';
        counter++;
        binary[counter] = (pixelData[i + 2] & 0x3) + '0';
        counter++;

        if (counter == 8) {
            binary[8] = '\0';
            message[k / 8] = strtol(binary, NULL, 2);
            counter = 0;
            if (message[k / 8] == '\0') {
                break;
            }
        }
    }
    message[k / 8] = '\0';
    size = strlen(message);

    // Display the extracted message
    printf("The hidden message is: %s\n", message);

    // Close the input file
    fclose(inFile);
}

/**
 * Main function that prompts the user for input and executes the corresponding operation.
 */
int main() {
    FILE *inFile, *msgFile, *outFile;
    char inputFileName[50], msgFileName[50], outputFileName[50];
    int option;

    printf("Welcome to Image Steganography\n\n");
    printf("Choose an option:\n");
    printf("1. Hide a message within the image\n");
    printf("2. Extract a message from the image\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter the name of the input image file: ");
            scanf("%s", inputFileName);
            printf("Enter the name of the message file: ");
            scanf("%s", msgFileName);
            printf("Enter the name of the output image file: ");
            scanf("%s", outputFileName);

            inFile = fopen(inputFileName, "rb");
            msgFile = fopen(msgFileName, "rb");
            outFile = fopen(outputFileName, "wb");
            hideMessage(inFile, msgFile, outFile);
            break;
        case 2:
            printf("Enter the name of the input image file: ");
            scanf("%s", inputFileName);

            inFile = fopen(inputFileName, "rb");
            extractMessage(inFile);
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}