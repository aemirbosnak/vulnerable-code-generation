//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define SIZE (WIDTH * HEIGHT)
#define BLOCK_SIZE 8
#define NUM_BLOCKS (SIZE / BLOCK_SIZE)
#define PIXEL_VALUE_RANGE 256
#define MAX_WATERMARK_SIZE (BLOCK_SIZE * BLOCK_SIZE)

typedef struct {
    int x, y;
} Point;

typedef struct {
    int value;
    int x, y;
} Pixel;

typedef struct {
    int size;
    Pixel pixels[MAX_WATERMARK_SIZE];
} Watermark;

void generateWatermark(Watermark* watermark) {
    int i;
    for (i = 0; i < watermark->size; i++) {
        watermark->pixels[i].value = rand() % PIXEL_VALUE_RANGE;
        watermark->pixels[i].x = rand() % BLOCK_SIZE;
        watermark->pixels[i].y = rand() % BLOCK_SIZE;
    }
}

void embedWatermark(Watermark* watermark, Pixel* image) {
    int x, y, i;
    for (i = 0; i < watermark->size; i++) {
        x = watermark->pixels[i].x;
        y = watermark->pixels[i].y;
        image[y * WIDTH + x].value += watermark->pixels[i].value;
    }
}

void extractWatermark(Watermark* watermark, Pixel* image) {
    int i;
    for (i = 0; i < watermark->size; i++) {
        watermark->pixels[i].value = image[watermark->pixels[i].y * WIDTH + watermark->pixels[i].x].value;
    }
}

int main() {
    Watermark watermark;
    Pixel image[SIZE];

    generateWatermark(&watermark);
    printf("Watermark generated.\n");

    embedWatermark(&watermark, image);
    printf("Watermark embedded.\n");

    extractWatermark(&watermark, image);
    printf("Watermark extracted.\n");

    return 0;
}