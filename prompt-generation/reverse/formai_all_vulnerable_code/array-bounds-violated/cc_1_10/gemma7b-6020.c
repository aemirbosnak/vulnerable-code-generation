//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

typedef struct Pixel {
    int x, y, r, g, b;
} Pixel;

Pixel pixels[MAX_WIDTH * MAX_HEIGHT];

void draw_pixel(int x, int y, int r, int g, int b) {
    pixels[x * MAX_WIDTH + y].x = x;
    pixels[x * MAX_WIDTH + y].y = y;
    pixels[x * MAX_WIDTH + y].r = r;
    pixels[x * MAX_WIDTH + y].g = g;
    pixels[x * MAX_WIDTH + y].b = b;
}

void draw_line(int x1, int y1, int x2, int y2, int r, int g, int b) {
    draw_pixel(x1, y1, r, g, b);
    draw_pixel(x2, y2, r, g, b);
    draw_pixel((x1 + x2) / 2, (y1 + y2) / 2, r, g, b);
}

void draw_circle(int x, int y, int radius, int r, int g, int b) {
    int i, j;
    for (i = -radius; i <= radius; i++) {
        for (j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) {
                draw_pixel(x + i, y + j, r, g, b);
            }
        }
    }
}

int main() {
    draw_pixel(10, 10, 255, 0, 0);
    draw_pixel(20, 20, 0, 255, 0);
    draw_pixel(30, 30, 0, 0, 255);

    draw_line(10, 10, 20, 20, 255, 0, 0);
    draw_line(20, 20, 30, 30, 0, 255, 0);

    draw_circle(10, 10, 5, 255, 0, 0);

    return 0;
}