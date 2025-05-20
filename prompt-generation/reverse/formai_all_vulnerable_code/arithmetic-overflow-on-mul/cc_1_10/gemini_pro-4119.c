//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t r, g, b;
} pixel_t;

typedef struct {
    int width, height;
    pixel_t *pixels;
} image_t;

char *ascii_chars = " .:!/()[]{}<>,.*#";

void read_image(image_t *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    image->pixels = malloc(image->width * image->height * sizeof(pixel_t));
    fread(image->pixels, sizeof(pixel_t), image->width * image->height, fp);
    fclose(fp);
}

void write_ascii_art(image_t *image, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t *pixel = &image->pixels[y * image->width + x];
            double brightness = (pixel->r + pixel->g + pixel->b) / (3.0 * 255.0);
            int index = (int)(brightness * (strlen(ascii_chars) - 1));
            fprintf(fp, "%c", ascii_chars[index]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output ascii art>\n", argv[0]);
        exit(1);
    }

    image_t image;
    read_image(&image, argv[1]);
    write_ascii_art(&image, argv[2]);

    return 0;
}