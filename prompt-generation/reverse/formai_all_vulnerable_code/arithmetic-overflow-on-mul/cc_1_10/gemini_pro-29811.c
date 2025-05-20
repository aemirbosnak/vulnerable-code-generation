//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} pixel_t;

typedef struct {
    pixel_t *pixels;
    int width, height;
} image_t;

image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->pixels = malloc(image->width * image->height * sizeof(pixel_t));
    if (!image->pixels) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->pixels, sizeof(pixel_t), image->width * image->height, fp);

    fclose(fp);

    return image;
}

void free_image(image_t *image) {
    free(image->pixels);
    free(image);
}

char *convert_image_to_ascii(const image_t *image) {
    char *ascii_image = malloc(image->width * image->height + 1);
    if (!ascii_image) {
        perror("malloc");
        return NULL;
    }

    for (int i = 0; i < image->width * image->height; i++) {
        double brightness = 0.2126 * image->pixels[i].r + 0.7152 * image->pixels[i].g + 0.0722 * image->pixels[i].b;
        int ascii_index = (int)round(brightness / 255.0 * 60);
        ascii_image[i] = "!@#&%?=)(,.;:-+*#%@"[ascii_index];
    }

    ascii_image[image->width * image->height] = '\0';

    return ascii_image;
}

void print_ascii_image(const char *ascii_image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_image[i * width + j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    image_t *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    char *ascii_image = convert_image_to_ascii(image);
    if (!ascii_image) {
        free_image(image);
        return 1;
    }

    print_ascii_image(ascii_image, image->width, image->height);

    free(ascii_image);
    free_image(image);

    return 0;
}