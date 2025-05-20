//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
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

void flipImageVertically(RGB **image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            RGB temp = image[i][j];
            image[i][j] = image[height - i - 1][j];
            image[height - i - 1][j] = temp;
        }
    }
}

void flipImageHorizontally(RGB **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            RGB temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

void changeBrightness(RGB **image, int width, int height, int value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].red = (image[i][j].red + value > 255) ? 255 : (image[i][j].red + value < 0) ? 0 : image[i][j].red + value;
            image[i][j].green = (image[i][j].green + value > 255) ? 255 : (image[i][j].green + value < 0) ? 0 : image[i][j].green + value;
            image[i][j].blue = (image[i][j].blue + value > 255) ? 255 : (image[i][j].blue + value < 0) ? 0 : image[i][j].blue + value;
        }
    }
}

void changeContrast(RGB **image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].red = (factor * (image[i][j].red - 128) + 128);
            image[i][j].green = (factor * (image[i][j].green - 128) + 128);
            image[i][j].blue = (factor * (image[i][j].blue - 128) + 128);
            // Ensure the values are within [0, 255]
            image[i][j].red = (image[i][j].red < 0) ? 0 : (image[i][j].red > 255) ? 255 : image[i][j].red;
            image[i][j].green = (image[i][j].green < 0) ? 0 : (image[i][j].green > 255) ? 255 : image[i][j].green;
            image[i][j].blue = (image[i][j].blue < 0) ? 0 : (image[i][j].blue > 255) ? 255 : image[i][j].blue;
        }
    }
}

RGB** loadBMP(const char* filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return NULL;
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    int width = infoHeader->biWidth;
    int height = infoHeader->biHeight;
    int padding = (4 - (width * sizeof(RGB)) % 4) % 4;

    RGB **image = (RGB **)malloc(height * sizeof(RGB *));
    for (int i = 0; i < height; i++) {
        image[i] = (RGB *)malloc(width * sizeof(RGB));
        fread(image[i], sizeof(RGB), width, file);
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);
    return image;
}

void saveBMP(const char* filename, BITMAPFILEHEADER fileHeader, BITMAPINFOHEADER infoHeader, RGB **image) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return;
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;
    int padding = (4 - (width * sizeof(RGB)) % 4) % 4;

    for (int i = 0; i < height; i++) {
        fwrite(image[i], sizeof(RGB), width, file);
        for (int p = 0; p < padding; p++)
            fputc(0, file);
    }

    fclose(file);
}

void freeImage(RGB **image, int height) {
    for (int i = 0; i < height; i++)
        free(image[i]);
    free(image);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    RGB **image = loadBMP(argv[1], &fileHeader, &infoHeader);
    if (!image) return 1;

    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    changeBrightness(image, infoHeader.biWidth, infoHeader.biHeight, brightness);
    changeContrast(image, infoHeader.biWidth, infoHeader.biHeight, contrast);

    // Flip image for fun
    flipImageVertically(image, infoHeader.biWidth, infoHeader.biHeight);

    saveBMP(argv[2], fileHeader, infoHeader, image);
    freeImage(image, infoHeader.biHeight);

    return 0;
}