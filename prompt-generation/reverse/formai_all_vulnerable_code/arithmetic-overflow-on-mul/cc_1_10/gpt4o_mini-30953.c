//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// BMP file header structure
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;        // Magic number for BMP files
    uint32_t bfSize;        // Size of the BMP file in bytes
    uint16_t bfReserved1;   // Reserved; must be 0
    uint16_t bfReserved2;   // Reserved; must be 0
    uint32_t bfOffBits;     // Offset to the start of pixel data
} BMPFileHeader;

typedef struct {
    uint32_t biSize;        // Size of the info header
    int32_t biWidth;        // Width of the image
    int32_t biHeight;       // Height of the image
    uint16_t biPlanes;      // Number of color planes
    uint16_t biBitCount;    // Bits per pixel
    uint32_t biCompression;  // Compression type
    uint32_t biSizeImage;   // Size of the image data
    int32_t biXPelsPerMeter; // Horizontal resolution
    int32_t biYPelsPerMeter; // Vertical resolution
    uint32_t biClrUsed;      // Number of colors in the color palette
    uint32_t biClrImportant;  // Number of important colors
} BMPInfoHeader;

// Pixel structure
typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

void invertColors(Pixel *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = 255 - pixels[i].red;
        pixels[i].green = 255 - pixels[i].green;
        pixels[i].blue = 255 - pixels[i].blue;
    }
}

void applyGrayscale(Pixel *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        uint8_t gray = (pixels[i].red + pixels[i].green + pixels[i].blue) / 3;
        pixels[i].red = gray;
        pixels[i].green = gray;
        pixels[i].blue = gray;
    }
}

void loadBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, Pixel **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open BMP file");
        exit(EXIT_FAILURE);
    }

    fread(fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    // Allocate memory for pixel data
    *pixels = malloc(infoHeader->biWidth * infoHeader->biHeight * sizeof(Pixel));
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(Pixel), infoHeader->biWidth * infoHeader->biHeight, file);

    fclose(file);
}

void saveBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, Pixel *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to create BMP file");
        exit(EXIT_FAILURE);
    }

    fwrite(fileHeader, sizeof(BMPFileHeader), 1, file);
    fwrite(infoHeader, sizeof(BMPInfoHeader), 1, file);
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fwrite(pixels, sizeof(Pixel), infoHeader->biWidth * infoHeader->biHeight, file);

    fclose(file);
}

void printUsage() {
    printf("Usage: image_editor <input.bmp> <output.bmp> <operation>\n");
    printf("Operations:\n");
    printf("  invert       - Invert colors\n");
    printf("  grayscale    - Convert to grayscale\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    Pixel *pixels = NULL;

    loadBMP(argv[1], &fileHeader, &infoHeader, &pixels);

    if (strcmp(argv[3], "invert") == 0) {
        invertColors(pixels, infoHeader.biWidth, infoHeader.biHeight);
    } else if (strcmp(argv[3], "grayscale") == 0) {
        applyGrayscale(pixels, infoHeader.biWidth, infoHeader.biHeight);
    } else {
        printUsage();
        free(pixels);
        return EXIT_FAILURE;
    }

    saveBMP(argv[2], &fileHeader, &infoHeader, pixels);
    free(pixels);

    return EXIT_SUCCESS;
}