//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: sophisticated
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
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void encodeMessage(uint8_t *pixelData, const char *message, int messageLength) {
    int i;
    for (i = 0; i < messageLength; i++) {
        // Embed message character into the least significant bits of RGB channels
        pixelData[i * 3] &= 0xFE;       // Clear the LSB
        pixelData[i * 3] |= (message[i] & 0x01); // Embed bit
        pixelData[i * 3 + 1] &= 0xFE;   // Clear the LSB
        pixelData[i * 3 + 1] |= (message[i] >> 1 & 0x01); // Embed next bit
        pixelData[i * 3 + 2] &= 0xFE;   // Clear the LSB
        pixelData[i * 3 + 2] |= (message[i] >> 2 & 0x01); // Embed another bit
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_bmp_file> <output_bmp_file> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    const char *message = argv[3];
    int messageLength = strlen(message);
    
    // Open BMP file
    FILE *bmpFile = fopen(inputFileName, "rb");
    if (!bmpFile) {
        perror("Error opening input BMP file");
        return EXIT_FAILURE;
    }

    // Read BMP headers
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    // Check BMP format
    if (fileHeader.bfType != 0x4D42) {
        fprintf(stderr, "This is not a BMP file.\n");
        fclose(bmpFile);
        return EXIT_FAILURE;
    }

    // Validate message size against the number of pixels
    int pixelCount = (infoHeader.biWidth * infoHeader.biHeight);
    if (messageLength * 3 > pixelCount) {
        fprintf(stderr, "Message is too long to fit in this image.\n");
        fclose(bmpFile);
        return EXIT_FAILURE;
    }

    // Allocate memory for pixel data
    uint8_t *pixelData = (uint8_t *)malloc(pixelCount * 3);
    if (!pixelData) {
        perror("Memory allocation failed");
        fclose(bmpFile);
        return EXIT_FAILURE;
    }

    fseek(bmpFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, 3, pixelCount, bmpFile);
    fclose(bmpFile);
    
    // Encode the message
    encodeMessage(pixelData, message, messageLength);
    
    // Save the modified BMP
    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output BMP file");
        free(pixelData);
        return EXIT_FAILURE;
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fseek(outputFile, fileHeader.bfOffBits, SEEK_SET);
    fwrite(pixelData, 3, pixelCount, outputFile);
    
    // Clean up
    free(pixelData);
    fclose(outputFile);

    printf("Message encoded successfully into %s!\n", outputFileName);
    return EXIT_SUCCESS;
}