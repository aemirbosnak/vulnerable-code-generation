//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_COLOR 256

typedef struct {
    int width;
    int height;
    int *data;
} Image;

void initImage(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = malloc(sizeof(int) * width * height);
    if (img->data == NULL) {
        printf("Error: Failed to allocate memory for image.\n");
        exit(1);
    }
    memset(img->data, 0, sizeof(int) * width * height);
}

void freeImage(Image *img) {
    if (img->data!= NULL) {
        free(img->data);
        img->data = NULL;
    }
}

void drawPixel(Image *img, int x, int y, int color) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return;
    }
    img->data[y * img->width + x] = color;
}

void fillRect(Image *img, int x, int y, int width, int height, int color) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            drawPixel(img, x + i, y + j, color);
        }
    }
}

void saveImage(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Failed to open file %s for writing.\n", filename);
        exit(1);
    }
    fprintf(fp, "P6\n%d %d\n%d\n", img->width, img->height, MAX_COLOR);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int color = img->data[i * img->width + j];
            fprintf(fp, "%d ", color);
        }
    }
    fclose(fp);
}

int main() {
    Image img1, img2;
    initImage(&img1, 50, 50);
    initImage(&img2, 50, 50);

    fillRect(&img1, 0, 0, 25, 25, 255);
    fillRect(&img2, 0, 0, 25, 25, 0);

    saveImage(&img1, "image1.png");
    saveImage(&img2, "image2.png");

    freeImage(&img1);
    freeImage(&img2);

    return 0;
}