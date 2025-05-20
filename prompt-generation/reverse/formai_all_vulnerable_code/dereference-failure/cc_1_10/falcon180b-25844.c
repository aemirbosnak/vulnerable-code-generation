//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    int **data;
} Image;

void create_image(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = (int **) malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        img->data[i] = (int *) malloc(width * sizeof(int));
    }
}

void destroy_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
}

void flip_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            int temp = img->data[i][j];
            img->data[i][j] = img->data[i][img->width - j - 1];
            img->data[i][img->width - j - 1] = temp;
        }
    }
}

void change_brightness_contrast(Image *img, int brightness, int contrast) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int value = img->data[i][j];
            int new_value = (value * contrast + brightness) / 255;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            img->data[i][j] = new_value;
        }
    }
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "P5\n%d %d\n255\n", img->width, img->height);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(fp, "%d ", img->data[i][j]);
        }
    }
    fclose(fp);
}

int main() {
    Image img;
    create_image(&img, 10, 10);
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            img.data[i][j] = i * img.width + j;
        }
    }
    save_image(&img, "original.pbm");

    flip_image(&img);
    save_image(&img, "flipped.pbm");

    change_brightness_contrast(&img, 50, 150);
    save_image(&img, "brightened.pbm");

    destroy_image(&img);
    return 0;
}