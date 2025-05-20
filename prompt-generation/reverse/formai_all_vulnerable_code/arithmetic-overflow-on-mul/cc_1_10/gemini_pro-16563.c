//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} pixel_t;

typedef struct {
    int width, height;
    pixel_t pixels[MAX_WIDTH * MAX_HEIGHT];
} image_t;

image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (image == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    fread(image->pixels, sizeof(pixel_t), image->width * image->height, fp);

    fclose(fp);

    return image;
}

void save_image(const char *filename, image_t *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    fwrite(image->pixels, sizeof(pixel_t), image->width * image->height, fp);

    fclose(fp);
}

void invert_colors(image_t *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r = 255 - image->pixels[i].r;
        image->pixels[i].g = 255 - image->pixels[i].g;
        image->pixels[i].b = 255 - image->pixels[i].b;
    }
}

void grayscale(image_t *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3;
        image->pixels[i].r = gray;
        image->pixels[i].g = gray;
        image->pixels[i].b = gray;
    }
}

void blur(image_t *image) {
    pixel_t new_pixels[MAX_WIDTH * MAX_HEIGHT];

    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            int sum_r = 0, sum_g = 0, sum_b = 0;
            int count = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = i + k;
                    int y = j + l;

                    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
                        sum_r += image->pixels[y * image->width + x].r;
                        sum_g += image->pixels[y * image->width + x].g;
                        sum_b += image->pixels[y * image->width + x].b;
                        count++;
                    }
                }
            }

            new_pixels[j * image->width + i].r = sum_r / count;
            new_pixels[j * image->width + i].g = sum_g / count;
            new_pixels[j * image->width + i].b = sum_b / count;
        }
    }

    memcpy(image->pixels, new_pixels, sizeof(pixel_t) * image->width * image->height);
}

void sharpen(image_t *image) {
    pixel_t new_pixels[MAX_WIDTH * MAX_HEIGHT];

    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            int sum_r = 0, sum_g = 0, sum_b = 0;
            int count = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = i + k;
                    int y = j + l;

                    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
                        sum_r += image->pixels[y * image->width + x].r;
                        sum_g += image->pixels[y * image->width + x].g;
                        sum_b += image->pixels[y * image->width + x].b;
                        count++;
                    }
                }
            }

            int avg_r = sum_r / count;
            int avg_g = sum_g / count;
            int avg_b = sum_b / count;

            new_pixels[j * image->width + i].r = avg_r + (avg_r - image->pixels[j * image->width + i].r) * 2;
            new_pixels[j * image->width + i].g = avg_g + (avg_g - image->pixels[j * image->width + i].g) * 2;
            new_pixels[j * image->width + i].b = avg_b + (avg_b - image->pixels[j * image->width + i].b) * 2;
        }
    }

    memcpy(image->pixels, new_pixels, sizeof(pixel_t) * image->width * image->height);
}

void edge_detect(image_t *image) {
    pixel_t new_pixels[MAX_WIDTH * MAX_HEIGHT];

    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            int sum_r = 0, sum_g = 0, sum_b = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = i + k;
                    int y = j + l;

                    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
                        sum_r += image->pixels[y * image->width + x].r * (k == 0 ? 0 : 1);
                        sum_g += image->pixels[y * image->width + x].g * (l == 0 ? 0 : 1);
                        sum_b += image->pixels[y * image->width + x].b * (k == 0 ? 0 : 1);
                    }
                }
            }

            new_pixels[j * image->width + i].r = abs(sum_r);
            new_pixels[j * image->width + i].g = abs(sum_g);
            new_pixels[j * image->width + i].b = abs(sum_b);
        }
    }

    memcpy(image->pixels, new_pixels, sizeof(pixel_t) * image->width * image->height);
}

void main() {
    image_t *image = load_image("input.bmp");
    if (image == NULL) {
        return;
    }

    // Apply some image processing filters
    invert_colors(image);
    grayscale(image);
    blur(image);
    sharpen(image);
    edge_detect(image);

    save_image("output.bmp", image);

    free(image);
}