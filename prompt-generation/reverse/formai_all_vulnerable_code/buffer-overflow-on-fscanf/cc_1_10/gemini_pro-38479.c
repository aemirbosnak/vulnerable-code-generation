//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 1280
#define HEIGHT 720
#define CHANNELS 3

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} pixel_t;

typedef struct {
    pixel_t *data;
    int width;
    int height;
    int channels;
} image_t;

image_t *new_image(int width, int height, int channels) {
    image_t *image = malloc(sizeof(image_t));
    image->data = malloc(width * height * channels);
    image->width = width;
    image->height = height;
    image->channels = channels;
    return image;
}

void free_image(image_t *image) {
    free(image->data);
    free(image);
}

pixel_t get_pixel(image_t *image, int x, int y) {
    return image->data[y * image->width * image->channels + x * image->channels];
}

void set_pixel(image_t *image, int x, int y, pixel_t pixel) {
    image->data[y * image->width * image->channels + x * image->channels] = pixel;
}

image_t *load_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    int width, height, channels;
    fscanf(file, "%d %d %d", &width, &height, &channels);

    image_t *image = new_image(width, height, channels);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel_t pixel;
            fread(&pixel, sizeof(pixel), 1, file);
            set_pixel(image, x, y, pixel);
        }
    }

    fclose(file);

    return image;
}

void save_image(image_t *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fprintf(file, "%d %d %d\n", image->width, image->height, image->channels);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t pixel = get_pixel(image, x, y);
            fwrite(&pixel, sizeof(pixel), 1, file);
        }
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    image_t *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Do something with the image...

    save_image(image, "output.ppm");

    free_image(image);

    return 0;
}