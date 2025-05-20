//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define structures for BMP file and header
#pragma pack(push, 1) // Ensure byte alignment
typedef struct BMPFileHeader {
    uint16_t bfType;      // Magic number
    uint32_t bfSize;      // File size
    uint16_t bfReserved1; // Reserved
    uint16_t bfReserved2; // Reserved
    uint32_t bfOffBits;   // Offset to pixel data
} BMPFileHeader;

typedef struct BMPInfoHeader {
    uint32_t biSize;          // Info header size
    int32_t  biWidth;         // Image width
    int32_t  biHeight;        // Image height
    uint16_t biPlanes;        // Color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Image size
    int32_t  biXPelsPerMeter;  // X pixels per meter
    int32_t  biYPelsPerMeter;  // Y pixels per meter
    uint32_t biClrUsed;       // Number of colors
    uint32_t biClrImportant;   // Important colors
} BMPInfoHeader;

typedef struct RGB {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;
#pragma pack(pop)

// Function prototypes
void loadBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, RGB **pixels);
void saveBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, RGB *pixels);
void applyGrayscale(RGB *pixels, int width, int height);
void applyInvert(RGB *pixels, int width, int height);
void freeMemory(RGB *pixels);

int main() {
    const char *inputFile = "input.bmp";
    const char *outputFile = "output.bmp";

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    RGB *pixels = NULL;

    // Load the BMP image
    loadBMP(inputFile, &fileHeader, &infoHeader, &pixels);

    // Prompt user for effect
    int choice;
    printf("Choose an effect to apply:\n");
    printf("1. Grayscale\n");
    printf("2. Invert Colors\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            applyGrayscale(pixels, infoHeader.biWidth, infoHeader.biHeight);
            break;
        case 2:
            applyInvert(pixels, infoHeader.biWidth, infoHeader.biHeight);
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            freeMemory(pixels);
            return 1;
    }

    // Save the modified BMP image
    saveBMP(outputFile, &fileHeader, &infoHeader, pixels);

    // Clean up memory
    freeMemory(pixels);
    printf("Image processing complete. Saved to %s\n", outputFile);
    return 0;
}

void loadBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, RGB **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    
    fread(fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    // Allocate memory for pixel data
    int width = infoHeader->biWidth;
    int height = infoHeader->biHeight;
    *pixels = (RGB *)malloc(width * height * sizeof(RGB));
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(RGB), width * height, file);
    fclose(file);
}

void saveBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, RGB *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fwrite(fileHeader, sizeof(BMPFileHeader), 1, file);
    fwrite(infoHeader, sizeof(BMPInfoHeader), 1, file);
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fwrite(pixels, sizeof(RGB), infoHeader->biWidth * infoHeader->biHeight, file);
    fclose(file);
}

void applyGrayscale(RGB *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        uint8_t gray = (pixels[i].red + pixels[i].green + pixels[i].blue) / 3;
        pixels[i].red = gray;
        pixels[i].green = gray;
        pixels[i].blue = gray;
    }
}

void applyInvert(RGB *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = 255 - pixels[i].red;
        pixels[i].green = 255 - pixels[i].green;
        pixels[i].blue = 255 - pixels[i].blue;
    }
}

void freeMemory(RGB *pixels) {
    free(pixels);
}