//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    double *data;
} Image;

void read_image(char *filename, Image *image) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fscanf(fp, "%d %d", &image->width, &image->height);
    image->data = (double *) malloc(sizeof(double) * image->width * image->height);

    for (int i = 0; i < image->width * image->height; i++) {
        fscanf(fp, "%lf", &image->data[i]);
    }

    fclose(fp);
}

void write_image(char *filename, Image *image) {
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fprintf(fp, "%d %d\n", image->width, image->height);

    for (int i = 0; i < image->width * image->height; i++) {
        fprintf(fp, "%lf ", image->data[i]);
    }

    fclose(fp);
}

void flip_image(Image *image) {
    int width = image->width;
    int height = image->height;

    double *data_copy = (double *) malloc(sizeof(double) * width * height);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            data_copy[j * width + i] = image->data[(height - j - 1) * width + i];
        }
    }

    free(image->data);
    image->data = data_copy;
}

void adjust_brightness(Image *image, double factor) {
    int width = image->width;
    int height = image->height;

    for (int i = 0; i < width * height; i++) {
        image->data[i] *= factor;
    }
}

void adjust_contrast(Image *image, double factor) {
    int width = image->width;
    int height = image->height;

    double mean = 0;

    for (int i = 0; i < width * height; i++) {
        mean += image->data[i];
    }

    mean /= width * height;

    for (int i = 0; i < width * height; i++) {
        image->data[i] = (image->data[i] - mean) * factor + mean;
    }
}

int main() {
    Image image;

    read_image("input.txt", &image);

    printf("Before flipping:\n");
    write_image("before_flip.txt", &image);

    flip_image(&image);

    printf("After flipping:\n");
    write_image("after_flip.txt", &image);

    adjust_brightness(&image, 2);

    printf("After increasing brightness by a factor of 2:\n");
    write_image("after_brightness.txt", &image);

    adjust_contrast(&image, 1.5);

    printf("After increasing contrast by a factor of 1.5:\n");
    write_image("after_contrast.txt", &image);

    return 0;
}