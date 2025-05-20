//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define HEIGHT 100
#define WIDTH 100
#define MAX_VALUE 255

typedef struct {
    int height;
    int width;
    unsigned char *data;
} Image;

void create_image(Image *img) {
    img->height = HEIGHT;
    img->width = WIDTH;
    img->data = (unsigned char *)malloc(img->height * img->width * sizeof(unsigned char));

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i * img->width + j] = (unsigned char)(i * j % 256);
        }
    }
}

void display_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d ", img->data[i * img->width + j]);
        }
        printf("\n");
    }
}

void flip_image(Image *img) {
    for (int i = 0; i < img->height / 2; i++) {
        for (int j = 0; j < img->width; j++) {
            unsigned char temp = img->data[(img->height - 1 - i) * img->width + j];
            img->data[(img->height - 1 - i) * img->width + j] = img->data[i * img->width + j];
            img->data[i * img->width + j] = temp;
        }
    }
}

void adjust_brightness(Image *img, int delta) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int value = img->data[i * img->width + j];
            value += delta;

            if (value < 0) {
                value = 0;
            } else if (value > MAX_VALUE) {
                value = MAX_VALUE;
            }

            img->data[i * img->width + j] = (unsigned char)value;
        }
    }
}

void adjust_contrast(Image *img, int delta) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int value = img->data[i * img->width + j];
            value = (value * (MAX_VALUE + delta)) / MAX_VALUE;

            if (value < 0) {
                value = 0;
            } else if (value > MAX_VALUE) {
                value = MAX_VALUE;
            }

            img->data[i * img->width + j] = (unsigned char)value;
        }
    }
}

int main() {
    Image img;
    create_image(&img);

    display_image(&img);

    flip_image(&img);
    display_image(&img);

    adjust_brightness(&img, 50);
    display_image(&img);

    adjust_contrast(&img, 50);
    display_image(&img);

    free(img.data);
    return 0;
}