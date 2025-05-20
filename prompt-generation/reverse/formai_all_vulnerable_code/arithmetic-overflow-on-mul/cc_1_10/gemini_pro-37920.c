//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
    int channels;
} Image;

void flip_image(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width / 2; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - 1 - j];
            image->data[i * image->width + image->width - 1 - j] = temp;
        }
    }
}

void change_brightness(Image *image, int brightness) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            int value = image->data[i * image->width + j] + brightness;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[i * image->width + j] = value;
        }
    }
}

void change_contrast(Image *image, int contrast) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            int value = (image->data[i * image->width + j] - 128) * contrast + 128;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[i * image->width + j] = value;
        }
    }
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }
    fprintf(fp, "P5\n");
    fprintf(fp, "%d %d\n", image->width, image->height);
    fprintf(fp, "255\n");
    fwrite(image->data, 1, image->width * image->height, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <brightness> <contrast>\n", argv[0]);
        exit(1);
    }
    Image image;
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }
    fscanf(fp, "P5\n");
    fscanf(fp, "%d %d\n", &image.width, &image.height);
    fscanf(fp, "255\n");
    image.data = (unsigned char *)malloc(image.width * image.height);
    fread(image.data, 1, image.width * image.height, fp);
    fclose(fp);
    int brightness = atoi(argv[3]);
    int contrast = atoi(argv[4]);
    flip_image(&image);
    change_brightness(&image, brightness);
    change_contrast(&image, contrast);
    save_image(&image, argv[2]);
    free(image.data);
    return 0;
}