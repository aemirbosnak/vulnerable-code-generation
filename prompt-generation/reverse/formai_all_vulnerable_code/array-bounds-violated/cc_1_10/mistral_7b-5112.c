//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 25
#define HEIGHT 10

typedef struct {
    int x, y;
} point;

char grid[HEIGHT][WIDTH];

void draw_line(int x1, int y1, int x2, int y2, char symbol) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;

    int err = dx > dy ? dx / 2 : dy / 2;

    while (x1 != x2 || y1 != y2) {
        grid[y1][x1] = symbol;
        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;
        if (e2 > -dx) {
            err -= dx;
            x1 += sx;
        }
        if (e2 < -dy) {
            err += dy;
            y1 += sy;
        }
    }
}

void print_grid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            printf("%c", grid[i][j]);
        printf("\n");
    }
}

int main() {
    point start = { 1, 1 }, end = { WIDTH - 2, HEIGHT - 2 };
    char symbol = '*';

    memset(grid, ' ', sizeof(grid));

    draw_line(start.x, start.y, end.x, end.y, symbol);

    print_grid();

    return 0;
}