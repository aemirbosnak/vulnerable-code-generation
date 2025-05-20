//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define PIXEL_SIZE 3

int main() {
    int i, j, x, y, color;
    FILE *fp;
    unsigned char *pixels;
    char filename[100];

    srand(time(NULL));

    pixels = (unsigned char*) malloc(WIDTH * HEIGHT * PIXEL_SIZE);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            x = (int) (j * PIXEL_SIZE);
            y = (int) (i * PIXEL_SIZE);

            color = rand() % 256;

            for (int k = 0; k < PIXEL_SIZE; k++) {
                pixels[y * WIDTH * PIXEL_SIZE + x + k] = color;
            }
        }
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            x = (int) (j * PIXEL_SIZE);
            y = (int) (i * PIXEL_SIZE);

            color = pixels[y * WIDTH * PIXEL_SIZE + x];

            printf("%.2X ", color);
        }
        printf("\n");
    }

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fwrite(pixels, 1, WIDTH * HEIGHT * PIXEL_SIZE, fp);

    fclose(fp);

    free(pixels);

    return 0;
}