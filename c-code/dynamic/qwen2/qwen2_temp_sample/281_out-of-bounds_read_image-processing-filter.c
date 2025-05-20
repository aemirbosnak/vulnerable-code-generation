#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void applyFilter(int *image) {
    int temp[HEIGHT][WIDTH];
    for (int y = -1; y <= HEIGHT; y++) {
        for (int x = -1; x <= WIDTH; x++) {
            int sumR = 0, sumG = 0, sumB = 0;
            for (int cy = -1; cy <= 1; cy++) {
                for (int cx = -1; cx <= 1; cx++) {
                    int iy = y + cy;
                    int ix = x + cx;
                    if (iy >= 0 && iy < HEIGHT && ix >= 0 && ix < WIDTH) {
                        sumR += *(image + ((iy * WIDTH) + ix));
                        sumG += *(image + ((iy * WIDTH) + ix));
                        sumB += *(image + ((iy * WIDTH) + ix));
                    }
                }
            }
            temp[y + 1][x + 1] = sumR + sumG + sumB;
        }
    }

    // Overwrite original image with filtered values
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = (y * WIDTH) + x;
            *(image + index) = temp[y][x];
        }
    }
}

int main() {
    int image[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image[y][x] = rand() % 256;
        }
    }

    printf("Original Image:\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", image[y][x]);
        }
        printf("\n");
    }

    applyFilter((int *)image);

    printf("Filtered Image:\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", image[y][x]);
        }
        printf("\n");
    }

    return 0;
}
