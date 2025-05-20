//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensure proper alignment for BMP structures
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

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
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGBTRIPLE;
#pragma pack(pop)

void embedWatermarkInPixel(RGBTRIPLE *pixel, char watermarkChar, int position) {
    pixel->red = (pixel->red & 0xFE) | ((watermarkChar >> position) & 0x01);
    pixel->green = (pixel->green & 0xFE) | ((watermarkChar >> (position + 1)) & 0x01);
    pixel->blue = (pixel->blue & 0xFE) | ((watermarkChar >> (position + 2)) & 0x01);
}

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");
    
    if (!input || !output) {
        perror("File opening failed");
        return;
    }
    
    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, input);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, input);
    
    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, output);
  
    int pixelCount = bmpInfoHeader.biWidth * abs(bmpInfoHeader.biHeight);
    RGBTRIPLE *pixels = (RGBTRIPLE*) malloc(pixelCount * sizeof(RGBTRIPLE));
    fread(pixels, sizeof(RGBTRIPLE), pixelCount, input);
    
    int watermarkLength = strlen(watermark);
    for (int i = 0; i < watermarkLength; i++) {
        for (int bitPosition = 0; bitPosition < 8; bitPosition++) {
            if (i * 8 + bitPosition < pixelCount) {
                embedWatermarkInPixel(&pixels[i * 8 + bitPosition], watermark[i], bitPosition);
            } else {
                break; // No more pixel left to modify
            }
        }
    }
    
    fwrite(pixels, sizeof(RGBTRIPLE), pixelCount, output);
    
    fclose(input);
    fclose(output);
    free(pixels);
    printf("Watermark embedded successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <watermark text>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    embedWatermark(argv[1], argv[2], argv[3]);
    
    return EXIT_SUCCESS;
}