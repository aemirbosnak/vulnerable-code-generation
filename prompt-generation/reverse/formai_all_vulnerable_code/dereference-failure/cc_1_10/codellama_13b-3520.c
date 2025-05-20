//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
/*
 * Simple C Basic Image Processing
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct {
    int width;
    int height;
    int channels;
    int stride;
    unsigned char *data;
} Image;

void flip_image(Image *img) {
    int i, j;
    unsigned char temp;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width / 2; j++) {
            temp = img->data[i * img->stride + j];
            img->data[i * img->stride + j] = img->data[i * img->stride + img->width - j - 1];
            img->data[i * img->stride + img->width - j - 1] = temp;
        }
    }
}

void adjust_brightness(Image *img, float brightness) {
    int i, j;
    float scale = 1.0 + brightness;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->data[i * img->stride + j] = (unsigned char)(scale * img->data[i * img->stride + j]);
        }
    }
}

void adjust_contrast(Image *img, float contrast) {
    int i, j;
    float scale = (1.0 + contrast) / 2.0;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->data[i * img->stride + j] = (unsigned char)(scale * img->data[i * img->stride + j] + 128.0);
        }
    }
}

int main() {
    Image img;
    img.width = 1024;
    img.height = 1024;
    img.channels = 3;
    img.stride = img.width * img.channels;
    img.data = (unsigned char *)malloc(img.stride * img.height * sizeof(unsigned char));

    flip_image(&img);
    adjust_brightness(&img, 0.5);
    adjust_contrast(&img, 0.5);

    free(img.data);

    return 0;
}