//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256
#define PIXEL_SIZE 4

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel *generate_pixels(int width, int height) {
    Pixel *pixels = malloc(sizeof(Pixel) * width * height);
    srand(time(NULL));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i * width + j].x = j;
            pixels[i * width + j].y = i;

            int color_index = rand() % MAX_COLORS;
            pixels[i * width + j].r = color_index >> 16;
            pixels[i * width + j].g = (color_index >> 8) & 0xFF;
            pixels[i * width + j].b = color_index & 0xFF;
        }
    }

    return pixels;
}

void save_bmp(const char *filename, Pixel *pixels, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    int filesize = width * height * PIXEL_SIZE;
    unsigned char header[54] = {
        0x42, 0x4D, // 'BM'
        0x36, 0x00, 0x00, 0x00, // filesize
        0x00, 0x00, 0x00, 0x00, // reserved
        0x36, 0x00, 0x00, 0x00, // offset to pixel data
        0x28, 0x00, 0x00, 0x00, // header size
        0x00, 0x00, 0x00, 0x00, // width
        0x00, 0x00, 0x00, 0x00, // height
        0x01, 0x00, 0x00, 0x00, // number of color planes
        0x18, 0x00, 0x00, 0x00, // bits per pixel
        0x00, 0x00, 0x00, 0x00, // compression method
        0x00, 0x00, 0x00, 0x00, // image size
        0x13, 0x00, 0x00, 0x00, // horizontal resolution
        0x13, 0x00, 0x00, 0x00, // vertical resolution
        0x00, 0x00, 0x00, 0x00, // number of colors
        0x00, 0x00, 0x00, 0x00 // number of important colors
    };

    fwrite(header, 1, 54, fp);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * width + j;
            fwrite(&pixels[index].r, PIXEL_SIZE, 1, fp);
        }
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    Pixel *pixels = generate_pixels(width, height);
    save_bmp("pixel_art.bmp", pixels, width, height);

    free(pixels);

    return 0;
}