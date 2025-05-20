//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // Magic number for the file
    uint32_t bfSize;      // Size of the BMP file
    uint16_t bfReserved1; // Reserved; must be 0
    uint16_t bfReserved2; // Reserved; must be 0
    uint32_t bfOffBits;   // Offset to image data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the image
    int32_t  biHeight;        // Height of the image
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Size of pixel data
    int32_t  biXPixPerMeter;   // Pixels per meter (X axis)
    int32_t  biYPixPerMeter;   // Pixels per meter (Y axis)
    uint32_t biClrUsed;        // Number of colors in the color palette
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;

#pragma pack(pop)

// Function prototypes
void flipImage(uint8_t* pixelData, int width, int height);
void adjustBrightnessContrast(uint8_t* pixelData, int width, int height, int brightness, float contrast);
void saveBitmap(const char* filename, BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, uint8_t* pixelData);

int main(int argc, char* argv[]) {
    if (argc != 5) {
        printf("Usage: %s <input.bmp> <output.bmp> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    FILE* input = fopen(argv[1], "rb");
    if (!input) {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, input);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, input);

    if (bfh.bfType != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file\n");
        fclose(input);
        return 1;
    }

    uint8_t* pixelData = (uint8_t*)malloc(bih.biSizeImage);
    fseek(input, bfh.bfOffBits, SEEK_SET);
    fread(pixelData, 1, bih.biSizeImage, input);
    fclose(input);

    // Flip the image vertically
    flipImage(pixelData, bih.biWidth, bih.biHeight);

    // Adjust brightness and contrast
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);
    adjustBrightnessContrast(pixelData, bih.biWidth, bih.biHeight, brightness, contrast);

    // Save the modified image
    const char* outputFilename = argv[2];
    saveBitmap(outputFilename, bfh, bih, pixelData);

    free(pixelData);
    return 0;
}

void flipImage(uint8_t* pixelData, int width, int height) {
    int rowSize = width * 3; // Assuming 24 bits per pixel
    uint8_t* tempRow = (uint8_t*)malloc(rowSize);

    for (int y = 0; y < height / 2; y++) {
        int oppositeY = height - y - 1;
        memcpy(tempRow, pixelData + y * rowSize, rowSize);
        memcpy(pixelData + y * rowSize, pixelData + oppositeY * rowSize, rowSize);
        memcpy(pixelData + oppositeY * rowSize, tempRow, rowSize);
    }

    free(tempRow);
}

void adjustBrightnessContrast(uint8_t* pixelData, int width, int height, int brightness, float contrast) {
    for (int i = 0; i < width * height * 3; i += 3) {
        // Adjust brightness
        pixelData[i] = (uint8_t)fmin(fmax(pixelData[i] + brightness, 0), 255);
        pixelData[i + 1] = (uint8_t)fmin(fmax(pixelData[i + 1] + brightness, 0), 255);
        pixelData[i + 2] = (uint8_t)fmin(fmax(pixelData[i + 2] + brightness, 0), 255);

        // Adjust contrast
        pixelData[i] = (uint8_t)fmin(fmax((pixelData[i] - 128) * contrast + 128, 0), 255);
        pixelData[i + 1] = (uint8_t)fmin(fmax((pixelData[i + 1] - 128) * contrast + 128, 0), 255);
        pixelData[i + 2] = (uint8_t)fmin(fmax((pixelData[i + 2] - 128) * contrast + 128, 0), 255);
    }
}

void saveBitmap(const char* filename, BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, uint8_t* pixelData) {
    FILE* output = fopen(filename, "wb");
    if (!output) {
        fprintf(stderr, "Error opening output file.\n");
        return;
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, output);
    fseek(output, bfh.bfOffBits, SEEK_SET);
    fwrite(pixelData, 1, bih.biSizeImage, output);

    fclose(output);
}