//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PIXELS 1000
#define PIXEL_SIZE 5

int main() {
    srand(time(NULL));

    int width, height, max_pixels;
    printf("Enter image dimensions (width and height): ");
    scanf("%d %d", &width, &height);

    printf("Enter maximum number of pixels (0 for no limit): ");
    scanf("%d", &max_pixels);

    if (max_pixels == 0 || max_pixels > MAX_PIXELS) {
        max_pixels = MAX_PIXELS;
    }

    int num_pixels = rand() % max_pixels + 1;

    int **pixels = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        pixels[i] = malloc(width * sizeof(int));
    }

    for (int i = 0; i < num_pixels; i++) {
        int x = rand() % width;
        int y = rand() % height;
        pixels[y][x] = 1;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (pixels[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}