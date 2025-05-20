//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 500
#define MAX_HEIGHT 500

struct pixel {
    int x, y;
    int r, g, b;
};

void read_image(char *filename, struct pixel *pixels, int *width, int *height) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fscanf(fp, "P6\n%d %d\n%d", width, height, MAX_WIDTH * MAX_HEIGHT);

    pixels = malloc(sizeof(struct pixel) * (*width) * (*height));

    for (int i = 0; i < *width * *height; i++) {
        fscanf(fp, "%d %d %d", &pixels[i].x, &pixels[i].y, &pixels[i].r);
        pixels[i].g = pixels[i].r;
        pixels[i].b = pixels[i].r;
    }

    fclose(fp);
}

void write_image(char *filename, struct pixel *pixels, int width, int height) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n%d", width, height, MAX_WIDTH * MAX_HEIGHT);

    for (int i = 0; i < width * height; i++) {
        fprintf(fp, "%d %d %d", pixels[i].x, pixels[i].y, pixels[i].r);
    }

    fclose(fp);
}

void flip_image(struct pixel *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        int x = pixels[i].x;
        int y = pixels[i].y;

        pixels[i].x = width - x - 1;
        pixels[i].y = height - y - 1;
    }
}

void adjust_brightness(struct pixel *pixels, int width, int height, int delta) {
    for (int i = 0; i < width * height; i++) {
        int r = pixels[i].r + delta;
        if (r < 0) r = 0;
        if (r > 255) r = 255;

        pixels[i].r = r;
        pixels[i].g = r;
        pixels[i].b = r;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file delta\n", argv[0]);
        exit(1);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int delta = atoi(argv[3]);

    struct pixel *pixels = NULL;
    int width, height;

    read_image(input_file, pixels, &width, &height);

    flip_image(pixels, width, height);
    adjust_brightness(pixels, width, height, delta);

    write_image(output_file, pixels, width, height);

    free(pixels);

    return 0;
}