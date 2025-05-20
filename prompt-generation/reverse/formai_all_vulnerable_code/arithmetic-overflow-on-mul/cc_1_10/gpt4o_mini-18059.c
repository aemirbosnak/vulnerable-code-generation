//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void encodeMessage(const char *inputText, unsigned char *pixelData, int imageSize) {
    int textLength = strlen(inputText);
    int bitPos = 0;

    // Encode the length of the text
    for (int i = 0; i < 8; i++) {
        pixelData[0] = (pixelData[0] & 0xFE) | ((textLength >> (7 - i)) & 0x01);
        pixelData++;
    }

    // Encode text
    for (int i = 0; i < textLength; i++) {
        for (int j = 0; j < 8; j++) {
            pixelData[0] = (pixelData[0] & 0xFE) | ((inputText[i] >> (7 - j)) & 0x01);
            pixelData++;
            if (pixelData >= pixelData + imageSize)
                return;
        }
    }
}

void decodeMessage(unsigned char *pixelData, char *outputText) {
    int bitCount = 0;

    // Decode the length of the text
    int textLength = 0;
    for (int i = 0; i < 8; i++) {
        textLength = (textLength << 1) | (pixelData[i] & 0x01);
    }

    // Decode text
    for (int i = 0; i < textLength; i++) {
        char tempChar = 0;
        for (int j = 0; j < 8; j++) {
            tempChar = (tempChar << 1) | (pixelData[8 + (i * 8) + j] & 0x01);
        }
        outputText[i] = tempChar;
    }
    outputText[textLength] = '\0';
}

int main() {
    FILE *file;
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    file = fopen("input.bmp", "rb");
    if (!file) {
        printf("Error opening the BMP file.\n");
        return 1;
    }

    fread(&fileHeader, sizeof(fileHeader), 1, file);
    fread(&infoHeader, sizeof(infoHeader), 1, file);

    if (fileHeader.bfType != 0x4D42) {
        printf("Not a valid BMP file.\n");
        fclose(file);
        return 1;
    }

    int imageSize = infoHeader.biWidth * infoHeader.biHeight * (infoHeader.biBitCount / 8);
    unsigned char *pixelData = (unsigned char *)malloc(imageSize);
    fread(pixelData, sizeof(unsigned char), imageSize, file);
    fclose(file);

    char inputText[256];
    printf("Enter a message to hide: ");
    fgets(inputText, sizeof(inputText), stdin);
    inputText[strcspn(inputText, "\n")] = '\0'; // Remove newline from input

    encodeMessage(inputText, pixelData, imageSize);
    printf("Message encoded successfully!\n");

    file = fopen("output.bmp", "wb");
    if (!file) {
        printf("Error creating the BMP file.\n");
        free(pixelData);
        return 1;
    }

    fwrite(&fileHeader, sizeof(fileHeader), 1, file);
    fwrite(&infoHeader, sizeof(infoHeader), 1, file);
    fwrite(pixelData, sizeof(unsigned char), imageSize, file);
    fclose(file);
    free(pixelData);

    // Decode the message for verification
    file = fopen("output.bmp", "rb");
    if (!file) {
        printf("Error opening the BMP file for reading.\n");
        return 1;
    }

    fread(&fileHeader, sizeof(fileHeader), 1, file);
    fread(&infoHeader, sizeof(infoHeader), 1, file);
    pixelData = (unsigned char *)malloc(imageSize);
    fread(pixelData, sizeof(unsigned char), imageSize, file);
    fclose(file);

    char outputText[256];
    decodeMessage(pixelData, outputText);
    printf("Decoded message: %s\n", outputText);
    
    free(pixelData);
    return 0;
}