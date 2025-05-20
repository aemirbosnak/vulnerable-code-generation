//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

#define BLACK 0x000000
#define WHITE 0x00FFFFFF

#define PIXEL_SIZE 4

int main() {
    srand(time(NULL));

    int **pixels = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = (int *)malloc(WIDTH * PIXEL_SIZE * sizeof(int));
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;

            int color = (r << 16) | (g << 8) | b;

            for (int k = 0; k < PIXEL_SIZE; k++) {
                for (int l = 0; l < PIXEL_SIZE; l++) {
                    int x = j * PIXEL_SIZE + k;
                    int y = i * PIXEL_SIZE + l;

                    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                        pixels[y][x] = color;
                    }
                }
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%06X ", pixels[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}