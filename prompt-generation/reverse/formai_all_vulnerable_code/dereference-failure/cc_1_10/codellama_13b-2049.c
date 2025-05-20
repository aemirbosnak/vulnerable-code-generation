//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

Image *create_image(int width, int height, int channels) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->channels = channels;
    img->data = (unsigned char *)malloc(width * height * channels * sizeof(unsigned char));
    return img;
}

void destroy_image(Image *img) {
    free(img->data);
    free(img);
}

void flip_image(Image *img) {
    int width = img->width;
    int height = img->height;
    int channels = img->channels;
    unsigned char *data = img->data;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                data[(y * width + x) * channels + c] = 255 - data[(y * width + x) * channels + c];
            }
        }
    }
}

void change_brightness(Image *img, int brightness) {
    int width = img->width;
    int height = img->height;
    int channels = img->channels;
    unsigned char *data = img->data;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                data[(y * width + x) * channels + c] += brightness;
            }
        }
    }
}

void change_contrast(Image *img, float contrast) {
    int width = img->width;
    int height = img->height;
    int channels = img->channels;
    unsigned char *data = img->data;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                data[(y * width + x) * channels + c] = (data[(y * width + x) * channels + c] - 128) * contrast + 128;
            }
        }
    }
}

int main() {
    Image *img = create_image(512, 512, 3);
    // Flip the image
    flip_image(img);
    // Change brightness by 10
    change_brightness(img, 10);
    // Change contrast by 2.0
    change_contrast(img, 2.0);
    destroy_image(img);
    return 0;
}