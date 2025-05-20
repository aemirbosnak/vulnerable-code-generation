//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)

typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPFileHeader;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BMPInfoHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

#pragma pack(pop)

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        perror("Error opening input file");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, input);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, input);

    if (fileHeader.bfType != 0x4D42) {
        fclose(input);
        printf("The file is not a valid BMP file.\n");
        return;
    }

    int pixelArraySize = infoHeader.biWidth * infoHeader.biHeight;
    RGB *pixels = (RGB *)malloc(pixelArraySize * sizeof(RGB));
    fseek(input, fileHeader.bfOffBits, SEEK_SET);
    fread(pixels, sizeof(RGB), pixelArraySize, input);
    fclose(input);

    int watermarkLength = strlen(watermark);
    for (int i = 0; i < watermarkLength && i < pixelArraySize; i++) {
        // Embed the watermark bit into the least significant bit of the pixel
        if (watermark[i] == '1') {
            pixels[i].red = (pixels[i].red & ~1) | 1; // Set LSB to 1
        } else {
            pixels[i].red = (pixels[i].red & ~1); // Set LSB to 0
        }
    }

    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        perror("Error opening output file");
        free(pixels);
        return;
    }

    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, output);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, output);
    fseek(output, fileHeader.bfOffBits, SEEK_SET);
    fwrite(pixels, sizeof(RGB), pixelArraySize, output);

    fclose(output);
    free(pixels);
    
    printf("Watermark embedded successfully!\n");
}

void printUsage() {
    printf("Usage: ./watermark input.bmp output.bmp watermark_string(0s and 1s)\n");
}

int main(int argc, char *argv[]) {
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