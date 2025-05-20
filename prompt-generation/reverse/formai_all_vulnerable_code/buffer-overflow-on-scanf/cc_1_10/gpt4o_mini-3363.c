//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

#pragma pack(pop)

void invertImage(RGB *data, int height, int width) {
    for (int i = 0; i < height * width; i++) {
        data[i].red = 255 - data[i].red;
        data[i].green = 255 - data[i].green;
        data[i].blue = 255 - data[i].blue;
    }
}

void convertToGrayscale(RGB *data, int height, int width) {
    for (int i = 0; i < height * width; i++) {
        uint8_t gray = (data[i].red + data[i].green + data[i].blue) / 3;
        data[i].red = gray;
        data[i].green = gray;
        data[i].blue = gray;
    }
}

int loadBMP(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, RGB **pixelData) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return 0;
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (fileHeader->bfType != 0x4D42) {
        fclose(file);
        return 0;
    }

    int width = infoHeader->biWidth;
    int height = infoHeader->biHeight;
    int padding = (4 - (width * sizeof(RGB)) % 4) % 4;

    *pixelData = (RGB *)malloc(height * width * sizeof(RGB));
    fseek(file, fileHeader->bfOffBits, SEEK_SET);

    for (int i = 0; i < height; i++) {
        fread((*pixelData) + (i * width), sizeof(RGB), width, file);
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);
    return 1;
}

int saveBMP(const char *filename, BITMAPFILEHEADER fileHeader, BITMAPINFOHEADER infoHeader, RGB *pixelData) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return 0;
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    int padding = (4 - (infoHeader.biWidth * sizeof(RGB)) % 4) % 4;

    for (int i = 0; i < infoHeader.biHeight; i++) {
        fwrite(pixelData + (i * infoHeader.biWidth), sizeof(RGB), infoHeader.biWidth, file);
        for (int j = 0; j < padding; j++) {
            fputc(0, file);
        }
    }

    fclose(file);
    return 1;
}

void displayMenu() {
    printf("Simple BMP Image Editor\n");
    printf("1. Invert Colors\n");
    printf("2. Convert to Grayscale\n");
    printf("3. Quit\n");
    printf("Choose an option: ");
}

int main() {
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    RGB *pixelData = NULL;

    char inputFile[100], outputFile[100];
    printf("Enter input BMP filename: ");
    scanf("%s", inputFile);

    if (!loadBMP(inputFile, &fileHeader, &infoHeader, &pixelData)) {
        printf("Error loading BMP file.\n");
        return 1;
    }

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invertImage(pixelData, infoHeader.biHeight, infoHeader.biWidth);
                printf("Colors inverted. Enter output filename: ");
                break;
            case 2:
                convertToGrayscale(pixelData, infoHeader.biHeight, infoHeader.biWidth);
                printf("Converted to grayscale. Enter output filename: ");
                break;
            case 3:
                break;
            default:
                printf("Invalid option. Please try again.\n");
                continue;
        }

        scanf("%s", outputFile);
        if (!saveBMP(outputFile, fileHeader, infoHeader, pixelData)) {
            printf("Error saving BMP file.\n");
            free(pixelData);
            return 1;
        }
        printf("File saved successfully.\n");

    } while (choice != 3);

    free(pixelData);
    return 0;
}