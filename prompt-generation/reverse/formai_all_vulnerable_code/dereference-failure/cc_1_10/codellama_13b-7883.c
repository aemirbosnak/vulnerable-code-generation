//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_IMAGE_SIZE 10000

struct Image {
    int width;
    int height;
    int **pixels;
};

struct Image *create_image(int width, int height) {
    struct Image *image = malloc(sizeof(struct Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(int *));
    for (int i = 0; i < width * height; i++) {
        image->pixels[i] = malloc(3 * sizeof(int));
    }
    return image;
}

void destroy_image(struct Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void flip_image(struct Image *image) {
    int **pixels = image->pixels;
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height / 2; j++) {
            int *tmp = pixels[i * image->height + j];
            pixels[i * image->height + j] = pixels[i * image->height + image->height - j - 1];
            pixels[i * image->height + image->height - j - 1] = tmp;
        }
    }
}

void adjust_brightness(struct Image *image, int brightness) {
    int **pixels = image->pixels;
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            for (int k = 0; k < 3; k++) {
                pixels[i * image->height + j][k] += brightness;
            }
        }
    }
}

void adjust_contrast(struct Image *image, float contrast) {
    int **pixels = image->pixels;
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            for (int k = 0; k < 3; k++) {
                pixels[i * image->height + j][k] = (int)(contrast * (pixels[i * image->height + j][k] - 128) + 128);
            }
        }
    }
}

int main() {
    struct Image *image = create_image(5, 5);
    flip_image(image);
    adjust_brightness(image, 50);
    adjust_contrast(image, 1.5);
    destroy_image(image);
    return 0;
}