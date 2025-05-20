//FormAI DATASET v1.0 Category: Image Editor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct pixel {
    unsigned char r, g, b;
};

struct image {
    int width;
    int height;
    struct pixel *pixels;
};

struct image loadImage(const char* filename)
{
    FILE *file;
    struct image result;
    int i, j;

    file = fopen(filename, "rb");

    if (!file) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    fscanf(file, "P6\n");
    fscanf(file, "%d %d\n", &result.width, &result.height);
    fscanf(file, "255\n");

    result.pixels = malloc(sizeof(struct pixel) * result.width * result.height);

    if (!result.pixels) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    for (i = 0; i < result.height; i++) {
        for (j = 0; j < result.width; j++) {
            result.pixels[i * result.width + j].r = fgetc(file);
            result.pixels[i * result.width + j].g = fgetc(file);
            result.pixels[i * result.width + j].b = fgetc(file);
        }
    }

    fclose(file);

    return result;
}

void saveImage(const char* filename, struct image img)
{
    FILE *file;
    int i, j;

    file = fopen(filename, "wb");

    if (!file) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", img.width, img.height);
    fprintf(file, "255\n");

    for (i = 0; i < img.height; i++) {
        for (j = 0; j < img.width; j++) {
            fputc(img.pixels[i * img.width + j].r, file);
            fputc(img.pixels[i * img.width + j].g, file);
            fputc(img.pixels[i * img.width + j].b, file);
        }
    }

    fclose(file);
}

void invertColors(struct image *img)
{
    int i, j;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->pixels[i * img->width + j].r = 255 - img->pixels[i * img->width + j].r;
            img->pixels[i * img->width + j].g = 255 - img->pixels[i * img->width + j].g;
            img->pixels[i * img->width + j].b = 255 - img->pixels[i * img->width + j].b;
        }
    }
}

void grayscale(struct image *img)
{
    int i, j;
    unsigned char gray;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            gray = (img->pixels[i * img->width + j].r + img->pixels[i * img->width + j].g + img->pixels[i * img->width + j].b) / 3;
            img->pixels[i * img->width + j].r = gray;
            img->pixels[i * img->width + j].g = gray;
            img->pixels[i * img->width + j].b = gray;
        }
    }
}

int main(int argc, char *argv[])
{
    struct image img;
    int i, j;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <action>\n", argv[0]);
        return 1;
    }

    img = loadImage(argv[1]);

    if (strcmp(argv[3], "invert") == 0) {
        invertColors(&img);
    } else if (strcmp(argv[3], "grayscale") == 0) {
        grayscale(&img);
    } else {
        fprintf(stderr, "Invalid action: %s\n", argv[3]);
        return 1;
    }

    saveImage(argv[2], img);

    free(img.pixels);

    return 0;
}