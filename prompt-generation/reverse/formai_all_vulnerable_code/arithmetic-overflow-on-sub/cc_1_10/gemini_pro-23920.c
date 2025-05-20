//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width, height;
    unsigned char *pixels;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    Image *image = malloc(sizeof(Image));
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    image->pixels = malloc(image->width * image->height * 3);
    fread(image->pixels, 1, image->width * image->height * 3, fp);
    fclose(fp);

    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) return;

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->pixels, 1, image->width * image->height * 3, fp);
    fclose(fp);
}

void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i++) {
        image->pixels[i] = 255 - image->pixels[i];
    }
}

void grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char avg = (image->pixels[i * 3] + image->pixels[i * 3 + 1] + image->pixels[i * 3 + 2]) / 3;
        image->pixels[i * 3] = avg;
        image->pixels[i * 3 + 1] = avg;
        image->pixels[i * 3 + 2] = avg;
    }
}

void blur(Image *image) {
    unsigned char *new_pixels = malloc(image->width * image->height * 3);

    for (int i = 1; i < image->width - 1; i++) {
        for (int j = 1; j < image->height - 1; j++) {
            unsigned char r = 0, g = 0, b = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    r += image->pixels[(i + k) * 3 + (j + l) * image->width * 3];
                    g += image->pixels[(i + k) * 3 + 1 + (j + l) * image->width * 3];
                    b += image->pixels[(i + k) * 3 + 2 + (j + l) * image->width * 3];
                }
            }
            new_pixels[i * 3 + j * image->width * 3] = r / 9;
            new_pixels[i * 3 + 1 + j * image->width * 3] = g / 9;
            new_pixels[i * 3 + 2 + j * image->width * 3] = b / 9;
        }
    }

    memcpy(image->pixels, new_pixels, image->width * image->height * 3);
    free(new_pixels);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    char *input_image = argv[1];
    char *output_image = argv[2];

    Image *image = load_image(input_image);
    if (!image) {
        printf("Error: could not load image %s\n", input_image);
        return 1;
    }

    invert_colors(image);
    grayscale(image);
    blur(image);

    save_image(output_image, image);

    free(image->pixels);
    free(image);

    return 0;
}