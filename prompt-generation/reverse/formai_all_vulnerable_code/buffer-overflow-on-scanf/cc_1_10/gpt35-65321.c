//FormAI DATASET v1.0 Category: Image Steganography ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_IMAGE_SIZE 512

// Function prototypes
bool readImage(char *filename, uint8_t image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int *width, int *height);
bool writeImage(char *filename, uint8_t image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height);
void hideMessage(char *message, uint8_t image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height);
void extractMessage(uint8_t image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], char *message, int width, int height);

int main()
{
    uint8_t image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int width, height;
    char message[MAX_IMAGE_SIZE];

    // Read the image
    if (!readImage("image.bmp", image, &width, &height)) {
        printf("Failed to read image file!\n");
        return -1;
    }

    // Hide message in the image
    printf("Enter the message to hide: ");
    scanf("%s", message);
    hideMessage(message, image, width, height);

    // Write the modified image with the hidden message
    if (!writeImage("hidden.bmp", image, width, height)) {
        printf("Failed to write image file!\n");
        return -1;
    }

    // Read the modified image with the hidden message
    if (!readImage("hidden.bmp", image, &width, &height)) {
        printf("Failed to read hidden image file!\n");
        return -1;
    }

    // Extract the hidden message from the image
    extractMessage(image, message, width, height);
    printf("The hidden message is: %s\n", message);

    return 0;
}

bool readImage(char *filename, uint8_t image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int *width, int *height)
{
    FILE *fp;
    unsigned char header[54];
    uint32_t fileSize, dataOffset, widthTemp, heightTemp;
    int bpp;

    // Open the file for reading
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return false;
    }

    // Read the BITMAP header
    fread(header, sizeof(unsigned char), 54, fp);

    // Get the file size and data offset
    fileSize = *(uint32_t *)&header[2];
    dataOffset = *(uint32_t *)&header[10];

    // Get the image dimensions
    widthTemp = *(uint32_t *)&header[18];
    heightTemp = *(uint32_t *)&header[22];
    *width = (int)widthTemp;
    *height = (int)heightTemp;

    // Get the number of bits per pixel
    bpp = *(uint16_t *)&header[28] / 8;

    // Check if the image is supported
    if (header[0] != 'B' || header[1] != 'M' || bpp != 1) {
        fclose(fp);
        return false;
    }

    // Read the image data
    fseek(fp, dataOffset, SEEK_SET);
    for (int row = 0; row < *height; row++) {
        for (int col = 0; col < *width; col++) {
            fread(&image[row][col], sizeof(uint8_t), 1, fp);
        }
    }

    // Close the file
    fclose(fp);

    return true;
}

bool writeImage(char *filename, uint8_t image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height)
{
    FILE *fp;
    unsigned char header[54] = {
        0x42, 0x4D, 0x36, 0x24, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02, 0x00,
        0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x36, 0x24, 0x09, 0x00, 0x13, 0x0B,
        0x00, 0x00, 0x13, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    // Open the file for writing
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        return false;
    }

    // Write the BITMAP header
    fwrite(header, sizeof(unsigned char), 54, fp);

    // Write the image data
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            fwrite(&image[row][col], sizeof(uint8_t), 1, fp);
        }
    }

    // Close the file
    fclose(fp);

    return true;
}

void hideMessage(char *message, uint8_t image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height)
{
    int messageLength = strlen(message);
    int messageIndex = 0;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (messageIndex >= messageLength) {
                return;
            }

            // Get the binary representation of the current pixel value
            uint8_t pixelBinary[8];
            uint8_t pixelValue = image[row][col];
            for (int i = 0; i < 8; i++) {
                pixelBinary[i] = (pixelValue >> i) & 1;
            }

            // Replace the least significant bit of each color channel with the message bit
            for (int i = 0; i < 8; i++) {
                if (messageIndex >= messageLength) {
                    return;
                }
                pixelBinary[i] = (pixelBinary[i] & 0xfe) | ((message[messageIndex] >> i) & 1);
                messageIndex++;
            }

            // Convert the binary representation back to a pixel value
            uint8_t newPixelValue = 0;
            for (int i = 0; i < 8; i++) {
                newPixelValue |= (pixelBinary[i] << i);
            }
            image[row][col] = newPixelValue;
        }
    }
}

void extractMessage(uint8_t image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], char *message, int width, int height)
{
    int messageIndex = 0;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (messageIndex >= MAX_IMAGE_SIZE) {
                return;
            }

            // Get the binary representation of the current pixel value
            uint8_t pixelBinary[8];
            uint8_t pixelValue = image[row][col];
            for (int i = 0; i < 8; i++) {
                pixelBinary[i] = (pixelValue >> i) & 1;
            }

            // Extract the least significant bit of each color channel and combine them into a message character
            char messageChar = 0;
            for (int i = 0; i < 8; i++) {
                messageChar |= (pixelBinary[i] & 1) << i;
            }
            message[messageIndex] = messageChar;
            messageIndex++;

            // If the message ends with a null character, terminate extraction
            if (messageChar == '\0') {
                return;
            }
        }
    }
}