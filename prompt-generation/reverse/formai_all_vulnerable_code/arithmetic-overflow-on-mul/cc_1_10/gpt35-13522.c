//FormAI DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54
#define BYTE_SIZE 8

// Function to convert decimal to binary
int *decimalToBinary(int decimalNum, int *binaryNum, int numBits)
{
    for (int i = numBits - 1; i >= 0; i--) {
        binaryNum[i] = decimalNum % 2;
        decimalNum /= 2;
    }
    return binaryNum;
}

// Function to convert binary to decimal
int binaryToDecimal(int *binaryNum, int numBits)
{
    int decimalNum = 0;
    for (int i = 0; i < numBits; i++) {
        decimalNum += binaryNum[i] * (1 << (numBits - i - 1));
    }
    return decimalNum;
}

// Function to hide text in LSB of image
void hideTextInImage(char *inputFileName, char *outputFileName, char *message)
{
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        printf("Error opening input file\n");
        exit(1);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Read BMP header
    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, inputFile);
    fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, outputFile);

    // Get image size
    int imgWidth = *(int *)(&header[18]);
    int imgHeight = abs(*(int *)(&header[22]));
    int imageSize = imgWidth * imgHeight * 3;

    // Read image data
    unsigned char *imageData = (unsigned char *)malloc(sizeof(unsigned char) * imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, inputFile);

    // Hide message in LSB of image data
    int messageLength = strlen(message);
    int messageLengthBinary[BYTE_SIZE] = {0};
    decimalToBinary(messageLength, messageLengthBinary, BYTE_SIZE);
    for (int i = 0; i < BYTE_SIZE; i++) {
        imageData[i] = (imageData[i] & 0xFE) | messageLengthBinary[i];
    }

    int messageIndex = 0;
    for (int i = BYTE_SIZE; i < imageSize && messageIndex < messageLength; i += 3) {
        int pixel[3] = {imageData[i], imageData[i + 1], imageData[i + 2]};
        for (int j = 0; j < 3 && messageIndex < messageLength; j++) {
            int pixelBinary[BYTE_SIZE] = {0};
            decimalToBinary(pixel[j], pixelBinary, BYTE_SIZE);
            pixelBinary[BYTE_SIZE - 1] = message[messageIndex];
            pixel[j] = binaryToDecimal(pixelBinary, BYTE_SIZE);
            imageData[i + j] = pixel[j];
            messageIndex++;
        }
    }

    // Write image data to output file
    fwrite(imageData, sizeof(unsigned char), imageSize, outputFile);

    // Close files and free memory
    fclose(inputFile);
    fclose(outputFile);
    free(imageData);
}

// Function to retrieve hidden text from LSB of image
char *retrieveTextFromImage(char *inputFileName)
{
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Read BMP header
    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, inputFile);

    // Get message length from LSB of first few pixels
    int messageLengthBinary[BYTE_SIZE] = {0};
    for (int i = 0; i < BYTE_SIZE; i++) {
        messageLengthBinary[i] = *(header + i) & 1;
    }
    int messageLength = binaryToDecimal(messageLengthBinary, BYTE_SIZE);

    // Read image data
    int imgWidth = *(int *)(&header[18]);
    int imgHeight = abs(*(int *)(&header[22]));
    int imageSize = imgWidth * imgHeight * 3;

    unsigned char *imageData = (unsigned char *)malloc(sizeof(unsigned char) * imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, inputFile);

    // Extract message from LSB of image data
    char *message = (char *)malloc(sizeof(char) * (messageLength + 1));
    int messageIndex = 0;
    for (int i = BYTE_SIZE; i < imageSize && messageIndex < messageLength; i += 3) {
        int pixel[3] = {imageData[i], imageData[i + 1], imageData[i + 2]};
        for (int j = 0; j < 3 && messageIndex < messageLength; j++) {
            int pixelBinary[BYTE_SIZE] = {0};
            decimalToBinary(pixel[j], pixelBinary, BYTE_SIZE);
            message[messageIndex] = pixelBinary[BYTE_SIZE - 1];
            messageIndex++;
        }
    }
    message[messageLength] = '\0';

    // Close file and free memory
    fclose(inputFile);
    free(imageData);

    return message;
}

int main()
{
    char *inputFileName = "image.bmp";
    char *outputFileName = "image_with_message.bmp";
    char *message = "Hello, world! This is a hidden message in an image.";

    printf("Hiding message in image...\n");
    hideTextInImage(inputFileName, outputFileName, message);
    printf("Message hidden successfully\n");

    printf("Retrieving message from image...\n");
    char *retrievedMessage = retrieveTextFromImage(outputFileName);
    printf("Retrieved message: %s\n", retrievedMessage);

    free(retrievedMessage);
    
    return 0;
}