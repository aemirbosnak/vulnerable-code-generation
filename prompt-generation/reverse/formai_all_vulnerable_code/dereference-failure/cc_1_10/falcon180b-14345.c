//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_COLOR 255

typedef struct {
    int width;
    int height;
    int **data;
} Image;

void initImage(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        img->data[i] = (int *)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            img->data[i][j] = rand() % MAX_COLOR;
        }
    }
}

void printImage(Image img) {
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%d ", img.data[i][j]);
        }
        printf("\n");
    }
}

void freeImage(Image img) {
    for (int i = 0; i < img.height; i++) {
        free(img.data[i]);
    }
    free(img.data);
}

int main() {
    srand(time(NULL));

    Image img1, img2, result;
    initImage(&img1, 10, 10);
    initImage(&img2, 10, 10);
    initImage(&result, 10, 10);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            result.data[i][j] = (img1.data[i][j] + img2.data[i][j]) / 2;
        }
    }

    printImage(result);

    freeImage(result);
    freeImage(img1);
    freeImage(img2);

    return 0;
}