//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_PIXELS (WIDTH * HEIGHT)

typedef struct {
    double x, y;
    int r, g, b;
} Pixel;

void init_pixels(Pixel* pixels) {
    for (int i = 0; i < MAX_PIXELS; i++) {
        pixels[i].x = rand() % WIDTH;
        pixels[i].y = rand() % HEIGHT;
        pixels[i].r = rand() % 256;
        pixels[i].g = rand() % 256;
        pixels[i].b = rand() % 256;
    }
}

void draw_pixels(Pixel* pixels, int num_pixels) {
    for (int i = 0; i < num_pixels; i++) {
        printf("%d,%d,%d\n", pixels[i].r, pixels[i].g, pixels[i].b);
    }
}

int main() {
    srand(time(NULL));

    Pixel* pixels = malloc(MAX_PIXELS * sizeof(Pixel));
    init_pixels(pixels);

    int num_pixels = WIDTH * HEIGHT / 2;
    Pixel* new_pixels = malloc(num_pixels * sizeof(Pixel));

    for (int i = 0; i < num_pixels; i++) {
        int index = rand() % MAX_PIXELS;
        new_pixels[i].x = pixels[index].x;
        new_pixels[i].y = pixels[index].y;
        new_pixels[i].r = pixels[index].r;
        new_pixels[i].g = pixels[index].g;
        new_pixels[i].b = pixels[index].b;
    }

    draw_pixels(new_pixels, num_pixels);

    free(pixels);
    free(new_pixels);

    return 0;
}