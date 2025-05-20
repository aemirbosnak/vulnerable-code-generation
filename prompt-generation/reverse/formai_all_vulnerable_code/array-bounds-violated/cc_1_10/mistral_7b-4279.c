//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_COLOR 16

typedef struct Pixel {
    unsigned char r, g, b;
} Pixel;

Pixel palette[MAX_COLOR];
Pixel image[WIDTH][HEIGHT];

void set_color(unsigned int index, unsigned char r, unsigned char g, unsigned char b) {
    palette[index].r = r;
    palette[index].g = g;
    palette[index].b = b;
}

void put_pixel(int x, int y, unsigned int color) {
    image[x][y] = palette[color];
}

void line(int x1, int y1, int x2, int y2, unsigned int color) {
    int dx, dy, sign_x, sign_y, error;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    sign_x = x1 < x2 ? 1 : -1;
    sign_y = y1 < y2 ? 1 : -1;

    x1 = x1 < x2 ? x1 : x2;
    y1 = y1 < y2 ? y1 : y2;

    put_pixel(x1, y1, color);

    error = (dx > dy ? dx : -dy) / 2;

    while (x1 != x2 || y1 != y2) {
        put_pixel(x1, y1, color);

        if (x1 == x2) {
            y1 += sign_y;
        }

        if (y1 == y2) {
            x1 += sign_x;
        }

        if (abs(dx - dy) * error > -dx / 2) {
            x1 += sign_x;
            error += dy;
        } else {
            y1 += sign_y;
            error += dx;
        }
    }
}

int main() {
    int i;

    set_color(0, 255, 0, 0);
    set_color(1, 0, 255, 0);

    for (i = 0; i < WIDTH * HEIGHT; i++) {
        image[i / WIDTH][i % WIDTH] = (Pixel) { 0 };
    }

    line(10, 10, 30, 30, 0);
    line(35, 35, 60, 60, 1);

    for (i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%d,%d:%d,%d,%d\n", i % WIDTH, i / WIDTH, image[i / WIDTH][i % WIDTH].r, image[i / WIDTH][i % WIDTH].g, image[i / WIDTH][i % WIDTH].b);
    }

    return 0;
}