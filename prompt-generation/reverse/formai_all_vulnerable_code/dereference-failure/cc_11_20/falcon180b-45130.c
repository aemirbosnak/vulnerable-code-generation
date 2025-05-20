//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIXEL_SIZE 0.5
#define MAX_PIXELS 1000

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    if (width <= 0 || height <= 0) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    int max_pixels = width * height;

    if (max_pixels > MAX_PIXELS) {
        printf("Image too large.\n");
        return 1;
    }

    srand(time(NULL));

    int **pixels = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        pixels[i] = malloc(width * sizeof(int));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j] = rand() % 256;
        }
    }

    printf("P6\n%d %d\n255\n", width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}