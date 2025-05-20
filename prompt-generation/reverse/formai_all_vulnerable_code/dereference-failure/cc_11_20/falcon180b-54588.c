//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

int main(void) {
    srand(time(NULL));
    int **pixels = malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            pixels[i][j] = rand() % 256;
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int r = 0, g = 0, b = 0;
            for (int k = 0; k < MAX_ITERATIONS; k++) {
                int x = i + rand() % 10 - 5;
                int y = j + rand() % 10 - 5;
                if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH) {
                    r += pixels[x][y] & 0xff0000;
                    g += pixels[x][y] & 0x00ff00;
                    b += pixels[x][y] & 0x0000ff;
                }
            }
            r = r / MAX_ITERATIONS;
            g = g / MAX_ITERATIONS;
            b = b / MAX_ITERATIONS;
            pixels[i][j] = (r << 16) | (g << 8) | b;
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}