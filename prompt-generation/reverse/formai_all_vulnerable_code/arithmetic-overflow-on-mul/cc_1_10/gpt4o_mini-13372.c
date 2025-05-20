//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BMPHeader;

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
} BMPInfoHeader;
#pragma pack(pop)

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        perror("Error opening input file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inFile);

    if(bmpHeader.bfType != 0x4D42) {
        printf("Not a BMP file!\n");
        fclose(inFile);
        return;
    }

    int width = bmpInfoHeader.biWidth;
    int height = bmpInfoHeader.biHeight;
    int pixelArraySize = width * height * (bmpInfoHeader.biBitCount / 8);
    uint8_t *pixelArray = (uint8_t *)malloc(pixelArraySize);
    
    fseek(inFile, bmpHeader.bfOffBits, SEEK_SET);
    fread(pixelArray, sizeof(uint8_t), pixelArraySize, inFile);
    fclose(inFile);

    int watermarkLength = strlen(watermark);
    for (int i = 0; i < watermarkLength * 8 && i < pixelArraySize; i++) {
        // Get the bit of the watermark to embed
        uint8_t watermarkBit = (watermark[i / 8] >> (7 - (i % 8))) & 1;
        // Modify the LSB of the pixel
        pixelArray[i] = (pixelArray[i] & ~1) | watermarkBit;
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        perror("Error opening output file");
        free(pixelArray);
        return;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outFile);
    fwrite(pixelArray, sizeof(uint8_t), pixelArraySize, outFile);

    fclose(outFile);
    free(pixelArray);
    printf("Watermark embedded successfully!\n");
}

int main() {
    const char *inputFile = "input.bmp"; // Input BMP image file
    const char *outputFile = "output.bmp"; // Output BMP image file with watermark
    const char *watermark = "WATERMARK";   // Watermark to embed

    embedWatermark(inputFile, outputFile, watermark);

    return 0;
}