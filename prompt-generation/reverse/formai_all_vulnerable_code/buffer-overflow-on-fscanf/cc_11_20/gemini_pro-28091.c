//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 40

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    char line[256];
    int width, height, maxval;
    if (fscanf(fp, "P3 %d %d %d\n", &width, &height, &maxval) != 3) {
        fprintf(stderr, "Error: Invalid PPM file format\n");
        fclose(fp);
        return 1;
    }

    if (width > WIDTH || height > HEIGHT) {
        fprintf(stderr, "Error: Image too large\n");
        fclose(fp);
        return 1;
    }

    char *pixels = malloc(width * height * 3);
    if (pixels == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        fclose(fp);
        return 1;
    }

    fread(pixels, width * height * 3, 1, fp);
    fclose(fp);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = pixels[(y * width + x) * 3 + 0];
            int g = pixels[(y * width + x) * 3 + 1];
            int b = pixels[(y * width + x) * 3 + 2];

            double luma = 0.2126 * r + 0.7152 * g + 0.0722 * b;

            char c;
            if (luma > 255 * 0.75) {
                c = '#';
            } else if (luma > 255 * 0.50) {
                c = '+';
            } else if (luma > 255 * 0.25) {
                c = '=';
            } else {
                c = ' ';
            }

            printf("%c", c);
        }

        printf("\n");
    }

    free(pixels);

    return 0;
}