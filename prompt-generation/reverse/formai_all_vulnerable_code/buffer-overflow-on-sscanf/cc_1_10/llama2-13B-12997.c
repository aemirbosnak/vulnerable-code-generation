//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256

typedef struct {
    int x;
    int y;
    int r;
    int g;
    int b;
} color_t;

color_t colors[MAX_COLORS];
int num_colors = 0;

void load_image(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        if (sscanf(line, "%d %d %d", &colors[num_colors].x, &colors[num_colors].y, &colors[num_colors].r) == 3) {
            num_colors++;
        }
    }
    fclose(file);
}

void draw_pixel(int x, int y, int r, int g, int b) {
    color_t c;
    c.x = x;
    c.y = y;
    c.r = r;
    c.g = g;
    c.b = b;
    colors[num_colors] = c;
    num_colors++;
}

void draw_line(int x1, int y1, int x2, int y2, int r, int g, int b) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = (dx > dy) ? dx : dy;
    int x = x1;
    int y = y1;
    int prev_x = x1;
    int prev_y = y1;
    while (steps--) {
        draw_pixel(x, y, r, g, b);
        if (dx > 0) {
            x++;
        } else {
            x--;
        }
        if (dy > 0) {
            y++;
        } else {
            y--;
        }
        if (x == x2) {
            break;
        }
    }
}

void draw_circle(int x, int y, int radius, int r, int g, int b) {
    int steps = (radius * 2 + 1) * (radius * 2 + 1);
    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;
    for (int i = 0; i < steps; i++) {
        draw_pixel(x1, y1, r, g, b);
        x1 += 2 * radius;
        y1 += 2 * radius;
        draw_pixel(x2, y2, r, g, b);
        x2 += 2 * radius;
        y2 += 2 * radius;
    }
}

void draw_image(int x, int y, int width, int height, int r, int g, int b) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            draw_pixel(x + j, y + i, r, g, b);
        }
    }
}

int main() {
    char filename[] = "image.bmp";
    load_image(filename);
    int width = WIDTH;
    int height = HEIGHT;
    draw_image(0, 0, width, height, 255, 0, 0);
    for (int i = 0; i < num_colors; i++) {
        draw_circle(colors[i].x, colors[i].y, 5, colors[i].r, colors[i].g, colors[i].b);
    }
    return 0;
}