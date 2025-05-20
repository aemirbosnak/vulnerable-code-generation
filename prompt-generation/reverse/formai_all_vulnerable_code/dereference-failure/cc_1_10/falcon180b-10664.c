//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    int width;
    int height;
    int **data;
} Image;

Image* createImage(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        image->data[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            image->data[i][j] = 0;
        }
    }
    return image;
}

void destroyImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

void setPixel(Image *image, int x, int y, int value) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        image->data[y][x] = value;
    }
}

int getPixel(Image *image, int x, int y) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        return image->data[y][x];
    }
    return 0;
}

void printImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%d ", getPixel(image, j, i));
        }
        printf("\n");
    }
}

int main() {
    Image *image = createImage(50, 50);
    setPixel(image, 10, 10, 255);
    setPixel(image, 20, 20, 255);
    setPixel(image, 30, 30, 255);
    printImage(image);
    destroyImage(image);
    return 0;
}