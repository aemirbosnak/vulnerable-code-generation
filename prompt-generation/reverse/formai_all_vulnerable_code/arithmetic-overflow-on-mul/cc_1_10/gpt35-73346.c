//FormAI DATASET v1.0 Category: Image Steganography ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to hide a message in an image
void hideMessageInImage(const char *imageFilename, const char *message, const char *outputImageFilename) {
    FILE *imageFile = fopen(imageFilename, "rb");
    if (!imageFile) {
        printf("Could not open image file '%s'\n", imageFilename);
        exit(1);
    }

    // Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);

    // Get image width and height from header
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Check if message will fit inside image
    int imageSize = width * height * 3; // 3 bytes per pixel
    int len = strlen(message) + 1; // Add 1 for null terminator
    if (len > (imageSize / 8)) {
        printf("Message is too large for image\n");
        fclose(imageFile);
        exit(1);
    }

    // Read image data
    unsigned char *imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, imageFile);
    fclose(imageFile);

    // Convert message to binary
    unsigned char *binaryMessage = (unsigned char*)malloc(len*8);
    int i, j, k;
    for (i = 0; i < len; i++) {
        for (j = 0; j < 8; j++) {
            binaryMessage[i*8 + j] = (message[i] >> (7-j)) & 1;
        }
    }

    // Hide binary message in image data
    for (i = 0, k = 0; i < imageSize && k < len*8; i += 3, k++) {
        imageData[i] = (imageData[i] & ~1) | binaryMessage[k];
        imageData[i+1] = (imageData[i+1] & ~1) | binaryMessage[k];
        imageData[i+2] = (imageData[i+2] & ~1) | binaryMessage[k];
    }

    // Write output image file
    FILE *outputImageFile = fopen(outputImageFilename, "wb");
    fwrite(header, sizeof(unsigned char), 54, outputImageFile);
    fwrite(imageData, sizeof(unsigned char), imageSize, outputImageFile);
    fclose(outputImageFile);

    // Free memory
    free(imageData);
    free(binaryMessage);

    printf("Message hidden in image '%s' and saved to '%s'\n", imageFilename, outputImageFilename);
}

// Function to extract a message from an image
void extractMessageFromImage(const char *imageFilename) {
    FILE *imageFile = fopen(imageFilename, "rb");
    if (!imageFile) {
        printf("Could not open image file '%s'\n", imageFilename);
        exit(1);
    }

    // Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);

    // Get image width and height from header
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read image data
    unsigned char *imageData = (unsigned char*)malloc(width*height*3);
    fread(imageData, sizeof(unsigned char), width*height*3, imageFile);
    fclose(imageFile);

    // Extract binary message from image data
    int len = 0;
    unsigned char *binaryMessage = (unsigned char*)malloc(width*height*3);
    int i;
    for (i = 0; i < width*height*3; i += 3) {
        binaryMessage[len++] = (imageData[i] & 1);
        binaryMessage[len++] = (imageData[i+1] & 1);
        binaryMessage[len++] = (imageData[i+2] & 1);
    }

    // Convert binary message to string
    char *message = (char*)malloc(len/8 + 1); // Add 1 for null terminator
    for (i = 0; i < len; i += 8) {
        char c = 0;
        int j;
        for (j = 0; j < 8; j++) {
            c |= binaryMessage[i+j] << (7-j);
        }
        message[i/8] = c;
    }
    message[len/8] = '\0';

    // Print message to console
    printf("Message extracted from image '%s':\n%s\n", imageFilename, message);

    // Free memory
    free(imageData);
    free(binaryMessage);
    free(message);
}

int main() {
    char *message = "This is a secret message";

    // Hide message in image
    hideMessageInImage("input.bmp", message, "output.bmp");

    // Extract message from image
    extractMessageFromImage("output.bmp");

    return 0;
}