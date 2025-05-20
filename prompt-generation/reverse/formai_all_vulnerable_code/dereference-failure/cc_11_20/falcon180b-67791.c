//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define NUM_PIXELS (WIDTH * HEIGHT)

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    double r;
    double g;
    double b;
} Color;

int main() {
    Color* image = (Color*)malloc(NUM_PIXELS * sizeof(Color));
    Color* watermark = (Color*)malloc(NUM_PIXELS * sizeof(Color));

    int i, j;
    for (i = 0; i < NUM_PIXELS; i++) {
        image[i].r = rand() % 256;
        image[i].g = rand() % 256;
        image[i].b = rand() % 256;
    }

    for (i = 0; i < NUM_PIXELS; i++) {
        watermark[i].r = 255;
        watermark[i].g = 255;
        watermark[i].b = 255;
    }

    for (i = 0; i < NUM_PIXELS; i++) {
        if (i % 16 == 0 && i % 32!= 0) {
            watermark[i].r = 0;
            watermark[i].g = 0;
            watermark[i].b = 0;
        }
    }

    for (i = 0; i < NUM_PIXELS; i++) {
        image[i].r = (image[i].r + watermark[i].r) / 2;
        image[i].g = (image[i].g + watermark[i].g) / 2;
        image[i].b = (image[i].b + watermark[i].b) / 2;
    }

    for (i = 0; i < NUM_PIXELS; i++) {
        if (image[i].r > 127) {
            image[i].r = 255;
        } else {
            image[i].r = 0;
        }
        if (image[i].g > 127) {
            image[i].g = 255;
        } else {
            image[i].g = 0;
        }
        if (image[i].b > 127) {
            image[i].b = 255;
        } else {
            image[i].b = 0;
        }
    }

    for (i = 0; i < NUM_PIXELS; i++) {
        printf("%d %d %d\n", image[i].r, image[i].g, image[i].b);
    }

    free(image);
    free(watermark);

    return 0;
}