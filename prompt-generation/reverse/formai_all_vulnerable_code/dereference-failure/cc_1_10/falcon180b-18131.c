//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define PI 3.14159265358979323846
#define WATERMARK_SIZE 64
#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

typedef struct {
    int *data;
    int width;
    int height;
} Image;

void generateWatermark(Image *watermark) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark->data[i] = rand() % 256;
    }
}

void addWatermark(Image *image, Image *watermark) {
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
        int x = i % IMAGE_WIDTH;
        int y = i / IMAGE_WIDTH;
        int w = x / WATERMARK_SIZE;
        int h = y / WATERMARK_SIZE;
        int offset = (h * WATERMARK_SIZE) + w;
        image->data[i] += watermark->data[offset];
    }
}

void saveImage(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fwrite(image->data, sizeof(int), IMAGE_WIDTH * IMAGE_HEIGHT, fp);
    fclose(fp);
}

void loadImage(Image *image, char *filename) {
    FILE *fp = fopen(filename, "rb");
    fread(image->data, sizeof(int), IMAGE_WIDTH * IMAGE_HEIGHT, fp);
    fclose(fp);
}

int main() {
    srand(time(NULL));

    Image watermark;
    generateWatermark(&watermark);

    Image image;
    loadImage(&image, "image.raw");

    addWatermark(&image, &watermark);

    saveImage(&image, "watermarked_image.raw");

    return 0;
}