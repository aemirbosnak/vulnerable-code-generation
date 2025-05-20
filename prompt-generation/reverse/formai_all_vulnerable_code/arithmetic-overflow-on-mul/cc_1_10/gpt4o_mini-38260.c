//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent the BMP file header
#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;        // Magic number for BMP files
    unsigned int bfSize;         // Size of the BMP file
    unsigned short bfReserved1;   // Reserved; must be 0
    unsigned short bfReserved2;   // Reserved; must be 0
    unsigned int bfOffBits;       // Offset to start of pixel data
} BITMAPFILEHEADER;

// Structure to represent the BMP info header
typedef struct {
    unsigned int biSize;         // Size of this header
    int biWidth;                 // Width of the bitmap
    int biHeight;                // Height of the bitmap
    unsigned short biPlanes;      // Number of color planes
    unsigned short biBitCount;    // Number of bits per pixel
    unsigned int biCompression;   // Type of compression
    unsigned int biSizeImage;     // Size of the raw bitmap data
    int biXPelsPerMeter;          // Horizontal resolution
    int biYPelsPerMeter;          // Vertical resolution
    unsigned int biClrUsed;       // Number of colors in the color palette
    unsigned int biClrImportant;   // Number of important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

// Function to read a BMP file and return handle and pixel data
unsigned char* readBMP(const char* filename, BITMAPFILEHEADER* fileHeader, BITMAPINFOHEADER* infoHeader) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open BMP file");
        return NULL;
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    unsigned char* pixelData = (unsigned char*)malloc(infoHeader->biSizeImage);
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(pixelData, 1, infoHeader->biSizeImage, file);

    fclose(file);
    return pixelData;
}

// Function to write a BMP file
void writeBMP(const char* filename, BITMAPFILEHEADER* fileHeader, BITMAPINFOHEADER* infoHeader, unsigned char* pixelData) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to create BMP file");
        return;
    }

    fwrite(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixelData, 1, infoHeader->biSizeImage, file);

    fclose(file);
}

// Function to embed watermark in pixel data
void embedWatermark(unsigned char* pixelData, int width, int height, const char* watermark) {
    int watermarkLength = strlen(watermark);
    for (int i = 0; i < watermarkLength; i++) {
        int pixelIndex = (height - 1) * width * 3 + (i * 3);
        pixelData[pixelIndex] = (pixelData[pixelIndex] & 0xFE) | (watermark[i] & 0x01);  // LSB
    }
}

// Function to demonstrate digital watermark extraction
void extractWatermark(unsigned char* pixelData, int width, int height, char* watermark, int maxLength) {
    for (int i = 0; i < maxLength; i++) {
        int pixelIndex = (height - 1) * width * 3 + (i * 3);
        watermark[i] = (pixelData[pixelIndex] & 0x01) + '0'; // Retrieve LSB
    }
    watermark[maxLength] = '\0'; // Null terminate
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_bmp> <output_bmp> <watermark>\n", argv[0]);
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    unsigned char* pixelData = readBMP(argv[1], &fileHeader, &infoHeader);
    if (!pixelData) return 1;

    embedWatermark(pixelData, infoHeader.biWidth, infoHeader.biHeight, argv[3]);
    writeBMP(argv[2], &fileHeader, &infoHeader, pixelData);
    printf("Watermark embedded successfully!\n");

    // Extract watermark for verification
    char extractedWatermark[100];
    extractWatermark(pixelData, infoHeader.biWidth, infoHeader.biHeight, extractedWatermark, sizeof(extractedWatermark) - 1);
    printf("Extracted watermark: %s\n", extractedWatermark);

    free(pixelData);
    return 0;
}