//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define COLOR_BLACK 0
#define COLOR_WHITE 1
#define COLOR_GRAY 2
#define COLOR_RED 3
#define COLOR_GREEN 4
#define COLOR_BLUE 5

#define X_SIZE 800
#define Y_SIZE 600
#define PIXEL_SIZE 10

int main(int argc, char **argv) {
    char *image_file = NULL;
    int x = 0;
    int y = 0;
    int color = COLOR_WHITE;
    int width = X_SIZE / PIXEL_SIZE;
    int height = Y_SIZE / PIXEL_SIZE;
    int i = 0;
    int j = 0;
    int pixels[X_SIZE][Y_SIZE];

    // Open the image file
    image_file = argv[1];
    FILE *fp = fopen(image_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file %s\n", image_file);
        return 1;
    }

    // Read the image data
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            fscanf(fp, "%d", &pixels[x][y]);
        }
    }

    // Generate the pixel art
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (pixels[x][y] == COLOR_BLACK) {
                printf(" ");
            } else if (pixels[x][y] == COLOR_WHITE) {
                printf("#");
            } else if (pixels[x][y] == COLOR_GRAY) {
                printf(".");
            } else if (pixels[x][y] == COLOR_RED) {
                printf(".");
            } else if (pixels[x][y] == COLOR_GREEN) {
                printf(".");
            } else if (pixels[x][y] == COLOR_BLUE) {
                printf(".");
            }
        }
        printf("\n");
    }

    // Close the image file
    fclose(fp);

    return 0;
}