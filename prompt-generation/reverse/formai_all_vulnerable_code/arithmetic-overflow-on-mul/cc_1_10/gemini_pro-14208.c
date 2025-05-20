//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);

    image->pixels = malloc(image->width * image->height * sizeof(Pixel));
    if (!image->pixels) {
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->pixels, sizeof(Pixel), image->width * image->height, file);

    fclose(file);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);

    fclose(file);
}

void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output ASCII art>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        fprintf(stderr, "Error: could not read image %s\n", argv[1]);
        return 1;
    }

    char *ascii_art = malloc(image->width * image->height + 1);
    if (!ascii_art) {
        fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
        free_image(image);
        return 1;
    }

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel = image->pixels[y * image->width + x];
            int gray = (pixel.red + pixel.green + pixel.blue) / 3;
            char *character = "#";
            if (gray > 192) {
                character = " ";
            } else if (gray > 128) {
                character = ".";
            } else if (gray > 64) {
                character = ":";
            } else if (gray > 32) {
                character = "~";
            } else {
                character = "#";
            }
            ascii_art[y * image->width + x] = character;
        }
    }

    ascii_art[image->width * image->height] = '\0';

    FILE *file = fopen(argv[2], "w");
    if (!file) {
        fprintf(stderr, "Error: could not open output file %s\n", argv[2]);
        free(ascii_art);
        free_image(image);
        return 1;
    }

    fprintf(file, "%s", ascii_art);

    fclose(file);

    free(ascii_art);
    free_image(image);

    return 0;
}