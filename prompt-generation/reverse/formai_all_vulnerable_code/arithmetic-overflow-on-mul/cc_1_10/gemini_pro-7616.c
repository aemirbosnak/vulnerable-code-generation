//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned char byte;

void embedWatermark(byte *image, int width, int height, byte *watermark, int wWidth, int wHeight) {
    int x, y, w, h;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (x < wWidth && y < wHeight) {
                int bit = (watermark[y * wWidth + x] & 1);
                int mask = 1 << (7 - (x % 8));
                image[y * width + x] = (image[y * width + x] & ~mask) | (bit << (7 - (x % 8)));
            }
        }
    }
}

void extractWatermark(byte *image, int width, int height, byte *watermark, int wWidth, int wHeight) {
    int x, y, w, h;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (x < wWidth && y < wHeight) {
                int bit = (image[y * width + x] >> (7 - (x % 8))) & 1;
                watermark[y * wWidth + x] = (watermark[y * wWidth + x] & ~1) | bit;
            }
        }
    }
}

int main() {
    int width, height, wWidth, wHeight;
    byte *image, *watermark;

    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);
    printf("Enter the width and height of the watermark: ");
    scanf("%d %d", &wWidth, &wHeight);

    image = (byte *) malloc(width * height);
    watermark = (byte *) malloc(wWidth * wHeight);

    printf("Enter the image data (0-255): ");
    for (int i = 0; i < width * height; i++) {
        scanf("%hhu", &image[i]);
    }

    printf("Enter the watermark data (0-1): ");
    for (int i = 0; i < wWidth * wHeight; i++) {
        scanf("%hhu", &watermark[i]);
    }

    embedWatermark(image, width, height, watermark, wWidth, wHeight);

    printf("Watermarked image: ");
    for (int i = 0; i < width * height; i++) {
        printf("%hhu ", image[i]);
    }
    printf("\n");

    extractWatermark(image, width, height, watermark, wWidth, wHeight);

    printf("Extracted watermark: ");
    for (int i = 0; i < wWidth * wHeight; i++) {
        printf("%hhu ", watermark[i]);
    }
    printf("\n");

    free(image);
    free(watermark);

    return 0;
}