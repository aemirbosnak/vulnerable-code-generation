//FormAI DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_PIXEL 3
#define BITS_PER_BYTE 8

void hideMessage(char* imageFileName, char* message) {
    FILE* imageFile = fopen(imageFileName, "rb");
    if (!imageFile) {
        printf("Error opening image file.\n");
        exit(1);
    }

    // Find the size of the image.
    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    rewind(imageFile);

    // Allocate memory to store the image.
    unsigned char* imageData = (unsigned char*) malloc(imageSize);
    if (!imageData) {
        printf("Error allocating memory.\n");
        fclose(imageFile);
        exit(1);
    }

    // Read the image data into memory.
    if (fread(imageData, imageSize, 1, imageFile) != 1) {
        printf("Error reading image data.\n");
        free(imageData);
        fclose(imageFile);
        exit(1);
    }
    fclose(imageFile);

    // Find the starting position to hide the message.
    long messagePos = 54;
    while (messagePos < imageSize && imageData[messagePos] == 0) {
        messagePos += BYTES_PER_PIXEL * BITS_PER_BYTE;
    }
    if (messagePos >= imageSize) {
        printf("Error hiding message. Image too small.\n");
        free(imageData);
        exit(1);
    }

    // Convert message to binary and store it in an array.
    long messageLength = strlen(message);
    unsigned char* messageData = (unsigned char*) calloc(messageLength * BITS_PER_BYTE, sizeof(unsigned char));
    if (!messageData) {
        printf("Error allocating memory.\n");
        free(imageData);
        exit(1);
    }

    int bitPos = 0;
    for (int i = 0; i < messageLength; i++) {
        unsigned char ch = message[i];
        for (int j = BITS_PER_BYTE - 1; j >= 0; j--) {
            messageData[bitPos++] = (ch & (1 << j)) ? 1 : 0;
        }
    }

    // Hide the message in the image.
    int messageIndex = 0;
    while (messageIndex < messageLength * BITS_PER_BYTE) {
        for (int i = 0; i < BYTES_PER_PIXEL; i++) {
            for (int j = BITS_PER_BYTE - 1; j >= 0; j--) {
                if (messageIndex >= messageLength * BITS_PER_BYTE) {
                    break;
                }

                unsigned char pixelBit = (imageData[messagePos + i] & (1 << j)) ? 1 : 0;
                if (pixelBit != messageData[messageIndex]) {
                    if (messageData[messageIndex]) {
                        imageData[messagePos + i] |= (1 << j);
                    } else {
                        imageData[messagePos + i] &= ~(1 << j);
                    }
                }

                messageIndex++;
            }
        }
        messagePos += BYTES_PER_PIXEL * BITS_PER_BYTE;
    }

    // Write the new image data to a file.
    char* extension = strrchr(imageFileName, '.');
    char newImageFileName[256];
    sprintf(newImageFileName, "%s_steg%s", imageFileName, extension);
    FILE* newImageFile = fopen(newImageFileName, "wb");
    if (!newImageFile) {
        printf("Error creating new image file.\n");
        free(imageData);
        free(messageData);
        exit(1);
    }

    if (fwrite(imageData, imageSize, 1, newImageFile) != 1) {
        printf("Error writing new image data.\n");
        fclose(newImageFile);
        free(imageData);
        free(messageData);
        exit(1);
    }

    fclose(newImageFile);
    free(imageData);
    free(messageData);
    printf("Message hidden successfully!\n");
}

void showMessage(char* imageFileName) {
    FILE* imageFile = fopen(imageFileName, "rb");
    if (!imageFile) {
        printf("Error opening image file.\n");
        exit(1);
    }

    // Find the size of the image.
    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    rewind(imageFile);

    // Allocate memory to store the image.
    unsigned char* imageData = (unsigned char*) malloc(imageSize);
    if (!imageData) {
        printf("Error allocating memory.\n");
        fclose(imageFile);
        exit(1);
    }

    // Read the image data into memory.
    if (fread(imageData, imageSize, 1, imageFile) != 1) {
        printf("Error reading image data.\n");
        free(imageData);
        fclose(imageFile);
        exit(1);
    }
    fclose(imageFile);

    // Find the starting position of the message.
    long messagePos = 54;
    unsigned char messageData[BITS_PER_BYTE];
    int bitPos = 0;
    while (messagePos < imageSize && (imageData[messagePos] == 0 || imageData[messagePos] == 255)) {
        messagePos += BYTES_PER_PIXEL * BITS_PER_BYTE;
    }

    // Extract the message from the image.
    int messageIndex = 0;
    while (messageIndex < BITS_PER_BYTE) {
        for (int i = 0; i < BYTES_PER_PIXEL; i++) {
            for (int j = BITS_PER_BYTE - 1; j >= 0; j--) {
                if (messageIndex >= BITS_PER_BYTE) {
                    break;
                }

                messageData[messageIndex] = (imageData[messagePos + i] & (1 << j)) ? 1 : 0;
                messageIndex++;
            }
        }
        messagePos += BYTES_PER_PIXEL * BITS_PER_BYTE;
    }

    // Convert the binary message to ASCII.
    unsigned char messageLength = 0;
    for (int i = 0; i < BITS_PER_BYTE; i++) {
        messageLength |= (messageData[i] << (BITS_PER_BYTE - 1 - i));
    }

    unsigned char message[256];
    messageIndex = 0;
    while (messageIndex < messageLength * BITS_PER_BYTE) {
        unsigned char ch = 0;
        for (int j = 0; j < BITS_PER_BYTE; j++) {
            ch |= (messageData[messageIndex++] << (BITS_PER_BYTE - 1 - j));
        }
        message[messageIndex / BITS_PER_BYTE] = ch;
    }

    printf("Message: %s\n", message);
    free(imageData);
}

int main() {
    char imageFileName[256];
    char message[256];
    int selection;

    printf("Welcome to Steganography Program\n");
    printf("1. Hide Message\n");
    printf("2. Show Message\n");
    printf("Choose an option: ");
    scanf("%d", &selection);

    if (selection == 1) {
        printf("Enter image file name: ");
        scanf("%s", imageFileName);
        printf("Enter message to hide: ");
        scanf(" %[^\n]", message);
        hideMessage(imageFileName, message);
    } else if (selection == 2) {
        printf("Enter image file name: ");
        scanf("%s", imageFileName);
        showMessage(imageFileName);
    } else {
        printf("Invalid selection.\n");
    }

    return 0;
}