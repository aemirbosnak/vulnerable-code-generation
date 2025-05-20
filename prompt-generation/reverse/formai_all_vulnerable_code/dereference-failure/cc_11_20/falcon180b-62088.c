//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
    srand(time(NULL));

    int **pixels = malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = malloc(WIDTH * sizeof(int));
    }

    int shapes[4] = {0, 1, 2, 3};

    while (1) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                int shape = shapes[rand() % 4];

                switch (shape) {
                    case 0:
                        pixels[i][j] = rand() % 256;
                        break;
                    case 1:
                        pixels[i][j] = 0;
                        break;
                    case 2:
                        pixels[i][j] = 255;
                        break;
                    case 3:
                        pixels[i][j] = rand() % 256;
                        break;
                }
            }
        }

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("%d ", pixels[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                int k = rand() % 4;
                while (k == shapes[rand() % 4]) {
                    k = rand() % 4;
                }
                shapes[k] = shapes[rand() % 4];
                shapes[rand() % 4] = k;
            }
        }
    }

    return 0;
}