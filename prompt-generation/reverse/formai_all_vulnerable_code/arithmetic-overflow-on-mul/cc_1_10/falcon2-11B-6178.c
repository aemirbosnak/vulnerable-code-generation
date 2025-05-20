//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PIXEL_VALUE 255
#define MIN_PIXEL_VALUE 0

typedef struct {
    unsigned char r, g, b;
} Pixel;

void readImage(const char* filename, Pixel** image, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fread(*image, sizeof(Pixel), *width * *height, fp);
    fclose(fp);

    *width = *height = (int)sqrt(*width * *height);
}

void flipImage(Pixel* image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Pixel p = image[i * width + j];
            image[i * width + j].r = MAX_PIXEL_VALUE - p.r;
            image[i * width + j].g = MAX_PIXEL_VALUE - p.g;
            image[i * width + j].b = MAX_PIXEL_VALUE - p.b;
        }
    }
}

void adjustBrightness(Pixel* image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Pixel p = image[i * width + j];
            double brightness = (double)p.r + (double)p.g + (double)p.b;
            double factor = 1.5;
            p.r = MAX_PIXEL_VALUE - (int)(factor * (brightness / 255));
            p.g = MAX_PIXEL_VALUE - (int)(factor * (brightness / 255));
            p.b = MAX_PIXEL_VALUE - (int)(factor * (brightness / 255));
        }
    }
}

void applyFilter(Pixel* image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Pixel p = image[i * width + j];
            p.r = MAX_PIXEL_VALUE - (int)(0.5 * (p.r - (MAX_PIXEL_VALUE / 2)));
            p.g = MAX_PIXEL_VALUE - (int)(0.5 * (p.g - (MAX_PIXEL_VALUE / 2)));
            p.b = MAX_PIXEL_VALUE - (int)(0.5 * (p.b - (MAX_PIXEL_VALUE / 2)));
        }
    }
}

void writeImage(const char* filename, Pixel* image, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fwrite(image, sizeof(Pixel), width * height, fp);
    fclose(fp);
}

int main() {
    Pixel image[200][200]; // Assuming a 200x200 image
    int width, height;

    readImage("input.bmp", image, &width, &height);

    flipImage(image, width, height);
    adjustBrightness(image, width, height);
    applyFilter(image, width, height);

    writeImage("output.bmp", image, width, height);

    return 0;
}