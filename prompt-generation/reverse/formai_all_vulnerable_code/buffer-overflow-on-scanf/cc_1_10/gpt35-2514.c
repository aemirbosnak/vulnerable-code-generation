//FormAI DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_SECRET_MESSAGE_LENGTH 100

typedef unsigned char BYTE;

// Function to get the bit value of a given byte at a given position
BYTE getBit(BYTE byte, int position) {
    return (byte >> position) & 1;
}

// Function to set the bit value of a given byte at a given position
BYTE setBit(BYTE byte, int position, BYTE bit) {
    if (bit) {
        return byte | (1 << position);
    } else {
        return byte & ~(1 << position);
    }
}

// Function to encode a secret message into an image file
bool encodeMessage(char* imageFilename, char* secretMessage) {
    // Open the image file in read/write mode
    FILE* imageFile = fopen(imageFilename, "r+b");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return false;
    }

    // Get the size of the image file
    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    rewind(imageFile);

    // Get the size of the secret message
    int secretMessageLength = strlen(secretMessage);

    // Check if the image file is large enough to hold the secret message
    if (secretMessageLength > imageSize / 8) {
        printf("Error: Secret message is too long for the given image file.\n");
        return false;
    }

    // Encode the secret message into the image file
    BYTE* imageData = malloc(imageSize);
    if (imageData == NULL) {
        printf("Error: Could not allocate memory for image data.\n");
        return false;
    }
    fread(imageData, sizeof(BYTE), imageSize, imageFile);
    rewind(imageFile);

    for (int i = 0; i < secretMessageLength; i++) {
        BYTE secretByte = secretMessage[i];
        for (int j = 0; j < 8; j++) {
            int bitPosition = i * 8 + j;
            BYTE imageByte = imageData[bitPosition];
            BYTE secretBit = getBit(secretByte, j);
            imageData[bitPosition] = setBit(imageByte, 0, secretBit);
        }
    }

    fwrite(imageData, sizeof(BYTE), imageSize, imageFile);

    // Cleanup
    free(imageData);
    fclose(imageFile);

    printf("Successfully encoded secret message into image file.\n");
    return true;
}

// Function to decode a secret message from an image file
bool decodeMessage(char* imageFilename, char* secretMessage) {
    // Open the image file in read mode
    FILE* imageFile = fopen(imageFilename, "rb");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return false;
    }

    // Get the size of the image file
    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    rewind(imageFile);

    // Decode the secret message from the image file
    BYTE* imageData = malloc(imageSize);
    if (imageData == NULL) {
        printf("Error: Could not allocate memory for image data.\n");
        return false;
    }
    fread(imageData, sizeof(BYTE), imageSize, imageFile);

    char decodedMessage[MAX_SECRET_MESSAGE_LENGTH] = "\0";
    int decodedMessageLength = 0;

    for (int i = 0; i < imageSize; i += 8) {
        BYTE secretByte = 0;
        for (int j = 0; j < 8; j++) {
            int bitPosition = i + j;
            BYTE imageByte = imageData[bitPosition];
            BYTE secretBit = getBit(imageByte, 0);
            secretByte = setBit(secretByte, j, secretBit);
        }

        decodedMessage[decodedMessageLength] = secretByte;
        decodedMessageLength++;

        // Check if we've reached the end of the secret message
        if (secretByte == '\0') {
            break;
        }
    }

    // Copy the decoded message to the output variable
    strcpy(secretMessage, decodedMessage);

    // Cleanup
    free(imageData);
    fclose(imageFile);

    printf("Successfully decoded secret message from image file.\n");
    return true;
}

int main() {
    char imageFilename[MAX_FILENAME_LENGTH];
    char secretMessage[MAX_SECRET_MESSAGE_LENGTH];

    // Get the image filename and secret message from the user
    printf("Enter image filename: ");
    scanf("%s", imageFilename);

    printf("Enter secret message: ");
    scanf("%s", secretMessage);

    // Encode the secret message into the image file
    if (!encodeMessage(imageFilename, secretMessage)) {
        return 1;
    }

    // Decode the secret message from the image file
    char decodedMessage[MAX_SECRET_MESSAGE_LENGTH] = "\0";
    if (!decodeMessage(imageFilename, decodedMessage)) {
        return 1;
    }

    // Print the decoded message
    printf("Decoded message: %s\n", decodedMessage);

    return 0;
}