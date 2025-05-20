//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    image->width = 0;
    image->height = 0;
    image->pixels = NULL;

    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));

    fread(image->pixels, sizeof(Pixel), width * height, file);

    fclose(file);

    return image;
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);

    fclose(file);
}

void flip_image(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel temp = image->pixels[y * image->width + x];
            image->pixels[y * image->width + x] = image->pixels[(image->height - y - 1) * image->width + x];
            image->pixels[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

void adjust_brightness(Image *image, double brightness) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r = fmin(255, image->pixels[i].r * brightness);
        image->pixels[i].g = fmin(255, image->pixels[i].g * brightness);
        image->pixels[i].b = fmin(255, image->pixels[i].b * brightness);
    }
}

void adjust_contrast(Image *image, double contrast) {
    for (int i = 0; i < image->width * image->height; i++) {
        double gray = (image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3.0;
        double new_gray = (gray - 127.5) * contrast + 127.5;
        image->pixels[i].r = fmin(255, round(new_gray));
        image->pixels[i].g = fmin(255, round(new_gray));
        image->pixels[i].b = fmin(255, round(new_gray));
    }
}

int main() {
    Image *image = load_image("input.bmp");

    flip_image(image);
    adjust_brightness(image, 1.2);
    adjust_contrast(image, 1.5);

    save_image(image, "output.bmp");

    free(image->pixels);
    free(image);

    return 0;
}