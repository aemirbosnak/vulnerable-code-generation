//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensures no padding to maintain structure size 
typedef struct {
    uint16_t bfType;      // Magic number for file
    uint32_t bfSize;      // Size of the file in bytes
    uint16_t bfReserved1; // Reserved, must be zero
    uint16_t bfReserved2; // Reserved, must be zero
    uint32_t bfOffBits;   // Offset to start of pixel data
} BMPFileHeader;

typedef struct {
    uint32_t biSize;          // Size of this header (40 bytes)
    int32_t  biWidth;         // Width of bitmap in pixels
    int32_t  biHeight;        // Height of bitmap in pixels
    uint16_t biPlanes;        // Number of color planes (must be 1)
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;      // Size of image data
    int32_t  biXPelsPerMeter;   // Pixels per meter in X
    int32_t  biYPelsPerMeter;   // Pixels per meter in Y
    uint32_t biClrUsed;        // Number of colors in palette
    uint32_t biClrImportant;   // Important colors
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

void flipImageVertically(RGB *pixels, int width, int height) {
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            int topIndex = y * width + x;
            int bottomIndex = (height - 1 - y) * width + x;

            // Swap color values
            RGB temp = pixels[topIndex];
            pixels[topIndex] = pixels[bottomIndex];
            pixels[bottomIndex] = temp;
        }
    }
}

void adjustBrightness(RGB *pixels, int width, int height, int brightness) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = (pixels[i].red + brightness > 255) ? 255 : (pixels[i].red + brightness < 0) ? 0 : pixels[i].red + brightness;
        pixels[i].green = (pixels[i].green + brightness > 255) ? 255 : (pixels[i].green + brightness < 0) ? 0 : pixels[i].green + brightness;
        pixels[i].blue = (pixels[i].blue + brightness > 255) ? 255 : (pixels[i].blue + brightness < 0) ? 0 : pixels[i].blue + brightness;
    }
}

void readBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, RGB **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fread(fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    
    *pixels = malloc(infoHeader->biWidth * infoHeader->biHeight * sizeof(RGB));

    if (*pixels == NULL) {
        perror("Unable to allocate memory for pixels");
        exit(EXIT_FAILURE);
    }

    fread(*pixels, sizeof(RGB), infoHeader->biWidth * infoHeader->biHeight, file);
    fclose(file);
}

void writeBMP(const char *filename, const BMPFileHeader *fileHeader, const BMPInfoHeader *infoHeader, RGB *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error writing file");
        exit(EXIT_FAILURE);
    }
    
    fwrite(fileHeader, sizeof(BMPFileHeader), 1, file);
    fwrite(infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fwrite(pixels, sizeof(RGB), infoHeader->biWidth * infoHeader->biHeight, file);
    fclose(file);
}

void printUsage() {
    printf("Usage: ./image_processor <input_bmp> <output_bmp> <brightness> <flip>\n");
    printf("  <input_bmp>      : Input BMP file to process.\n");
    printf("  <output_bmp>     : Output BMP file name.\n");
    printf("  <brightness>     : Brightness adjustment (-255 to +255).\n");
    printf("  <flip>           : 1 to flip vertically, 0 to skip flip.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage();
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    int brightness = atoi(argv[3]);
    int flip = atoi(argv[4]);

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    RGB *pixels = NULL;

    readBMP(inputFile, &fileHeader, &infoHeader, &pixels);
    
    if (flip) {
        flipImageVertically(pixels, infoHeader.biWidth, infoHeader.biHeight);
    }

    adjustBrightness(pixels, infoHeader.biWidth, infoHeader.biHeight, brightness);
    
    writeBMP(outputFile, &fileHeader, &infoHeader, pixels);

    free(pixels);
    printf("Image processing completed successfully!\n");
    return 0;
}