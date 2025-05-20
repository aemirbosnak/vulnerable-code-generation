//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(1)
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

void embedWatermark(const char *inputFileName, const char *outputFileName, const char *watermark) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    
    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    // Check if it's a 24-bit BMP file
    if (infoHeader.biBitCount != 24) {
        fprintf(stderr, "Only 24-bit BMP files are supported.\n");
        fclose(inputFile);
        return;
    }

    // Calculate the size of the image data
    uint32_t imageSize = infoHeader.biWidth * infoHeader.biHeight * 3;
    uint8_t *imageData = (uint8_t *)malloc(imageSize);
    fread(imageData, sizeof(uint8_t), imageSize, inputFile);
    fclose(inputFile);

    // Embed the watermark in the least significant bit of each pixel
    int watermarkLength = strlen(watermark);
    for (int i = 0; i < watermarkLength; i++) {
        for (int bit = 0; bit < 8; bit++) {
            // Determine pixel index to modify
            int pixelIndex = i * 8 + bit;
            if (pixelIndex < imageSize) {
                // Get the current pixel's color
                uint8_t *pixel = &imageData[pixelIndex * 3]; // 3 bytes per pixel (B, G, R)
                
                // Embed the watermark bit into the least significant bit
                uint8_t bitToEmbed = (watermark[i] >> (7 - bit)) & 1;
                pixel[0] = (pixel[0] & 0xFE) | bitToEmbed; // Modify Blue component (LSB)
            }
        }
    }

    // Save modified image data to a new file
    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        free(imageData);
        return;
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fwrite(imageData, sizeof(uint8_t), imageSize, outputFile);
    fclose(outputFile);
    free(imageData);
    
    printf("Watermark \"%s\" embedded successfully in %s\n", watermark, outputFileName);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    const char *watermark = argv[3];

    embedWatermark(inputFileName, outputFileName, watermark);

    return EXIT_SUCCESS;
}