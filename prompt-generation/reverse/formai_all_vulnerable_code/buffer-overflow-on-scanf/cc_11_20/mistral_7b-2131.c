//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} color;

color colors[6] = {
    {255, 0, 0},   // red
    {0, 255, 0},    // green
    {0, 0, 255},    // blue
    {255, 255, 0},  // yellow
    {0, 255, 255},  // cyan
    {255, 0, 255}   // magenta
};

int main() {
    int x, y, color_num;
    color grid[WIDTH][HEIGHT];

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].r = grid[i][j].g = grid[i][j].b = 0;
        }
    }

    while (1) {
        printf("Enter x, y and color number (1-6): ");
        scanf("%d%d%d", &x, &y, &color_num);

        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
            printf("Invalid coordinates.\n");
            continue;
        }

        switch (color_num) {
            case 1:
                grid[x][y] = colors[0];
                break;
            case 2:
                grid[x][y] = colors[1];
                break;
            case 3:
                grid[x][y] = colors[2];
                break;
            case 4:
                grid[x][y] = colors[3];
                break;
            case 5:
                grid[x][y] = colors[4];
                break;
            case 6:
                grid[x][y] = colors[5];
                break;
            default:
                printf("Invalid color number.\n");
                continue;
        }

        printf("Pixel (%d, %d) set to color %d.\n", x, y, color_num);
    }

    return 0;
}