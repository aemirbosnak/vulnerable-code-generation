//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int biXpelsPerMeter;
    int biYpelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

#pragma pack(pop)

void embedMessage(RGB *pixels, const char *message, int width, int height) {
    int messageLength = strlen(message);
    int pixelCount = width * height;

    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            if (i * 8 + j >= pixelCount * 3) {
                printf("Message is too long to be embedded in the image.\n");
                return;
            }

            int pixelIndex = (i * 8 + j) / 3;
            int colorIndex = (i * 8 + j) % 3;

            if (colorIndex == 0) { // Red
                pixels[pixelIndex].red = (pixels[pixelIndex].red & ~1) | ((message[i] >> (7 - j)) & 1);
            } else if (colorIndex == 1) { // Green
                pixels[pixelIndex].green = (pixels[pixelIndex].green & ~1) | ((message[i] >> (7 - j)) & 1);
            } else { // Blue
                pixels[pixelIndex].blue = (pixels[pixelIndex].blue & ~1) | ((message[i] >> (7 - j)) & 1);
            }
        }
    }
}

void saveBMP(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, RGB *pixels) {
    FILE *file = fopen(filename, "wb");
    fwrite(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixels, sizeof(RGB), infoHeader->biWidth * infoHeader->biHeight, file);
    fclose(file);
}

void readBMP(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, RGB **pixels) {
    FILE *file = fopen(filename, "rb");
    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    int pixelCount = infoHeader->biWidth * infoHeader->biHeight;
    *pixels = (RGB *)malloc(pixelCount * sizeof(RGB));
    fread(*pixels, sizeof(RGB), pixelCount, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.bmp> <output.bmp> <message>\n", argv[0]);
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    RGB *pixels;

    readBMP(argv[1], &fileHeader, &infoHeader, &pixels);
    embedMessage(pixels, argv[3], infoHeader.biWidth, infoHeader.biHeight);
    saveBMP(argv[2], &fileHeader, &infoHeader, pixels);

    free(pixels);
    printf("Message embedded successfully! Check the output image: %s\n", argv[2]);
    return 0;
}