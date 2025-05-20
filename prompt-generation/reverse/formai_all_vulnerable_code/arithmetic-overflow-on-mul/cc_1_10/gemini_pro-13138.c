//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PIXEL_WIDTH 3
#define PIXEL_HEIGHT 3

typedef struct {
    int r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Allocate memory for the image
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(sizeof(pixel) * width * height);

    // Read the pixel data
    fread(img->data, sizeof(pixel), width * height, file);

    fclose(file);

    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

int get_pixel(image *img, int x, int y) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return 0;
    }

    int r = img->data[y * img->width + x].r;
    int g = img->data[y * img->width + x].g;
    int b = img->data[y * img->width + x].b;

    return (r << 16) | (g << 8) | b;
}

void set_pixel(image *img, int x, int y, int color) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return;
    }

    img->data[y * img->width + x].r = (color >> 16) & 0xFF;
    img->data[y * img->width + x].g = (color >> 8) & 0xFF;
    img->data[y * img->width + x].b = color & 0xFF;
}

void convert_image_to_ascii(image *img, char *output) {
    int i, j;
    char *p = output;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            int color = get_pixel(img, j, i);
            *p++ = " .,:;c889@@";
        }

        *p++ = '\n';
    }

    *p = '\0';
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    image *img = load_image(argv[1]);
    if (!img) {
        return 1;
    }

    char *output = malloc(img->width * img->height * PIXEL_WIDTH * PIXEL_HEIGHT + 1);
    convert_image_to_ascii(img, output);

    free_image(img);

    printf("%s\n", output);

    free(output);

    return 0;
}