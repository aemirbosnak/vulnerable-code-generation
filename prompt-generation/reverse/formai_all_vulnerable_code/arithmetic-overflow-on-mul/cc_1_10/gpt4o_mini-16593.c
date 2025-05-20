//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define BMP file header and information header structures
#pragma pack(push, 1) // Ensure no padding
typedef struct {
    unsigned short bfType; // BMP file type
    unsigned int bfSize;   // Size of the BMP file
    unsigned short bfReserved1; // Reserved; must be 0
    unsigned short bfReserved2; // Reserved; must be 0
    unsigned int bfOffBits; // Offset to start of pixel data
} BMPHeader;

typedef struct {
    unsigned int biSize;         // Size of this header
    int biWidth;                 // Width of the image
    int biHeight;                // Height of the image
    unsigned short biPlanes;     // Number of color planes
    unsigned short biBitCount;   // Number of bits per pixel
    unsigned int biCompression;   // Compression type
    unsigned int biSizeImage;    // Size of the pixel data
    int biXPelsPerMeter;          // Horizontal resolution
    int biYPelsPerMeter;          // Vertical resolution
    unsigned int biClrUsed;       // Number of colors in the color palette
    unsigned int biClrImportant;   // Number of important colors
} BMPInfoHeader;
#pragma pack(pop)

void embedMessage(const char *inputFile, const char *outputFile, const char *message) {
    FILE *bmpFile = fopen(inputFile, "rb");
    if (!bmpFile) {
        fprintf(stderr, "Error: Could not open file %s\n", inputFile);
        exit(EXIT_FAILURE);
    }

    // Read BMP Header and Info Header
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmpFile);

    // Check if the image is a BMP file with 24 bits per pixel
    if (bmpHeader.bfType != 0x4D42 || bmpInfoHeader.biBitCount != 24) {
        fprintf(stderr, "Error: Image must be a 24-bit BMP file\n");
        fclose(bmpFile);
        exit(EXIT_FAILURE);
    }

    // Prepare to embed the message into the image
    int messageLength = strlen(message);
    if (messageLength > (bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * 3) / 8) {
        fprintf(stderr, "Error: Message is too long to embed in the image\n");
        fclose(bmpFile);
        exit(EXIT_FAILURE);
    }
    
    // Allocate space for pixel data
    unsigned char *pixelData = malloc(bmpInfoHeader.biSizeImage);
    fseek(bmpFile, bmpHeader.bfOffBits, SEEK_SET);
    fread(pixelData, 1, bmpInfoHeader.biSizeImage, bmpFile);
    fclose(bmpFile);

    // Embed message in the pixel data
    for (int i = 0; i < messageLength; i++) {
        int byte = message[i];
        for (int bit = 0; bit < 8; bit++) {
            int pixelIndex = (i * 8 + bit) * 3; // 3 bytes per pixel (BGR)
            pixelData[pixelIndex] = (pixelData[pixelIndex] & 0xFE) | ((byte >> (7 - bit)) & 0x01);
        }
    }

    // Save the modified image
    FILE *outputBmpFile = fopen(outputFile, "wb");
    if (!outputBmpFile) {
        fprintf(stderr, "Error: Could not save file %s\n", outputFile);
        free(pixelData);
        exit(EXIT_FAILURE);
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputBmpFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputBmpFile);
    fwrite(pixelData, 1, bmpInfoHeader.biSizeImage, outputBmpFile);

    fclose(outputBmpFile);
    free(pixelData);
    printf("Message embedded successfully in %s\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input.bmp output.bmp \"message\"\n", argv[0]);
        return EXIT_FAILURE;
    }

    embedMessage(argv[1], argv[2], argv[3]);
    return EXIT_SUCCESS;
}