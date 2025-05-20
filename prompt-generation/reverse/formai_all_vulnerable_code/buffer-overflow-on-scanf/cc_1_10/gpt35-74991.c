//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40

void clear(char pixels[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            pixels[i][j] = '-';
        }
    }
}

void show(char pixels[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            putchar(pixels[i][j]);
        }
        putchar('\n');
    }
}

void point(char pixels[HEIGHT][WIDTH], int x, int y) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        pixels[y][x] = '*';
    }
}

void line(char pixels[HEIGHT][WIDTH], int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    if (steps == 0) {
        return;
    }
    float xinc = dx / (float) steps;
    float yinc = dy / (float) steps;
    float x = x1;
    float y = y1;
    int i;
    for (i = 0; i < steps; i++) {
        point(pixels, round(x), round(y));
        x += xinc;
        y += yinc;
    }
    point(pixels, round(x2), round(y2));
}

void gen_sierpinski(char pixels[HEIGHT][WIDTH], int x1, int y1, int x2, int y2, int x3, int y3, int depth) {
    if (depth == 0) {
        return;
    }
    int nx1 = (x1 + x2) / 2;
    int ny1 = (y1 + y2) / 2;
    int nx2 = (x2 + x3) / 2;
    int ny2 = (y2 + y3) / 2;
    int nx3 = (x3 + x1) / 2;
    int ny3 = (y3 + y1) / 2;
    line(pixels, nx1, ny1, nx2, ny2);
    line(pixels, nx2, ny2, nx3, ny3);
    line(pixels, nx3, ny3, nx1, ny1);
    gen_sierpinski(pixels, x1, y1, nx1, ny1, nx3, ny3, depth - 1);
    gen_sierpinski(pixels, nx1, ny1, x2, y2, nx2, ny2, depth - 1);
    gen_sierpinski(pixels, nx3, ny3, nx2, ny2, x3, y3, depth - 1);
}

void gen_koch(char pixels[HEIGHT][WIDTH], int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        line(pixels, x1, y1, x2, y2);
    }
    else {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int x3 = x1 + dx / 3;
        int y3 = y1 + dy / 3;
        int x4 = x2 - dx / 3;
        int y4 = y2 - dy / 3;
        double angle = M_PI / 3;
        int x5 = x3 + cos(angle)*dx / 3 - sin(angle)*dy / 3;
        int y5 = y3 + sin(angle)*dx / 3 + cos(angle)*dy / 3;
        gen_koch(pixels, x1, y1, x3, y3, depth - 1);
        gen_koch(pixels, x3, y3, x5, y5, depth - 1);
        gen_koch(pixels, x5, y5, x4, y4, depth - 1);
        gen_koch(pixels, x4, y4, x2, y2, depth - 1);
    }
}

void gen_fractal(char pixels[HEIGHT][WIDTH], int type, int depth) {
    clear(pixels);
    if (type == 1) {
        gen_sierpinski(pixels, 0, HEIGHT - 1, WIDTH - 1, HEIGHT - 1, WIDTH / 2, 0, depth);
    }
    else {
        gen_koch(pixels, 0, HEIGHT / 2, WIDTH - 1, HEIGHT / 2, depth);
    }
    show(pixels);
}

int main() {
    char pixels[HEIGHT][WIDTH];
    int type, depth;
    do {
        printf("Select fractal type (1 for Sierpinski, 2 for Koch): ");
        scanf("%d", &type);
    } while (type != 1 && type != 2);
    printf("Enter fractal depth: ");
    scanf("%d", &depth);
    gen_fractal(pixels, type, depth);
    return 0;
}