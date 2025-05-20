//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (!img) {
        perror("Error allocating memory for image");
        fclose(fp);
        return NULL;
    }

    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);

    img->data = malloc(sizeof(pixel) * img->width * img->height);
    if (!img->data) {
        perror("Error allocating memory for image data");
        free(img);
        fclose(fp);
        return NULL;
    }

    fread(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);

    return img;
}

void save_image(const char *filename, image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);

    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void flip_image(image *img) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width / 2; j++) {
            pixel temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[i * img->width + img->width - j - 1];
            img->data[i * img->width + img->width - j - 1] = temp;
        }
    }
}

void change_brightness(image *img, double factor) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->data[i * img->width + j].r = (unsigned char)fmax(0, fmin(255, img->data[i * img->width + j].r * factor));
            img->data[i * img->width + j].g = (unsigned char)fmax(0, fmin(255, img->data[i * img->width + j].g * factor));
            img->data[i * img->width + j].b = (unsigned char)fmax(0, fmin(255, img->data[i * img->width + j].b * factor));
        }
    }
}

void change_contrast(image *img, double factor) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->data[i * img->width + j].r = (unsigned char)fmax(0, fmin(255, 128 + (img->data[i * img->width + j].r - 128) * factor));
            img->data[i * img->width + j].g = (unsigned char)fmax(0, fmin(255, 128 + (img->data[i * img->width + j].g - 128) * factor));
            img->data[i * img->width + j].b = (unsigned char)fmax(0, fmin(255, 128 + (img->data[i * img->width + j].b - 128) * factor));
        }
    }
}

int main() {
    image *img = load_image("input.bmp");
    if (!img) {
        return 1;
    }

    flip_image(img);
    change_brightness(img, 1.5);
    change_contrast(img, 1.2);

    save_image("output.bmp", img);
    free(img->data);
    free(img);

    return 0;
}