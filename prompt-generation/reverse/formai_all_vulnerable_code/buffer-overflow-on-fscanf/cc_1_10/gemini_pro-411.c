//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 1024
#define HEIGHT 768

typedef struct {
    unsigned char r, g, b;
} Pixel;

Pixel screen[WIDTH * HEIGHT];

void draw_line(int x0, int y0, int x1, int y1, Pixel color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (1) {
        screen[y0 * WIDTH + x0] = color;
        if (x0 == x1 && y0 == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_circle(int x0, int y0, int radius, Pixel color) {
    int x = radius, y = 0;
    int radiusError = 1 - x;
    while (x >= y) {
        screen[(y0 + y) * WIDTH + (x0 + x)] = color;
        screen[(y0 + y) * WIDTH + (x0 - x)] = color;
        screen[(y0 - y) * WIDTH + (x0 + x)] = color;
        screen[(y0 - y) * WIDTH + (x0 - x)] = color;
        screen[(y0 + x) * WIDTH + (x0 + y)] = color;
        screen[(y0 + x) * WIDTH + (x0 - y)] = color;
        screen[(y0 - x) * WIDTH + (x0 + y)] = color;
        screen[(y0 - x) * WIDTH + (x0 - y)] = color;
        y++;
        if (radiusError < 0) {
            radiusError += 2 * y + 1;
        } else {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}

void draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, Pixel color) {
    draw_line(x0, y0, x1, y1, color);
    draw_line(x1, y1, x2, y2, color);
    draw_line(x2, y2, x0, y0, color);
}

void draw_rectangle(int x0, int y0, int x1, int y1, Pixel color) {
    draw_line(x0, y0, x1, y0, color);
    draw_line(x1, y0, x1, y1, color);
    draw_line(x1, y1, x0, y1, color);
    draw_line(x0, y1, x0, y0, color);
}

void draw_image(char* filename, int x, int y) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error loading image: %s\n", filename);
        exit(1);
    }
    int width, height;
    fscanf(file, "P3\n%d %d\n255\n", &width, &height);
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            Pixel color;
            fscanf(file, "%hhu %hhu %hhu\n", &color.r, &color.g, &color.b);
            screen[(y + j) * WIDTH + (x + i)] = color;
        }
    }
    fclose(file);
}

int main(int argc, char** argv) {
    memset(screen, 0, sizeof(screen));
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        exit(1);
    }
    draw_image(argv[1], 0, 0);
    FILE* out = fopen("output.ppm", "wb");
    if (!out) {
        fprintf(stderr, "Error saving image: output.ppm\n");
        exit(1);
    }
    fprintf(out, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            Pixel color = screen[j * WIDTH + i];
            fprintf(out, "%hhu %hhu %hhu ", color.r, color.g, color.b);
        }
        fprintf(out, "\n");
    }
    fclose(out);
    return 0;
}