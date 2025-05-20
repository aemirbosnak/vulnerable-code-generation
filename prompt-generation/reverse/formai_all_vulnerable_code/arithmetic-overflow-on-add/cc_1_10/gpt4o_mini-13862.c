//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // BMP File Type
    uint32_t bfSize;      // Size of the BMP file
    uint16_t bfReserved1; // Reserved
    uint16_t bfReserved2; // Reserved
    uint32_t bfOffBits;   // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of the info header
    int32_t  biWidth;         // Width of the image
    int32_t  biHeight;        // Height of the image
    uint16_t biPlanes;        // Color planes (must be 1)
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;      // Size of image data
    int32_t  biXPelsPerMeter;   // Horizontal resolution
    int32_t  biYPelsPerMeter;   // Vertical resolution
    uint32_t biClrUsed;        // Number of colors
    uint32_t biClrImportant;    // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

void convertToGrayscale(uint8_t* pixelData, int width, int height) {
    int rowSize = (width * 3 + 3) & ~3; // padded row size to 4 bytes
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            uint8_t* pixel = pixelData + (h * rowSize) + (w * 3);
            uint8_t blue = pixel[0];
            uint8_t green = pixel[1];
            uint8_t red = pixel[2];
            uint8_t gray = (uint8_t)(0.299 * red + 0.587 * green + 0.114 * blue);
            pixel[0] = gray; // blue
            pixel[1] = gray; // green
            pixel[2] = gray; // red
        }
    }
}

void loadBMP(const char* filename, uint8_t** pixelData, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        exit(1);
    }

    BITMAPFILEHEADER bfHeader;
    fread(&bfHeader, sizeof(bfHeader), 1, file);

    BITMAPINFOHEADER biHeader;
    fread(&biHeader, sizeof(biHeader), 1, file);

    *width = biHeader.biWidth;
    *height = biHeader.biHeight;
    int rowSize = (*width * 3 + 3) & ~3; // padded row size to 4 bytes
    *pixelData = malloc(rowSize * (*height));
    fseek(file, bfHeader.bfOffBits, SEEK_SET);
    fread(*pixelData, rowSize, *height, file);
    fclose(file);
}

void saveBMP(const char* filename, uint8_t* pixelData, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        exit(1);
    }

    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;

    bfHeader.bfType = 0x4D42; // 'BM'
    bfHeader.bfReserved1 = 0;
    bfHeader.bfReserved2 = 0;
    bfHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bfHeader.bfSize = bfHeader.bfOffBits + ((width * 3 + 3) & ~3) * height;

    biHeader.biSize = sizeof(BITMAPINFOHEADER);
    biHeader.biWidth = width;
    biHeader.biHeight = height;
    biHeader.biPlanes = 1;
    biHeader.biBitCount = 24; 
    biHeader.biCompression = 0;
    biHeader.biSizeImage = 0;
    biHeader.biXPelsPerMeter = 0;
    biHeader.biYPelsPerMeter = 0;
    biHeader.biClrUsed = 0;
    biHeader.biClrImportant = 0;

    fwrite(&bfHeader, sizeof(bfHeader), 1, file);
    fwrite(&biHeader, sizeof(biHeader), 1, file);

    int rowSize = (width * 3 + 3) & ~3; // padded row size to 4 bytes
    fwrite(pixelData, rowSize, height, file);
    fclose(file);
}

int main() {
    uint8_t* pixelData;
    int width, height;

    printf("Loading image...\n");
    loadBMP("input.bmp", &pixelData, &width, &height);
    
    printf("Converting to grayscale...\n");
    convertToGrayscale(pixelData, width, height);
    
    saveBMP("output.bmp", pixelData, width, height);
    free(pixelData);
    
    printf("Image processed and saved as output.bmp\n");
    
    return 0;
}