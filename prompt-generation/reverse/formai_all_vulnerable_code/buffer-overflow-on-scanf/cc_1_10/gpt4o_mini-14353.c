//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    uint16_t bfType;      // Magic number for BMP files
    uint32_t bfSize;      // Size of the BMP file
    uint16_t bfReserved1; // Reserved; must be 0
    uint16_t bfReserved2; // Reserved; must be 0
    uint32_t bfOffBits;   // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header (40 bytes)
    int32_t  biWidth;         // Width of the bitmap in pixels
    int32_t  biHeight;        // Height of the bitmap in pixels
    uint16_t biPlanes;        // Number of color planes (must be 1)
    uint16_t biBitCount;      // Number of bits per pixel (1, 4, 8, 16, 24, or 32)
    uint32_t biCompression;    // Compression type (0 = uncompressed)
    uint32_t biSizeImage;     // Size of pixel data (may be 0 for uncompressed)
    int32_t  biXPelsPerMeter;   // Horizontal resolution (pixels per meter)
    int32_t  biYPelsPerMeter;   // Vertical resolution (pixels per meter)
    uint32_t biClrUsed;        // Number of colors in the palette
    uint32_t biClrImportant;   // Important colors; generally ignored
} BITMAPINFOHEADER;

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGB;

void applyGrayscale(RGB* pixelData, int pixelCount) {
    for(int i = 0; i < pixelCount; i++) {
        uint8_t gray = (pixelData[i].r + pixelData[i].g + pixelData[i].b) / 3;
        pixelData[i].r = gray;
        pixelData[i].g = gray;
        pixelData[i].b = gray;
    }
}

void flipHorizontally(RGB* pixelData, int width, int height) {
    int rowSize = width * sizeof(RGB);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            int oppositeIndex = width - j - 1;
            RGB temp = pixelData[i * width + j];
            pixelData[i * width + j] = pixelData[i * width + oppositeIndex];
            pixelData[i * width + oppositeIndex] = temp;
        }
    }
}

void readBitmap(const char* filename, RGB** pixelData, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);

    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    *width = infoHeader.biWidth;
    *height = infoHeader.biHeight;

    int pixelCount = (*width) * (*height);
    *pixelData = (RGB*)malloc(pixelCount * sizeof(RGB));
    fseek(file, fileHeader.bfOffBits, SEEK_SET);
    fread(*pixelData, sizeof(RGB), pixelCount, file);
    
    fclose(file);
}

void writeBitmap(const char* filename, RGB* pixelData, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot create file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER fileHeader = {0x4D42, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (width * height * sizeof(RGB)), 0, 0, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)};
    BITMAPINFOHEADER infoHeader = {sizeof(BITMAPINFOHEADER), width, height, 1, 24, 0, 0, 0, 0, 0, 0};

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixelData, sizeof(RGB), width * height, file);
    
    fclose(file);
}

void displayMenu() {
    printf("Image Editor Menu:\n");
    printf("1. Convert to Grayscale\n");
    printf("2. Flip Horizontally\n");
    printf("3. Exit\n");
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    RGB* pixelData;
    int width, height;
    readBitmap(argv[1], &pixelData, &width, &height);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                applyGrayscale(pixelData, width * height);
                printf("Converted to Grayscale.\n");
                break;
            case 2:
                flipHorizontally(pixelData, width, height);
                printf("Image Flipped Horizontally.\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    writeBitmap(argv[2], pixelData, width, height);
    free(pixelData);
    return EXIT_SUCCESS;
}