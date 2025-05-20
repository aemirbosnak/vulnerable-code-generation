//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// define grayscale levels 
#define LEVELS 10
const char *levels = " .:-=+*#%@";

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("error opening file %s\n", argv[1]);
        return 1;
    }

    // read header info
    char type[3];
    int width, height, maxval;
    fscanf(fp, "%2s\n%d %d\n%d\n", type, &width, &height, &maxval);
    if (type[0] != 'P' || type[1] != '2') {
        printf("invalid image format\n");
        return 1;
    }
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("invalid image size\n");
        return 1;
    }

    // read pixel data
    int pixels[MAX_HEIGHT][MAX_WIDTH];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int val;
            fscanf(fp, "%d", &val);
            pixels[i][j] = val;
        }
    }

    // print ascii art
    for (int i = 0; i < height; i += 2) {
        for (int j = 0; j < width; j++) {
            int val = (pixels[i][j] + pixels[i+1][j]) / 2;
            int level = (int)((val / (float)maxval) * LEVELS);
            putchar(levels[level]);
        }
        putchar('\n');
    }

    fclose(fp);
    return 0;
}