//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width;
    int height;
    pixel *pixels;
} image;

image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (img == NULL) {
        fclose(file);
        return NULL;
    }

    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);

    img->pixels = malloc(sizeof(pixel) * img->width * img->height);
    if (img->pixels == NULL) {
        fclose(file);
        free(img);
        return NULL;
    }

    fread(img->pixels, sizeof(pixel), img->width * img->height, file);

    fclose(file);

    return img;
}

void free_image(image *img) {
    free(img->pixels);
    free(img);
}

void to_ascii(image *img) {
    char *chars = "@#%*=+;:,. ";

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int r = img->pixels[y * img->width + x].r;
            int g = img->pixels[y * img->width + x].g;
            int b = img->pixels[y * img->width + x].b;

            int gray = (r + g + b) / 3;
            int index = (gray / (256 / strlen(chars)));

            printf("%c", chars[index]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    image *img = load_image(argv[1]);
    if (img == NULL) {
        printf("Failed to load image\n");
        return 1;
    }

    to_ascii(img);

    free_image(img);

    return 0;
}