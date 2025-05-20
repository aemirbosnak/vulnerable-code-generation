//FormAI DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

// Function to store secret message in the image
void hideMessageInImage(FILE* fptr, char* message) {
    int c, messageIndex = 0;
    int pixelCount = 0;
    char bit;

    // Read the image pixel by pixel
    while (pixelCount < MAX_FILE_SIZE) {
        c = getc(fptr);

        // Check if the pixel is valid
        if (pixelCount < 54) {
            // Do nothing
        }
        else {
            // Get the least significant bit of each pixel color channel
            bit = message[messageIndex] & 1;

            if (bit) {
                c |= 1;
            }
            else {
                c &= ~1;
            }

            messageIndex++;

            // Check if the message has been completely hidden
            if (strlen(message) <= messageIndex) {
                printf("\nMessage hidden in image successfully!\n\n");
                break;
            }
        }

        pixelCount++;
        putc(c, fptr);
    }
}

// Function to extract the secret message from the image
void extractMessageFromImage(FILE* fptr) {
    int c, pixelCount = 0;
    char bit, message[MAX_FILE_SIZE] = "";
    int messageIndex = 0;

    // Read the image pixel by pixel
    while (pixelCount < MAX_FILE_SIZE) {
        c = getc(fptr);

        // Check if the pixel is valid
        if (pixelCount < 54) {
            // Do nothing
        }
        else {
            // Get the least significant bit of each pixel color channel
            bit = c & 1;

            message[messageIndex] <<= 1;
            message[messageIndex] |= bit;

            // Check if the message has been completely extracted
            if ((messageIndex > 0) && (message[messageIndex] == '\0')) {
                printf("\nMessage extracted from image successfully: %s\n\n", message);
                break;
            }

            messageIndex++;
        }

        pixelCount++;
    }
}

int main() {
    FILE* imgFile;
    char message[MAX_FILE_SIZE], fileName[100];

    printf("--- Welcome to the Image Steganography program ---\n\n");

    printf("Enter the name of the image file to hide the message in: ");
    scanf("%s", fileName);

    // Open the image file
    imgFile = fopen(fileName, "rb+");

    if (imgFile == NULL) {
        printf("Unable to open file!");
        return 1;
    }

    printf("\nEnter the secret message to hide in the image: ");
    scanf(" %[^\n]", message);

    hideMessageInImage(imgFile, message);

    // Close and reopen the file for extracting the message
    fclose(imgFile);
    imgFile = fopen(fileName, "rb");

    extractMessageFromImage(imgFile);

    // Close the image file
    fclose(imgFile);

    return 0;
}