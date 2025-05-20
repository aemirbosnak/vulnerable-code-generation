//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t fileType;
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offsetData;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPelsPerMeter;
    int32_t yPelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} BMPPixel;
#pragma pack(pop)

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *imgFile = fopen(inputFile, "rb");
    if (!imgFile) {
        perror("Error opening input file");
        return;
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, imgFile);

    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, imgFile);

    if (bmpInfoHeader.bitCount != 24) {
        printf("Only true color (24 bit) BMP files are supported.\n");
        fclose(imgFile);
        return;
    }

    BMPPixel *pixels = malloc(bmpInfoHeader.width * bmpInfoHeader.height * sizeof(BMPPixel));
    fread(pixels, sizeof(BMPPixel), bmpInfoHeader.width * bmpInfoHeader.height, imgFile);
    fclose(imgFile);

    // Watermark embedding
    size_t watermarkLength = strlen(watermark);
    size_t totalLength = bmpInfoHeader.width * bmpInfoHeader.height;
    for (size_t i = 0; i < watermarkLength && i < totalLength; i++) {
        // Embed one bit of each watermark character into the least significant bit of the pixel
        uint8_t bit = (watermark[i / 8] >> (7 - (i % 8))) & 1;
        BMPPixel *pixel = &pixels[i];
        pixel->red = (pixel->red & 0xFE) | bit; // Embed in red channel only
    }

    // Save watermarked image
    FILE *outputImgFile = fopen(outputFile, "wb");
    if (!outputImgFile) {
        perror("Error opening output file");
        free(pixels);
        return;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputImgFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputImgFile);
    fwrite(pixels, sizeof(BMPPixel), bmpInfoHeader.width * bmpInfoHeader.height, outputImgFile);
    fclose(outputImgFile);

    free(pixels);
    printf("Watermark embedded successfully!\n");
}

void printUsage() {
    printf("Usage: watermark <input.bmp> <output.bmp> <watermark>\n");
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printUsage();
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    const char *watermark = argv[3];

    embedWatermark(inputFile, outputFile, watermark);
    return 0;
}