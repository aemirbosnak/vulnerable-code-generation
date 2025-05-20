//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_VALUE 255

typedef struct {
    int x, y;
} Point;

typedef struct {
    int width, height;
    int **data;
} Image;

void init_image(Image *img) {
    img->width = WIDTH;
    img->height = HEIGHT;
    img->data = (int **)malloc(img->height * sizeof(int *));
    for (int i = 0; i < img->height; i++) {
        img->data[i] = (int *)malloc(img->width * sizeof(int));
    }
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i][j] = rand() % MAX_VALUE;
        }
    }
}

void print_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->data[i][j]);
        }
        printf("\n");
    }
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

void change_brightness(Image *img, int delta) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i][j] += delta;
            if (img->data[i][j] > MAX_VALUE) {
                img->data[i][j] = MAX_VALUE;
            } else if (img->data[i][j] < 0) {
                img->data[i][j] = 0;
            }
        }
    }
}

void change_contrast(Image *img, int delta) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int value = img->data[i][j];
            img->data[i][j] = (value * (MAX_VALUE + delta)) / MAX_VALUE;
            if (img->data[i][j] > MAX_VALUE) {
                img->data[i][j] = MAX_VALUE;
            } else if (img->data[i][j] < 0) {
                img->data[i][j] = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Image img;
    init_image(&img);
    print_image(&img);

    flip_image(&img);
    printf("Flipped image:\n");
    print_image(&img);

    change_brightness(&img, 50);
    printf("Increased brightness by 50:\n");
    print_image(&img);

    change_contrast(&img, 50);
    printf("Increased contrast by 50:\n");
    print_image(&img);

    return 0;
}