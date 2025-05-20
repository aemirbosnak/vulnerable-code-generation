//FormAI DATASET v1.0 Category: Image Steganography ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 100000

typedef unsigned char byte;

void hideMessage(byte* image, int messageSize, byte* message) {
    int index = 54;   // Start of image data section
    int bitIndex = 0; // Used to track the current bit of the message being hidden

    // Loop through each byte of the message
    for (int i = 0; i < messageSize; i++) {
        byte currentByte = message[i];

        // Loop through each bit in the current byte
        for (int j = 0; j < 8; j++) {
            // Get the current bit of the message and image byte
            int messageBit = (currentByte >> j) & 1;
            int imageBit = (image[index] >> bitIndex) & 1;

            // If the current bit of the message is different than the current bit of the image byte
            // change the current bit of the image byte to match
            if (messageBit != imageBit) {
                // Change the current bit of the image byte
                image[index] ^= 1 << bitIndex;
            }

            // Increment the bitIndex
            bitIndex++;

            // If we've finished hiding the message, return
            if (bitIndex == 8) {
                bitIndex = 0;
                index++;
            }
        }
    }
}

byte* extractMessage(byte* image, int imageSize, int messageSize) {
    byte* message = (byte*)malloc(sizeof(byte) * messageSize);

    int index = 54;   // Start of image data section
    int bitIndex = 0; // Used to track the current bit of the message being extracted

    // Loop through each byte of the message
    for (int i = 0; i < messageSize; i++) {
        byte currentByte = 0;

        // Loop through each bit in the current byte
        for (int j = 0; j < 8; j++) {
            // Get the current bit of the message byte
            int messageBit = (image[index] >> bitIndex) & 1;

            // Set the current bit of the current byte of the message to the message bit
            currentByte |= messageBit << j;

            // Increment the bitIndex
            bitIndex++;

            // If we've finished extracting the message, return
            if (bitIndex == 8) {
                bitIndex = 0;
                index++;
            }
        }

        // Store the current byte of the message
        message[i] = currentByte;
    }

    return message;
}

int main(int argc, char** argv) {
    // Verify the correct number of command line arguments
    if (argc != 4) {
        printf("Usage: stegano.exe [input file] [output file] [message file]\n");
        return -1;
    }

    // Open the input file
    FILE* inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        printf("Unable to open input file: %s\n", argv[1]);
        return -1;
    }

    // Open the output file
    FILE* outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        fclose(inputFile);
        printf("Unable to open output file: %s\n", argv[2]);
        return -1;
    }

    // Open the message file
    FILE* messageFile = fopen(argv[3], "rb");
    if (!messageFile) {
        fclose(inputFile);
        fclose(outputFile);
        printf("Unable to open message file: %s\n", argv[3]);
        return -1;
    }

    // Get the size of the input file
    fseek(inputFile, 0, SEEK_END);
    int fileSize = ftell(inputFile);
    rewind(inputFile);

    // Read the image data from the input file
    byte* imageData = (byte*)malloc(sizeof(byte) * fileSize);
    fread(imageData, sizeof(byte), fileSize, inputFile);

    // Get the size of the message file
    fseek(messageFile, 0, SEEK_END);
    int messageSize = ftell(messageFile);
    rewind(messageFile);

    // Verify that the message can fit in the image
    if (messageSize * 8 > fileSize - 54) {
        fclose(inputFile);
        fclose(outputFile);
        fclose(messageFile);
        free(imageData);
        printf("Message file is too large to fit in the image\n");
        return -1;
    }

    // Read the message data from the message file
    byte* messageData = (byte*)malloc(sizeof(byte) * messageSize);
    fread(messageData, sizeof(byte), messageSize, messageFile);

    // Hide the message in the image
    hideMessage(imageData, messageSize, messageData);

    // Write the modified image data to the output file
    fwrite(imageData, sizeof(byte), fileSize, outputFile);

    // Extract the message from the modified image data
    byte* extractedMessage = extractMessage(imageData, fileSize, messageSize);

    // Verify that the extracted message matches the original message
    if (memcmp(messageData, extractedMessage, messageSize)) {
        printf("Error: extracted message does not match the original message\n");
    } else {
        printf("Steganography was successful!\n");
    }

    // Free memory and close files
    free(imageData);
    free(messageData);
    free(extractedMessage);
    fclose(inputFile);
    fclose(outputFile);
    fclose(messageFile);

    return 0;
}