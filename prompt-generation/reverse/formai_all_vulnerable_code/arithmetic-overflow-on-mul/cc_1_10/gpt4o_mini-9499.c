//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    unsigned char  bfType[2];
    unsigned long  bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned long  bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned long  biSize;
    long           biWidth;
    long           biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long  biCompression;
    unsigned long  biSizeImage;
    long           biXPelsPerMeter;
    long           biYPelsPerMeter;
    unsigned long  biClrUsed;
    unsigned long  biClrImportant;
} BITMAPINFOHEADER;

void encodeMessage(unsigned char *image, const char *message, int imgSize) {
    for (int i = 0; message[i] != '\0' && i < imgSize; i++) {
        image[i] = (image[i] & 0xFE) | (message[i] & 0x01);
    }
}

void decodeMessage(unsigned char *image, char *message, int maxLength) {
    for (int i = 0; i < maxLength; i++) {
        message[i] = 0;
        for (int bit = 0; bit < 8; bit++) {
            message[i] |= ((image[i * 8 + bit] & 0x01) << bit);
        }
        if (message[i] == '\0') break;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    unsigned char *imageData;
    char message[256];

    // Step 1: Open the BMP file
    inputFile = fopen("input.bmp", "rb");
    if (!inputFile) {
        fprintf(stderr, "Error opening input BMP file.\n");
        return 1;
    }
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    // Step 2: Allocate memory for image data
    int imgSize = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight;
    imageData = (unsigned char*)malloc(imgSize);
    if (!imageData) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(inputFile);
        return 1;
    }

    // Step 3: Read the pixel data
    fseek(inputFile, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(imageData, sizeof(unsigned char), imgSize, inputFile);
    fclose(inputFile);

    // Step 4: Get the message from the user
    printf("Enter a message to hide in the image: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline

    // Step 5: Encode the message into the image
    encodeMessage(imageData, message, imgSize);

    // Step 6: Write the new image to file
    outputFile = fopen("output.bmp", "wb");
    if (!outputFile) {
        fprintf(stderr, "Error creating output BMP file.\n");
        free(imageData);
        return 1;
    }

    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fwrite(imageData, sizeof(unsigned char), imgSize, outputFile);
    fclose(outputFile);
    free(imageData);

    // Step 7: Decode the message from the image
    inputFile = fopen("output.bmp", "rb");
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);
    imgSize = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight;
    imageData = (unsigned char*)malloc(imgSize);
    fseek(inputFile, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(imageData, sizeof(unsigned char), imgSize, inputFile);
    fclose(inputFile);

    char revealedMessage[256] = {0};
    decodeMessage(imageData, revealedMessage, 32);
    free(imageData);

    // Step 8: Output the hidden message
    printf("The hidden message is: %s\n", revealedMessage);

    return 0;
}