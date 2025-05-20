//FormAI DATASET v1.0 Category: Image Steganography ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int num, int *binary, int len)
{
    for (int i = len - 1; i >= 0; i--) {
        binary[i] = num % 2;
        num /= 2;
    }
}

// Function to convert binary to decimal
int binaryToDecimal(int *binary, int len)
{
    int num = 0, base = 1;
    for (int i = len - 1; i >= 0; i--) {
        num += binary[i] * base;
        base *= 2;
    }
    return num;
}

// Function to perform image steganography
void imageSteganography(char *inputImage, char *outputImage, char *message)
{
    FILE *fp1, *fp2;
    int c, len, width, height;
    int *binary;
    int index = 0;

    // Open input image in read mode
    fp1 = fopen(inputImage, "rb");
    if (fp1 == NULL) {
        printf("Error: Unable to open input image!");
        exit(1);
    }

    // Open output image in write mode
    fp2 = fopen(outputImage, "wb");
    if (fp2 == NULL) {
        printf("Error: Unable to open output image!");
        exit(1);
    }

    // Read PGM file header
    fscanf(fp1, "P5 %d %d 255 ", &width, &height);

    // Calculate max message length
    len = width * height / 8;

    // Allocate memory for binary array
    binary = (int*)malloc(sizeof(int) * 8);

    // Convert message to binary and write it to output image
    for (int i = 0; message[i] != '\0' && index < len; i++) {
        // Convert character to binary
        decimalToBinary(message[i], binary, 8);

        // Write binary to output image
        for (int j = 0; j < 8; j++) {
            c = fgetc(fp1);
            c = (c & 0xFE) | binary[j];
            fputc(c, fp2);
            index++;
        }
    }

    // Copy remaining pixels from input image to output image
    while ((c = fgetc(fp1)) != EOF && index < len * 8) {
        fputc(c, fp2);
        index++;
    }

    // Print success message
    printf("Message embedded successfully!");

    // Close files
    fclose(fp1);
    fclose(fp2);

    // Free memory
    free(binary);
}

// Function to retrieve message from image
char *retrieveMessage(char *image)
{
    FILE *fp;
    int c, width, height;
    int *binary;
    int index = 0;
    char *message;
    int len;

    // Open image in read mode
    fp = fopen(image, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open input image!");
        exit(1);
    }

    // Read PGM file header
    fscanf(fp, "P5 %d %d 255 ", &width, &height);

    // Calculate max message length
    len = width * height / 8;

    // Allocate memory for binary and message arrays
    binary = (int*)malloc(sizeof(int) * 8);
    message = (char*)malloc(sizeof(char) * len);

    // Read binary from image and convert it to message
    while ((c = fgetc(fp)) != EOF && index < len) {
        // Get last bit from character and store it in binary
        binary[index % 8] = c & 1;

        // Convert binary to decimal and add it to message
        if ((index + 1) % 8 == 0) {
            message[index / 8] = binaryToDecimal(binary, 8);
        }

        index++;
    }

    // Add null terminator to message
    message[len] = '\0';

    // Print retrieved message
    printf("Retrieved message: %s", message);

    // Close file
    fclose(fp);

    // Free memory
    free(binary);

    // Return message
    return message;
}

int main()
{
    char *inputImage = "input.pgm";
    char *outputImage = "output.pgm";
    char *message = "This is a secret message!";

    // Embed message in image
    imageSteganography(inputImage, outputImage, message);

    // Retrieve message from image
    char *retrievedMessage = retrieveMessage(outputImage);

    // Free memory
    free(retrievedMessage);

    return 0;
}