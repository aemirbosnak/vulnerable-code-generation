//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

void free_image(Image *img)
{
    free(img->data);
    free(img);
}

Pixel get_pixel(Image *img, int x, int y)
{
    return img->data[y * img->width + x];
}

void set_pixel(Image *img, int x, int y, Pixel p)
{
    img->data[y * img->width + x] = p;
}

Image *load_image(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    char magic[3];
    int width, height, maxval;
    fscanf(fp, "%2s%d%d%d", magic, &width, &height, &maxval);

    if (strcmp(magic, "P6")) {
        fprintf(stderr, "Error: invalid magic number in file %s\n", filename);
        fclose(fp);
        return NULL;
    }

    if (maxval > 255) {
        fprintf(stderr, "Error: could not handle values larger than 255 in file %s\n", filename);
        fclose(fp);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (Pixel *)malloc(sizeof(Pixel) * width * height);

    fread(img->data, sizeof(Pixel), width * height, fp);
    fclose(fp);

    return img;
}

void save_image(const char *filename, Image *img)
{
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s for writing\n", filename);
        return;
    }

    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

void flip_image(Image *img)
{
    int x, y;
    Pixel temp;

    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width / 2; x++) {
            temp = get_pixel(img, x, y);
            set_pixel(img, x, y, get_pixel(img, img->width - x - 1, y));
            set_pixel(img, img->width - x - 1, y, temp);
        }
    }
}

void adjust_brightness(Image *img, int amount)
{
    int x, y;
    Pixel p;

    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            p = get_pixel(img, x, y);

            p.r += amount;
            p.g += amount;
            p.b += amount;

            set_pixel(img, x, y, p);
        }
    }
}

void adjust_contrast(Image *img, float amount)
{
    int x, y;
    Pixel p;

    float factor = (259 * (amount + 255)) / (255 * (259 - amount));

    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            p = get_pixel(img, x, y);

            p.r = round(factor * (p.r - 128) + 128);
            p.g = round(factor * (p.g - 128) + 128);
            p.b = round(factor * (p.b - 128) + 128);

            set_pixel(img, x, y, p);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input output\n", argv[0]);
        return 1;
    }

    Image *img = load_image(argv[1]);
    if (!img) {
        return 1;
    }

    flip_image(img);
    adjust_brightness(img, 50);
    adjust_contrast(img, 1.5);
    save_image(argv[2], img);

    free_image(img);

    return 0;
}