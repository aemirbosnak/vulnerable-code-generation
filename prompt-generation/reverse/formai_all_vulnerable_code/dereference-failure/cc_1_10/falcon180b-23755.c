//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define PIXEL_SIZE 3

typedef struct {
    int width;
    int height;
    char *data;
} Image;

void create_image(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = (char *)malloc(width * height * PIXEL_SIZE);
    memset(img->data, 0, width * height * PIXEL_SIZE);
}

void destroy_image(Image *img) {
    free(img->data);
    memset(img, 0, sizeof(Image));
}

void set_pixel(Image *img, int x, int y, char color) {
    int index = (y * img->width + x) * PIXEL_SIZE;
    img->data[index] = color;
    img->data[index + 1] = color;
    img->data[index + 2] = color;
}

char get_pixel(Image *img, int x, int y) {
    int index = (y * img->width + x) * PIXEL_SIZE;
    return img->data[index];
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not save image to file.\n");
        return;
    }

    fwrite(img->data, img->width * img->height * PIXEL_SIZE, 1, fp);
    fclose(fp);
}

int main() {
    Image img1, img2;

    // Create two images
    create_image(&img1, 500, 500);
    create_image(&img2, 500, 500);

    // Fill the first image with random pixels
    for (int i = 0; i < img1.width; i++) {
        for (int j = 0; j < img1.height; j++) {
            set_pixel(&img1, i, j, rand() % 256);
        }
    }

    // Copy the first image to the second image
    for (int i = 0; i < img1.width; i++) {
        for (int j = 0; j < img1.height; j++) {
            set_pixel(&img2, i, j, get_pixel(&img1, i, j));
        }
    }

    // Save the second image to a file
    save_image(&img2, "output.bmp");

    // Destroy the images
    destroy_image(&img1);
    destroy_image(&img2);

    return 0;
}