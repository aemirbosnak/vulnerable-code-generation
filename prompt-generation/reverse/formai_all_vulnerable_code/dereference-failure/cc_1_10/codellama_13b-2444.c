//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

typedef struct {
    int width;
    int height;
    pixel *data;
} image;

image *load_image(char *filename) {
    image *img = (image *)malloc(sizeof(image));
    img->data = (pixel *)malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(pixel));
    img->width = MAX_WIDTH;
    img->height = MAX_HEIGHT;

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fread(img->data, sizeof(pixel), MAX_WIDTH * MAX_HEIGHT, fp);
    fclose(fp);

    return img;
}

void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fwrite(img->data, sizeof(pixel), MAX_WIDTH * MAX_HEIGHT, fp);
    fclose(fp);
}

void flip_image_vertical(image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            pixel tmp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[i * img->width + (img->width - 1 - j)];
            img->data[i * img->width + (img->width - 1 - j)] = tmp;
        }
    }
}

void flip_image_horizontal(image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            pixel tmp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[(img->height - 1 - i) * img->width + j];
            img->data[(img->height - 1 - i) * img->width + j] = tmp;
        }
    }
}

void adjust_brightness(image *img, int brightness) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            pixel *p = &img->data[i * img->width + j];
            p->r = (p->r * brightness) / 255;
            p->g = (p->g * brightness) / 255;
            p->b = (p->b * brightness) / 255;
        }
    }
}

void adjust_contrast(image *img, int contrast) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            pixel *p = &img->data[i * img->width + j];
            p->r = (((p->r - 128) * contrast) / 128) + 128;
            p->g = (((p->g - 128) * contrast) / 128) + 128;
            p->b = (((p->b - 128) * contrast) / 128) + 128;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    image *img = load_image(argv[1]);

    flip_image_vertical(img);
    adjust_brightness(img, 50);
    adjust_contrast(img, 100);

    save_image(img, argv[2]);

    free(img->data);
    free(img);

    return 0;
}