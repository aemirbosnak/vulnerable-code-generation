//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX 256

typedef struct Pixel {
    int r, g, b, a;
} Pixel;

Pixel pixels[MAX];

void drawPixel(int x, int y, Pixel pixel) {
    pixels[x + MAX * y] = pixel;
}

void drawLine(int x1, int y1, int x2, int y2, Pixel color) {
    Pixel p1 = pixels[x1 + MAX * y1];
    Pixel p2 = pixels[x2 + MAX * y2];

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int steps = dx > dy ? dx : dy;

    for (int i = 0; i < steps; i++) {
        int x = x1 + i * (x2 - x1) / steps;
        int y = y1 + i * (y2 - y1) / steps;

        drawPixel(x, y, color);
    }
}

void drawCircle(int x, int y, int r, Pixel color) {
    for (int dx = -r; dx <= r; dx++) {
        for (int dy = -r; dy <= r; dy++) {
            if (dx * dx + dy * dy <= r * r) {
                drawPixel(x + dx, y + dy, color);
            }
        }
    }
}

int main() {
    Pixel white = {255, 255, 255, 255};
    Pixel black = {0, 0, 0, 255};

    drawPixel(10, 10, black);
    drawLine(10, 10, 50, 10, black);
    drawCircle(20, 20, 10, white);

    system("pause");

    return 0;
}