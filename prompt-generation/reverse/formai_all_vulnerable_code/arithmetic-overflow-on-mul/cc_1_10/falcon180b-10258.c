//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char r, g, b;
} Pixel;

Pixel* loadImage(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open image file.\n");
        exit(1);
    }

    int width, height, channels;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&channels, sizeof(int), 1, fp);

    if (channels!= 3) {
        printf("Error: Image must have 3 channels (RGB).\n");
        exit(1);
    }

    Pixel* pixels = (Pixel*)malloc(sizeof(Pixel) * width * height);
    fread(pixels, sizeof(Pixel), width * height, fp);

    fclose(fp);

    return pixels;
}

void saveImage(const char* filename, Pixel* pixels, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Failed to open output file.\n");
        exit(1);
    }

    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(&pixels, sizeof(Pixel), width * height, fp);

    fclose(fp);
}

void hideMessage(Pixel* pixels, int width, int height, const char* message) {
    int messageLength = strlen(message);
    int pixelIndex = 0;

    for (int i = 0; i < messageLength; ++i) {
        char c = message[i];
        int value = c - 'a' + 1;

        if (value <= 0 || value > 26) {
            value = 1;
        }

        for (int j = 0; j < 3; ++j) {
            int channelValue = value * (j + 1);
            if (channelValue > 255) {
                channelValue = 255;
            }

            pixels[pixelIndex].r = channelValue;
            pixels[pixelIndex].g = channelValue;
            pixels[pixelIndex].b = channelValue;

            ++pixelIndex;
        }
    }
}

void main() {
    Pixel* pixels = loadImage("input.bmp");
    int width = WIDTH;
    int height = HEIGHT;

    hideMessage(pixels, width, height, "Hello, world!");

    saveImage("output.bmp", pixels, width, height);
}