//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct pixel_t {
    uint8_t r, g, b, a;
} pixel_t;

typedef struct image_t {
    uint16_t width, height;
    pixel_t *pixels;
} image_t;

image_t *read_image(const char *file) {
    FILE *fp = fopen(file, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", file);
        return NULL;
    }

    image_t *img = malloc(sizeof(image_t));
    if (img == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(fp);
        return NULL;
    }

    fread(&img->width, sizeof(uint16_t), 1, fp);
    fread(&img->height, sizeof(uint16_t), 1, fp);
    img->pixels = malloc(sizeof(pixel_t) * img->width * img->height);
    if (img->pixels == NULL) {
        fprintf(stderr, "Error allocating memory for image pixels\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    fread(img->pixels, sizeof(pixel_t), img->width * img->height, fp);
    fclose(fp);

    return img;
}

void write_image(const char *file, image_t *img) {
    FILE *fp = fopen(file, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", file);
        return;
    }

    fwrite(&img->width, sizeof(uint16_t), 1, fp);
    fwrite(&img->height, sizeof(uint16_t), 1, fp);
    fwrite(img->pixels, sizeof(pixel_t), img->width * img->height, fp);
    fclose(fp);
}

void flip_image(image_t *img) {
    for (int i = 0; i < img->height / 2; i++) {
        for (int j = 0; j < img->width; j++) {
            pixel_t temp = img->pixels[i * img->width + j];
            img->pixels[i * img->width + j] = img->pixels[(img->height - 1 - i) * img->width + j];
            img->pixels[(img->height - 1 - i) * img->width + j] = temp;
        }
    }
}

void adjust_brightness(image_t *img, int brightness) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = img->pixels[i].r + brightness;
        img->pixels[i].g = img->pixels[i].g + brightness;
        img->pixels[i].b = img->pixels[i].b + brightness;
        if (img->pixels[i].r > 255) img->pixels[i].r = 255;
        if (img->pixels[i].g > 255) img->pixels[i].g = 255;
        if (img->pixels[i].b > 255) img->pixels[i].b = 255;
    }
}

void adjust_contrast(image_t *img, int contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = img->pixels[i].r * (1 + contrast / 100.0);
        img->pixels[i].g = img->pixels[i].g * (1 + contrast / 100.0);
        img->pixels[i].b = img->pixels[i].b * (1 + contrast / 100.0);
        if (img->pixels[i].r > 255) img->pixels[i].r = 255;
        if (img->pixels[i].g > 255) img->pixels[i].g = 255;
        if (img->pixels[i].b > 255) img->pixels[i].b = 255;
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input_file output_file [options]\n", argv[0]);
        return 1;
    }

    image_t *img = read_image(argv[1]);
    if (img == NULL) {
        return 1;
    }

    int brightness = 0, contrast = 0;
    int flip = 0;

    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "-flip") == 0) {
            flip = 1;
        } else if (strcmp(argv[i], "-brightness") == 0) {
            brightness = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-contrast") == 0) {
            contrast = atoi(argv[++i]);
        } else {
            fprintf(stderr, "Invalid option '%s'\n", argv[i]);
            return 1;
        }
    }

    if (flip) {
        flip_image(img);
    }

    if (brightness != 0) {
        adjust_brightness(img, brightness);
    }

    if (contrast != 0) {
        adjust_contrast(img, contrast);
    }

    write_image(argv[2], img);
    free(img->pixels);
    free(img);

    return 0;
}