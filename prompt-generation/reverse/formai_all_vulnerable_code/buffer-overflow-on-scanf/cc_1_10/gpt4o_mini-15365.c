//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1)  // Ensure no padding is added

typedef struct {
    uint8_t signature[2]; // BMP file signature
    uint32_t fileSize;    // Size of the file in bytes
    uint16_t reserved1;   // Reserved, must be 0
    uint16_t reserved2;   // Reserved, must be 0
    uint32_t offset;      // Offset to start of pixel data
} BMPHeader;

typedef struct {
    uint32_t headerSize;  // Size of this header
    int32_t width;        // Width of the bitmap in pixels
    int32_t height;       // Height of the bitmap in pixels
    uint16_t planes;      // Number of color planes
    uint16_t bitCount;    // Number of bits per pixel
    uint32_t compression; // Compression type
    uint32_t sizeImage;   // Size of the pixel data
    int32_t xPelsPerMeter; // Pixels per meter in X
    int32_t yPelsPerMeter; // Pixels per meter in Y
    uint32_t colorsUsed;   // Number of colors in the bitmap
    uint32_t colorsImportant; // Important colors
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

void invertColors(RGB *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = 255 - pixels[i].red;
        pixels[i].green = 255 - pixels[i].green;
        pixels[i].blue = 255 - pixels[i].blue;
    }
}

void loadBMP(const char *filename, BMPHeader *bmpHeader, BMPInfoHeader *bmpInfoHeader, RGB **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }
    
    fread(bmpHeader, sizeof(BMPHeader), 1, file);
    fread(bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);
    
    if (bmpHeader->signature[0] != 'B' || bmpHeader->signature[1] != 'M') {
        printf("Error: Not a BMP file\n");
        fclose(file);
        exit(1);
    }

    // Allocate memory for pixel data
    int width = bmpInfoHeader->width;
    int height = bmpInfoHeader->height;
    *pixels = (RGB*)malloc(sizeof(RGB) * width * height);
    
    // Move to the pixel data section
    fseek(file, bmpHeader->offset, SEEK_SET);
    fread(*pixels, sizeof(RGB), width * height, file);
    
    fclose(file);
}

void saveBMP(const char *filename, BMPHeader *bmpHeader, BMPInfoHeader *bmpInfoHeader, RGB *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    fwrite(bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    // Write pixel data
    fwrite(pixels, sizeof(RGB), bmpInfoHeader->width * bmpInfoHeader->height, file);
    
    fclose(file);
}

void printMenu() {
    printf("Welcome to the Exciting BMP Image Editor!\n");
    printf("1. Invert Colors\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    RGB *pixels = NULL;
    char filename[256];
    
    printf("Enter the BMP filename to edit: ");
    scanf("%s", filename);

    // Load the BMP file
    loadBMP(filename, &bmpHeader, &bmpInfoHeader, &pixels);

    int choice;
    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invertColors(pixels, bmpInfoHeader.width, bmpInfoHeader.height);
                printf("Colors inverted! Saving...\n");
                char outputFilename[256];
                snprintf(outputFilename, sizeof(outputFilename), "inverted_%s", filename);
                saveBMP(outputFilename, &bmpHeader, &bmpInfoHeader, pixels);
                printf("Saved as %s\n", outputFilename);
                break;
            case 2:
                printf("Exiting the editor. Goodbye!\n");
                free(pixels);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    free(pixels);
    return 0;
}