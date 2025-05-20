//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    image->data = malloc(image->width * image->height);
    if (!image->data) {
        free(image);
        fclose(file);
        return NULL;
    }

    fread(image->data, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);

    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

void adjust_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] += brightness;
        if (image->data[i] > 255) {
            image->data[i] = 255;
        } else if (image->data[i] < 0) {
            image->data[i] = 0;
        }
    }
}

void adjust_contrast(Image *image, float contrast) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = (image->data[i] - 128) * contrast + 128;
        if (image->data[i] > 255) {
            image->data[i] = 255;
        } else if (image->data[i] < 0) {
            image->data[i] = 0;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        printf("Error: could not load image\n");
        return 1;
    }

    flip_image(image);
    adjust_brightness(image, 30);
    adjust_contrast(image, 1.5);

    save_image(image, "output.bmp");

    free(image->data);
    free(image);

    return 0;
}