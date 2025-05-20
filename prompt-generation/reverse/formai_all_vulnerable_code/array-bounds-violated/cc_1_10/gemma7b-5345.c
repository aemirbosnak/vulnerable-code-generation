//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

typedef struct Pixel {
    int r, g, b;
} Pixel;

Pixel pixels[MAX_WIDTH * MAX_HEIGHT];

void draw_pixel(int x, int y, Pixel pixel) {
    pixels[x * MAX_WIDTH + y] = pixel;
}

void draw_line(int x1, int y1, int x2, int y2, Pixel color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) + abs(dy);

    for (int i = 0; i < steps; i++) {
        int x = x1 + i * dx / steps;
        int y = y1 + i * dy / steps;
        draw_pixel(x, y, color);
    }
}

void draw_circle(int x, int y, int radius, Pixel color) {
    for (int dx = -radius; dx <= radius; dx++) {
        for (int dy = -radius; dy <= radius; dy++) {
            if (dx * dx + dy * dy <= radius * radius) {
                draw_pixel(x + dx, y + dy, color);
            }
        }
    }
}

void main() {
    Pixel black = {0, 0, 0};
    Pixel red = {255, 0, 0};
    Pixel green = {0, 255, 0};
    Pixel blue = {0, 0, 255};

    srand(time(NULL));

    draw_circle(50, 50, 20, red);
    draw_line(10, 10, 70, 50, green);
    draw_pixel(20, 20, black);

    for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++) {
        printf("%c", pixels[i].r);
        printf("%c", pixels[i].g);
        printf("%c", pixels[i].b);
        printf("\n");
    }
}