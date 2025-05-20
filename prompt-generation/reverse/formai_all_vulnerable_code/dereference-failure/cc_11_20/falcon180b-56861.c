//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

int main() {
    srand(time(0));

    int **image = (int **) malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = (int *) malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % 256;
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int count = 0;
            int r = 0, g = 0, b = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = i + k;
                    int y = j + l;

                    if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH) {
                        int c = image[x][y];
                        r += (c & 0xFF0000) >> 16;
                        g += (c & 0x00FF00) >> 8;
                        b += c & 0x0000FF;
                        count++;
                    }
                }
            }

            if (count > 0) {
                r /= count;
                g /= count;
                b /= count;
            }

            image[i][j] = (r << 16) | (g << 8) | b;
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}