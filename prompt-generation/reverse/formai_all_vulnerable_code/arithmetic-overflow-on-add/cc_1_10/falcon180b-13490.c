//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000
#define MAX_COLOR 255

typedef struct {
    int x, y;
    int color;
} Pixel;

void drawPixel(int x, int y, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        printf("%d ", color);
    }
}

int getColor(int iterations) {
    return iterations * MAX_COLOR / MAX_ITERATIONS;
}

void generateFractal(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = 0;

    while (steps < MAX_ITERATIONS) {
        int nx = x1 + dx / 2 + dy / 2 * (dx / 2 - y1);
        int ny = y1 + dy / 2 - dx / 2 * (dy / 2 - x1);

        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
            drawPixel(nx, ny, getColor(steps));
        }

        int temp = dx;
        dx = dy;
        dy = temp - dx / 2;

        x1 = nx;
        y1 = ny;

        steps++;
    }
}

int main() {
    int x1, y1, x2, y2;

    printf("Enter the coordinates of the two points:\n");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    printf("Generating fractal...\n");
    generateFractal(x1, y1, x2, y2);

    return 0;
}