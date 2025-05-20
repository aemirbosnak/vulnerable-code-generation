//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an image to binary format
void imageToBinary(char *image, char *binary) {
    FILE *fp;
    int i, j, k;

    // Open the image file
    fp = fopen(image, "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the image dimensions
    fseek(fp, 18, SEEK_SET);
    fread(&i, 4, 1, fp);
    fread(&j, 4, 1, fp);

    // Allocate memory for the binary data
    binary = malloc(i * j * 3);

    // Read the image data
    fseek(fp, 54, SEEK_SET);
    fread(binary, 1, i * j * 3, fp);

    // Close the image file
    fclose(fp);
}

// Function to convert binary data to an image
void binaryToImage(char *binary, char *image) {
    FILE *fp;
    int i, j, k;

    // Open the image file
    fp = fopen(image, "wb");
    if (fp == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Write the image header
    fwrite("BM", 2, 1, fp);
    fwrite(&i, 4, 1, fp);
    fwrite(&j, 4, 1, fp);
    fwrite("\0\0", 2, 1, fp);
    fwrite("\0\0\0\0", 4, 1, fp);
    fwrite("\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 14, 1, fp);

    // Write the image data
    fwrite(binary, 1, i * j * 3, fp);

    // Close the image file
    fclose(fp);
}

// Function to embed a message in an image
void embedMessage(char *image, char *message) {
    FILE *fp;
    int i, j, k;

    // Open the image file
    fp = fopen(image, "rb+");
    if (fp == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the image dimensions
    fseek(fp, 18, SEEK_SET);
    fread(&i, 4, 1, fp);
    fread(&j, 4, 1, fp);

    // Get the message length
    int messageLength = strlen(message);

    // Embed the message length in the image
    fseek(fp, 54, SEEK_SET);
    fwrite(&messageLength, 4, 1, fp);

    // Embed the message in the image
    for (k = 0; k < messageLength; k++) {
        for (i = 0; i < 8; i++) {
            // Get the bit from the message
            int bit = (message[k] >> i) & 1;

            // Get the corresponding byte from the image
            int byte = fgetc(fp);

            // Set the least significant bit of the byte to the bit from the message
            byte &= ~(1 << i);
            byte |= (bit << i);

            // Write the byte back to the image
            fseek(fp, -1, SEEK_CUR);
            fputc(byte, fp);
        }
    }

    // Close the image file
    fclose(fp);
}

// Function to extract a message from an image
char *extractMessage(char *image) {
    FILE *fp;
    int i, j, k;

    // Open the image file
    fp = fopen(image, "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the image dimensions
    fseek(fp, 18, SEEK_SET);
    fread(&i, 4, 1, fp);
    fread(&j, 4, 1, fp);

    // Get the message length
    fseek(fp, 54, SEEK_SET);
    int messageLength;
    fread(&messageLength, 4, 1, fp);

    // Allocate memory for the message
    char *message = malloc(messageLength + 1);

    // Extract the message from the image
    for (k = 0; k < messageLength; k++) {
        for (i = 0; i < 8; i++) {
            // Get the byte from the image
            int byte = fgetc(fp);

            // Get the least significant bit of the byte
            int bit = byte & 1;

            // Shift the message byte to the left by one bit
            message[k] <<= 1;

            // Set the least significant bit of the message byte to the bit from the image
            message[k] |= bit;
        }
    }

    // Add a null terminator to the message
    message[messageLength] = '\0';

    // Close the image file
    fclose(fp);

    // Return the message
    return message;
}

int main() {
    // Image file name
    char *image = "image.bmp";

    // Message to embed in the image
    char *message = "Hello, world!";

    // Convert the image to binary format
    char *binary;
    imageToBinary(image, binary);

    // Embed the message in the image
    embedMessage(binary, message);

    // Convert the binary data back to an image
    binaryToImage(binary, "output.bmp");

    // Extract the message from the image
    char *extractedMessage = extractMessage("output.bmp");

    // Print the extracted message
    printf("Extracted message: %s\n", extractedMessage);

    // Free the allocated memory
    free(binary);
    free(extractedMessage);

    return 0;
}