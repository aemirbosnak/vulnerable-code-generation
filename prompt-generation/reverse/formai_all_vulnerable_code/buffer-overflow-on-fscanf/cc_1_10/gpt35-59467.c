//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 512  // Maximum size of image

int image[MAX][MAX];  // Global 2D array to hold image

void read_image(char* name, int image[][MAX], int* rows, int* cols) {
    FILE* fp;
    int i, j;

    fp = fopen(name, "rb");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", name);
        exit(1);
    }

    // read image dimensions
    fscanf(fp, "%d %d", rows, cols);

    // read image data
    for (i = 0; i < *rows; ++i) {
        for (j = 0; j < *cols; ++j) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    fclose(fp);
}

void write_image(char* name, int image[][MAX], int rows, int cols) {
    FILE* fp;
    int i, j;

    fp = fopen(name, "wb");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", name);
        exit(1);
    }

    // write image dimensions
    fprintf(fp, "%d %d\n", rows, cols);

    // write image data
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void flip_image(int image[][MAX], int rows, int cols) {
    int i, j, temp;

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols/2; ++j) {
            // swap pixels horizontally
            temp = image[i][j];
            image[i][j] = image[i][cols-1-j];
            image[i][cols-1-j] = temp;
        }
    }
}

void brighten_image(int image[][MAX], int rows, int cols, int brightness) {
    int i, j;

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            // increase brightness by specified amount
            image[i][j] += brightness;

            // make sure pixel value stays within legal range
            if (image[i][j] > 255) {
                image[i][j] = 255;
            }
            else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

void contrast_image(int image[][MAX], int rows, int cols, double contrast) {
    int i, j;
    double factor;

    factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            // apply contrast formula to each pixel
            image[i][j] = factor * (image[i][j] - 128) + 128;

            // make sure pixel value stays within legal range
            if (image[i][j] > 255) {
                image[i][j] = 255;
            }
            else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

int main() {
    int rows, cols;
    int brightness;
    double contrast;

    // read image from file
    read_image("input.txt", image, &rows, &cols);

    // flip image horizontally
    flip_image(image, rows, cols);

    // increase brightness by 50
    brightness = 50;
    brighten_image(image, rows, cols, brightness);

    // decrease contrast by 50%
    contrast = 0.5;
    contrast_image(image, rows, cols, contrast);

    // write resulting image to file
    write_image("output.txt", image, rows, cols);

    return 0;
}