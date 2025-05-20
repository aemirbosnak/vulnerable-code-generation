//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    uint8_t *pixels;
    int width;
    int height;
    int channels;
} Image;

Image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    int width, height, channels;
    fscanf(fp, "%d %d %d", &width, &height, &channels);

    Image *image = malloc(sizeof(Image));
    image->pixels = malloc(width * height * channels);
    image->width = width;
    image->height = height;
    image->channels = channels;

    fread(image->pixels, 1, width * height * channels, fp);

    fclose(fp);

    return image;
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fprintf(fp, "%d %d %d\n", image->width, image->height, image->channels);

    fwrite(image->pixels, 1, image->width * image->height * image->channels, fp);

    fclose(fp);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                uint8_t tmp = image->pixels[i * image->width * image->channels + j * image->channels + k];
                image->pixels[i * image->width * image->channels + j * image->channels + k] = image->pixels[(image->height - i - 1) * image->width * image->channels + j * image->channels + k];
                image->pixels[(image->height - i - 1) * image->width * image->channels + j * image->channels + k] = tmp;
            }
        }
    }
}

void change_brightness_contrast(Image *image, double brightness, double contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                double pixel = (double)image->pixels[i * image->width * image->channels + j * image->channels + k];
                pixel = (pixel - 127.5) * contrast + 127.5 * brightness;
                if (pixel < 0) pixel = 0;
                if (pixel > 255) pixel = 255;
                image->pixels[i * image->width * image->channels + j * image->channels + k] = (uint8_t)pixel;
            }
        }
    }
}

int main() {
    Image *image = load_image("image.ppm");
    if (image == NULL) {
        return 1;
    }

    flip_image(image);
    change_brightness_contrast(image, 0.5, 1.2);

    save_image(image, "output.ppm");

    free(image->pixels);
    free(image);

    return 0;
}