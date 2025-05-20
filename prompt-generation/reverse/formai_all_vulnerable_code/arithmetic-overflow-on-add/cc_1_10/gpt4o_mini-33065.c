//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>

#pragma pack(1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMPInfoHeader;

void* embedMessage(void* args) {
    uint8_t* pixelData = (uint8_t*)args;
    const char* secret = "Hidden Message!";
    
    // Embed the message length
    int messageLength = strlen(secret);
    for (int i = 0; i < 8; i++) {
        pixelData[i] = (pixelData[i] & 0xFE) | ((messageLength >> i) & 0x01);
    }
    
    // Embed the message itself
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            pixelData[8 + (i * 8) + j] = (pixelData[8 + (i * 8) + j] & 0xFE) | ((secret[i] >> j) & 0x01);
        }
    }

    return NULL;
}

void* extractMessage(void* args) {
    uint8_t* pixelData = (uint8_t*)args;
    int messageLength = 0;

    // Extract the message length
    for (int i = 0; i < 8; i++) {
        messageLength |= ((pixelData[i] & 0x01) << i);
    }
    
    char* secret = malloc(messageLength + 1);
    
    // Extract the message itself
    for (int i = 0; i < messageLength; i++) {
        secret[i] = 0;
        for (int j = 0; j < 8; j++) {
            secret[i] |= ((pixelData[8 + (i * 8) + j] & 0x01) << j);
        }
    }
    
    secret[messageLength] = '\0';
    printf("Extracted Message: %s\n", secret);
    free(secret);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input BMP file> <output BMP file>\n", argv[0]);
        return 1;
    }

    FILE* bmpFile = fopen(argv[1], "rb");
    if (!bmpFile) {
        perror("Error opening input BMP file");
        return 1;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmpFile);

    // Only support 24 bits per pixel BMP files
    if (bmpInfoHeader.bitsPerPixel != 24) {
        printf("Only 24-bit BMP files are supported.\n");
        fclose(bmpFile);
        return 1;
    }

    int rowSize = ((bmpInfoHeader.bitsPerPixel * bmpInfoHeader.width + 31) / 32) * 4;
    int pixelDataSize = rowSize * bmpInfoHeader.height;
    uint8_t* pixelData = malloc(pixelDataSize);

    fseek(bmpFile, bmpHeader.offset, SEEK_SET);
    fread(pixelData, pixelDataSize, 1, bmpFile);
    fclose(bmpFile);

    pthread_t embedThread;
    pthread_create(&embedThread, NULL, embedMessage, pixelData);
    
    pthread_join(embedThread, NULL);

    FILE* outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        perror("Error opening output BMP file");
        free(pixelData);
        return 1;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    fwrite(pixelData, pixelDataSize, 1, outputFile);
    fclose(outputFile);
    
    // Extracting message for demonstration
    pthread_t extractThread;
    pthread_create(&extractThread, NULL, extractMessage, pixelData);
    pthread_join(extractThread, NULL);

    free(pixelData);
    printf("Steganography completed!\n");

    return 0;
}