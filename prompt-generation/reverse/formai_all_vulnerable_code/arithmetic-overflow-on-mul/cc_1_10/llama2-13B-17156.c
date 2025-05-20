//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define BITS_PER_PIXEL 32
#define COLORS 256

typedef struct {
    char *data;
    int width;
    int height;
} image_t;

void load_image(image_t *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    image->width = (int)ftell(file);
    image->height = (int)ftell(file) / WIDTH * HEIGHT;

    image->data = malloc(image->width * image->height * BITS_PER_PIXEL / 8);
    if (!image->data) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(file);
        return;
    }

    fseek(file, 0, SEEK_SET);
    fread(image->data, 1, image->width * image->height * BITS_PER_PIXEL / 8, file);
    fclose(file);
}

void save_image(image_t *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fwrite(image->data, 1, image->width * image->height * BITS_PER_PIXEL / 8, file);
    fclose(file);
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int stepx = x1 < x2 ? 1 : 0;
    int stepy = y1 < y2 ? 1 : 0;

    for (int i = 0; i < abs(dx); i++) {
        for (int j = 0; j < abs(dy); j++) {
            int px = x1 + (stepx * i);
            int py = y1 + (stepy * j);
            image->data[((px * WIDTH + py * HEIGHT) * BITS_PER_PIXEL) / 8] =
                    (px * WIDTH + py * HEIGHT) % 2 == 0 ? 0 : 255;
        }
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height) {
    draw_line(image, x, y, x + width, y);
    draw_line(image, x, y + height, x + width, y + height);
    draw_line(image, x, y, x, y + height);
    draw_line(image, x + width, y, x + width, y + height);
}

void draw_circle(image_t *image, int x, int y, int radius) {
    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;

    draw_line(image, x1, y1, x2, y2);
    draw_line(image, x1, y2, x2, y1);
}

void main() {
    image_t image;
    load_image(&image, "example.bmp");

    draw_rectangle(&image, 100, 100, 300, 300);
    draw_circle(&image, 200, 200, 150);

    save_image(&image, "output.bmp");
}