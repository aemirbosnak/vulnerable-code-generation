//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ASCII_ART_LINES 20

typedef struct Pixel {
    int x;
    int y;
    int color;
} Pixel;

Pixel pixels[MAX_ASCII_ART_LINES][MAX_ASCII_ART_LINES];

void drawPixel(int x, int y, int color) {
    pixels[x][y].x = x;
    pixels[x][y].y = y;
    pixels[x][y].color = color;
}

void drawLine(int x1, int y1, int x2, int y2, int color) {
    drawPixel(x1, y1, color);
    drawPixel(x2, y2, color);
    drawPixel(x1, y2, color);
    drawPixel(x2, y1, color);
}

void drawCircle(int x, int y, int radius, int color) {
    int i, j;
    for (i = -radius; i <= radius; i++) {
        for (j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) {
                drawPixel(x + i, y + j, color);
            }
        }
    }
}

int main() {
    drawPixel(10, 10, 1);
    drawLine(10, 10, 20, 10, 2);
    drawCircle(15, 15, 5, 3);
    drawPixel(20, 20, 4);

    for (int i = 0; i < MAX_ASCII_ART_LINES; i++) {
        for (int j = 0; j < MAX_ASCII_ART_LINES; j++) {
            printf("%c ", pixels[i][j].color);
        }
        printf("\n");
    }

    return 0;
}