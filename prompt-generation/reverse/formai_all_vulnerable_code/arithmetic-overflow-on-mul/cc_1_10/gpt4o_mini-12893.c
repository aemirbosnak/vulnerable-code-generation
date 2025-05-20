//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;
#pragma pack(pop)

void flipImage(const char* inputFileName, const char* outputFileName) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    if (fileHeader.bfType != 'MB') {
        printf("Not a BMP file.\n");
        fclose(inputFile);
        return;
    }

    RGB *pixelData = malloc(infoHeader.biWidth * infoHeader.biHeight * sizeof(RGB));
    fseek(inputFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, sizeof(RGB), infoHeader.biWidth * infoHeader.biHeight, inputFile);
    fclose(inputFile);

    // Flip the image
    RGB *flippedData = malloc(infoHeader.biWidth * infoHeader.biHeight * sizeof(RGB));
    for (int y = 0; y < infoHeader.biHeight; y++) {
        for (int x = 0; x < infoHeader.biWidth; x++) {
            flippedData[y * infoHeader.biWidth + (infoHeader.biWidth - x - 1)] = pixelData[y * infoHeader.biWidth + x];
        }
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fseek(outputFile, fileHeader.bfOffBits, SEEK_SET);
    fwrite(flippedData, sizeof(RGB), infoHeader.biWidth * infoHeader.biHeight, outputFile);
    
    free(pixelData);
    free(flippedData);
    fclose(outputFile);
}

void adjustBrightness(const char* inputFileName, const char* outputFileName, int brightness) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    if (fileHeader.bfType != 'MB') {
        printf("Not a BMP file.\n");
        fclose(inputFile);
        return;
    }

    RGB *pixelData = malloc(infoHeader.biWidth * infoHeader.biHeight * sizeof(RGB));
    fseek(inputFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, sizeof(RGB), infoHeader.biWidth * infoHeader.biHeight, inputFile);
    fclose(inputFile);

    // Adjust brightness
    for (int i = 0; i < infoHeader.biWidth * infoHeader.biHeight; i++) {
        int newRed = pixelData[i].red + brightness;
        int newGreen = pixelData[i].green + brightness;
        int newBlue = pixelData[i].blue + brightness;

        pixelData[i].red = (newRed > 255) ? 255 : (newRed < 0) ? 0 : newRed;
        pixelData[i].green = (newGreen > 255) ? 255 : (newGreen < 0) ? 0 : newGreen;
        pixelData[i].blue = (newBlue > 255) ? 255 : (newBlue < 0) ? 0 : newBlue;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fseek(outputFile, fileHeader.bfOffBits, SEEK_SET);
    fwrite(pixelData, sizeof(RGB), infoHeader.biWidth * infoHeader.biHeight, outputFile);

    free(pixelData);
    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input.bmp> <output_flipped.bmp> <output_brightness.bmp> <brightness_value>\n", argv[0]);
        return 1;
    }

    flipImage(argv[1], argv[2]);
    int brightness = atoi(argv[4]);
    adjustBrightness(argv[1], argv[3], brightness);

    return 0;
}