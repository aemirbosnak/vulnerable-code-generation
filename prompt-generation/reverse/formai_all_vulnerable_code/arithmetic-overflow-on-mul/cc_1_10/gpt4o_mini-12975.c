//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)

// BMP Header structures
typedef struct {
    uint16_t bfType;      // File type
    uint32_t bfSize;      // File size in bytes
    uint16_t bfReserved1; // Reserved; must be 0
    uint16_t bfReserved2; // Reserved; must be 0
    uint32_t bfOffBits;   // Offset to the pixel data
} BMPHeader;

typedef struct {
    uint32_t biSize;         // Size of this header
    int32_t  biWidth;        // Width of the bitmap in pixels
    int32_t  biHeight;       // Height of the bitmap in pixels
    uint16_t biPlanes;       // Number of color planes
    uint16_t biBitCount;     // Bits per pixel
    uint32_t biCompression;   // Compression type
    uint32_t biSizeImage;    // Size of the image data
    int32_t  biXPelsPerMeter;  // Horizontal resolution
    int32_t  biYPelsPerMeter;  // Vertical resolution
    uint32_t biClrUsed;       // Number of colors used
    uint32_t biClrImportant;   // Number of important colors
} BMPInfoHeader;

#pragma pack(pop)

void apply_grayscale(uint8_t *pixelData, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        uint8_t r = pixelData[i * 3 + 2];
        uint8_t g = pixelData[i * 3 + 1];
        uint8_t b = pixelData[i * 3];
        uint8_t gray = (r + g + b) / 3;
        pixelData[i * 3 + 2] = gray; // R
        pixelData[i * 3 + 1] = gray; // G
        pixelData[i * 3] = gray;     // B
    }
}

void apply_invert(uint8_t *pixelData, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        pixelData[i * 3 + 2] = 255 - pixelData[i * 3 + 2]; // Invert R
        pixelData[i * 3 + 1] = 255 - pixelData[i * 3 + 1]; // Invert G
        pixelData[i * 3] = 255 - pixelData[i * 3];         // Invert B
    }
}

int read_bmp(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader, uint8_t **pixelData) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    fread(header, sizeof(BMPHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    if (header->bfType != 0x4D42) { // 'BM'
        fprintf(stderr, "Not a BMP file\n");
        fclose(file);
        return -1;
    }

    int width = infoHeader->biWidth;
    int height = infoHeader->biHeight;
    
    fseek(file, header->bfOffBits, SEEK_SET);
    
    *pixelData = malloc(width * height * 3);
    fread(*pixelData, 3, width * height, file);
    
    fclose(file);
    return 0;
}

int write_bmp(const char *filename, BMPHeader header, BMPInfoHeader infoHeader, uint8_t *pixelData) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error creating file");
        return -1;
    }

    fwrite(&header, sizeof(BMPHeader), 1, file);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    fseek(file, header.bfOffBits, SEEK_SET);
    fwrite(pixelData, 3, infoHeader.biWidth * infoHeader.biHeight, file);
    
    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> [option: grayscale/invert]\n", argv[0]);
        return 1;
    }

    BMPHeader header;
    BMPInfoHeader infoHeader;
    uint8_t *pixelData = NULL;

    if (read_bmp(argv[1], &header, &infoHeader, &pixelData) < 0) {
        return 1;
    }

    if (argc == 4 && strcmp(argv[3], "grayscale") == 0) {
        apply_grayscale(pixelData, infoHeader.biWidth, infoHeader.biHeight);
    } else if (argc == 4 && strcmp(argv[3], "invert") == 0) {
        apply_invert(pixelData, infoHeader.biWidth, infoHeader.biHeight);
    } else {
        fprintf(stderr, "Invalid option. Use 'grayscale' or 'invert'.\n");
        free(pixelData);
        return 1;
    }

    if (write_bmp(argv[2], header, infoHeader, pixelData) < 0) {
        free(pixelData);
        return 1;
    }

    free(pixelData);
    printf("Image processing complete. Saved to %s\n", argv[2]);
    return 0;
}