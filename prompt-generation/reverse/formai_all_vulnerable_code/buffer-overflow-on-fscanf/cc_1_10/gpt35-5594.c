//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width, height;
    int pixels[MAX_HEIGHT][MAX_WIDTH];
} Image;

void flip_image(Image *img) {
    int temp;
    for(int y=0; y<img->height; y++) {
        for(int x=0; x<img->width/2; x++) {
            temp = img->pixels[y][x];
            img->pixels[y][x] = img->pixels[y][img->width-1-x];
            img->pixels[y][img->width-1-x] = temp;
        }
    }
}

void adjust_brightness(Image *img, int value) {
    for(int y=0; y<img->height; y++) {
        for(int x=0; x<img->width; x++) {
            img->pixels[y][x] = img->pixels[y][x] + value;
            if(img->pixels[y][x] > 255) {
                img->pixels[y][x] = 255;
            } else if(img->pixels[y][x] < 0) {
                img->pixels[y][x] = 0;
            }
        }
    }
}

void adjust_contrast(Image *img, float value) {
    float factor = (259 * (value + 255)) / (255 * (259 - value));
    for(int y=0; y<img->height; y++) {
        for(int x=0; x<img->width; x++) {
            img->pixels[y][x] = factor * (img->pixels[y][x] - 128) + 128;
            if(img->pixels[y][x] > 255) {
                img->pixels[y][x] = 255;
            } else if(img->pixels[y][x] < 0) {
                img->pixels[y][x] = 0;
            }
        }
    }
}

void read_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Failed to open file for reading: %s", filename);
        exit(1);
    }
    fscanf(fp, "%d%d", &img->width, &img->height);
    for(int y=0; y<img->height; y++) {
        for(int x=0; x<img->width; x++) {
            fscanf(fp, "%d", &img->pixels[y][x]);
        }
    }
    fclose(fp);
}

void write_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Failed to open file for writing: %s", filename);
        exit(1);
    }
    fprintf(fp, "%d %d\n", img->width, img->height);
    for(int y=0; y<img->height; y++) {
        for(int x=0; x<img->width; x++) {
            fprintf(fp, "%d ", img->pixels[y][x]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    Image img;
    read_image(&img, "sample.pgm");
    flip_image(&img);
    adjust_brightness(&img, 50);
    adjust_contrast(&img, 50);
    write_image(&img, "output.pgm");
    return 0;
}