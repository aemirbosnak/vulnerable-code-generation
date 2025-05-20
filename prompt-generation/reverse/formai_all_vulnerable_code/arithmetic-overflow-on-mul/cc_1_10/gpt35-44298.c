//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXRGB 255

void flip_horizontal(unsigned char* image, int width, int height);
void flip_vertical(unsigned char* image, int width, int height);
void adjust_brightness(unsigned char* image, int width, int height, int brightness);
void adjust_contrast(unsigned char* image, int width, int height, float contrast);

int main(int argc, char **argv) {

    // open input file
    FILE *fin = fopen("input.ppm", "rb");
    if (fin == NULL) {
        fprintf(stderr, "Error: Unable to open input file.\n");
        return -1;
    }

    // read header
    char magic_number[3];
    int width, height, max_value;
    fscanf(fin, "%s\n%d %d\n%d\n", magic_number, &width, &height, &max_value);

    // allocate memory for image data
    int num_pixels = width * height;
    unsigned char *image = (unsigned char *) malloc(num_pixels * 3);

    // read image data
    fread(image, sizeof(unsigned char), num_pixels * 3, fin);

    // close input file
    fclose(fin);

    // perform image processing tasks
    flip_horizontal(image, width, height);
    flip_vertical(image, width, height);
    adjust_brightness(image, width, height, 50);
    adjust_contrast(image, width, height, 1.5);

    // open output file
    FILE *fout = fopen("output.ppm", "wb");
    if (fout == NULL) {
        fprintf(stderr, "Error: Unable to open output file.\n");
        return -1;
    }

    // write header
    fprintf(fout, "%s\n%d %d\n%d\n", magic_number, width, height, max_value);

    // write image data
    fwrite(image, sizeof(unsigned char), num_pixels * 3, fout);

    // close output file
    fclose(fout);

    // free memory
    free(image);

    return 0;
}

void flip_horizontal(unsigned char* image, int width, int height) {
    int i, j;
    unsigned char temp[3];
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            memcpy(temp, &image[(i * width + j) * 3], 3);
            memcpy(&image[(i * width + j) * 3], &image[(i * width + (width - j - 1)) * 3], 3);
            memcpy(&image[(i * width + (width - j - 1)) * 3], temp, 3);
        }
    }
}

void flip_vertical(unsigned char* image, int width, int height) {
    int i, j;
    unsigned char temp[3];
    for (i = 0; i < height / 2; i++) {
        for (j = 0; j < width; j++) {
            memcpy(temp, &image[(i * width + j) * 3], 3);
            memcpy(&image[(i * width + j) * 3], &image[((height - i - 1) * width + j) * 3], 3);
            memcpy(&image[((height - i - 1) * width + j) * 3], temp, 3);
        }
    }
}

void adjust_brightness(unsigned char* image, int width, int height, int brightness) {
    int i;
    for (i = 0; i < width * height * 3; i++) {
        int val = image[i] + brightness;
        if (val < 0) {
            image[i] = 0;
        } else if (val > MAXRGB) {
            image[i] = MAXRGB;
        } else {
            image[i] = val;
        }
    }
}

void adjust_contrast(unsigned char* image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    int i;
    for (i = 0; i < width * height * 3; i++) {
        int val = (int) ((factor * (image[i] - 128)) + 128);
        if (val < 0) {
            image[i] = 0;
        } else if (val > MAXRGB) {
            image[i] = MAXRGB;
        } else {
            image[i] = val;
        }
    }
}