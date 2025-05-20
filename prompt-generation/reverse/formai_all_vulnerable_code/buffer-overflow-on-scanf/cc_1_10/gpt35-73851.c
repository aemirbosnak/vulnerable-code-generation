//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WIDTH 100
#define HEIGHT 60

typedef struct {
    int x;
    int y;
} point_t;

void draw_point(int x, int y, char screen[HEIGHT][WIDTH]) {
    if (x < 0 || x >= WIDTH) return;
    if (y < 0 || y >= HEIGHT) return;
    screen[y][x] = '*';
}

void draw_line(point_t p1, point_t p2, char screen[HEIGHT][WIDTH]) {
    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
    int sx, sy;
    if (p1.x < p2.x) sx = 1; else sx = -1;
    if (p1.y < p2.y) sy = 1; else sy = -1;
    int err = dx - dy;
    int x = p1.x;
    int y = p1.y;
    draw_point(x, y, screen);
    while (x != p2.x || y != p2.y) {
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
        draw_point(x, y, screen);
    }
}

void draw_fractal(int n, int x1, int y1, int x2, int y2, char screen[HEIGHT][WIDTH]) {
    if (n == 0)
        draw_line((point_t){x1, y1}, (point_t){x2, y2}, screen);
    else {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int x3 = x1 + dx / 3;
        int y3 = y1 + dy / 3;
        int x4 = x2 - dx / 3;
        int y4 = y2 - dy / 3;
        int xm = x3 + cos(M_PI/3) * (x4 - x3) - sin(M_PI/3) * (y4 - y3);
        int ym = y3 + sin(M_PI/3) * (x4 - x3) + cos(M_PI/3) * (y4 - y3);
        draw_fractal(n-1, x1, y1, x3, y3, screen);
        draw_fractal(n-1, x3, y3, xm, ym, screen);
        draw_fractal(n-1, xm, ym, x4, y4, screen);
        draw_fractal(n-1, x4, y4, x2, y2, screen);
    }
}

int main() {
    // Obtain the number of iterations from the user
    int n;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    // Initialize screen buffer
    char screen[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            screen[y][x] = ' ';

    // Draw the fractal
    draw_fractal(n, 10, 30, 90, 30, screen);

    // Output the screen buffer to the console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
            putchar(screen[y][x]);
        putchar('\n');
    }

    return 0;
}