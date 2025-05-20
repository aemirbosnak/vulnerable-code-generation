//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

typedef struct ImgInfo {
    int width;
    int height;
    BYTE* pixels;
} ImgInfo;

// Helper function to read bitmap header information
void readBmpHeader(FILE* fp, ImgInfo* info) {
    fseek(fp, 18, SEEK_SET);
    fread(&info->width, sizeof(int), 1, fp);
    fread(&info->height, sizeof(int), 1, fp);
    fseek(fp, 28, SEEK_SET);
}

// Helper function to read bitmap pixel array data
void readBmpPixels(FILE* fp, ImgInfo* info) {
    fseek(fp, 54, SEEK_SET);
    int imgSize = info->width * info->height * 3;
    info->pixels = (BYTE*)malloc(imgSize);
    fread(info->pixels, sizeof(BYTE), imgSize, fp);
}

// Helper function to write bitmap file header
void writeBmpFileHeader(FILE* fp, int fileSize) {
    fseek(fp, 2, SEEK_SET);
    WORD bfType = 0x4D42;
    fwrite(&bfType, sizeof(WORD), 1, fp);
    DWORD bfSize = fileSize;
    fwrite(&bfSize, sizeof(DWORD), 1, fp);
    WORD bfReserved1 = 0;
    fwrite(&bfReserved1, sizeof(WORD), 1, fp);
    WORD bfReserved2 = 0;
    fwrite(&bfReserved2, sizeof(WORD), 1, fp);
    DWORD bfOffBits = 54;
    fwrite(&bfOffBits, sizeof(DWORD), 1, fp);
}

// Helper function to write bitmap information header
void writeBmpInfoHeader(FILE* fp, ImgInfo* info) {
    DWORD biSize = 40;
    fwrite(&biSize, sizeof(DWORD), 1, fp);
    fwrite(&info->width, sizeof(int), 1, fp);
    fwrite(&info->height, sizeof(int), 1, fp);
    WORD biPlanes = 1;
    fwrite(&biPlanes, sizeof(WORD), 1, fp);
    WORD biBitCount = 24;
    fwrite(&biBitCount, sizeof(WORD), 1, fp);
    DWORD biCompression = 0;
    fwrite(&biCompression, sizeof(DWORD), 1, fp);
    DWORD biSizeImage = info->width * info->height * 3;
    fwrite(&biSizeImage, sizeof(DWORD), 1, fp);
    int biXPelsPerMeter = 2834;
    fwrite(&biXPelsPerMeter, sizeof(int), 1, fp);
    int biYPelsPerMeter = 2834;
    fwrite(&biYPelsPerMeter, sizeof(int), 1, fp);
    DWORD biClrUsed = 0;
    fwrite(&biClrUsed, sizeof(DWORD), 1, fp);
    DWORD biClrImportant = 0;
    fwrite(&biClrImportant, sizeof(DWORD), 1, fp);
}

// Helper function to flip image horizontally
void flipHorizontal(ImgInfo* info) {
    int rowSize = info->width * 3;
    BYTE* tempRow = (BYTE*)malloc(rowSize);
    int halfHeight = info->height / 2;
    for (int i = 0; i < halfHeight; i++) {
        int topIndex = i * rowSize;
        int bottomIndex = (info->height - i - 1) * rowSize;
        memcpy(tempRow, info->pixels + topIndex, rowSize);
        memcpy(info->pixels + topIndex, info->pixels + bottomIndex, rowSize);
        memcpy(info->pixels + bottomIndex, tempRow, rowSize);
    }
    free(tempRow);
}

// Helper function to adjust brightness of an image
void adjustBrightness(ImgInfo* info, int brightness) {
    int imgSize = info->width * info->height * 3;
    for (int i = 0; i < imgSize; i += 3) {
        int r = *(info->pixels + i);
        int g = *(info->pixels + i + 1);
        int b = *(info->pixels + i + 2);
        r += brightness;
        r = (r > 255 ? 255 : (r < 0 ? 0 : r));
        g += brightness;
        g = (g > 255 ? 255 : (g < 0 ? 0 : g));
        b += brightness;
        b = (b > 255 ? 255 : (b < 0 ? 0 : b));
        *(info->pixels + i) = r;
        *(info->pixels + i + 1) = g;
        *(info->pixels + i + 2) = b;
    }
}

// Helper function to adjust contrast of an image
void adjustContrast(ImgInfo* info, double contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    int imgSize = info->width * info->height * 3;
    for (int i = 0; i < imgSize; i += 3) {
        int r = *(info->pixels + i);
        int g = *(info->pixels + i + 1);
        int b = *(info->pixels + i + 2);
        r = (int)(factor * (r - 128) + 128);
        r = (r > 255 ? 255 : (r < 0 ? 0 : r));
        g = (int)(factor * (g - 128) + 128);
        g = (g > 255 ? 255 : (g < 0 ? 0 : g));
        b = (int)(factor * (b - 128) + 128);
        b = (b > 255 ? 255 : (b < 0 ? 0 : b));
        *(info->pixels + i) = r;
        *(info->pixels + i + 1) = g;
        *(info->pixels + i + 2) = b;
    }
}

// Main function to process the image file
int main() {
    char inputFilename[MAX_FILENAME_SIZE];
    printf("Enter input filename: ");
    scanf("%s", inputFilename);
    FILE* inputFile = fopen(inputFilename, "rb");
    if (!inputFile) {
        printf("Error: could not open file %s\n", inputFilename);
        return 1;
    }
    ImgInfo info;
    readBmpHeader(inputFile, &info);
    readBmpPixels(inputFile, &info);
    fclose(inputFile);
    printf("Enter desired brightness level (-255 to 255): ");
    int brightness;
    scanf("%d", &brightness);
    adjustBrightness(&info, brightness);
    printf("Enter desired contrast level (0.1 to 10.0): ");
    double contrast;
    scanf("%lf", &contrast);
    adjustContrast(&info, contrast);
    flipHorizontal(&info);
    char outputFilename[MAX_FILENAME_SIZE];
    printf("Enter output filename: ");
    scanf("%s", outputFilename);
    FILE* outputFile = fopen(outputFilename, "wb");
    if (!outputFile) {
        printf("Error: could not open file %s\n", outputFilename);
        free(info.pixels);
        return 1;
    }
    int fileSize = info.width * info.height * 3 + 54;
    writeBmpFileHeader(outputFile, fileSize);
    writeBmpInfoHeader(outputFile, &info);
    fwrite(info.pixels, sizeof(BYTE), fileSize - 54, outputFile);
    fclose(outputFile);
    free(info.pixels);
    printf("Image processing successful!\n");
    return 0;
}