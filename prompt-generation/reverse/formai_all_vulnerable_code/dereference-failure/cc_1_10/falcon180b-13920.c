//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define IMAGE_SIZE WIDTH * HEIGHT
#define WATERMARK_SIZE 32
#define ALPHA 0.5

typedef struct {
    int r, g, b;
} RGB;

RGB *loadImage(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error loading image.\n");
        exit(1);
    }

    RGB *image = (RGB *) malloc(IMAGE_SIZE * sizeof(RGB));
    fread(image, sizeof(RGB), IMAGE_SIZE, fp);
    fclose(fp);

    return image;
}

void saveImage(char *filename, RGB *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error saving image.\n");
        exit(1);
    }

    fwrite(image, sizeof(RGB), IMAGE_SIZE, fp);
    fclose(fp);
}

void applyWatermark(RGB *image, RGB *watermark) {
    int i, j, k;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int index = i * WIDTH + j;
            RGB *pixel = &image[index];
            RGB *watermarkPixel = &watermark[j % WATERMARK_SIZE];

            pixel->r = pixel->r * (1 - ALPHA) + watermarkPixel->r * ALPHA;
            pixel->g = pixel->g * (1 - ALPHA) + watermarkPixel->g * ALPHA;
            pixel->b = pixel->b * (1 - ALPHA) + watermarkPixel->b * ALPHA;
        }
    }
}

int main() {
    RGB *image = loadImage("image.bmp");
    RGB *watermark = (RGB *) malloc(WATERMARK_SIZE * sizeof(RGB));

    watermark[0].r = 255;
    watermark[0].g = 0;
    watermark[0].b = 0;

    applyWatermark(image, watermark);

    saveImage("watermarked_image.bmp", image);

    free(image);
    free(watermark);

    return 0;
}