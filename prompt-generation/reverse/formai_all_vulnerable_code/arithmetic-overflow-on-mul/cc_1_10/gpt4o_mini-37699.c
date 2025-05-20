//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: single-threaded
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
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} DIBHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

void applyGrayscale(Pixel *imageData, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        uint8_t gray = (imageData[i].red + imageData[i].green + imageData[i].blue) / 3;
        imageData[i].red = gray;
        imageData[i].green = gray;
        imageData[i].blue = gray;
    }
}

void loadBMP(char* filename, BMPHeader* bmpHeader, DIBHeader* dibHeader, Pixel** imageData) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    fread(bmpHeader, sizeof(BMPHeader), 1, file);
    fread(dibHeader, sizeof(DIBHeader), 1, file);
    
    if (bmpHeader->fileType != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    
    *imageData = malloc(dibHeader->width * dibHeader->height * sizeof(Pixel));
    fseek(file, bmpHeader->offsetData, SEEK_SET);
    fread(*imageData, sizeof(Pixel), dibHeader->width * dibHeader->height, file);
    
    fclose(file);
}

void saveBMP(char* filename, BMPHeader* bmpHeader, DIBHeader* dibHeader, Pixel* imageData) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    
    fwrite(bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(dibHeader, sizeof(DIBHeader), 1, file);
    
    fseek(file, bmpHeader->offsetData, SEEK_SET);
    fwrite(imageData, sizeof(Pixel), dibHeader->width * dibHeader->height, file);
    
    fclose(file);
}

void printUsage() {
    printf("Usage: bmp_editor <input_file> <output_file>\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printUsage();
        return EXIT_FAILURE;
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    Pixel* imageData;

    loadBMP(argv[1], &bmpHeader, &dibHeader, &imageData);
    applyGrayscale(imageData, dibHeader.width, dibHeader.height);
    saveBMP(argv[2], &bmpHeader, &dibHeader, imageData);

    free(imageData);
    printf("Grayscale conversion completed successfully!\n");
    return EXIT_SUCCESS;
}