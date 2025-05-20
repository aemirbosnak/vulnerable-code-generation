//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t importantColors;
} DIBHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

void flipImageHorizontally(Pixel* pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            Pixel temp = pixels[y * width + x];
            pixels[y * width + x] = pixels[y * width + (width - 1 - x)];
            pixels[y * width + (width - 1 - x)] = temp;
        }
    }
}

void changeBrightness(Pixel* pixels, int width, int height, int adjustment) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixels[y * width + x].red = (pixels[y * width + x].red + adjustment > 255) ? 255 : (pixels[y * width + x].red + adjustment < 0) ? 0 : (pixels[y * width + x].red + adjustment);
            pixels[y * width + x].green = (pixels[y * width + x].green + adjustment > 255) ? 255 : (pixels[y * width + x].green + adjustment < 0) ? 0 : (pixels[y * width + x].green + adjustment);
            pixels[y * width + x].blue = (pixels[y * width + x].blue + adjustment > 255) ? 255 : (pixels[y * width + x].blue + adjustment < 0) ? 0 : (pixels[y * width + x].blue + adjustment);
        }
    }
}

void changeContrast(Pixel* pixels, int width, int height, float factor) {
    float contrastFactor = (259 * (factor + 255)) / (255 * (259 - factor));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixels[y * width + x].red = (int)(contrastFactor * (pixels[y * width + x].red - 128) + 128);
            pixels[y * width + x].green = (int)(contrastFactor * (pixels[y * width + x].green - 128) + 128);
            pixels[y * width + x].blue = (int)(contrastFactor * (pixels[y * width + x].blue - 128) + 128);
            pixels[y * width + x].red = (pixels[y * width + x].red > 255) ? 255 : (pixels[y * width + x].red < 0) ? 0 : pixels[y * width + x].red;
            pixels[y * width + x].green = (pixels[y * width + x].green > 255) ? 255 : (pixels[y * width + x].green < 0) ? 0 : pixels[y * width + x].green;
            pixels[y * width + x].blue = (pixels[y * width + x].blue > 255) ? 255 : (pixels[y * width + x].blue < 0) ? 0 : pixels[y * width + x].blue;
        }
    }
}

void loadBMP(const char* filename, Pixel** pixels, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, file);
    fread(&dibHeader, sizeof(DIBHeader), 1, file);
    
    *width = dibHeader.width;
    *height = dibHeader.height;
    *pixels = malloc((*width) * (*height) * sizeof(Pixel));

    fseek(file, bmpHeader.offset, SEEK_SET);
    fread(*pixels, sizeof(Pixel), (*width) * (*height), file);
    fclose(file);
}

void saveBMP(const char* filename, Pixel* pixels, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error saving file");
        return;
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    bmpHeader.type = 0x4D42;
    bmpHeader.size = sizeof(BMPHeader) + sizeof(DIBHeader) + (width * height * sizeof(Pixel));
    bmpHeader.reserved1 = 0;
    bmpHeader.reserved2 = 0;
    bmpHeader.offset = sizeof(BMPHeader) + sizeof(DIBHeader);
    
    dibHeader.size = sizeof(DIBHeader);
    dibHeader.width = width;
    dibHeader.height = height;
    dibHeader.planes = 1;
    dibHeader.bitsPerPixel = 24;
    dibHeader.compression = 0;
    dibHeader.imageSize = width * height * sizeof(Pixel);
    dibHeader.xPixelsPerMeter = 0;
    dibHeader.yPixelsPerMeter = 0;
    dibHeader.colorsUsed = 0;
    dibHeader.importantColors = 0;

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, file);
    fwrite(pixels, sizeof(Pixel), width * height, file);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input.bmp> <output.bmp> <brightness adjustment> <contrast factor>\n", argv[0]);
        return 1;
    }

    const char* inputFile = argv[1];
    const char* outputFile = argv[2];
    int brightnessAdjustment = atoi(argv[3]);
    float contrastFactor = atof(argv[4]);

    Pixel* pixels;
    int width, height;

    loadBMP(inputFile, &pixels, &width, &height);

    flipImageHorizontally(pixels, width, height);
    changeBrightness(pixels, width, height, brightnessAdjustment);
    changeContrast(pixels, width, height, contrastFactor);

    saveBMP(outputFile, pixels, width, height);

    free(pixels);
    return 0;
}