//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_COLOR 256

int main() {
    int x, y;
    char filename[20];
    FILE *fp;
    int **pixels;
    int color;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    pixels = (int **) malloc(sizeof(int *) * HEIGHT);
    for (y = 0; y < HEIGHT; y++) {
        pixels[y] = (int *) malloc(sizeof(int) * WIDTH);
    }

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fread(&color, sizeof(int), 1, fp);
            pixels[y][x] = color;
        }
    }

    fclose(fp);

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%d ", pixels[y][x]);
        }
        printf("\n");
    }

    for (y = 0; y < HEIGHT; y++) {
        free(pixels[y]);
    }
    free(pixels);

    return 0;
}