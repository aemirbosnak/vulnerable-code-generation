//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 400
#define NUM_PIXELS (WIDTH * HEIGHT)
#define NUM_COLORS 8

typedef struct {
    int x;
    int y;
    int color;
} Pixel;

Pixel* generatePixels(void) {
    Pixel* pixels = (Pixel*) malloc(NUM_PIXELS * sizeof(Pixel));

    srand(time(NULL));
    for (int i = 0; i < NUM_PIXELS; ++i) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int color = rand() % NUM_COLORS;

        pixels[i].x = x;
        pixels[i].y = y;
        pixels[i].color = color;
    }

    return pixels;
}

void printPixels(Pixel* pixels, int numPixels) {
    for (int i = 0; i < numPixels; ++i) {
        Pixel pixel = pixels[i];

        int x = pixel.x;
        int y = pixel.y;
        int color = pixel.color;

        printf("Pixel %d: (%d, %d) - Color %d\n", i + 1, x, y, color);
    }
}

int main(void) {
    Pixel* pixels = generatePixels();
    printPixels(pixels, NUM_PIXELS);

    free(pixels);

    return 0;
}