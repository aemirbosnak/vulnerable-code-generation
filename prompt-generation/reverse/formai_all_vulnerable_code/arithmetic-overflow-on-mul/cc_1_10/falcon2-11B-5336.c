//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    int width;
    int height;
    unsigned char *data;
} image;

typedef struct {
    image *original;
    image *watermark;
} image_pair;

image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int width, height;
    unsigned char *data = NULL;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    data = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (data == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    fread(data, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    image *img = (image *)malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = data;

    return img;
}

image_pair *load_image_pair(const char *original_filename, const char *watermark_filename) {
    image *original = load_image(original_filename);
    image *watermark = load_image(watermark_filename);

    image_pair *pair = (image_pair *)malloc(sizeof(image_pair));
    pair->original = original;
    pair->watermark = watermark;

    return pair;
}

void save_image(const char *filename, image *img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);
    fwrite(img->data, sizeof(unsigned char), img->width * img->height, fp);
    fclose(fp);
}

void save_image_pair(const char *filename, image_pair *pair) {
    save_image(filename, pair->original);
    save_image(filename + 2, pair->watermark);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s original_image watermark_image\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    image_pair *pair = load_image_pair(argv[1], argv[2]);

    for (int y = 0; y < pair->original->height; y++) {
        for (int x = 0; x < pair->original->width; x++) {
            unsigned char *original_pixel = pair->original->data + (y * pair->original->width + x) * 3;
            unsigned char *watermark_pixel = pair->watermark->data + (y * pair->watermark->width + x) * 3;

            unsigned char red = original_pixel[0];
            unsigned char green = original_pixel[1];
            unsigned char blue = original_pixel[2];

            if (red > 127 || green > 127 || blue > 127) {
                red -= 50;
                green -= 50;
                blue -= 50;
            } else {
                red += 50;
                green += 50;
                blue += 50;
            }

            unsigned char *new_pixel = pair->original->data + (y * pair->original->width + x) * 3;
            new_pixel[0] = red;
            new_pixel[1] = green;
            new_pixel[2] = blue;
        }
    }

    save_image_pair("output.png", pair);

    return 0;
}