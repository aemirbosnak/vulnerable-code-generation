//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define NUM_COLORS 256

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel *generatePixels(int width, int height) {
    Pixel *pixels = (Pixel *)malloc(sizeof(Pixel) * width * height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int distance = sqrt(pow(x - width / 2, 2) + pow(y - height / 2, 2));
            int angle = atan2(y - height / 2, x - width / 2);
            int hue = (int)(255 * distance / (height / 2));
            int saturation = (int)(255 * cos(angle * M_PI / 180));
            int value = (int)(255 * sin(angle * M_PI / 180));

            pixels[y * width + x].r = hue;
            pixels[y * width + x].g = saturation;
            pixels[y * width + x].b = value;
        }
    }

    return pixels;
}

void savePixelsAsImage(Pixel *pixels, int width, int height, char *filename) {
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fprintf(fp, "%d %d %d ", pixels[y * width + x].r, pixels[y * width + x].g, pixels[y * width + x].b);
        }
    }

    fclose(fp);
}

int main() {
    Pixel *pixels = generatePixels(WIDTH, HEIGHT);
    savePixelsAsImage(pixels, WIDTH, HEIGHT, "pixel_art.png");

    free(pixels);

    return 0;
}