//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1) // Ensure no padding in the structures

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

void apply_contrast(uint8_t *imageData, int width, int height, float contrastFactor) {
    for (int i = 0; i < width * height; ++i) {
        int pixel = (int)(imageData[i] * contrastFactor);
        if (pixel > 255) pixel = 255;
        if (pixel < 0) pixel = 0;
        imageData[i] = (uint8_t)pixel;
    }
}

int load_bmp(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, uint8_t **imageData) {
    FILE *file = fopen(filename, "rb");
    if (!file) return -1;

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (fileHeader->bfType != 0x4D42) { // Check if it's a BMP file
        fclose(file);
        return -1;
    }

    size_t imageSize = infoHeader->biWidth * infoHeader->biHeight;
    *imageData = (uint8_t *)malloc(imageSize);
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(*imageData, imageSize, 1, file);
    fclose(file);

    return 0;
}

int save_bmp(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, uint8_t *imageData) {
    FILE *file = fopen(filename, "wb");
    if (!file) return -1;

    fwrite(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    size_t imageSize = infoHeader->biWidth * infoHeader->biHeight;
    fwrite(imageData, imageSize, 1, file);
    fclose(file);

    return 0;
}

void print_usage() {
    printf("Usage: image_editor <input.bmp> <output.bmp> <contrast_factor>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    uint8_t *imageData;

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    float contrastFactor = atof(argv[3]); // Get the contrast factor

    if (load_bmp(inputFile, &fileHeader, &infoHeader, &imageData) != 0) {
        printf("Error loading BMP file.\n");
        return EXIT_FAILURE;
    }

    apply_contrast(imageData, infoHeader.biWidth, infoHeader.biHeight, contrastFactor);

    if (save_bmp(outputFile, &fileHeader, &infoHeader, imageData) != 0) {
        printf("Error saving BMP file.\n");
        free(imageData);
        return EXIT_FAILURE;
    }

    free(imageData);
    printf("Image processed and saved successfully to %s\n", outputFile);
    return EXIT_SUCCESS;
}