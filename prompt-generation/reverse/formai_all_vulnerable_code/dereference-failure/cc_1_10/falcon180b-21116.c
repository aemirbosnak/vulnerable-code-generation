//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_VALUE 255

typedef struct {
    int width;
    int height;
    int **data;
} Image;

Image* createImage(int width, int height) {
    Image *image = (Image*)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        image->data[i] = (int*)malloc(width * sizeof(int));
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

void flipImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            int temp = image->data[i][j];
            image->data[i][j] = image->data[i][image->width - j - 1];
            image->data[i][image->width - j - 1] = temp;
        }
    }
}

void changeBrightness(Image *image, int delta) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int value = image->data[i][j];
            value += delta;
            if (value > MAX_VALUE) {
                value = MAX_VALUE;
            } else if (value < 0) {
                value = 0;
            }
            image->data[i][j] = value;
        }
    }
}

void changeContrast(Image *image, int delta) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int value = image->data[i][j];
            int factor = (MAX_VALUE - value) * delta / 100;
            value += factor;
            if (value > MAX_VALUE) {
                value = MAX_VALUE;
            } else if (value < 0) {
                value = 0;
            }
            image->data[i][j] = value;
        }
    }
}

void printImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%d ", image->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Image *image = createImage(WIDTH, HEIGHT);
    int value = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image->data[i][j] = value++;
        }
    }
    printImage(image);
    flipImage(image);
    printImage(image);
    changeBrightness(image, 50);
    printImage(image);
    changeContrast(image, 50);
    printImage(image);
    destroyImage(image);
    return 0;
}