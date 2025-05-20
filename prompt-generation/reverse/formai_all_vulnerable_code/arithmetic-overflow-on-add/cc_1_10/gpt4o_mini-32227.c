//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char bfType[2];     // Bitmap identifier
    unsigned int bfSize;         // Size of the bitmap file
    unsigned short bfReserved1;  // Reserved, must be 0
    unsigned short bfReserved2;  // Reserved, must be 0
    unsigned int bfOffBits;      // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;         // Size of this header
    int biWidth;                 // Width of bitmap in pixels
    int biHeight;                // Height of bitmap in pixels
    unsigned short biPlanes;     // Number of color planes, must be 1
    unsigned short biBitCount;   // Number of bits per pixel
    unsigned int biCompression;   // Compression type
    unsigned int biSizeImage;    // Size of pixel data
    int biXPelsPerMeter;         // Horizontal resolution (pixels per meter)
    int biYPelsPerMeter;         // Vertical resolution (pixels per meter)
    unsigned int biClrUsed;      // Number of colors used (0 means all)
    unsigned int biClrImportant;  // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

void convertToGrayscale(const char* inputFilePath, const char* outputFilePath) {
    FILE *inputFile = fopen(inputFilePath, "rb");
    if (!inputFile) {
        perror("Unable to open input file");
        return;
    }

    BITMAPFILEHEADER bmFileHeader;
    fread(&bmFileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    if (bmFileHeader.bfType[0] != 'B' || bmFileHeader.bfType[1] != 'M') {
        fclose(inputFile);
        fprintf(stderr, "Not a valid BMP file.\n");
        return;
    }

    BITMAPINFOHEADER bmInfoHeader;
    fread(&bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    if (bmInfoHeader.biBitCount != 24) {
        fclose(inputFile);
        fprintf(stderr, "Only 24-bit BMP images are supported.\n");
        return;
    }

    fseek(inputFile, bmFileHeader.bfOffBits, SEEK_SET);
    int rowSize = (bmInfoHeader.biWidth * 3 + 3) & (~3);
    unsigned char *pixelData = malloc(rowSize * bmInfoHeader.biHeight);
    fread(pixelData, rowSize, bmInfoHeader.biHeight, inputFile);
    fclose(inputFile);

    for (int y = 0; y < bmInfoHeader.biHeight; y++) {
        for (int x = 0; x < bmInfoHeader.biWidth; x++) {
            unsigned char *pixel = pixelData + (rowSize * y + x * 3);
            unsigned char gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
            pixel[0] = gray; // Blue
            pixel[1] = gray; // Green
            pixel[2] = gray; // Red
        }
    }

    FILE *outputFile = fopen(outputFilePath, "wb");
    if (!outputFile) {
        perror("Unable to open output file");
        free(pixelData);
        return;
    }

    fwrite(&bmFileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fwrite(pixelData, rowSize, bmInfoHeader.biHeight, outputFile);
    fclose(outputFile);
    free(pixelData);
    
    printf("Converted image to grayscale and saved as %s\n", outputFilePath);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return 1;
    }

    convertToGrayscale(argv[1], argv[2]);
    return 0;
}