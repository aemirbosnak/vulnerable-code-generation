//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 255

void flipImage(int *image, int width, int height) {
    int i, j;
    int temp;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            temp = image[i*width + j];
            image[i*width + j] = image[i*width + (width - j - 1)];
            image[i*width + (width - j - 1)] = temp;
        }
    }
}

void brightnessContrast(int *image, int width, int height, int brightness, int contrast) {
    int i, j;
    float temp;
    float c = (float)(100 + contrast) / 100;
    float b = (float)brightness / 255;

    for (i = 0; i < height*width; i++) {
        temp = c * (image[i] - 128) + 128 + b * 255;
        if (temp < 0) temp = 0;
        if (temp > 255) temp = 255;
        image[i] = (int)temp;
    }
}

int main() {
    FILE *fp;
    char *filename = "input.pgm";
    char buffer[3];
    int width, height, max;
    int *image;
    int i, j;
    int brightness = 50;
    int contrast = 50;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fscanf(fp, "%s %d %d %d", buffer, &width, &height, &max);
    printf("Image size: %dx%d\n", width, height);

    image = (int*)malloc(sizeof(int)*width*height);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fscanf(fp, "%d", &image[i*width + j]);
        }
    }

    fclose(fp);

    flipImage(image, width, height);

    brightnessContrast(image, width, height, brightness, contrast);

    fp = fopen("output.pgm", "wb");
    fprintf(fp, "P2\n%d %d\n%d\n", width, height, MAX);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(fp, "%d ", image[i*width + j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    free(image);

    return 0;
}