//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    int width, height;
    Color *pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("malloc");
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Color));
    if (image->pixels == NULL) {
        perror("malloc");
        free(image);
        return NULL;
    }

    return image;
}

void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

int save_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Color), image->width * image->height, fp);

    fclose(fp);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    const char *filename = argv[1];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    int width, height;
    fscanf(fp, "%d %d\n", &width, &height);

    Image *image = create_image(width, height);
    if (image == NULL) {
        fclose(fp);
        return -1;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fp, "%hhu %hhu %hhu\n", &image->pixels[i * width + j].r, &image->pixels[i * width + j].g, &image->pixels[i * width + j].b);
        }
    }

    fclose(fp);

    if (save_image(image, "output.ppm") < 0) {
        destroy_image(image);
        return -1;
    }

    destroy_image(image);

    return 0;
}