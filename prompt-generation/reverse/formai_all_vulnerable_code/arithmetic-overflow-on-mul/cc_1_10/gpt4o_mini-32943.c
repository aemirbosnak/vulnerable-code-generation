//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;

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
} DIBHeader;

typedef struct {
    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    Pixel *pixels;
} BMPImage;

BMPImage* loadBMP(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    BMPImage *image = malloc(sizeof(BMPImage));
    fread(&image->bmpHeader, sizeof(BMPHeader), 1, file);
    fread(&image->dibHeader, sizeof(DIBHeader), 1, file);

    int width = image->dibHeader.biWidth;
    int height = image->dibHeader.biHeight;
    image->pixels = malloc(width * height * sizeof(Pixel));
    
    fseek(file, image->bmpHeader.bfOffBits, SEEK_SET);
    fread(image->pixels, sizeof(Pixel), width * height, file);
    
    fclose(file);
    return image;
}

void saveBMP(const char *filename, BMPImage *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for saving");
        return;
    }

    fwrite(&image->bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&image->dibHeader, sizeof(DIBHeader), 1, file);
    
    int size = image->dibHeader.biWidth * image->dibHeader.biHeight;
    fwrite(image->pixels, sizeof(Pixel), size, file);
    
    fclose(file);
}

void embedWatermark(BMPImage *image, const char *watermark) {
    int width = image->dibHeader.biWidth;
    int height = image->dibHeader.biHeight;
    int length = strlen(watermark);

    for (int i = 0; i < length; i++) {
        if (i >= width * height) break; // Prevent overflow
        Pixel *px = &image->pixels[i];
        px->blue = (px->blue & 0xFE) | ((watermark[i] >> 0) & 0x01);
        px->green = (px->green & 0xFE) | ((watermark[i] >> 1) & 0x01);
        px->red = (px->red & 0xFE) | ((watermark[i] >> 2) & 0x01);
    }

    // Add a termination character for the watermark
    if (length < width * height) {
        Pixel *px = &image->pixels[length];
        px->blue = (px->blue & 0xFE) | ((0) & 0x01);
        px->green = (px->green & 0xFE) | ((0) & 0x01);
        px->red = (px->red & 0xFE) | ((0) & 0x01);
    }
}

void extractWatermark(BMPImage *image, char *watermark, int max_len) {
    int width = image->dibHeader.biWidth;
    int height = image->dibHeader.biHeight;

    for (int i = 0; i < max_len; i++) {
        if (i >= width * height) break; // Prevent overflow
        Pixel *px = &image->pixels[i];
        watermark[i] = ((px->blue & 0x01) << 0) |
                       ((px->green & 0x01) << 1) |
                       ((px->red & 0x01) << 2);
        
        if (watermark[i] == 0) break; // Stop at null terminator
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_bmp> <output_bmp> <watermark_string>\n", argv[0]);
        return -1;
    }

    BMPImage *image = loadBMP(argv[1]);
    if (!image) {
        return -1;
    }

    printf("Watermarking image...\n");
    embedWatermark(image, argv[3]);

    saveBMP(argv[2], image);
    printf("Watermarked image saved as %s\n", argv[2]);

    char extracted[256] = {0};
    extractWatermark(image, extracted, sizeof(extracted));
    printf("Extracted watermark: %s\n", extracted);

    free(image->pixels);
    free(image);
    return 0;
}