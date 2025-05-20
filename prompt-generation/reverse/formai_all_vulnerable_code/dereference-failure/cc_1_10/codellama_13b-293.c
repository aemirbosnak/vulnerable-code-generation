//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1000000

typedef struct {
    int width;
    int height;
    int* pixels;
} Image;

void print_image(Image* image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%d ", image->pixels[i * image->width + j]);
        }
        printf("\n");
    }
}

Image* create_image(int width, int height) {
    Image* image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(int));
    return image;
}

void destroy_image(Image* image) {
    free(image->pixels);
    free(image);
}

void rotate_image(Image* image, float angle) {
    int new_width = round(image->width * cos(angle) + image->height * sin(angle));
    int new_height = round(image->width * sin(angle) + image->height * cos(angle));
    Image* new_image = create_image(new_width, new_height);

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int new_i = round(j * cos(angle) - i * sin(angle));
            int new_j = round(j * sin(angle) + i * cos(angle));
            new_image->pixels[new_i * new_width + new_j] = image->pixels[i * image->width + j];
        }
    }

    destroy_image(image);
    image = new_image;
}

void resize_image(Image* image, float factor) {
    int new_width = round(image->width * factor);
    int new_height = round(image->height * factor);
    Image* new_image = create_image(new_width, new_height);

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int new_i = round(i * factor);
            int new_j = round(j * factor);
            new_image->pixels[new_i * new_width + new_j] = image->pixels[i * image->width + j];
        }
    }

    destroy_image(image);
    image = new_image;
}

void apply_filter(Image* image, int filter[]) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int new_pixel = 0;
            for (int k = 0; k < 3; k++) {
                new_pixel += image->pixels[i * image->width + j] * filter[k];
            }
            image->pixels[i * image->width + j] = new_pixel;
        }
    }
}

int main() {
    Image* image = create_image(100, 100);

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i * image->width + j] = 255;
        }
    }

    print_image(image);

    rotate_image(image, 45);
    resize_image(image, 0.5);
    apply_filter(image, (int[]){1, 2, 3});

    print_image(image);

    destroy_image(image);

    return 0;
}