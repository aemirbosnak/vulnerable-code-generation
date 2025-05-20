//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_PIXELS (WIDTH * HEIGHT)
#define NUM_COLORS 256

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel *pixels;
int num_pixels;

void init() {
    srand(time(NULL));
    pixels = (Pixel *)malloc(MAX_PIXELS * sizeof(Pixel));
    num_pixels = 0;
}

void add_pixel(int x, int y, int r, int g, int b) {
    if (num_pixels >= MAX_PIXELS) {
        return;
    }
    pixels[num_pixels].x = x;
    pixels[num_pixels].y = y;
    pixels[num_pixels].r = r;
    pixels[num_pixels].g = g;
    pixels[num_pixels].b = b;
    num_pixels++;
}

void generate() {
    int i;
    for (i = 0; i < num_pixels; i++) {
        int x = pixels[i].x;
        int y = pixels[i].y;
        int r = pixels[i].r;
        int g = pixels[i].g;
        int b = pixels[i].b;
        printf("SetPixel(%d, %d, %d, %d, %d)\n", x, y, r, g, b);
    }
}

int main() {
    init();
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int r = rand() % NUM_COLORS;
            int g = rand() % NUM_COLORS;
            int b = rand() % NUM_COLORS;
            add_pixel(j, i, r, g, b);
        }
    }
    generate();
    return 0;
}