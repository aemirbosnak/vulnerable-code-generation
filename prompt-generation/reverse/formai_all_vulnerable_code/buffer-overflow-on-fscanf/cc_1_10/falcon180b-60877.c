//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXELS 1024

typedef struct {
    int x, y;
    double value;
} Pixel;

void read_image(char *filename, Pixel *pixels) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error reading image file.\n");
        exit(1);
    }
    int count = 0;
    while (fscanf(fp, "%d %d %lf", &pixels[count].x, &pixels[count].y, &pixels[count].value)!= EOF) {
        count++;
        if (count >= MAX_PIXELS) {
            printf("Error: image has too many pixels.\n");
            exit(1);
        }
    }
    fclose(fp);
}

void write_image(char *filename, Pixel *pixels) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error writing image file.\n");
        exit(1);
    }
    int count = 0;
    while (count < MAX_PIXELS && pixels[count].x!= -1) {
        fprintf(fp, "%d %d %lf\n", pixels[count].x, pixels[count].y, pixels[count].value);
        count++;
    }
    fclose(fp);
}

void flip_image(Pixel *pixels) {
    int i, j;
    for (i = 0; i < MAX_PIXELS; i++) {
        if (pixels[i].x!= -1) {
            pixels[i].x = MAX_PIXELS - pixels[i].x - 1;
            pixels[i].y = MAX_PIXELS - pixels[i].y - 1;
        }
    }
}

void adjust_brightness(Pixel *pixels, double factor) {
    int i;
    for (i = 0; i < MAX_PIXELS; i++) {
        if (pixels[i].x!= -1) {
            pixels[i].value *= factor;
        }
    }
}

void adjust_contrast(Pixel *pixels, double factor) {
    int i;
    double mean = 0;
    for (i = 0; i < MAX_PIXELS; i++) {
        if (pixels[i].x!= -1) {
            mean += pixels[i].value;
        }
    }
    mean /= MAX_PIXELS;
    for (i = 0; i < MAX_PIXELS; i++) {
        if (pixels[i].x!= -1) {
            pixels[i].value = (pixels[i].value - mean) * factor + mean;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image output_image\n", argv[0]);
        exit(1);
    }
    char *input_filename = argv[1];
    char *output_filename = argv[2];
    Pixel pixels[MAX_PIXELS];
    read_image(input_filename, pixels);
    flip_image(pixels);
    adjust_brightness(pixels, 2);
    adjust_contrast(pixels, 1.5);
    write_image(output_filename, pixels);
    return 0;
}