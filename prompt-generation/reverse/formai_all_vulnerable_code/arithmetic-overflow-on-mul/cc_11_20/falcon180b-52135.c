//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

int main(int argc, char **argv) {
    FILE *fp;
    unsigned char header[54];
    int width, height, i, j, k, x, y;
    unsigned char *pixels;

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    fread(header, 1, 54, fp);
    if (memcmp(header, "BM", 2)!= 0) {
        printf("Error: Input file is not a valid BMP image.\n");
        fclose(fp);
        return 1;
    }

    width = *(int *)&header[18];
    height = *(int *)&header[22];

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image dimensions are too large.\n");
        fclose(fp);
        return 1;
    }

    pixels = malloc(width * height);
    if (pixels == NULL) {
        printf("Error: Could not allocate memory for pixel data.\n");
        fclose(fp);
        return 1;
    }

    fseek(fp, 54, SEEK_SET);
    fread(pixels, 1, width * height, fp);
    fclose(fp);

    fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error: Could not open output file.\n");
        free(pixels);
        return 1;
    }

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (pixels[(y * width) + x] == 0) {
                fprintf(fp, " ");
            } else {
                fprintf(fp, "*");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    free(pixels);

    return 0;
}