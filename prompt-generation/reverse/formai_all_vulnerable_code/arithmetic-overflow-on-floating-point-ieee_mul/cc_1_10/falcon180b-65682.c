//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256
#define MAX_PIXELS (WIDTH * HEIGHT)
#define PIXEL_SIZE 4

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

int main() {
    srand(time(NULL));

    Pixel *pixels = (Pixel *)malloc(MAX_PIXELS * sizeof(Pixel));
    int num_pixels = 0;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int distance = sqrt(pow(x - WIDTH / 2, 2) + pow(y - HEIGHT / 2, 2));
            int angle = atan2(y - HEIGHT / 2, x - WIDTH / 2);

            int r = (int)(255 * cos(angle));
            int g = (int)(255 * sin(angle));
            int b = (int)(255 * (1 - distance / (double)HEIGHT / 2));

            pixels[num_pixels].x = x;
            pixels[num_pixels].y = y;
            pixels[num_pixels].r = r;
            pixels[num_pixels].g = g;
            pixels[num_pixels].b = b;

            num_pixels++;
        }
    }

    FILE *fp = fopen("pixel_art.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    fwrite("BM", 2, 1, fp);
    fwrite(&(int){0}, 4, 1, fp);
    fwrite(&(int){WIDTH}, 4, 1, fp);
    fwrite(&(int){HEIGHT}, 4, 1, fp);
    fwrite(&(int){1}, 2, 1, fp);
    fwrite(&(int){24}, 4, 1, fp);

    for (int y = HEIGHT - 1; y >= 0; y--) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;

            int r = pixels[index].r;
            int g = pixels[index].g;
            int b = pixels[index].b;

            fwrite(&b, 1, 1, fp);
            fwrite(&g, 1, 1, fp);
            fwrite(&r, 1, 1, fp);
        }
    }

    fclose(fp);

    free(pixels);

    return 0;
}