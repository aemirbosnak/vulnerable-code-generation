//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // Disable padding for BMP structures

typedef struct {
    unsigned short bfType;
    unsigned long bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned long bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
} BITMAPINFOHEADER;

void hideMessageInImage(const char *imagePath, const char *message) {
    FILE *image = fopen(imagePath, "rb+");
    if (!image) {
        printf("Error: Unable to open the image file.\n");
        return;
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, image);
    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, image);
    
    if (bfh.bfType != 0x4D42) { // Check BMP identifier
        printf("Error: Not a BMP file.\n");
        fclose(image);
        return;
    }

    // Move to the pixel data
    fseek(image, bfh.bfOffBits, SEEK_SET);
    
    // Determine available space for the message
    long imgSize = bih.biWidth * bih.biHeight * (bih.biBitCount / 8);
    int messageLength = strlen(message);
    
    if ((messageLength * 8) > imgSize) {
        printf("Error: Message is too long to hide in this image.\n");
        fclose(image);
        return;
    }

    // Hide the message
    for (int i = 0; i < messageLength; i++) {
        char currentChar = message[i];
        for (int j = 0; j < 8; j++) {
            int bit = (currentChar >> (7 - j)) & 1; // Extract bits from current character
            unsigned char pixel;
            fread(&pixel, sizeof(unsigned char), 1, image);
            // Modify the least significant bit
            pixel = (pixel & ~1) | bit;
            fseek(image, -1, SEEK_CUR);
            fwrite(&pixel, sizeof(unsigned char), 1, image);
        }
    }

    fclose(image);
    printf("Message hidden in the image successfully.\n");
}

void extractMessageFromImage(const char *imagePath, int messageLength) {
    FILE *image = fopen(imagePath, "rb");
    if (!image) {
        printf("Error: Unable to open the image file.\n");
        return;
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, image);
    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, image);
    
    if (bfh.bfType != 0x4D42) { // Check BMP identifier
        printf("Error: Not a BMP file.\n");
        fclose(image);
        return;
    }

    // Move to the pixel data
    fseek(image, bfh.bfOffBits, SEEK_SET);
    
    char *extractedMessage = (char *)malloc(messageLength + 1);
    memset(extractedMessage, 0, messageLength + 1);

    // Extract the message
    for (int i = 0; i < messageLength; i++) {
        char currentChar = 0;
        for (int j = 0; j < 8; j++) {
            unsigned char pixel;
            fread(&pixel, sizeof(unsigned char), 1, image);
            // Get the least significant bit
            int bit = pixel & 1;
            currentChar = (currentChar << 1) | bit;
        }
        extractedMessage[i] = currentChar;
    }

    fclose(image);
    printf("Extracted Message: %s\n", extractedMessage);
    free(extractedMessage);
}

int main() {
    int choice;
    char imagePath[256];
    char message[256];

    printf("Image Steganography Tool\n");
    printf("=========================\n");
    printf("1. Hide Message\n");
    printf("2. Extract Message\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter the BMP image path: ");
    scanf("%s", imagePath);

    if (choice == 1) {
        printf("Enter the message to hide: ");
        scanf(" %[^\n]", message);
        hideMessageInImage(imagePath, message);
    } else if (choice == 2) {
        printf("Enter the length of the hidden message: ");
        int msgLength;
        scanf("%d", &msgLength);
        extractMessageFromImage(imagePath, msgLength);
    } else {
        printf("Invalid option chosen.\n");
    }

    return 0;
}