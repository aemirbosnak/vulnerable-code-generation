//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define PIXEL_SIZE 5

int main() {
    srand(time(NULL));

    int **pixels = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int color = rand() % 7;
            switch (color) {
                case 0:
                    pixels[y][x] = 0;
                    break;
                case 1:
                    pixels[y][x] = 1;
                    break;
                case 2:
                    pixels[y][x] = 2;
                    break;
                case 3:
                    pixels[y][x] = 3;
                    break;
                case 4:
                    pixels[y][x] = 4;
                    break;
                case 5:
                    pixels[y][x] = 5;
                    break;
                case 6:
                    pixels[y][x] = 6;
                    break;
            }
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", pixels[y][x]);
        }
        printf("\n");
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}