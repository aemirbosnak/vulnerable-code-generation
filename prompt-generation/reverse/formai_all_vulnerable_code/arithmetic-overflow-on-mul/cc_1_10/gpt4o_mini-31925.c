//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: secure
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

void embed_watermark(uint8_t *pixelData, const char *watermark, int width, int height) {
    int wmLen = strlen(watermark);
    for (int i = 0; i < wmLen && i < width * height; i++) {
        pixelData[i * 3] = (pixelData[i * 3] & 0xFE) | ((watermark[i] >> 7) & 0x01); // Embed watermark bit in Red channel
        pixelData[i * 3 + 1] = (pixelData[i * 3 + 1] & 0xFE) | ((watermark[i] >> 6) & 0x01); // Green
        pixelData[i * 3 + 2] = (pixelData[i * 3 + 2] & 0xFE) | ((watermark[i] >> 5) & 0x01); // Blue
    }
}

void extract_watermark(uint8_t *pixelData, char *watermark, int length, int width, int height) {
    for (int i = 0; i < length; i++) {
        watermark[i] = 0; // Reset watermark character
        watermark[i] |= ((pixelData[i * 3] & 0x01) << 7); // Extract Red channel
        watermark[i] |= ((pixelData[i * 3 + 1] & 0x01) << 6); // Green channel
        watermark[i] |= ((pixelData[i * 3 + 2] & 0x01) << 5); // Blue channel
    }
    watermark[length] = '\0'; // Null-terminate the string
}

void read_bmp(const char *filename, BITMAPFILEHEADER *bfh, BITMAPINFOHEADER *bih, uint8_t **pixelData) {
    FILE *bmpFile = fopen(filename, "rb");
    if (!bmpFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    fread(bfh, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    int size = bih->biWidth * bih->biHeight * 3; // Assuming 24-bits per pixel (3 bytes)
    *pixelData = (uint8_t *)malloc(size);
    fseek(bmpFile, bfh->bfOffBits, SEEK_SET);
    fread(*pixelData, sizeof(uint8_t), size, bmpFile);
    fclose(bmpFile);
}

void write_bmp(const char *filename, BITMAPFILEHEADER *bfh, BITMAPINFOHEADER *bih, uint8_t *pixelData) {
    FILE *bmpFile = fopen(filename, "wb");
    if (!bmpFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fwrite(bfh, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fwrite(bih, sizeof(BITMAPINFOHEADER), 1, bmpFile);
    fwrite(pixelData, sizeof(uint8_t), bih->biWidth * bih->biHeight * 3, bmpFile);
    fclose(bmpFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    const char *watermark = argv[3];

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    uint8_t *pixelData = NULL;

    read_bmp(inputFile, &bfh, &bih, &pixelData);
    
    embed_watermark(pixelData, watermark, bih.biWidth, bih.biHeight);
    write_bmp(outputFile, &bfh, &bih, pixelData);

    char extracted[256]; // Allocate memory for extracted watermark
    extract_watermark(pixelData, extracted, strlen(watermark), bih.biWidth, bih.biHeight);

    printf("Extracted watermark: %s\n", extracted);

    free(pixelData);
    return EXIT_SUCCESS;
}