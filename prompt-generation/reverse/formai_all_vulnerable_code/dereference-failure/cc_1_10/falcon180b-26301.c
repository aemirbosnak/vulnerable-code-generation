//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define PIXEL_SIZE 4
#define NUM_COLORS 16

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel *generate_pixels(int width, int height) {
    Pixel *pixels = malloc(sizeof(Pixel) * width * height);
    for (int i = 0; i < width * height; i++) {
        pixels[i].x = i % width;
        pixels[i].y = i / width;
        pixels[i].r = rand() % 256;
        pixels[i].g = rand() % 256;
        pixels[i].b = rand() % 256;
    }
    return pixels;
}

void draw_pixel(int x, int y, int r, int g, int b) {
    printf("#%02x%02x%02x", r, g, b);
}

void draw_row(Pixel *row, int width) {
    for (int i = 0; i < width; i++) {
        Pixel pixel = row[i];
        draw_pixel(pixel.x * PIXEL_SIZE, pixel.y * PIXEL_SIZE, pixel.r, pixel.g, pixel.b);
    }
}

void draw_image(Pixel *pixels, int width, int height) {
    for (int i = 0; i < height; i++) {
        Pixel *row = &pixels[i * width];
        draw_row(row, width);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Pixel *pixels = generate_pixels(WIDTH, HEIGHT);
    draw_image(pixels, WIDTH, HEIGHT);

    return 0;
}