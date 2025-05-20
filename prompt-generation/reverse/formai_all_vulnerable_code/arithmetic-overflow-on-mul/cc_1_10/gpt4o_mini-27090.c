//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)  // Ensures structure padding does not occur

typedef struct {
    unsigned short bfType;
    unsigned long bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned long bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXYPixPerMeter;
    long biYPixPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    unsigned char Blue;
    unsigned char Green;
    unsigned char Red;
} RGB;

void readBMP(const char *filename, BITMAPFILEHEADER *bmh, BITMAPINFOHEADER *bih, RGB **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fread(bmh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, file);

    *pixels = (RGB *)malloc(bih->biWidth * bih->biHeight * sizeof(RGB));
    fseek(file, bmh->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(RGB), bih->biWidth * bih->biHeight, file);

    fclose(file);
}

void saveBMP(const char *filename, BITMAPFILEHEADER *bmh, BITMAPINFOHEADER *bih, RGB *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error creating file");
        exit(1);
    }

    fwrite(bmh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(bih, sizeof(BITMAPINFOHEADER), 1, file);

    fseek(file, bmh->bfOffBits, SEEK_SET);
    fwrite(pixels, sizeof(RGB), bih->biWidth * bih->biHeight, file);

    fclose(file);
}

void embedWatermark(RGB *pixels, int width, int height, const char *watermark) {
    int len = strlen(watermark);
    for (int i = 0; i < len; i++) {
        int x = (i * width) / len;  // Spacing out the watermark across the width
        int y = height - 10;        // Embedding the watermark near the bottom

        // Modify the pixel color slightly to embed the watermark
        if (x < width) { // Ensure we don't go out of bounds
            pixels[y * width + x].Red = (pixels[y * width + x].Red + 50) % 256;
            pixels[y * width + x].Green = (pixels[y * width + x].Green + 50) % 256;
            pixels[y * width + x].Blue = (pixels[y * width + x].Blue + 50) % 256;
        }
    }
}

void extractWatermark(RGB *pixels, int width, int height, char *watermark, int maxWatermarkLen) {
    for (int i = 0; i < maxWatermarkLen; i++) {
        int x = (i * width) / maxWatermarkLen; // Same calculation as in embedding
        int y = height - 10; // Same y coordinate

        // Assume the watermark is present if the Red component is altered
        if (x < width) {
            if (pixels[y * width + x].Red > 100) { // Arbitrary threshold to determine embedding
                watermark[i] = '*'; // Placeholder character indicating watermark presence
            } else {
                watermark[i] = ' '; // No watermark present
            }
        }
    }
    watermark[maxWatermarkLen] = '\0'; // Null-terminate the string
}

int main() {
    const char *inputImagePath = "input.bmp";
    const char *outputImagePath = "output.bmp";
    const char *watermark = "MyWatermark";

    BITMAPFILEHEADER bmh;
    BITMAPINFOHEADER bih;
    RGB *pixels;

    readBMP(inputImagePath, &bmh, &bih, &pixels);

    embedWatermark(pixels, bih.biWidth, bih.biHeight, watermark);
    saveBMP(outputImagePath, &bmh, &bih, pixels);

    char extractedWatermark[50]; // Adjust size as needed
    extractWatermark(pixels, bih.biWidth, bih.biHeight, extractedWatermark, sizeof(extractedWatermark) - 1);

    printf("Extracted Watermark: '%s'\n", extractedWatermark);

    free(pixels);
    return 0;
}