//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    uint8_t* pixels;
} Image;

Image* create_image(int width, int height) {
    Image* image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(uint8_t));
    return image;
}

void destroy_image(Image* image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image* image, int x, int y, uint8_t value) {
    image->pixels[x + y * image->width] = value;
}

uint8_t get_pixel(Image* image, int x, int y) {
    return image->pixels[x + y * image->width];
}

void set_region(Image* image, int x, int y, int width, int height, uint8_t value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            set_pixel(image, x + j, y + i, value);
        }
    }
}

void draw_rectangle(Image* image, int x, int y, int width, int height, uint8_t value) {
    set_region(image, x, y, width, height, value);
    set_region(image, x, y + height - 1, width, height, value);
    set_region(image, x + width - 1, y, width, height, value);
    set_region(image, x + width - 1, y + height - 1, width, height, value);
}

void draw_circle(Image* image, int x, int y, int radius, uint8_t value) {
    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius; j++) {
            if (i * i + j * j <= radius * radius) {
                set_pixel(image, x + i, y + j, value);
            }
        }
    }
}

void draw_line(Image* image, int x1, int y1, int x2, int y2, uint8_t value) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (true) {
        set_pixel(image, x1, y1, value);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_ellipse(Image* image, int x, int y, int width, int height, uint8_t value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (pow((j - width / 2.0), 2) / pow(width / 2.0, 2) + pow((i - height / 2.0), 2) / pow(height / 2.0, 2) <= 1.0) {
                set_pixel(image, x + j, y + i, value);
            }
        }
    }
}

void draw_image(Image* image, int x, int y, Image* sub_image) {
    for (int i = 0; i < sub_image->height; i++) {
        for (int j = 0; j < sub_image->width; j++) {
            set_pixel(image, x + j, y + i, get_pixel(sub_image, j, i));
        }
    }
}

int main() {
    Image* image = create_image(1000, 1000);

    draw_rectangle(image, 100, 100, 200, 200, 255);
    draw_circle(image, 500, 500, 100, 255);
    draw_line(image, 100, 100, 500, 500, 255);
    draw_ellipse(image, 100, 500, 200, 100, 255);

    Image* sub_image = create_image(50, 50);
    draw_circle(sub_image, 25, 25, 25, 255);
    draw_image(image, 100, 100, sub_image);

    destroy_image(image);
    destroy_image(sub_image);

    return 0;
}