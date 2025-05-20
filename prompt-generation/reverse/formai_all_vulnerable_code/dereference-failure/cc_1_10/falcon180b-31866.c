//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_COLOR 255

typedef struct {
    int width;
    int height;
    int **data;
} Image;

void createImage(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        img->data[i] = (int *)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            img->data[i][j] = 0;
        }
    }
}

void destroyImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
}

void setPixel(Image *img, int x, int y, int color) {
    if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
        img->data[y][x] = color;
    }
}

int getPixel(Image *img, int x, int y) {
    if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
        return img->data[y][x];
    }
    return 0;
}

void printImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Image img1, img2;
    createImage(&img1, 10, 10);
    createImage(&img2, 10, 10);

    setPixel(&img1, 0, 0, 255);
    setPixel(&img2, 0, 0, 0);

    printImage(&img1);
    printImage(&img2);

    destroyImage(&img1);
    destroyImage(&img2);

    return 0;
}