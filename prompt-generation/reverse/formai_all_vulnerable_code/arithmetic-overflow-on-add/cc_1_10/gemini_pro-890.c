//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    int x, y;
} point;

typedef struct {
    point p1, p2;
} line;

void draw_line(line l) {
    int dx = abs(l.p2.x - l.p1.x);
    int dy = abs(l.p2.y - l.p1.y);
    int sx = (l.p2.x > l.p1.x) ? 1 : -1;
    int sy = (l.p2.y > l.p1.y) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        putchar('#');

        if (l.p1.x == l.p2.x && l.p1.y == l.p2.y) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            l.p1.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            l.p1.y += sy;
        }
    }
}

int main() {
    int fib[WIDTH + 1];
    int i;

    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i <= WIDTH; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (i = 1; i <= HEIGHT; i++) {
        line l;
        l.p1.x = fib[i - 1];
        l.p1.y = i - 1;
        l.p2.x = fib[i];
        l.p2.y = i - 1;
        draw_line(l);
        putchar('\n');
    }

    return 0;
}